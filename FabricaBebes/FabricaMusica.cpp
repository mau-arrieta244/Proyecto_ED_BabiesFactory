#include "estructuras.h"
string FabricaMusica::generarNotaRandom(){
    string tiposNotas[2] ={"vacia", "llena"};
    srand(time(0));
    int numRandom = rand() % 2;
    return tiposNotas[numRandom];
}
void FabricaMusica::insertarNota(int segundos, int cantidad, FabricaMusica * fabrica){
    if((cantidad+fabrica->notasActivas) <= fabrica->capacidad){
        string tipoNota;
        int i = cantidad;
        while(i != 0){
            sleep(segundos);
            tipoNota = generarNotaRandom();
            fabrica->notas->encolarNota(new Nota(tipoNota));
            i--;
        }
        fabrica->notasActivas += cantidad;
    }
    else{
        cout << "La cantidad ingresada sobrepasa la capacidad de la fabrica." << endl;
    }
}
void FabricaMusica::imprimir(){
    notas->imprimir();
}