#include "estructuras.h"
string ColaHate::generarHateRandom(){
    string tiposHate[2] ={"vacio", "lleno"};
    srand(time(0));
    int numRandom = rand() % 2;
    return tiposHate[numRandom];
}
void ColaHate::imprimir(void){
     cout << "Frente" << endl;
     NodoHate *tmp = frente;
     while (tmp != NULL){
           cout << tmp->hate->tipoHate << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}
NodoHate* ColaHate::verFrente(){
      return frente;      
}
void ColaHate::encolarHate(){
    if (frente == NULL){
            frente = new NodoHate(new Hate(generarHateRandom()));
            hatesActivos ++;
    }
	else{
        if((1+hatesActivos) <= capacidad){
            string tipoHate;
            NodoHate* actual = frente;
            while (actual->siguiente != NULL)
                actual = actual->siguiente;
            sleep(segundos);
            NodoHate* nuevo = new NodoHate(new Hate(generarHateRandom()));
            actual->siguiente = nuevo;
            hatesActivos ++;
        }
    }
}
NodoHate *  ColaHate::desencolarHate(){
      if (frente == NULL){
         return NULL;
      }
      else{
          NodoHate * borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = NULL;
          hatesActivos-=1;
          return borrado;
      }
}
bool ColaHate::isFinish(){
    return hatesActivos == 20;
}

