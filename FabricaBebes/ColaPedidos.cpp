#include "estructuras.h"
bool ColaPedidos::vacia(){
 if (frente == NULL)
    return true;
 else
     return false;
}
void ColaPedidos::encolarBebe(Bebe * b){
     if (vacia())
         frente = new NodoBebe (b);
     else{
          NodoBebe* actual = frente;
          while (actual->siguiente != NULL)
              actual = actual->siguiente;
          NodoBebe* nuevo = new NodoBebe (b);
          actual->siguiente = nuevo;
          bebesActivos+= 1;
     }
}
NodoBebe * ColaPedidos::desencolar(){
      if (vacia()){
         return NULL;
      }
      else{
          NodoBebe* borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = NULL;
          bebesActivos-=1;
          return borrado;
       }
}
void ColaPedidos::imprimir(){
     cout << "Frente" << endl;
     NodoBebe *tmp = frente;
     while (tmp != NULL){
           cout << tmp->bebe->colorPiel << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}
NodoBebe* ColaPedidos::verFrente(){
    return frente;
}
