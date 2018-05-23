#include "highlighter.h"

void Highlighter::setRulesFromXML(const QString &path)
{
    QFile * xmlFile = new QFile(path);
    if (!xmlFile->open(QIODevice::ReadOnly)) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }

    QXmlStreamReader * rdr = new QXmlStreamReader(xmlFile);
    while(rdr->name().toString() != QString("StandardRules") || !rdr->isEndElement()) {
        if (rdr->isEndElement())    {
            rdr->readNextStartElement();
            continue;
        }

        QString tmp = rdr->name().toString();
        if (tmp == QString("Keyword")) {
            QXmlStreamAttributes xmlAttr = rdr->attributes();
            keywords = rdr->readElementText().split(" ");
            foreach(QXmlStreamAttribute attr, xmlAttr) {
                if (attr.name() == "color")
                    keywords_format.setForeground(QBrush(QColor(attr.value().toString())));
                if (attr.name() == "bold" && attr.value().toString() == QString("true"))
                    keywords_format.setFontWeight(QFont::Bold);
                if (attr.name() == "italic" && attr.value().toString() == QString("true"))
                    keywords_format.setFontItalic(true);
            }
        }
        else if (tmp == QString("MultiLineComment")) {
            QXmlStreamAttributes xmlAttr = rdr->attributes();
            foreach(QXmlStreamAttribute attr, xmlAttr) {
                if (attr.name() == "start")
                    multiStart = attr.value().toString();
                if (attr.name() == "end")
                    multiEnd = attr.value().toString();
            }
        }
        else if (tmp == QString("SingleLineComment")) {
            QXmlStreamAttributes xmlAttr = rdr->attributes();
            foreach(QXmlStreamAttribute attr, xmlAttr) {
                if (attr.name() == "regularExpr")
                    singleLineComment = QRegularExpression(attr.value().toString());
                if (attr.name() == "color")
                    comment_format.setForeground(QBrush(QColor(attr.value().toString())));
                if (attr.name() == "bold" && attr.value().toString() == QString("true"))
                    comment_format.setFontWeight(QFont::Bold);
                if (attr.name() == "italic" && attr.value().toString() == QString("true"))
                    comment_format.setFontItalic(true);
            }
        }
        else if (tmp == QString("FunctionOrClass")) {
            QXmlStreamAttributes xmlAttr = rdr->attributes();
            foreach(QXmlStreamAttribute attr, xmlAttr) {
                if (attr.name() == "regularExpr")
                    class_function = QRegularExpression(attr.value().toString());
                if (attr.name() == "color")
                    class_function_format.setForeground(QBrush(QColor(attr.value().toString())));
                if (attr.name() == "bold" && attr.value().toString() == QString("true"))
                    class_function_format.setFontWeight(QFont::Bold);
                if (attr.name() == "italic" && attr.value().toString() == QString("true"))
                    class_function_format.setFontItalic(true);
            }
        }
        else if (tmp == QString("String")) {
            QXmlStreamAttributes xmlAttr = rdr->attributes();
            QStringList quote = rdr->readElementText().split(" ");
            singleQuote = QRegularExpression(quote.at(0));
            doubleQuote = QRegularExpression(quote.at(1));
            foreach(QXmlStreamAttribute attr, xmlAttr) {
                if (attr.name() == "color")
                    string_format.setForeground(QBrush(QColor(attr.value().toString())));
                if (attr.name() == "bold" && attr.value().toString() == QString("true"))
                    string_format.setFontWeight(QFont::Bold);
                if (attr.name() == "italic" && attr.value().toString() == QString("true"))
                    string_format.setFontItalic(true);
            }
        }

        rdr->readNextStartElement();
    }
}

void Highlighter::highlightBlock(const QString &text)
{
    QRegularExpressionMatchIterator matchIterator;
    foreach (QString keyword, keywords) {
        matchIterator = QRegularExpression(QString("\\b%1\\b").arg(keyword)).globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), keywords_format);
        }
    }

    matchIterator = class_function.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), class_function_format);
    }

    matchIterator = singleLineComment.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), comment_format);
    }

    matchIterator = singleQuote.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), string_format);
    }

    matchIterator = doubleQuote.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), string_format);
    }

    QRegularExpression start(multiStart), end(multiEnd);
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(start);

    while (startIndex >= 0) {
        if (startIndex == 0) {
            if (previousBlockState() != 1) {
                ;
            }
            else {
                startIndex -= multiStart.length();
            }
        }
        QRegularExpressionMatch match = end.match(text, startIndex + multiStart.length());
        int endIndex = match.capturedStart();
        int commentLength = 0;

        startIndex = startIndex < 0 ? 0 : startIndex;

        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }

        int st = currentBlockState();
        setFormat(startIndex, commentLength, comment_format);
        startIndex = text.indexOf(start, startIndex + commentLength);
    }
}
