#include "bebes.cpp"

int main(int argc,char*argv[]){

    //listdir("C:\\Users\\mauar\\Desktop\\CODE\\Proyecto_ED_BabiesFactory\\pedidosEspeciales");

    /*
    int matriz[4][4];
    for(int i =0;i<=3;i++){
        for(int j = 0 ;j<=3;j++){
            
            matriz[i][j] = 20;
        }
    }
    

    const int matriz[4][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    for(int i =0;i<=3;i++){
        for(int j = 0 ;j<=3;j++){
            cout<<"\n fila no: "<<i<<endl;
            cout<<"columna no: "<<j<<endl;
            cout<<matriz[i][j]<<endl;
            cout<<"\n ------- \n"<<endl;
        }
    }
    return 0;
    */
   Padres * p1 = new Padres("Castano","Morena");
   cout<<"Hijo: "<<p1->probabilidadHijo()<<endl;
   

}