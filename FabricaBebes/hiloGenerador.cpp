#include "estructuras.h"
hilo_Generador::hilo_Generador(){

}

void hilo_Generador::__init__(struct FabricanteAutomatico * fabricanteAutomatico){
    this->fabricanteAutomatico = fabricanteAutomatico;
    this->running = true;
}

void hilo_Generador::run(){
    while(!this->fabricanteAutomatico->isFinishGenerador()){
        while(!this->running){
            sleep(1);
        }
        this->fabricanteAutomatico->crearBebeRandom();
        sleep(this->fabricanteAutomatico->segundos);
    }
}

void hilo_Generador::stop(){
    this->running = false;
}

void hilo_Generador::continuar(){
    this->running = true;
}
