//estructura de bebé para proyecto Babies Factory
//Mauricio Arrieta , Gabriel Fallas
//Estructuras de Datos, grupo 3

#include <iostream>
#include <string>
#include<fstream>
#include<dirent.h>
#include<cstdio>

#include<stdlib.h> // para los randoms de probabilidades
#include<time.h>

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

    cout<<"tipo padre: "<<tipoPadre<<endl;
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

    cout<<"longitud: "<<tipoPadre.length()<<endl;
    return tipoPadre.length();
}

string colorMama(string nombreArchivo,int longitudPadre){
    ifstream file(nombreArchivo);
    string contenido;
    string input;
    while(file>>input){
        contenido+=input;
    }
    string tipoMadre = contenido.substr(longitudPadre+1);
    cout<<"tipo madre: "<<tipoMadre<<endl;
    return tipoMadre;
    
}

string checkPathString(string path){
    if(path[path.length()-1] == '/'){
        path = path.substr(0,path.length()-1);
    }
    return path;
}

struct Padres{ // será lo que contiene cada "casilla" en la matriz para creacion por pedido especial
    string tipoPadre;
    string tipoMadre;
    Padres(){
        tipoPadre = "";
        tipoMadre = "";
    }
    Padres(string colorPadre , string colorMadre){
        tipoPadre = colorPadre;
        tipoMadre = colorMadre;
    }
    string probabilidadHijo(){
        srand(time(nullptr));
        int aleatorio = rand() %100+1;
        //cout<<"random : "<<aleatorio<<endl;

        //hay 64 combinaciones... muchos ifs, elifs!

        //preguntarle bien al profe de manera de escribir castano , BadBunny, etc..

        // columna 1 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////
        if(tipoPadre == "Moreno" & tipoMadre == "Morena"){
            return "Moreno";
        }

        else if(tipoPadre == "Afro" & tipoMadre == "Morena"){
            if(aleatorio<=70){
                return "Afro";
            }
            else{
                return "Moreno";
            }
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "Morena"){
            if(aleatorio<=90){
                return "Moreno";
            }
            else{
                return "Rubio";
            }
        }

        else if(tipoPadre == "Castano" & tipoMadre == "Morena"){
            if(aleatorio<=50){
                return "Castano";
            }
            else{
                return "Moreno";
            }
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "Morena"){
            if(aleatorio<=10){
                return "Pelirrojo";
            }
            else{
                return "Moreno";
            }
        }

        else if(tipoPadre == "Pink" & tipoMadre == "Morena"){
            return "Moreno";
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "Morena"){
            if(aleatorio<=10){
                return "BadBunny";
            }
            else{
                return "Moreno";
            }
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "Morena"){
            if(aleatorio<=10){
                return "Pitufo";
            }
            else{
                return "Moreno";
            }
        }

        // columna 2 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////

        else if(tipoPadre == "Moreno" & tipoMadre == "Afro"){
            if(aleatorio<=30){
                return "Moreno";
            }
            else{
                return "Afro";
            }
        }

        else if(tipoPadre == "Afro" & tipoMadre == "Afro"){
            return "Afro";
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "Afro"){
            return "Afro";
        }

        else if(tipoPadre == "Castano" & tipoMadre == "Afro"){
            return "Afro";
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "Afro"){
            return "Afro";
        }

        else if(tipoPadre == "Pink" & tipoMadre == "Afro"){
            return "Afro";
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "Afro"){
            return "Afro";
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "Afro"){
            return "Afro";
        }

        // columna 3 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////
        else if(tipoPadre == "Moreno" & tipoMadre == "Rubia"){
            if(aleatorio<=70){
                return "Moreno";
            }
            else{
                return "Rubia";
            }
        }

        else if(tipoPadre == "Afro" & tipoMadre == "Rubia"){
            if(aleatorio<=90){
                return "Afro";
            }
            else{
                return "Rubia";
            }
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "Rubia"){
            return "Rubio";
        }

        else if(tipoPadre == "Castano" & tipoMadre == "Rubia"){
            if(aleatorio<=90){
                return "Rubio";
            }
            else{
                return "Castano";
            }
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "Rubia"){
            if(aleatorio<=90){
                return "Rubio";
            }
            else{
                return "Pelirrojo";
            }
        }

        else if(tipoPadre == "Pink" & tipoMadre == "Rubia"){
            return "Rubia";
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "Rubia"){
            return "Rubia";
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "Rubia"){
            return "Rubia";
        }

        // columna 4 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////

        else if(tipoPadre == "Moreno" & tipoMadre == "Castana"){
            if(aleatorio<=50){
                return "Moreno";
            }
            else{
                return "Castano";
            }
        }

        else if(tipoPadre == "Afro" & tipoMadre == "Castana"){
            if(aleatorio<=70){
                return "Afro";
            }
            else{
                return "Castano";
            }
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "Castana"){
            if(aleatorio<=40){
                return "Rubio";
            }
            else{
                return "Castano";
            }
        }

        else if(tipoPadre == "Castano" & tipoMadre == "Castana"){
            return "Castano";
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "Castana"){
            if(aleatorio<=40){
                return "Pelirrojo";
            }
            else{
                return "Castano";
            }
        }

        else if(tipoPadre == "Pink" & tipoMadre == "Castana"){
            if(aleatorio<=30){
                return "Pink";
            }
            else{
                return "Castano";
            }
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "Castana"){
            if(aleatorio<=50){
                return "BadBunny";
            }
            else{
                return "Castano";
            }
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "Castana"){
            if(aleatorio<=30){
                return "Pitufo";
            }
            else{
                return "Castano";
            }
        }

        return "Default / Fallo";

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
    Bebe(string colorMama,string colorPapa){
        amor = "";
        arte = "";
        hate = "";
        bebeMalo = false;
        if(colorMama == "Morena"&colorPapa == "Moreno"){
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

void listdir(string initStrPath){

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
                cout<<"\n ------ \n"<<endl;
                string cP =colorPapa(strPath);
                int lenPadre = longitudPapa(strPath);
                string cM = colorMama(strPath,lenPadre); // recibe len de tipo padre para cortar string a partir de ahi
                //ocurre prblema por crear bebes con mismo identificador en loop?
                Bebe * b1 = new Bebe(cM,cP);
                b1->imprimirPiel();
                listdir(strPath);
                const int result = remove(strPath.c_str());
                cout<<"\n ------ \n"<<endl;
                
            }
        }
        closedir(dp);
    }
    
}