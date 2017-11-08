#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
//#include "Caja.h"
#include <windows.h>
using namespace std;

struct Nodo{
    int datoEntero;
    struct Nodo *siguienteDir;
};
typedef struct Nodo *ListaSimple;

//Declaración de Funciones
//void menuTeclas();
int menuTeclas();
int ingresar(char mensaje[20]);
void insertarNodo(ListaSimple *,int);
void eliminarNodo(ListaSimple *);
//void modificarNodo(ListaSimple *,int );
void listar(ListaSimple *);
void guardarLista(ListaSimple *,FILE *);
void menu(int opc);


int main(){
    ListaSimple lista;
    lista=NULL;
    FILE *archivo;
    int opc;
    do{
        opc=menuTeclas();
        printf("%d",opc);
        menu(opc);
    }while(opc!=6);

	return 0 ;
}

void menu(int opc){
    switch(opc){
case 1:
    printf("caso 1");
    break;
case 2:
    printf("caso 2");
    break;
case 3:
    printf("caso 3");
    break;
case 4:
    printf("caso 4");
    break;
case 5:
    printf("caso 5");
    break;
case 6:
    exit(1);
    break;

    }


}

void backgroundcolor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void insertarNodo(ListaSimple &Nuevo, int datoInt){
    ListaSimple aux=new Nodo();
	if(Nuevo==NULL){
		aux->datoEntero = datoInt;
		aux->siguienteDir=NULL;

	}else{
		aux->datoEntero = datoInt;
		aux->siguienteDir =Nuevo;
	}
	Nuevo=aux;
}

void guardarLista(ListaSimple &Lista,FILE *archivo){
    ListaSimple aux = new Nodo();
    aux=Lista;
    int i=0;
    archivo=fopen("ListaSimple.txt","a");
    if(archivo!=NULL){
            do{
               fprintf(archivo,"%d-->",aux->datoEntero);
               fprintf(archivo,"\n");
               aux=aux->siguienteDir;
            }while(aux!=NULL);
            fclose(archivo);
    }else{
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
}

int ingresar(char mensaje[20]){
    int dato;
    printf(mensaje);
    scanf("%d",&dato);
    return dato;
}

void menuTeclas() {
	system("color F0");
	system("cls");
	string menu[] = { "\tInsertar Dato","\tEliminar Dato","\tModificar Datos","\tImprimir Lista","\tGuardar Lista","\tSalir" };
	int cursor = 0;
	char tecla;
	for (;;){
		system("cls");
		backgroundcolor(240);
		printf("\n\t\t      MENU\n");
		printf("\n\t    OPCIONES LISTAS SIMPLES \n\n");
		//cout << "                         MENU (LISTAS ENLAZADAS SIMPLES)" << endl;
		for (int i = 0; i < 6; i++){
			if (cursor == i){
                backgroundcolor(160);
				cout << menu[i] << endl;
                backgroundcolor(240);
			}
			else{
                backgroundcolor(240);
				cout << menu[i] << endl;
			}
		}
		for (;;){
			tecla = _getch();
			if (tecla == 80){
				cursor++;
				if (cursor == 6)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72){
				cursor--;
				if (cursor == -1)
				{
					cursor = 5;
				}
				break;
			}
			if (tecla == 13){
            /*Dependiendo de donde el cursor de enter entra en el switch*/
				switch (cursor){
				case 0:
					system("cls");
                    printf("\n\t\tInsertar dato");
                    system("cls");
					ingresar("INGRESE NUMERO");
					insertarNodo(lista);
					//leerDatoLista();
					menuTeclas();
					break;
				case 1:
					system("cls");
					printf("Ar");
					//buscarDatoLista();
					menuTeclas();
					break;
				case 2:
					system("cls");
					printf("asdfa");
					//verDatoLista();
					menuTeclas();
					break;
				case 3:
					system("cls");
					//ShellExecute(NULL, TEXT("open"), TEXT("C:\\Program Files (x86)\\P&C\\Listas SimplesP\\Ayuda Listas SimplesP.chm"), NULL, NULL, SW_SHOWNORMAL);
					menuTeclas();
					break;
				case 4:
					//cout << endl << "Programa realizado por: Luis Cuascota / Daniel Pallo" << endl;
					//cout << "         <<<<<<CopyLeft P&C (licencia de codigo abierto)>>>>>>" << endl;
					//pausas();
					menuTeclas();
					break;
				case 5:
					//cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
					exit(1);
					break;
				}
				break;
			}
		}
	}
}


int menuTeclas() {
	system("color F0");
	system("cls");
	string menu[] = { "\tInsertar Dato","\tEliminar Dato","\tModificar Datos","\tImprimir Lista","\tGuardar Lista","\tSalir" };
	int cursor = 0;
	char tecla;
	for (;;){
		system("cls");
		backgroundcolor(240);
		printf("\n\t\t      MENU\n");
		printf("\n\t    OPCIONES LISTAS SIMPLES \n\n");
		//cout << "                         MENU (LISTAS ENLAZADAS SIMPLES)" << endl;
		for (int i = 0; i < 6; i++){
			if (cursor == i){
                backgroundcolor(160);
				cout << menu[i] << endl;
                backgroundcolor(240);
			}
			else{
                backgroundcolor(240);
				cout << menu[i] << endl;
			}
		}
		for (;;){
			tecla = _getch();
			if (tecla == 80){
				cursor++;
				if (cursor == 6)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72){
				cursor--;
				if (cursor == -1)
				{
					cursor = 5;
				}
				break;
			}
			if (tecla == 13){
            /*Dependiendo de donde el cursor de enter entra en el switch*/
				switch (cursor){
				case 1:
				    return 1;
					/*system("cls");
                    printf("\n\t\tInsertar dato");
                    system("cls");
					ingresar("INGRESE NUMERO");
					insertarNodo(lista);
					leerDatoLista();
					menuTeclas();*/
					break;
				case 2:
				    return 2;
					/*system("cls");
					printf("Ar");
					buscarDatoLista();
					menuTeclas();*/
					break;
				case 3:
				    return 3:
					system("cls");
					/*printf("asdfa");
					verDatoLista();
					menuTeclas();*/
					break;
				case 4:
				    return 4;
					//system("cls");
					//ShellExecute(NULL, TEXT("open"), TEXT("C:\\Program Files (x86)\\P&C\\Listas SimplesP\\Ayuda Listas SimplesP.chm"), NULL, NULL, SW_SHOWNORMAL);
					//menuTeclas();
					break;
				case 5:
				    return 5;
					//cout << endl << "Programa realizado por: Luis Cuascota / Daniel Pallo" << endl;
					//cout << "         <<<<<<CopyLeft P&C (licencia de codigo abierto)>>>>>>" << endl;
					//pausas();
					//menuTeclas();
					break;
				case 6:
					return 6;//cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
					//exit(1);
					break;
				}
				break;
			}
		}
	}
}
