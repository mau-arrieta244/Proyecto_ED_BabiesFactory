//estructura de bebé para proyecto Babies Factory
//Mauricio Arrieta , Gabriel Fallas
//Estructuras de Datos, grupo 3


// tambien incluye struct colaPedidos, deberia cambiarle el nombre a estructuras.h 
// cuando unamos todas las estructuras en este.

//para unir las estructuras en uno solo, debemos cambiar nombres de Nodo y Cola a mas especificos


#include <iostream>
#include <string>
#include<fstream>
#include<dirent.h>
#include<cstdio>
#include "padres.cpp"



#include<sstream> //string to stream para getline()

using namespace std;



string colorPapa(string nombreArchivo){
    ifstream file(nombreArchivo);
    string contenido;
    string input;
    while(file>>input){
        contenido+=input;
    }
    stringstream stream(contenido);
    string tipoPadre;
    char separador(';'); // siempre puntos y comas
    getline(stream,tipoPadre,separador);

    //cout<<"\ntipo padre: "<<tipoPadre<<endl;
    return tipoPadre;
    
}

int longitudPapa(string nombreArchivo){
    int len = 0;
    ifstream file(nombreArchivo);
    string contenido;
    string input;
    while(file>>input){
        contenido+=input;
    }
    stringstream stream(contenido);
    string tipoPadre;
    char separador(';'); // siempre puntos y comas
    getline(stream,tipoPadre,separador);

    //cout<<"longitud: "<<tipoPadre.length()<<endl;
    return tipoPadre.length();
}


string colorMama(string nombreArchivo,int longitudPadre){
    ifstream file(nombreArchivo);
    string contenido;
    string input;
    while(file>>input){
        contenido+=input;
    }
    //que pasa si le toca Bad Bunny? lo retorna como "BadBunny" (corta el whitespace)
    string tipoMadre = contenido.substr(longitudPadre+1);
    //cout<<"\ntipo madre: "<<tipoMadre<<endl;
    return tipoMadre;
    
}

string checkPathString(string path){
    if(path[path.length()-1] == '/'){
        path = path.substr(0,path.length()-1);
    }
    return path;
}


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
        if(amor == "FULL"&arte == "EMPTY"&hate == "EMPTY"){
            colorPiel = "Rubio";
        }
        else
            colorPiel = "Default";
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
       
       NodoBebe() 
       { 
            siguiente = NULL; // sig es null
       }

       //TODO: CHANGE PRIORITY       
       NodoBebe(Bebe * bebeIngresado) 
       {
            siguiente = NULL; // sig es null
            bebe = bebeIngresado;
                
       }
      void imprimir();
       
};


struct ColaPedidos {
       // solo con pN es suficiente
       NodoBebe *frente; // ERROR sin ultimo nodo
       
       ColaPedidos()
       {
            frente = NULL;
       }
       

       void encolarBebe (Bebe * b){
       		if (vacia())
		        frente = new NodoBebe (b);
		    else 
		    {
		            // referencia al primero para recorrer la lista
		            NodoBebe* actual = frente;
		            // recorre la lista hasta llegar al penultimo nodo
		            while (actual->siguiente != NULL)
		                          actual = actual->siguiente; 
		              
		            // Crea nuevo nodo, lo apunta con uN  
		            NodoBebe* nuevo = new NodoBebe (b);
		            //le quita el enlace al que era ultimo
		            actual->siguiente = nuevo;
		    }
	   }


       NodoBebe * desencolar()
       {
      // si no hay elementos, no borra nada, retorna null
      if (vacia())
      {
         return NULL;
      }
      else
            {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          NodoBebe* borrado = frente;     
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          frente = frente->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
            }
       }

    bool vacia()
    {
     if (frente == NULL)
        return true;
     else
         return false;
    }

    void imprimir()
    {
     cout << "Frente" << endl;
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     NodoBebe *tmp = frente;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->bebe->colorPiel << "  " << endl;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
    }


    NodoBebe* verFrente()
        {
            return frente;      
        }
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
	
	bool isEmpty(){
		return primerNodo == NULL;
	}
	
	void insertar (string infoMama,string infoPapa,string infoHijo){
		if (isEmpty())
			primerNodo = ultimoNodo = new NodoHistorico(infoMama,infoPapa,infoHijo);
		else{
			primerNodo->anterior = new NodoHistorico(infoMama,infoPapa,infoHijo);
			primerNodo->anterior->siguiente = primerNodo;
			primerNodo = primerNodo->anterior;
		}
        cantidadBebes++;		
	}
	
	void insertarAlFinal(string infoMama,string infoPapa,string infoHijo){
		if (isEmpty())
			primerNodo = ultimoNodo = new NodoHistorico(infoMama,infoPapa,infoHijo);
		else{
			ultimoNodo->siguiente = new NodoHistorico(infoMama,infoPapa,infoHijo);
			ultimoNodo->siguiente->anterior = ultimoNodo;
			ultimoNodo = ultimoNodo->siguiente;
		}
        cantidadBebes++;			
	}
	
	void imprimir(bool inverted){
		if (inverted){
			NodoHistorico * tmp = ultimoNodo;
			while(tmp != NULL){
				cout << tmp->tipoPadre<< " "<<tmp ->tipoMadre<<" "<< tmp->tipoBebe<< " -> ";
				tmp = tmp->anterior;
			}		
		}
		else{
			NodoHistorico * tmp = primerNodo;
			while(tmp != NULL){
				cout << tmp->tipoPadre<< " "<<tmp ->tipoMadre<<" "<< tmp->tipoBebe<< " -> ";
				tmp = tmp->siguiente;
			}
		}
		cout << endl;
	}
	
	//borrar al inicio: si esta vacia retorna null
	NodoHistorico * borrar(){
		NodoHistorico * borrado = primerNodo;
		if (!isEmpty() && primerNodo == ultimoNodo)
			primerNodo = ultimoNodo = NULL;
		else if (!isEmpty()){
			primerNodo = primerNodo->siguiente;
			primerNodo->anterior = borrado->siguiente = NULL;	
		}
		return borrado;
	}
	
	NodoHistorico * borrarAlFinal(){
		NodoHistorico * borrado = ultimoNodo;
		if (!isEmpty() && primerNodo == ultimoNodo)
			primerNodo = ultimoNodo = NULL;
		else if (!isEmpty()){
			ultimoNodo = ultimoNodo->anterior;
			ultimoNodo->siguiente = borrado->anterior = NULL;	
		}
		return borrado;
	}
	
	
	
};




void listdir(string initStrPath,ColaPedidos * cola,ListaPedidosEspeciales * lista){

    struct dirent * dir;
    DIR * dp = opendir(initStrPath.c_str());
     
    
    if(dp){
        while((dir = readdir(dp))!=NULL){
            string strPath ="";
            if(strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0)continue;
  
            else{
                
                initStrPath = checkPathString(initStrPath);
                strPath = initStrPath+"/"+dir->d_name;
                //cout<<strPath<<endl;
                //cout<<"\n ------ \n"<<endl;
                string cP =colorPapa(strPath);
                int lenPadre = longitudPapa(strPath);
                string cM = colorMama(strPath,lenPadre); // recibe len de tipo padre para cortar string a partir de ahi
                //ocurre prblema por crear bebes con mismo identificador en loop?

                Padres * p1 = new Padres(cP,cM);
                string colorHijo = p1->probabilidadHijo();
                Bebe * b1 = new Bebe(colorHijo);
                //cola->encolarBebe(b1);
                //cola->imprimir();

                //NodoHistorico * n1 = new NodoHistorico(cM,cP,colorHijo);
                lista->insertarAlFinal(cM,cP,colorHijo); // crea nuevo nodo y lo mete a la lista
                

                listdir(strPath,cola,lista);
                const int result = remove(strPath.c_str());
                //cout<<"\n ------ \n"<<endl;
                
            }
        }
        closedir(dp);
    }
    
}