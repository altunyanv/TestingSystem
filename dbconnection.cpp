#include "dbconnection.h"

QSqlDatabase DBConnection::DB = QSqlDatabase::addDatabase("QSQLITE");

DBConnection::DBConnection()
{

}
