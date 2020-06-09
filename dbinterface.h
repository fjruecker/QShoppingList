#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <QObject>

class DbInterface : public QObject
{
    Q_OBJECT
public:
    explicit DbInterface(QObject *parent = nullptr);

signals:

};

#endif // DBINTERFACE_H
