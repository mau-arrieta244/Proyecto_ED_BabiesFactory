#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mythread.h"
#include <QMainWindow>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MyThread * mThread;

private slots:
    void on_pushButton_clicked();

    void on_boton1_clicked();

    //void onValorCambio(int);

private:
    Ui::MainWindow *ui;

public slots:
    void onValorCambio(int);

};

#endif // MAINWINDOW_H
