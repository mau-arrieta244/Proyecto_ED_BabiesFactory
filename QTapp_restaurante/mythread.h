#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT // "macro" , correr qmake y ahora si encuentra signal
public:
    explicit MyThread(QObject * parent =0);
    //MyThread();
    int tiempoEspera=2;
    bool stop;
    /*
    void __init__(){
        //this->tiempoEspera = tiempo;
        this->stop = false;

    }
    */
    void run();

signals:
    void ValorCambio(int);

public slots:

};

#endif // MYTHREAD_H
