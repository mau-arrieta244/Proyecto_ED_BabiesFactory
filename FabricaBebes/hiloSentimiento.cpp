#include "estructuras.h"
hilo_Sentimiento::hilo_Sentimiento(){

}

void hilo_Sentimiento::__init__(struct ColaSentimiento * colaSentimiento){
    this->colaSentimiento = colaSentimiento;
    this->running = true;
}


void hilo_Sentimiento::run(){
    while(!this->colaSentimiento->isFinishSentimiento()){
        while(!this->running){
            sleep(1);
        }
        this->colaSentimiento->encolarSentimiento();
        qDebug() << "Llevo " << this->colaSentimiento->sentimientosActivos << "Sentimiento (s)";
        sleep(this->colaSentimiento->segundos);
    }
}

void hilo_Sentimiento::stop(){
    this->running = false;
}

void hilo_Sentimiento::continuar(){
    this->running = true;
}
