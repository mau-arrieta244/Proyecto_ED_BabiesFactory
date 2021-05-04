//estructura de bebé para proyecto Babies Factory
//Mauricio Arrieta , Gabriel Fallas
//Estructuras de Datos, grupo 3

#include <iostream>
#include <string>
#include<fstream>
#include<dirent.h>
using namespace std;


void imprimirTXT(string nombreArchivo){
    ifstream file(nombreArchivo);
    string contenido;
    string input;
    while(file>>input){
        contenido+=input;
    }
    cout<<contenido<<endl;
}
string checkPathString(string path){
    if(path[path.length()-1] == '/'){
        path = path.substr(0,path.length()-1);
    }
    return path;
}

void listdir(string initStrPath){
    
    struct dirent * dir;
    DIR * dp = opendir(initStrPath.c_str()); 
    
    if(dp){
        while((dir = readdir(dp))!=NULL){
            cout<<dir<<endl;
            string strPath ="";
            if(strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0)continue;
  
            else{
                initStrPath = checkPathString(initStrPath);
                strPath = initStrPath+"/"+dir->d_name;
                //cout<<strPath<<endl;
                cout<<"\n ------ \n"<<endl;
                imprimirTXT(strPath);
                listdir(strPath);
                cout<<"\n ------ \n"<<endl;
            }
        }
        closedir(dp);
    }
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