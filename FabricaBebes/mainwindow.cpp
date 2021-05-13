#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_botonIniciarSentimiento_clicked()
{
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

    ColaHate * colaHate = new ColaHate();
    colaHate->segundos = ui->cajaSegundos->text().toInt();
    this->hilo1.__init__(colaHate);
    this->hilo1.start();
}
void MainWindow::on_botonDetenerSentimiento_clicked()
{
    this->hilo1.stop();
}

void MainWindow::on_botonSentimientoContinuar_clicked()
{
    this->hilo1.continuar();
}
