#ifndef PYTHON_H
#define PYTHON_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QRegularExpression>

class Python
{
public:
    Python();
    static QString source;
    static void set_source(const QString& source);
    static void create_source();
    static void remove_source();
    static bool compile();
    static bool run_on_test(QString input, QString output);
};

#endif // PYTHON_H
