#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardPaths>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QApplication::setApplicationName("QShoppingList");
    QString db = QStandardPaths::locate(QStandardPaths::AppDataLocation, "database.db");
    if(db.isEmpty()) {
        QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        if(! QDir(path).exists()) {
            QDir().mkpath(path);
        }
        db = path + QDir::separator() + "database.db";
    }

    mDbInterface.initDatabase(db);
}

MainWindow::~MainWindow()
{
    delete ui;
}

