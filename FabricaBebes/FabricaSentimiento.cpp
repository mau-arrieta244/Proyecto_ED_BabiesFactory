#include "estructuras.h"
string FabricaSentimiento::generarSentimientoRandom(){
    string tiposSentimientos[3] ={"vacio", "lleno","roto"};
    srand(time(0));
    int numRandom = rand() % 3;
    return tiposSentimientos[numRandom];
}
string FabricaSentimiento::insertarSentimiento(int segundos, FabricaSentimiento * fabrica){
    string activosString = std::to_string(fabrica->sentimientosActivos);
    if((1+fabrica->sentimientosActivos) <= fabrica->capacidad){
        string tipoSentimiento;
        int i = 1;
        while(i != 0){
            sleep(segundos);
            tipoSentimiento = generarSentimientoRandom();
            fabrica->sentimientos->encolarSentimiento(new Sentimiento(tipoSentimiento));
            i--;
        }
        fabrica->sentimientosActivos += 1;
        return "Sentimiento(s) agregado(s) " + activosString + "/20";
    }
    else if(fabrica->sentimientosActivos == 20){
        return "Fábrica sentimiento llena 20/20";
    }
    else{
        return "Ingrese una menor cantidad" + activosString + "/20";
    }
}
void FabricaSentimiento::imprimir(){
    sentimientos->imprimir();
}
