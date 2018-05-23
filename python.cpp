#include "python.h"

QString Python::source = "";

Python::Python()
{

}

void Python::set_source(const QString &source_code)
{
    source = source_code;
}

void Python::create_source() {
    QFile * reading = new QFile("tmp_source.py");
    reading->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream * out = new QTextStream(reading);
    out->operator <<(source);
    reading->close();
}

void Python::remove_source() {
    QFile * reading = new QFile("tmp_source.py");
    reading->remove();
}

bool Python::compile() {
    create_source();

    QProcess pr;
    pr.start("cmd.exe");

    if (!pr.waitForStarted())
        return false;

    pr.waitForReadyRead();
    pr.write("python syntax_checker.py tmp_source.py");
    pr.write("\r\n");
    pr.waitForReadyRead();
    pr.waitForFinished(1000);
    pr.close();
    remove_source();

    QFile * reading;
    reading = new QFile("status.txt");
    reading->open(QIODevice::ReadOnly);
    QTextStream * in = new QTextStream(reading);
    QString res;
    in->operator >>(res);
    reading->close();

    return res == "Success";
}

bool Python::run_on_test(QString input, QString output) {
    QFile * reading = new QFile("tmp_input.txt");
    reading->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream * out = new QTextStream(reading);
    out->operator <<(input);
    reading->close();
    reading = new QFile("tmp_output.txt");
    reading->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    reading->close();

    QProcess pr;
    pr.start("cmd.exe");

    if (!pr.waitForStarted())
        return false;

    pr.waitForReadyRead();
    pr.write("python test_checker.py tmp_source.py tmp_input.txt tmp_output.txt");
    pr.write("\r\n");
    pr.waitForReadyRead();
    pr.waitForFinished(500);
    pr.close();

    reading->open(QIODevice::ReadOnly);

    QString user_output = QString::fromStdString(reading->readAll().toStdString());
    reading->close();                       reading->remove();
    reading = new QFile("tmp_input.txt");   reading->remove();

    user_output.replace(QRegularExpression("\r\n"), " ");
    user_output.replace(QRegularExpression("\n"), " ");
    output.replace(QRegularExpression("\r\n"), " ");
    output.replace(QRegularExpression("\n"), " ");

    qDebug(user_output.toStdString().c_str());
    qDebug(output.toStdString().c_str());
    return user_output == output;
}
