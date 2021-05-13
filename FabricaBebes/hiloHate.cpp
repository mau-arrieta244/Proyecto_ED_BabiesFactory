#include "hiloHate.h"
hilo_Hate::hilo_Hate(){

}

void hilo_Hate::__init__(struct ColaHate * colaHate){
    this->colaHate = colaHate;
    this->running = true;
}


void hilo_Hate::run(){
    while(!this->colaHate->isFinish()){
        while(!this->running){
            sleep(1);
        }
        this->colaHate->encolarHate();
        qDebug() << "Llevo " << this->colaHate->hatesActivos << "Sentimiento (s)";
        sleep(this->colaHate->segundos);
    }
}

void hilo_Hate::stop(){
    this->running = false;
}

void hilo_Hate::continuar(){
    this->running = true;
}