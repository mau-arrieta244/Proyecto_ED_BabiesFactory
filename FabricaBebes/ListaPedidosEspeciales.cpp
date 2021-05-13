#include "estructuras.h"
bool ListaPedidosEspeciales::isEmpty(){
    return primerNodo == NULL;
}

void ListaPedidosEspeciales::insertar (string infoMama,string infoPapa,string infoHijo){
    if (isEmpty())
        primerNodo = ultimoNodo = new NodoHistorico(infoMama,infoPapa,infoHijo);
    else{
        primerNodo->anterior = new NodoHistorico(infoMama,infoPapa,infoHijo);
        primerNodo->anterior->siguiente = primerNodo;
        primerNodo = primerNodo->anterior;
    }
    cantidadBebes++;
}

void ListaPedidosEspeciales::insertarAlFinal(string infoMama,string infoPapa,string infoHijo){
    if (isEmpty())
        primerNodo = ultimoNodo = new NodoHistorico(infoMama,infoPapa,infoHijo);
    else{
        ultimoNodo->siguiente = new NodoHistorico(infoMama,infoPapa,infoHijo);
        ultimoNodo->siguiente->anterior = ultimoNodo;
        ultimoNodo = ultimoNodo->siguiente;
    }
    cantidadBebes++;
}

void ListaPedidosEspeciales::imprimir(bool inverted){
    if (inverted){
        NodoHistorico * tmp = ultimoNodo;
        while(tmp != NULL){
            cout << tmp->tipoPadre<< " "<<tmp ->tipoMadre<<" "<< tmp->tipoBebe<< " -> ";
            tmp = tmp->anterior;
        }
    }
    else{
        NodoHistorico * tmp = primerNodo;
        while(tmp != NULL){
            cout << tmp->tipoPadre<< " "<<tmp ->tipoMadre<<" "<< tmp->tipoBebe<< " -> ";
            tmp = tmp->siguiente;
        }
    }
    cout << endl;
}

//borrar al inicio: si esta vacia retorna null
NodoHistorico * ListaPedidosEspeciales::borrar(){
    NodoHistorico * borrado = primerNodo;
    if (!isEmpty() && primerNodo == ultimoNodo)
        primerNodo = ultimoNodo = NULL;
    else if (!isEmpty()){
        primerNodo = primerNodo->siguiente;
        primerNodo->anterior = borrado->siguiente = NULL;
    }
    return borrado;
}

NodoHistorico * ListaPedidosEspeciales::borrarAlFinal(){
    NodoHistorico * borrado = ultimoNodo;
    if (!isEmpty() && primerNodo == ultimoNodo)
        primerNodo = ultimoNodo = NULL;
    else if (!isEmpty()){
        ultimoNodo = ultimoNodo->anterior;
        ultimoNodo->siguiente = borrado->anterior = NULL;
    }
    return borrado;
}
