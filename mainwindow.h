#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbinterface.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();
    void on_radioShowFinished_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    DbInterface mDbInterface;

    void clearUi();
};
#endif // MAINWINDOW_H
