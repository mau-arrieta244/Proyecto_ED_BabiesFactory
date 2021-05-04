#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <Windows.h>
#include <unistd.h>
using namespace std;

//Prototipos de estructuras
struct Sentimiento;
struct FabricaSentimiento;
struct Nodo;
struct Cola;

// estructura nodo para lista simple
struct Nodo{
       Sentimiento * sentimiento;  //TODO: CHANGE PRIORITY
       Nodo* siguiente; // puntero para enlazar nodos
       
       Nodo() {
              sentimiento = NULL;
              siguiente = NULL;
       }
       Nodo(Sentimiento * inSentimiento){
              sentimiento = inSentimiento; // asigna los datos 
              siguiente = NULL;
       }
      void imprimir();   
};
struct Sentimiento{
       string corazon;
       Sentimiento(string pCorazon){
              corazon = pCorazon;
              
       }
       void imprimir(){
              cout << "Corazon " << corazon << endl;
       }
};
struct Cola{
       Nodo *frente; 
       
       Cola(){
            frente = NULL;
       }
       
       // encabezados de funcion
       //void encolar (int dato);
       //Nodo* desencolar (void);
       Nodo* verFrente(void);
       void imprimir(void);
       void encolarSentimiento(Sentimiento * pSentimiento){
       	if (frente == NULL)
		       frente = new Nodo(pSentimiento);
		else{
		       // referencia al primero para recorrer la lista
		       Nodo* actual = frente;
	              // recorre la lista hasta llegar al penultimo nodo
	              while (actual->siguiente != NULL)
		              actual = actual->siguiente; 
		       
	              // Crea nuevo nodo, lo apunta con uN  
	              Nodo* nuevo = new Nodo(pSentimiento);
		       //le quita el enlace al que era ultimo
		       actual->siguiente = nuevo;
		}
	}
};

struct FabricaSentimiento{
       int capacidad;
       int sentimientosActivos;
       Cola * sentimientos; 
       //ListaSimple * sentimientos;

       FabricaSentimiento(){
              capacidad = 20;
              sentimientosActivos = 0;
              sentimientos = new Cola();
       }
       /*
       void imprimir(){
              sentimientos->imprimir();
       }
       */
};

