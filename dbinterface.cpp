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

int DbInterface::addData(QMap<QString, QVariant> data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Shopping (Status, Item) VALUES (?, ?)");
    query.bindValue(0, data.value("Status"));
    query.bindValue(1, data.value("Item"));

    if(! query.exec()) {
        qDebug() << "Error adding item";
        emit addData(-1);
        return -1;
    }

    int id = query.lastInsertId().toInt();
    emit addData(id);
    return id;
}

QList<QMap<QString, QVariant> > DbInterface::getData()
{

}
