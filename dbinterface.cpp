#include "dbinterface.h"

DbInterface::DbInterface(QObject *parent) : QObject(parent)
{

}

bool DbInterface::initDatabase(QString path)
{
    mDb = QSqlDatabase::addDatabase("QSQLITE");
    mDb.setDatabaseName(path);
    if(! mDb.open()) {
        return false;
    }

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS Shopping (ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                  "Status BOOLEAN, Item TEXT)");
    if(! query.exec()) {
        qDebug() << "Error creating table";
        qDebug() << query.lastError().databaseText();
        return false;
    }

    return true;
}
