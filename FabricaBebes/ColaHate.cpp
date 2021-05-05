#include "estructuras.h"
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
void ColaHate::encolarHate(Hate * pHate){
    if (frente == NULL)
		    frente = new NodoHate(pHate);
	else{
		NodoHate* actual = frente;
	    while (actual->siguiente != NULL)
		    actual = actual->siguiente;  
	    NodoHate* nuevo = new NodoHate(pHate);
		actual->siguiente = nuevo;
	}
}