#include "estructuras.h"
hilo_Musica::hilo_Musica(){

}

void hilo_Musica::__init__(struct ColaNota * colaNota){
    this->colaNota = colaNota;
    this->running = true;
}

void hilo_Musica::run(){
    while(!this->colaNota->isFinishNota()){
        while(!this->running){
            sleep(1);
        }
        this->colaNota->encolarNota();
        qDebug() << "Llevo " << this->colaNota->notasActivas << "Nota (s)";
        sleep(this->colaNota->segundos);
    }
}

void hilo_Musica::stop(){
    this->running = false;
}

void hilo_Musica::continuar(){
    this->running = true;
}
