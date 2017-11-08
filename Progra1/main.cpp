/*ESTRUCTURA DE DATOS
      CLASE 1
    LISTA SIMPLE  */

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Nodo{
    int datoEntero;
    Nodo *sigDir;
};

typedef struct Nodo *ListaSimple;

/*free()--> para calloc y realloc
  delete()-->para new */

char *ingreso(char *msg);
void imprimirNodo(ListaSimple *);
void insertarDatoNodo(ListaSimple *,int dato);
int ingresodato(char *msg);

char *ingreso(char *msg){
    char dato[]="123";
    printf("%s",msg);
    gets(dato);
    //puts(dato);
    return dato;
}

int ingresodato(char *msg){
    char dato[]="123";
    int valor;
    printf("%s",msg);
    gets(dato);
    valor=atoi(dato);
    return valor;
}

void insertarDatoNodo(ListaSimple &lista,int dato){
    /*Creo un nodo auxiliar que tenga el dato a ingresar */
    ListaSimple aux= new Nodo();
    if(lista==NULL){
        aux->datoEntero=dato;
        aux->sigDir=NULL;
    }else{
        aux->datoEntero=dato;
        aux->sigDir=lista;
    }
    lista = aux;
    /*Nodo* auxiliar = new Nodo();
    auxiliar->datoEntero=dato;
    if(primero==NULL){
        auxiliar->sigDir=lista;
        lista=auxiliar;
        /*primero=auxiliar;
        primero->sigDir=NULL;
        ultimo=auxiliar;
    }else{

        /*ultimo->sigDir=auxiliar;
        auxiliar->sigDir=NULL;
        ultimo=auxiliar;
    }*/
}

void imprimirNodo(ListaSimple &lista){
    ListaSimple aux= new Nodo();
    aux=lista;
    while(aux!= NULL){
        printf("%d ->",aux->datoEntero);
        aux=aux->sigDir;

    }
    /*ListaSimple actual;
    actual = primero;
    if(primero!=NULL){
        while(actual!=NULL){
            printf("%d\t",*actual);
            actual = actual->sigDir;
        }
    }else{
        printf("\n\tNo hay datos en la cola\n");
    }*/
}

using namespace std;

int main()
{
    ListaSimple *lista;
    int valor;
    lista=NULL;
    //valor=atoi(ingreso("\nIngrese valor entero:\t"));

    /*
        DEBER :      4    5   7   9   0   3   2
        CREAR UNA FUNCIONE QUE INGRESE UNA POSICION Y RETORNE EL DATO QUE ESTA EN ESA POSICION
        Prohibido usar vectores

    */

    lISTAsIMPLE lista;
    LISTA=NULL;

    valor=ingresodato("\nIngrese valor entero:\t");
    insertarDatoNodo(lista,valor);
    valor=ingresodato("\nIngrese valor entero:\t");
    insertarDatoNodo(lista,valor);
    valor=ingresodato("\nIngrese valor entero:\t");
    insertarDatoNodo(lista,valor);
    valor=ingresodato("\nIngrese valor entero:\t");
    insertarDatoNodo(lista,valor);
    insertarDatoNodo(lista,12);
    imprimirNodo(lista);
    return 0;
}
