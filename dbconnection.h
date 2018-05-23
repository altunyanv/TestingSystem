#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql>
#include <QXmlStreamReader>
#include <QFile>


#define OPEN_CONN   DBConnection::open();
#define CLOSE_CONN  DBConnection::close();
#define SETUP_CONN  DBConnection::setup_database_name();

class DBConnection
{
public:
    DBConnection();
    static QSqlDatabase DB;
    static void setup_database_name() {
        QFile * xmlFile = new QFile(":/data/appconfig.xml");
        if (!xmlFile->open(QIODevice::ReadOnly)) {
            qDebug("Ստոպ բեյբի էս ինչ ես անում!");
        }

        QXmlStreamReader * rdr = new QXmlStreamReader(xmlFile);
        while(rdr->name().toString() != QString("Configuration") || !rdr->isEndElement()) {
            if (rdr->name().toString() == QString("DatabaseName")) {
                DB.setDatabaseName(rdr->readElementText());
                xmlFile->close();
                break;
            }
            rdr->readNextStartElement();
        }
    }
    static void open() {
        if (!DB.isOpen())
            DB.open();
    }
    static void close() {
        if (DB.isOpen())
            DB.close();
    }
};

#endif // DBCONNECTION_H
