#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hiloHate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    hilo_Hate hilo1;
    ~MainWindow();

private slots:

    void on_botonIniciarSentimiento_clicked();

    void on_botonDetenerSentimiento_clicked();

    void on_botonSentimientoContinuar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
