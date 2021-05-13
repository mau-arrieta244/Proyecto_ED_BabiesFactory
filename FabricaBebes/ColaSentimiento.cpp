#include "estructuras.h"
string ColaSentimiento::generarSentimientoRandom(){
    string tiposSentimientos[3] ={"vacio", "lleno","roto"};
    srand(time(0));
    int numRandom = rand() % 3;
    return tiposSentimientos[numRandom];
}
void ColaSentimiento::imprimir(void){
     cout << "Frente" << endl;
     NodoSentimiento *tmp = frente;
     while (tmp != NULL){
           cout << tmp->sentimiento->corazon << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}

NodoSentimiento* ColaSentimiento::verFrente(){
      return frente;      
}
void ColaSentimiento::encolarSentimiento(){
     if (frente == NULL)
            frente = new NodoSentimiento(new Sentimiento(generarSentimientoRandom()));
     else{
         if((1+sentimientosActivos) <= capacidad){
             NodoSentimiento* actual = frente;
             while (actual->siguiente != NULL)
                    actual = actual->siguiente;
             sleep(segundos);
             NodoSentimiento* nuevo = new NodoSentimiento(new Sentimiento(generarSentimientoRandom()));
             actual->siguiente = nuevo;
             sentimientosActivos ++;
         }
     }
}
NodoSentimiento *  ColaSentimiento::desencolarSentimiento(){
      if (frente == NULL){
         return NULL;
      }
      else{
          NodoSentimiento * borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = NULL;
          sentimientosActivos-=1;
          return borrado;
      }
}
