#include "estructuras.h"
int main(int argc, char *argv[]){
    ListaSimple * sentimientos = new ListaSimple();
    Sentimiento * pruebaSentimiento = new Sentimiento("Vacio");
    sentimientos->insertar(pruebaSentimiento);
    sentimientos->imprimir();
    system("PAUSE");
    return EXIT_SUCCESS;  
}