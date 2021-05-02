//estructura de bebé para proyecto Babies Factory
//Mauricio Arrieta , Gabriel Fallas
//Estructuras de Datos, grupo 3

#include <iostream>
#include <string>
using namespace std;

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
    Bebe(string colorMama,string colorPapa){
        amor = "";
        arte = "";
        hate = "";
        bebeMalo = false;
        if(colorMama == "Moreno"&colorPapa == "Moreno"){
            colorPiel = "Moreno";
        }
        else{
            colorPiel = "Default";
        }
            
        
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
        cout<<"\n ------------------------------ \n"<<endl;
        cout<<"\ncolor de piel: "<<colorPiel<<endl;
    }

};