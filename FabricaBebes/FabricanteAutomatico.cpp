#include "estructuras.h"

void FabricanteAutomatico::crearBebeRandom(){
    NodoHate * nHateObtenido;
    string tipoHate;
    NodoSentimiento * nSentimientoObtenido;
    string tipoSentimiento;
    NodoNota * nMusicaObtenido;
    string tipoNota;
    int porcentaje = rand() % 100;
    int cantidad = 0;
    if(porcentaje <= 89){
        cantidad = 1;
    }
    else if(porcentaje <= 94){
        cantidad = 2;
    }
    else if(porcentaje <= 97){
        cantidad = 3;
    }
    else if(porcentaje <= 99){
        cantidad = 4;
    }
    for(int i = 0; i < cantidad; i++){
        nHateObtenido = colaHate->desencolarHate();
        tipoHate = nHateObtenido->hate->tipoHate;
        nMusicaObtenido = colaNota->desencolarNota();
        tipoNota = nMusicaObtenido->nota->tipoNota;
        nSentimientoObtenido = colaSentimiento->desencolarSentimiento();
        tipoSentimiento = nSentimientoObtenido->sentimiento->corazon;
        if(nHateObtenido != NULL & nMusicaObtenido != NULL & nSentimientoObtenido != NULL){
            Bebe * bebeCreado = new Bebe(tipoSentimiento, tipoNota , tipoHate);
            if(bebeCreado->bebeMalo == false && colaBebes->bebesActivos+1 <= colaBebes->capacidad){
                colaBebes->encolarBebe(bebeCreado);
                qDebug() << "Llevo " << this->colaBebes->bebesActivos << "Bebes bueno (s)";
            }
            else{
                colaMalos->encolarBebe(bebeCreado);
                qDebug() << "Llevo " << this->colaMalos->malosActivos << "Bebes malo (s)";
            }
        }
        else{
            Bebe * bebeCreado2 = new Bebe(true);
            colaMalos->encolarBebe(bebeCreado2);
            qDebug() << "Llevo " << this->colaMalos->malosActivos << "Bebes malo (s)";
        }
    }
}
bool FabricanteAutomatico::isFinishGenerador(){
    return colaBebes->bebesActivos == 10;
}

