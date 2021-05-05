#include "estructuras.h"
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
void ColaNota::encolarNota(Nota * pNota){
      if (frente == NULL)
		frente = new NodoNota(pNota);
	else{
		NodoNota* actual = frente;
	      while (actual->siguiente != NULL)
		    actual = actual->siguiente;  
	      NodoNota* nuevo = new NodoNota(pNota);
		actual->siguiente = nuevo;
	}
}