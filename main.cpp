#include "bebes.cpp"

int main(int argc,char*argv[]){
    
    //debe crear bebe "Moreno"
    Bebe * b1 = new Bebe("Moreno","Moreno");
    b1->imprimirPiel();

    //debe crear bebe "Default"
    Bebe * b2 = new Bebe("Moreno","Rubio");
    b2->imprimirPiel();

    //debe crear bebe "Rubio"
    Bebe * b3 = new Bebe("FULL","EMPTY","EMPTY");
    b3->imprimirPiel();

    //debe crear bebe "Default"
    Bebe * b4 = new Bebe("HALF","EMPTY","EMPTY");
    b4->imprimirPiel();

    return 0;
}