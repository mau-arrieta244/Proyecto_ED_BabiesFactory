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
        nHateObtenido = fabricas->fabricaHate->hates->desencolarHate();
        tipoHate = nHateObtenido->hate->tipoHate;
        nMusicaObtenido = fabricas->fabricaMusica->notas->desencolarNota();
        tipoNota = nMusicaObtenido->nota->tipoNota;
        nSentimientoObtenido = fabricas->fabricaSentimiento->sentimientos->desencolarSentimiento();
        tipoSentimiento = nSentimientoObtenido->sentimiento->corazon;
        Bebe * bebeCreado = new Bebe(tipoSentimiento, tipoNota , tipoHate);
        if(bebeCreado->bebeMalo == false && colaBebes->bebesActivos+1 <= colaBebes->capacidad){
            colaBebes->encolarBebe(bebeCreado);
        }
        else{
            colaMalos->encolarBebe(bebeCreado);
        }
    }
}
