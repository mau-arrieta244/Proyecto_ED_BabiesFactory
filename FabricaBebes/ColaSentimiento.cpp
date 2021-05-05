#include "estructuras.h"
void ColaSentimiento::imprimir(void)
{
     cout << "Frente" << endl;
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     NodoSentimiento *tmp = frente;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->sentimiento->corazon << "  " << endl;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}


NodoSentimiento* ColaSentimiento::verFrente()
{
      return frente;      
}