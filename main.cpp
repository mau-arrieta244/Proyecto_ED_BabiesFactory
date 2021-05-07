#include "bebes.cpp"


int main(int argc,char*argv[]){
    ColaPedidos * c1 = new ColaPedidos ();
    ListaPedidosEspeciales * l1 = new ListaPedidosEspeciales();

    listdir("C:\\Users\\mauar\\Desktop\\CODE\\Proyecto_ED_BabiesFactory\\pedidosEspeciales",c1,l1);
    //l1->imprimir(false);
    cout<<"\ncant bebes: "<<l1->cantidadBebes<<endl;
   

}