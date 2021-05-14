#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "estructuras.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    hilo_Hate hilo1;
    hilo_Sentimiento hilo2;
    hilo_Musica hilo3;
    hilo_Generador hilo4;
    ~MainWindow();

private slots:

    void on_botonIniciarHate_clicked();

    void on_botonDetenerHate_clicked();

    void on_botonHateContinuar_clicked();

    void on_botonIniciarSentimiento_clicked();

    void on_botonDetenerSentimiento_clicked();

    void on_botonContinuarSentimiento_clicked();

    void on_botonIniciarMusica_clicked();

    void on_botonDetenerMusica_clicked();

    void on_botonContinuarMusica_clicked();

    void on_botonIniciarGenerador_clicked();

    void on_botonDetenerGenerador_clicked();

    void on_botonContinuarGenerador_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
