#include "estructuras.h"
string FabricaHate::generarHateRandom(){
    string tiposHate[2] ={"vacio", "lleno"};
    srand(time(0));
    int numRandom = rand() % 2;
    return tiposHate[numRandom];
}
void FabricaHate::insertarHate(int segundos,int cantidad, FabricaHate * fabrica){
    if((cantidad+fabrica->hatesActivos) <= fabrica->capacidad){
        string tipoHate;
        int i = cantidad;
        while(i != 0){
            sleep(segundos);
            tipoHate = generarHateRandom();
            fabrica->hates->encolarHate(new Hate(tipoHate));
            i--;
        }
        fabrica->hatesActivos += cantidad;
    }
    else{
        cout << "La cantidad ingresada sobrepasa la capacidad de la fabrica." << endl;
    }
}
void FabricaHate::imprimir(){
    hates->imprimir();
}