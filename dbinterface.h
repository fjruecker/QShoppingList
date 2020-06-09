#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <QObject>
#include <QtSql>

class DbInterface : public QObject
{
    Q_OBJECT
public:
    explicit DbInterface(QObject *parent = nullptr);
    bool initDatabase(QString path);

signals:
    void getData(QList<QMap<QString,QVariant>>);
    void addData(int id);

public slots:
    int addData(QMap<QString,QVariant> data);
    QList<QMap<QString,QVariant>> getData();
    QList<QMap<QString,QVariant>> getData(bool status);

private:
    QSqlDatabase mDb;
    QList<QMap<QString, QVariant> > createList(QSqlQuery query);
};

#endif // DBINTERFACE_H
