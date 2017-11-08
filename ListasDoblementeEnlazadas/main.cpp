#include <iostream>
#include <stdio.h>

struct Nodo{
    int datoEntero;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

//typedef struct Nodo *ListaSimple;
typedef struct Nodo *tLista; // tLista ->t porque es de tabla
//<T > CLASE GENERICA/template

/*Prototipo de funciones*/
tlista crear();

using namespace std;

int main()
{
    /*ListaSimple proceso(ListaSimple );*/




    return 0;
}
/*Desarrollo de funciones*/
tlista crear(){
    tlista lista = new Nodo();
    if(lista==NULL){
        printf("\nMemoria insuficiente\n");
        //lista->siguiente=lista->anterior=NULL;
    }


}
