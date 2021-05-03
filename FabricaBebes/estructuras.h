#include <cstdlib>
#include <iostream>
using namespace std;

//Prototipos de estructuras

struct Sentimiento;
struct NodoSentimiento;
struct ListaSimple;
struct FabricaSentimiento;
struct Persona;
struct Nodo;
struct Pila;
struct Cola;
struct ColaPrioridad;

struct Sentimiento{
       string corazon;
       Sentimiento(string pCorazon){
              corazon = pCorazon;
       }
       void imprimir(){
              cout << "Sentimiento: " << corazon << endl;
       }
};
struct NodoSentimiento{
       Sentimiento * sentimiento;
       NodoSentimiento * siguiente;

       NodoSentimiento(Sentimiento * pSentimiento){
              sentimiento = pSentimiento;
              siguiente = NULL;
       }
};

struct ListaSimple{
	NodoSentimiento * primerNodo, *ultimoNodo;

	ListaSimple (){
		primerNodo = ultimoNodo = NULL;
	}
	
	void imprimir();
	void insertar(Sentimiento*);	
	
	// busca un hijo por nombre. Retorna null si no lo encuentra
	/*
       NodoHijo * buscar(string nombre){
		NodoHijo * tmp = primerNodo;
		while (tmp!= NULL){
			if (tmp->hijo->nombre == nombre)
				return tmp;
			tmp = tmp->siguiente;
		}
		return NULL;
	}
       */
};
struct FabricaSentimiento{
       int capacidad;
       ListaSimple * sentimientos;

       FabricaSentimiento(){
              capacidad = 0;
              sentimientos = new ListaSimple();
       }
       FabricaSentimiento(int pCapacidad){
              capacidad = pCapacidad;
              sentimientos = new ListaSimple();
       }
       void imprimir(){
              sentimientos->imprimir();
       }

};
struct Persona{
	int id;
	int priority;
	
	Persona (int _id, int _p){
		id = _id;
		priority = _p;
	}

};


// estructura nodo para lista simple
struct Nodo {
       int dato; // parte de datos
       Persona * persona;  //TODO: CHANGE PRIORITY
       Nodo* siguiente;// puntero para enlazar nodos
       // constructor
       
       Nodo(int d) 
       {
                dato = d; // asigna los datos 
                siguiente = NULL; // sig es null
       }

       //TODO: CHANGE PRIORITY       
       Nodo(Persona * p) 
       {
                dato = p->id; // asigna los datos 
                siguiente = NULL; // sig es null
                persona = p;
       }
      void imprimir();
       
};


struct Pila {
       // solo con pN es suficiente
       Nodo *tope;
       
       Pila()
       {
                    tope = NULL;
       }
       
       // encabezados de funcion
       void push (int dato);
       Nodo* pop (void);
       Nodo* peek(void);
       bool empty(void);
       void imprimir(void);
};

struct Cola {
       // solo con pN es suficiente
       Nodo *frente; // ERROR sin ultimo nodo
       
       Cola()
       {
            frente = NULL;
       }
       
       // encabezados de funcion
       void encolar (int dato);
       Nodo* desencolar (void);
       Nodo* verFrente(void);
       bool vacia(void);
       void imprimir(void);

       void encolarPersona (Persona * p){
       		if (vacia())
		        frente = new Nodo (p);
		    else 
		    {
		            // referencia al primero para recorrer la lista
		            Nodo* actual = frente;
		            // recorre la lista hasta llegar al penultimo nodo
		            while (actual->siguiente != NULL)
		                          actual = actual->siguiente; 
		              
		            // Crea nuevo nodo, lo apunta con uN  
		            Nodo* nuevo = new Nodo (p);
		            //le quita el enlace al que era ultimo
		            actual->siguiente = nuevo;
		    }
	   }
};

struct ColaPrioridad {
       // solo con pN es suficiente
       Cola * colaRegular;
       Cola * colaEspecial;
       
       ColaPrioridad()
       {
            colaRegular = new Cola();
            colaEspecial = new Cola();
       }
       
       // encabezados de funcion
       void encolar (Persona * p){
       		if (p->priority == 1)
       			colaRegular->encolarPersona(p);
       		else
       			colaEspecial->encolarPersona(p);
	   }
       Nodo* desencolar (){
       		if (!colaEspecial->vacia())
       			return colaEspecial->desencolar();
       		else
       			return colaRegular->desencolar();
	   }
	   
	   void imprimir(){
	   	cout <<"Cola prioridad: " << endl;
	   	colaEspecial->imprimir();
	   	cout << endl << endl << "Cola: ";
	   	colaRegular->imprimir();
	   }
};


