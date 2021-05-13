#include "estructuras.h"
bool ColaMalos::vacia(){
 if (frente == NULL)
    return true;
 else
     return false;
}
void ColaMalos::encolarBebe(Bebe * b){
     if (vacia()){
        frente = new NodoBebe (b);
        malosActivos++;
     }
     else{
          if((1+malosActivos) <= capacidad){
              NodoBebe* actual = frente;
              while (actual->siguiente != NULL)
                 actual = actual->siguiente;
              NodoBebe* nuevo = new NodoBebe (b);
              actual->siguiente = nuevo;
              malosActivos++;
          }
     }
}
NodoBebe * ColaMalos::desencolar(){
      if (vacia()){
         return NULL;
      }
      else{
          NodoBebe* borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = NULL;
          malosActivos-=1;
          return borrado;
       }
}
void ColaMalos::imprimir(){
     cout << "Frente" << endl;
     NodoBebe *tmp = frente;
     while (tmp != NULL){
           cout << tmp->bebe->colorPiel << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}
NodoBebe* ColaMalos::verFrente(){
    return frente;
}
