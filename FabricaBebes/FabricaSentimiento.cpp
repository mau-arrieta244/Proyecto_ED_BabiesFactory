#include "estructuras.h"
string FabricaSentimiento::generarSentimientoRandom(){
    string tiposSentimientos[3] ={"vacio", "lleno","roto"};
    srand(time(0));
    int numRandom = rand() % 3;
    return tiposSentimientos[numRandom];
}
void FabricaSentimiento::insertarSentimiento(int segundos, int cantidad, FabricaSentimiento * fabrica){
    if((cantidad+fabrica->sentimientosActivos) <= fabrica->capacidad){
        string tipoSentimiento;
        int i = cantidad;
        while(i != 0){
            sleep(segundos);
            tipoSentimiento = generarSentimientoRandom();
            fabrica->sentimientos->encolarSentimiento(new Sentimiento(tipoSentimiento));
            i--;
        }
        fabrica->sentimientosActivos += cantidad;
    }
    else{
        cout << "La cantidad ingresada sobrepasa la capacidad de la fabrica." << endl;
    }
}
void FabricaSentimiento::imprimir(){
    sentimientos->imprimir();
}