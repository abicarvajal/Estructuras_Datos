/* encabezado*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
/*declaración de estructura*/
struct Nodo{
	int datoEntero;
	struct Nodo *siguinteDir;
};
typedef struct Nodo *ListaSimple;
/*Declaracion de prototipos*/
char *ingresar(char *);
void insertarDato(ListaSimple *,int);
void imprimirDatos(ListaSimple *);
/*desarrollo de prototipos*/
/*char *ingresar(char *msg){
	char dato[5];
	char c;
	int i=0;
	printf("%s",msg);
	while((c=getch())!=13){
		if(c>='0'&&c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
		dato[i]='\0';
	}
	return dato;
}*/


void imprimirEncabezado(){
    printf("\t UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n");
    printf("                ESTRUCTURA DE DATOS\n");
    printf("            Abigail Carvajal\t NRC:2856\n");

}
void buscarDato(ListaSimple Lista,int posicionDato){
    int auxiliar=0,dato;
    while(Lista!=NULL){
        if(auxiliar==posicionDato){
            dato=Lista->datoEntero;
            printf("\nEl dato es: %d",dato);
        }
        Lista=Lista->siguinteDir;
        auxiliar++;
    }
}
int ingresar(){
    int dato;
    printf("\nIngrese el valor entero =\t");
    scanf("%d",&dato);
    return dato;
}
void insertarDato(ListaSimple &Nuevo,int datoInt)
{
	ListaSimple aux=new Nodo();
	if(Nuevo==NULL){
		aux->datoEntero = datoInt;
		aux->siguinteDir=NULL;

	}else{
		aux->datoEntero = datoInt;
		aux->siguinteDir =Nuevo;
	}
	Nuevo=aux;
}

void imprimirDatos(ListaSimple &lista)
{
	ListaSimple aux=new Nodo();
	aux = lista;
	while(aux != NULL)
	{
		printf("%d -> ",aux->datoEntero);
		aux = aux->siguinteDir;
	}
}

int main(int argc, char** argv) {
	ListaSimple lista;
	lista=NULL;
	int datoEntero;
	int opc,posicion,contador=0;

	do{

        system("cls");
        imprimirEncabezado();
		datoEntero=ingresar();
		printf("\nValor ingresado es : %d",datoEntero);
		insertarDato(lista,datoEntero);
		printf("Desea ingresar otro valor\n1 Para si \n0 Para no\n");
		scanf("%d",&opc);
		contador++;
	}while(opc!=0);
	imprimirDatos(lista);
	printf("\nIngrese la posicion de la cual desea el dato:\t");
	scanf("%d",&posicion);
	posicion-=1;

	if(posicion>contador){
        printf("\nNO HAY DATO EN ESA POSICION\n");
	}else{
        buscarDato(lista,posicion);
	}

	return 0;
}


