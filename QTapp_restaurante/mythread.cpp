#include "mythread.h"
#include "bebes.cpp"
#include <QtCore>
/*
MyThread::MyThread()
{

}
*/
MyThread::MyThread(QObject * parent):
        QThread(parent)
    {

    }



void MyThread::run()
    {

    ColaPedidos * c1 = new ColaPedidos ();
    ListaPedidosEspeciales * l1 = new ListaPedidosEspeciales();

    QMutex mutex;

    while(!this->stop){
        //mutex.lock();
        listdir("C:\\Users\\mauar\\Desktop\\CODE\\Proyecto_ED_BabiesFactory\\pedidosEspeciales",c1,l1);
        //mutex.unlock();
        this->sleep(this->tiempoEspera);
        emit ValorCambio(l1->cantidadBebes);
    }


    }
