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
struct NodoSentimiento;
struct ColaSentimiento;
struct FabricaSentimiento;
struct Nota;
struct NodoNota;
struct ColaNota;
struct FabricaMusica;

struct Sentimiento{
       string corazon;
       Sentimiento(string pCorazon){
              corazon = pCorazon;
              
       }
       void imprimir(){
              cout << "Corazon " << corazon << endl;
       }
};
struct NodoSentimiento{
       Sentimiento * sentimiento;  //TODO: CHANGE PRIORITY
       
       NodoSentimiento* siguiente; // puntero para enlazar nodos
       
       NodoSentimiento(){
              sentimiento = NULL;
              siguiente = NULL;
       }
       NodoSentimiento(Sentimiento * inSentimiento){
              sentimiento = inSentimiento; // asigna los datos 
              siguiente = NULL;
       }
       
};
struct ColaSentimiento{
       NodoSentimiento *frente; 
       ColaSentimiento(){
            frente = NULL;
       }
       NodoSentimiento* verFrente(void);
       void imprimir(void);
       void encolarSentimiento(Sentimiento * pSentimiento){
       	if (frente == NULL)
		       frente = new NodoSentimiento(pSentimiento);
		else{
		       // referencia al primero para recorrer la lista
		       NodoSentimiento* actual = frente;
	              // recorre la lista hasta llegar al penultimo nodo
	              while (actual->siguiente != NULL)
		              actual = actual->siguiente; 
		       
	              // Crea nuevo nodo, lo apunta con uN  
	              NodoSentimiento* nuevo = new NodoSentimiento(pSentimiento);
		       //le quita el enlace al que era ultimo
		       actual->siguiente = nuevo;
		}
	}
};
struct FabricaSentimiento{
       int capacidad;
       int sentimientosActivos;
       ColaSentimiento * sentimientos;
       FabricaSentimiento(){
              capacidad = 20;
              sentimientosActivos = 0;
              sentimientos = new ColaSentimiento();
       }
       string generarSentimientoRandom();
       void insertarSentimiento(int, int, FabricaSentimiento *);
       void imprimir();
};
struct Nota{
       string tipoNota;
       Nota(string pNota){
              tipoNota = pNota;
       }
       void imprimir(){
              cout << "Nota" << tipoNota << endl;
       }
};
struct NodoNota{
       Nota * nota; 
       NodoNota* siguiente;  
       NodoNota(){
              nota = NULL;
              siguiente = NULL;
       }
       NodoNota(Nota * inNota){
              nota = inNota;
              siguiente = NULL;
       }  
};
struct ColaNota{
       NodoNota *frente; 
       ColaNota(){
            frente = NULL;
       }
       NodoNota* verFrente(void);
       void imprimir(void);
       void encolarNota(Nota*);
};
struct FabricaMusica{
       int capacidad;
       int notasActivas;
       ColaNota * notas;
       FabricaMusica(){
              capacidad = 20;
              notasActivas = 0;
              notas = new ColaNota();
       }
       string generarNotaRandom();
       void insertarNota(int, int, FabricaMusica *);
       void imprimir();
};

struct Hate{
       string tipoHate;
       Hate(string pHate){
              tipoHate = pHate;
       }
};
struct NodoHate{
       Hate * hate; 
       NodoHate* siguiente;  
       NodoHate(){
              hate = NULL;
              siguiente = NULL;
       }
       NodoHate(Hate * inHate){
              hate = inHate;
              siguiente = NULL;
       }  
};
struct ColaHate{
       NodoHate *frente; 
       ColaHate(){
            frente = NULL;
       }
       NodoHate* verFrente(void);
       void imprimir(void);
       void encolarHate(Hate*);
};
struct FabricaHate{
       int capacidad;
       int hatesActivos;
       ColaHate * hates;
       FabricaHate(){
              capacidad = 20;
              hatesActivos = 0;
              hates = new ColaHate();
       }
       string generarHateRandom();
       void insertarHate(int, int, FabricaHate *);
       void imprimir();
};

