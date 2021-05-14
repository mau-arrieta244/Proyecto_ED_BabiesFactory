#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "estructuraspedido.h"
#include "hilopedidos.h"
#include <QFile>
#include <QStringList>
#include <QMessageBox>

//Globales
ColaHate * colaHate = new ColaHate();
ColaSentimiento * colaSentimiento = new ColaSentimiento();
ColaNota * colaNota = new ColaNota();
ColaBebes * colaBebes = new ColaBebes();
ColaMalos * colaMalos = new ColaMalos();
FabricanteAutomatico * generador = new FabricanteAutomatico(colaHate,
                                                            colaSentimiento,
                                                            colaNota,colaBebes,
                                                            colaMalos);
estructurasPedido::ListaPedidosEspeciales * listaGlobal = new estructurasPedido::ListaPedidosEspeciales;
estructurasPedido::ColaPedidos * colaGlobal = new estructurasPedido::ColaPedidos;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}
//////////////////////////////////////////////////////////////
//     Funciones "sueltas" (no pertenecen a ningun struct)  //
//////////////////////////////////////////////////////////////


//prueba, para ver como accesar a estas funciones desde botones
// QString algo = this -> easy();
QString MainWindow::easy()
{
    QStringList a = {"a","b","c"};
    return a[0];
}



QString MainWindow::colorPapa(QString nombreArchivo){
        QFile file(nombreArchivo);

        if(file.open(QFile::ReadOnly |QFile::Text)){
            QTextStream in(&file);
            QString contenido = in.readAll();

            //genera una lista donde el caracter separa string
            // colores = { tipoPadre , tipoMadre}
            QStringList colores = contenido.split(';');

            QString tipoPadre = colores[0];
            file.close();
            return tipoPadre;
        }

}

int MainWindow::longitudPapa(QString nombreArchivo){
    QString tipoPadre = MainWindow::colorPapa(nombreArchivo);
    return tipoPadre.length();
}

//ya no ocupa longitudPadre! modificarlo despues...
QString MainWindow::colorMama(QString nombreArchivo,int longitudPadre){
    QFile file(nombreArchivo);

    if(file.open(QFile::ReadOnly |QFile::Text)){
        QTextStream in(&file);
        QString contenido = in.readAll();

        //genera una lista donde el caracter separa string
        // colores = { tipoPadre , tipoMadre}

        //con doble comilla o single comilla???
        QStringList colores = contenido.split(';');


        QString tipoMadre = colores[1];
        file.close();
        return tipoMadre;
    }



}

QString MainWindow::checkPathString(QString path){
    if(path[path.length()-1] == '/'){
            path = path.remove(path.length()-1,1);
        }
    return path;
}

void MainWindow::listdir(QString initStrPath,
         estructurasPedido::ColaPedidos * cola,
         estructurasPedido::ListaPedidosEspeciales * lista)
{
    struct dirent * dir;
        //siguiente linea puede o puede no dar problemas...
        DIR * dp = opendir(initStrPath.toStdString().c_str());

        if(dp){
            while((dir = readdir(dp))!=NULL){
                QString strPath ="";
                if(strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0)continue;

                else{

                    initStrPath = checkPathString(initStrPath);
                    strPath = initStrPath+"/"+dir->d_name;
                    //cout<<strPath<<endl;
                    //cout<<"\n ------ \n"<<endl;
                    QString cP =colorPapa(strPath);
                    int lenPadre = longitudPapa(strPath);
                    QString cM = colorMama(strPath,lenPadre); // recibe len de tipo padre para cortar string a partir de ahi

                    /// !!!!!!!!
                    estructurasPedido::Padres * p1 = new estructurasPedido::Padres(cP,cM);
                    QString colorHijo = p1->probabilidadHijo();
                    //estructurasPedido::Bebe * b1 = new estructurasPedido::Bebe(colorHijo);

                    //cola->encolarBebe(b1);
                    //cola->imprimir();

                    //NodoHistorico * n1 = new NodoHistorico(cM,cP,colorHijo);


                    //!!!!!
                    lista->insertarAlFinal(cM,cP,colorHijo); // crea nuevo nodo y lo mete a la lista

                    listdir(strPath,cola,lista);
                    const int result = remove(strPath.toStdString().c_str());
                    //cout<<"\n ------ \n"<<endl;

                }
            }
            closedir(dp);
        }
}
void MainWindow::on_botonIniciarHate_clicked(){
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

