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

private:
    QSqlDatabase mDb;
};

#endif // DBINTERFACE_H
