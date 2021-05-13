#include "estructuras.h"
string ColaNota::generarNotaRandom(){
    string tiposNotas[2] ={"vacia", "llena"};
    srand(time(0));
    int numRandom = rand() % 2;
    return tiposNotas[numRandom];
}
void ColaNota::imprimir(void)
{
     cout << "Frente" << endl;
     NodoNota *tmp = frente;
     while (tmp != NULL)
     {
           cout << tmp->nota->tipoNota << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}
NodoNota* ColaNota::verFrente(){
      return frente;      
}
void ColaNota::encolarNota(){
    if (frente == NULL){
        frente = new NodoNota(new Nota(generarNotaRandom()));
        notasActivas ++;
    }

	else{
        if((1+notasActivas) <= capacidad){
            NodoNota* actual = frente;
            while (actual->siguiente != NULL)
                actual = actual->siguiente;
            sleep(segundos);
            NodoNota* nuevo = new NodoNota(new Nota(generarNotaRandom()));
            actual->siguiente = nuevo;
            notasActivas ++;
        }
	}
}
NodoNota *  ColaNota::desencolarNota(){
      if (frente == NULL){
         return NULL;
      }
      else{
          NodoNota * borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = NULL;
          notasActivas-=1;
          return borrado;
      }
}
