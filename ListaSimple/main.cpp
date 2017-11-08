#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo{
    int dato;
    struct Nodo *siguiente;
}*first,*last;

//declaro la función
void insertar(struct Nodo *);
void desplegarConPuntero(struct Nodo *);
void desplegar();


/*
aux->datoEntero=dato;
aux->siguiente=lista;
lista=aux;

*/
int main()
{
    cout << "Hello world!" << endl;
    struct Nodo *Lista= new Nodo();
    insertar(Lista);
    insertar(Lista);
    insertar(Lista);

    desplegar();
    return 0;
}

void insertar(Nodo *Lista){
    Nodo* nuevo = new Nodo();
    printf("Ingrese el dato:");
    scanf("%d",nuevo); // no se pone & por que es tipo puntero
    //scanf("%d",Lista);
    //Condicion
    if(first==NULL){
        first = nuevo;
        first->siguiente = NULL;
        last = nuevo;
    }else{
        last->siguiente = nuevo;
        nuevo->siguiente = NULL;
        last = nuevo;
    }
    printf("\nNodo ingresado\n");

    /*if(first==NULL){
        first = Lista;
        first->siguiente = NULL;
        last = Lista;
    }else{
        last->siguiente = Lista;
        Lista->siguiente = NULL;
        last = Lista;
    }*/
}

void desplegarConPuntero(Nodo *Lista){
    printf("\n\n\tLista\n");
    Lista = first;
    if(first!=NULL){
        while(Lista != NULL){
                printf("%d\t",*Lista);
                Lista= Lista -> siguiente;
        }
    }else{
        printf("\nLa lista esta vacia\n");
    }
}

void desplegar(){
    printf("\n\tLista\n");
    Nodo* actual = new Nodo();
    actual = first;
    if(first!=NULL){
        while(actual != NULL){
                printf("%d\t",*actual);
                actual= actual -> siguiente;
        }
    }else{
        printf("\nLa lista esta vacia\n");
    }
}
