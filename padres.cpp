
//estructura de Padres para proyecto Babies Factory
//Mauricio Arrieta ,Gabriel Fallas
//Estructuras de Datos, grupo 3


#include<stdlib.h> // para los randoms de probabilidades
#include<time.h>
#include <iostream>
#include <string>
using namespace std;

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

        // columna 5 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////

        else if(tipoPadre == "Moreno" & tipoMadre == "Pelirroja"){
            if(aleatorio<=65){
                return "Moreno";
            }
            else{
                return "Pelirrojo";
            }
        }

        else if(tipoPadre == "Afro" & tipoMadre == "Pelirroja"){
            if(aleatorio<=85){
                return "Afro";
            }
            else{
                return "Pelirrojo";
            }
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "Pelirroja"){
            if(aleatorio<=40){
                return "Rubio";
            }
            else{
                return "Pelirrojo";
            }
        }

        else if(tipoPadre == "Castano" & tipoMadre == "Pelirroja"){
            if(aleatorio<=40){
                return "Castano";
            }
            else{
                return "Pelirrojo";
            }
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "Pelirroja"){
            return "Pelirrojo";
        }

        else if(tipoPadre == "Pink" & tipoMadre == "Pelirroja"){
            if(aleatorio<=25){
                return "Pink";
            }
            else{
                return "Pelirrojo";
            }
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "Pelirroja"){
            if(aleatorio<=40){
                return "BadBunny";
            }
            else{
                return "Pelirrojo";
            }
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "Pelirroja"){
            if(aleatorio<=30){
                return "Pitufo";
            }
            else{
                return "Pelirrojo";
            }
        }


        // columna 6 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////

        else if(tipoPadre == "Moreno" & tipoMadre == "Pink"){
            if(aleatorio<=90){
                return "Moreno";
            }
            else{
                return "Pink";
            }
        }

        else if(tipoPadre == "Afro" & tipoMadre == "Pink"){
            if(aleatorio<=100){
                return "Afro";
            }
            else{
                return "Pink";
            }
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "Pink"){
            if(aleatorio<=70){
                return "Rubio";
            }
            else{
                return "Pink";
            }
        }

        else if(tipoPadre == "Castano" & tipoMadre == "Pink"){
            if(aleatorio<=40){
                return "Castano";
            }
            else{
                return "Pink";
            }
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "Pink"){
            if(aleatorio<=65){
                return "Pelirrojo";
            }
            else{
                return "Pink";
            }
        }

        else if(tipoPadre == "Pink" & tipoMadre == "Pink"){
            return "Pink";
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "Pink"){
            if(aleatorio<=40){
                return "BadBunny";
            }
            else{
                return "Pink";
            }
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "Pink"){
            if(aleatorio<=45){
                return "Pitufo";
            }
            else{
                return "Pink";
            }
        }


        // columna 7 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////

        else if(tipoPadre == "Moreno" & tipoMadre == "BadBunny"){
            if(aleatorio<=70){
                return "Moreno";
            }
            else{
                return "BadBunny";
            }
        }

        else if(tipoPadre == "Afro" & tipoMadre == "BadBunny"){
            if(aleatorio<=70){
                return "Afro";
            }
            else{
                return "BadBunny";
            }
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "BadBunny"){
            if(aleatorio<=45){
                return "Rubio";
            }
            else{
                return "BadBunny";
            }
        }

        else if(tipoPadre == "Castano" & tipoMadre == "BadBunny"){
            if(aleatorio<=55){
                return "Castano";
            }
            else{
                return "BadBunny";
            }
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "BadBunny"){
            if(aleatorio<=70){
                return "Pelirrojo";
            }
            else{
                return "BadBunny";
            }
        }

        else if(tipoPadre == "Pink" & tipoMadre == "BadBunny"){
            if(aleatorio<=50){
                return "Pink";
            }
            else{
                return "BadBunny";
            }
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "BadBunny"){
            return "BadBunny";
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "BadBunny"){
            if(aleatorio<=50){
                return "Pitufo";
            }
            else{
                return "BadBunny";
            }
        }


        // columna 8 /////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////

        else if(tipoPadre == "Moreno" & tipoMadre == "Pitufa"){
            if(aleatorio<=15){
                return "Moreno";
            }
            else{
                return "Pitufa";
            }
        }

        else if(tipoPadre == "Afro" & tipoMadre == "Pitufa"){
            if(aleatorio<=50){
                return "Afro";
            }
            else{
                return "Pitufa";
            }
        }

        else if(tipoPadre == "Rubio" & tipoMadre == "Pitufa"){
            if(aleatorio<=15){
                return "Rubio";
            }
            else{
                return "Pitufa";
            }
        }

        else if(tipoPadre == "Castano" & tipoMadre == "Pitufa"){
            if(aleatorio<=20){
                return "Castano";
            }
            else{
                return "Pitufa";
            }
        }

        else if(tipoPadre == "Pelirrojo" & tipoMadre == "Pitufa"){
            if(aleatorio<=40){
                return "Pelirrojo";
            }
            else{
                return "Pitufa";
            }
        }

        else if(tipoPadre == "Pink" & tipoMadre == "Pitufa"){
            if(aleatorio<=50){
                return "Pink";
            }
            else{
                return "Pitufa";
            }
        }

        else if(tipoPadre == "BadBunny" & tipoMadre == "Pitufa"){
            if(aleatorio<=50){
                return "BadBunny";
            }
            else{
                return "Pitufa";
            }
        }

        else if(tipoPadre == "Pitufo" & tipoMadre == "Pitufa"){
            return "Pitufo";
        }


        return "Default / Fallo";

    }

};