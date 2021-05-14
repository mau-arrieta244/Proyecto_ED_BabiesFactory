#include "mainwindow.h"
#include "ui_mainwindow.h"

ColaHate * colaHate = new ColaHate();
ColaSentimiento * colaSentimiento = new ColaSentimiento();
ColaNota * colaNota = new ColaNota();
ColaBebes * colaBebes = new ColaBebes();
ColaMalos * colaMalos = new ColaMalos();
FabricanteAutomatico * generador = new FabricanteAutomatico(colaHate,
                                                            colaSentimiento,
                                                            colaNota,colaBebes,
                                                            colaMalos);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_botonIniciarHate_clicked(){
    /*
    //FabricanteAutomatico * fabricante = new FabricanteAutomatico();
    fabricas->fabricaHate->hates->segundos = ui->cajaSegundos->text().toInt();
    fabricas->fabricaHate->hates->encolarHate();
    int activosHate = fabricas->fabricaHate->hates->hatesActivos;
    string activosString = std::to_string(activosHate);
    string txt = activosString +"/20";
    QString qstr = QString::fromStdString(txt);
    ui->labelSentimiento->setText(qstr);
    fabricas->fabricaHate->hates->imprimir();
    */


    colaHate->segundos = ui->cajaSegundos->text().toInt();
    this->hilo1.__init__(colaHate);
    this->hilo1.start();
}
void MainWindow::on_botonDetenerHate_clicked()
{
    colaHate->imprimir();
    this->hilo1.stop();
}

void MainWindow::on_botonHateContinuar_clicked()
{
    this->hilo1.continuar();
}

void MainWindow::on_botonIniciarSentimiento_clicked()
{

    colaSentimiento->segundos = ui->cajaSegundos_2->text().toInt();
    this->hilo2.__init__(colaSentimiento);
    this->hilo2.start();
}

void MainWindow::on_botonDetenerSentimiento_clicked()
{
    colaSentimiento->imprimir();
    this->hilo2.stop();
}

void MainWindow::on_botonContinuarSentimiento_clicked()
{
    this->hilo2.continuar();
}


void MainWindow::on_botonIniciarMusica_clicked()
{

    colaNota->segundos = ui->cajaSegundos_3->text().toInt();
    this->hilo3.__init__(colaNota);
    this->hilo3.start();
}

void MainWindow::on_botonDetenerMusica_clicked()
{
    colaNota->imprimir();
    this->hilo3.stop();
}

void MainWindow::on_botonContinuarMusica_clicked()
{
    this->hilo3.continuar();
}

void MainWindow::on_botonIniciarGenerador_clicked()
{
    generador->segundos = ui->cajaSegundos_4->text().toInt();
    this->hilo4.__init__(generador);
    this->hilo4.start();
}

void MainWindow::on_botonDetenerGenerador_clicked()
{
    generador->colaBebes->imprimir();
    generador->colaMalos->imprimir();
    this->hilo4.stop();
}

void MainWindow::on_botonContinuarGenerador_clicked()
{
    this->hilo4.continuar();
}
