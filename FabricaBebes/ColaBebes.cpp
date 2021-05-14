#include "estructuras.h"
bool ColaBebes::vacia(){
 if (frente == NULL)
    return true;
 else
     return false;
}
void ColaBebes::encolarBebe(Bebe * b){
     if (vacia()){
         frente = new NodoBebe (b);
         bebesActivos ++;
     }
     else{
          NodoBebe* actual = frente;
          while (actual->siguiente != NULL)
              actual = actual->siguiente;
          NodoBebe* nuevo = new NodoBebe (b);
          actual->siguiente = nuevo;
          bebesActivos ++;
     }
}
NodoBebe * ColaBebes::desencolar(){
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
void ColaBebes::imprimir(){
     cout << "Frente" << endl;
     NodoBebe *tmp = frente;
     while (tmp != NULL){
           cout << tmp->bebe->colorPiel << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}
NodoBebe* ColaBebes::verFrente(){
    return frente;
}
