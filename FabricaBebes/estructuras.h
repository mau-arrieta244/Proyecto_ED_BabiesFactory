#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <Windows.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <dirent.h>
#include <cstdio>
#include <sstream> //string to stream para getline()

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
struct Hate;
struct NodoHate;
struct ColaHate;
struct FabricaHate;
struct Fabricas;
struct Bebe;
struct NodoBebe;
struct ColaPedidos;
struct ColaMalos;
struct NodoHistorico;
struct ListaPedidosEspeciales;
struct FabricanteAutomatico;

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
       int segundos;
       int capacidad;
       int sentimientosActivos;
       NodoSentimiento *frente; 
       ColaSentimiento(){
           segundos = 0;
           capacidad = 20;
           sentimientosActivos = 0;
           frente = NULL;
       }
       ColaSentimiento(int pSegundos){
           segundos = pSegundos;
           capacidad = 20;
           sentimientosActivos = 0;
           frente = NULL;
       }
       NodoSentimiento* verFrente(void);
       void imprimir(void);
       void encolarSentimiento();
       NodoSentimiento * desencolarSentimiento();
       string generarSentimientoRandom();
};
struct FabricaSentimiento{
       ColaSentimiento * sentimientos;
       FabricaSentimiento(){
              sentimientos = new ColaSentimiento();
       }
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
       int segundos;
       int capacidad;
       int notasActivas;
       NodoNota *frente; 
       ColaNota(){
           segundos = 0;
           capacidad = 20;
           notasActivas = 0;
           frente = NULL;
       }
       ColaNota(int pSegundos){
           segundos = pSegundos;
           capacidad = 20;
           notasActivas = 0;
           frente = NULL;
       }
       NodoNota* verFrente(void);
       void imprimir(void);
       void encolarNota();
       NodoNota * desencolarNota();
       string generarNotaRandom();
};
struct FabricaMusica{
       ColaNota * notas;
       FabricaMusica(){
              notas = new ColaNota();
       }
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
public:
       int segundos;
       int capacidad;
       int hatesActivos;
       NodoHate *frente; 
       ColaHate(){
           segundos = 0;
           capacidad = 20;
           hatesActivos = 0;
           frente = NULL;
       }
       ColaHate(int pSegundos){
           segundos = pSegundos;
           capacidad = 20;
           hatesActivos = 0;
           frente = NULL;
       }
       NodoHate* verFrente(void);
       void imprimir(void);
       string generarHateRandom();
       void encolarHate();
       NodoHate* desencolarHate();
       bool isFinish();
};
struct FabricaHate{
       ColaHate * hates;
       FabricaHate(){
            hates = new ColaHate();
       }
};
struct Fabricas{
    FabricaHate * fabricaHate;
    FabricaMusica * fabricaMusica;
    FabricaSentimiento * fabricaSentimiento;
    Fabricas(){
        fabricaHate = new FabricaHate();
        fabricaMusica = new FabricaMusica();
        fabricaSentimiento = new FabricaSentimiento();
    }
};

struct Bebe{
    string amor;
    string arte;
    string hate;

    string colorPiel;
    bool bebeMalo;
    //constructor default
    Bebe(){
        amor = "";
        arte = "";
        hate = "";
        colorPiel = "";
        bebeMalo = false;
    }
    //constructor cuando se ingresan string papá y mamá
    Bebe(string color){
        amor = "";
        arte = "";
        hate = "";
        bebeMalo = false;
        colorPiel = color;
    }
    //constructor cuando se ingresan tres strings de emociones
    Bebe(string pAmor,string pArte,string pHate){
        amor = pAmor;
        arte = pArte;
        hate = pHate;
        //no siempre va a ser bebe malo = false cuando se ingresen emociones
        //tenemos que validar si las 3 estan en lista, si no estan, es bebeMalo
        bebeMalo = false;
        //podemos usar strings FULL, EMPTY Y HALF como las medidas
        if(pHate == "vacio" && pArte == "llena" && pAmor == "lleno"){
            colorPiel = "Moreno";
        }
        else if(pHate == "lleno" && pArte == "llena" && pAmor == "lleno"){
            colorPiel = "Afrodescendiente";
        }
        else if(pHate == "vacio" && pArte == "vacia" && pAmor == "lleno"){
            colorPiel = "Rubio";
        }
        else if(pHate == "lleno" && pArte == "vacia" && pAmor == "lleno"){
            colorPiel = "Castaño";
        }
        else if(pHate == "vacio" && pArte == "vacia" && pAmor == "vacio"){
            colorPiel = "Pelirrojo";
        }
        else if(pHate == "lleno" && pArte == "vacia" && pAmor == "vacio"){
            colorPiel = "Pink";
        }
        else if(pHate == "vacio" && pArte == "llena" && pAmor == "roto"){
            colorPiel = "BadBunny";
        }
        else if(pHate == "lleno" && pArte == "llena" && pAmor == "roto"){
            colorPiel = "Pitufo";
        }
        else{
            colorPiel = "desconocido";
            bebeMalo = true;
        }
    }
    void imprimirPiel(){
        cout<<"\ncolor de piel: "<<colorPiel<<endl;
        cout<<"\n ------------------------------ \n"<<endl;
    }
};


//Nodos para colaPedidos , los nodos seran bebes que estan a la espera
//de pasar a la cola de produccion

struct NodoBebe {
       int dato; // parte de datos
       Bebe * bebe;  //TODO: CHANGE PRIORITY
       NodoBebe* siguiente;// puntero para enlazar nodos
       // constructor
       NodoBebe(){
            siguiente = NULL; // sig es null
       }
       NodoBebe(Bebe * bebeIngresado){
            siguiente = NULL; // sig es null
            bebe = bebeIngresado;

       }
       //void imprimir();
};

struct ColaPedidos {
    int segundos;
    int capacidad;
    int bebesActivos;
    NodoBebe *frente;
    ColaPedidos(){
        segundos = 0;
        capacidad = 10;
        bebesActivos = 0;
        frente = NULL;
     }
    ColaPedidos(int pSegundos){
        segundos = pSegundos;
        capacidad = 10;
        bebesActivos = 0;
        frente = NULL;
     }
    void encolarBebe(Bebe * b);
    NodoBebe * desencolar();
    bool vacia();
    void imprimir();
    NodoBebe* verFrente();
};
struct ColaMalos{
    int segundos;
    int capacidad;
    int malosActivos;
    NodoBebe *frente; // ERROR sin ultimo nodo
    ColaMalos(){
        segundos = 0;
        capacidad = 10;
        malosActivos = 0;
        frente = NULL;
    }
    ColaMalos(int pSegundos){
        segundos = pSegundos;
        capacidad = 10;
        malosActivos = 0;
        frente = NULL;
    }
    void encolarBebe(Bebe * b);
    NodoBebe * desencolar();
    bool vacia();
    void imprimir();
    NodoBebe* verFrente();
};

//Nodo para lista doble del historico de los pedidos especiales
struct NodoHistorico{
    string tipoMadre;
    string tipoPadre;
    string tipoBebe;

    NodoHistorico * siguiente;
    NodoHistorico * anterior;

    NodoHistorico(){
        tipoMadre = "";
        tipoPadre = "";
        tipoBebe = "";
        siguiente = anterior = NULL;
    }

    NodoHistorico(string mama , string papa, string bebe){
        tipoMadre = mama;
        tipoPadre = papa;
        tipoBebe = bebe;
        siguiente = anterior = NULL;
    }
};

//lista doble para guardar historico de los pedidos especiales
struct ListaPedidosEspeciales{
    NodoHistorico * primerNodo, * ultimoNodo;
    int cantidadBebes=0;

    ListaPedidosEspeciales(){
        primerNodo = ultimoNodo = NULL;
    }
    bool isEmpty();
    void insertar (string infoMama,string infoPapa,string infoHijo);
    void insertarAlFinal(string infoMama,string infoPapa,string infoHijo);
    void imprimir(bool inverted);
    //borrar al inicio: si esta vacia retorna null
    NodoHistorico * borrar();
    NodoHistorico * borrarAlFinal();

};
struct FabricanteAutomatico{
        Fabricas* fabricas;
        int segundos;
        ColaPedidos * colaBebes;
        ColaMalos * colaMalos;
        FabricanteAutomatico(){
            fabricas = new Fabricas();
            segundos = 0;
            colaBebes = new ColaPedidos();
        }
        void crearBebeRandom();
};


