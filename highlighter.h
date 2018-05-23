#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QXmlStreamReader>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QString>
#include <QStringList>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

private:
    QString multiStart, multiEnd;
    QStringList keywords;
    QTextCharFormat keywords_format, comment_format, class_function_format, string_format;
    QRegularExpression class_function, singleLineComment, singleQuote, doubleQuote;

public:
    Highlighter(QTextDocument *parent = 0) : QSyntaxHighlighter(parent) {}

    void setRulesFromXML(const QString& path);

protected:
    void highlightBlock(const QString &text) override;
};

#endif // HIGHLIGHTER_H
