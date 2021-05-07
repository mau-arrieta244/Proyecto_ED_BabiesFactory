#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "bebes.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mThread = new MyThread(this);
    //MyThread t1;
    //t1.__init__(12);
    connect(mThread,SIGNAL(ValorCambio(int)),this,SLOT(onValorCambio(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_boton1_clicked()
{
    //iniciar
    mThread->start();

}

void MainWindow::onValorCambio(int valor)
    {
        ui->display->setText(QString::number(valor));
    }

void MainWindow::on_pushButton_clicked()
{
    //detener
    mThread->stop=true;
}
