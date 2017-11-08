/*
    UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
            ESTRUCTURA DE DATOS
    ABIGAIL CARVAJAL
    OPERACIONES CON LISTAS SIMPLES
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13

COORD coord={0,0}; /*Esta constante setea una coordenada en
                    la parte superior izquierda del
                    programa*/

struct Nodo{
    int datoEntero;
    struct Nodo *siguienteDir;
};
typedef struct Nodo *ListaSimple;

//DECLARACION DE LAS FUNCIONES
int menu();
int ingresar(char mensaje[20]);
void opcionesListaSimple(int opcion,ListaSimple *,boolean verifica,int ,FILE *);
void insertarNodo(ListaSimple *,int);
void eliminarNodo(ListaSimple *);
void modificarNodo(ListaSimple *,int );
void listar(ListaSimple *);
void guardarLista(ListaSimple *,FILE *);
int menu(const char*titulo,const char*opciones[],int n);


using namespace std;

void color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

   ReadConsoleA (ih, &c, 1, &contador, NULL);

   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }

   SetConsoleMode (ih, modo); // Devolvemos control normal

   return c;
}
void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void guardarLista(ListaSimple &Lista,FILE *archivo){
    ListaSimple aux = new Nodo();
    aux=Lista;
    int i=0;
    archivo=fopen("ListaSimple.txt","a");
    if(archivo!=NULL){
            do{
               fprintf(archivo,"%d-->",aux->datoEntero);
               aux=aux->siguienteDir;
            }while(aux!=NULL);
            fclose(archivo);
    }else{
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
}

void eliminarNodo(ListaSimple &Lista){
    ListaSimple auxiliar=new Nodo();
    boolean verifica=false;
    auxiliar = Lista;
     if(auxiliar!=NULL){
        Lista = Lista->siguienteDir;
        delete(auxiliar);
        verifica=true;
     }
     if(verifica==true){
        printf("\n   _________________________________\n");
        printf("        Nodo eliminado con éxito\!\n");
        printf("   _________________________________\n");
        system("pause");
     }


 }

void modificarNodo(ListaSimple &Lista,int contador){
    int numero,reemplazo,verifica=0;
    numero=ingresar("\nIngrese el numero que desea reemplazar:\t");
    reemplazo=ingresar("\nIngrese el reemplazo para ese numero:\t");
    ListaSimple indice = new Nodo();   /*indice apunta a LA LISTA y la recorre con un for*/
    for(indice=Lista;indice!=NULL;indice=indice->siguienteDir){
        if(numero==indice->datoEntero){
            indice->datoEntero=reemplazo;
            verifica++;
        }
    }
    if(verifica==0){
        printf("\n\nEl dato que quiere reemplazar, no se encuentra ingresado en la lista:\n\n");
    }
    else{
        printf("\n\nEl dato %d ha sido reemplazado por %d en la lista:\n\n",numero,reemplazo);
    }
 }

int ingresar(char mensaje[20]){
    int dato;
    printf(mensaje);
    scanf("%d",&dato);
    return dato;
}

void listar(ListaSimple &lista){
    ListaSimple aux=new Nodo();
	aux = lista;
	/*IMPRESION NORMAL -- ULTIMO INGRESADO ES EL QUE SE IMPRIME PRIMERO*/
	while(aux != NULL)
	{
		printf("%d -> ",aux->datoEntero);
		aux = aux->siguienteDir;
	}

	/*IMPRESION -- EL PRIMERO INGRESADO ES EL QUE SE IMPRIME PRIMERO*/
	/*if(aux==NULL){
        return;
	}else{
        listar(aux->siguienteDir);
        printf("%d-->",aux->datoEntero);
	}*/

	printf("\n\n");
	system("pause");
}

void insertarNodo(ListaSimple &Nuevo,int datoInt){
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

void opcionesListaSimple(int opcion,ListaSimple &lista,boolean verifica,int contador,FILE *archivo){
    int dato;
    switch(opcion){
    case 1:
        system("cls");
        printf("\n\t\tINSERTAR NODO");
        dato=ingresar("\n\nIngrese el dato a insertar:\t");
        insertarNodo(lista,dato);
        break;
    case 2:
        if(verifica==false){
            system("cls");
            printf("\n\t\tLISTA VACIA\t\n\tNO HAY ELEMENTOS PARA ELIMINAR DE LA LISTA\n\n");
            system("pause");
        }else{
            system("cls");
            printf("\n\t\tELIMINAR NODO");
            eliminarNodo(lista);
            guardarLista(lista,archivo);
            //contador--;
        }
        break;
    case 3:
        if(verifica==false){
            system("cls");
            printf("\n\t\tLISTA VACIA\!\n\tNO HAY ELEMENTOS POR MODIFICAR\n\n");
            system("pause");
        }
        else{
            system("cls");
            printf("\n\t\tMODIFICAR NODO");
            modificarNodo(lista,contador);
            listar(lista);
        }
        break;
    case 4:
        if(verifica==false){
            system("cls");
            printf("\n\t\tLISTA VACIA\!\n\tNO HAY ELEMENTOS POR IMPRIMIR\n\n");
            system("\n\npause");
        }
        else{
            system("cls");
            printf("\n\t\tELEMENTOS DE LA LISTA SIMPLE\n");
            listar(lista);
        }
        break;
    case 5:
        if(verifica==false){
            system("cls");
            printf("\n\t\tLISTA VACIA\!\n\tNO HAY ELEMENTOS POR GUARDAR\n\n");
            system("\n\npause");

        }else{
            system("cls");
            printf("\n\t\tGUARDAR LISTA SIMPLE");
            guardarLista(lista,archivo);
            printf("\nGuardado con éxito\n");
            system("pause");
        }
        break;
    case 6:
        system("cls");
        printf("\n\n\t\tPROGRAMA FINALIZADO");
        break;
    }


}

int menu(const char*titulo,const char*opciones[],int n)
{
    int opcionSeleccionada=1;
    int tecla;
    bool repite=true;
    //textbackground(1);
    do
    {
        system("cls");
        //imprime titulo
        gotoxy(15,2);printf("%s",titulo);
        //textbackground(2 );
        //color(240);
        color(240);

        gotoxy(10,3+opcionSeleccionada);printf("==>");
        //imprime opciones

        for(int i=0;i<n;i++)
        {
            color( 240 );
            gotoxy(10,4+i); printf("%s",opciones[i]);
            //color(47);
        }
        for(int x=10;x<40;x++)
        {
            gotoxy(x,3+opcionSeleccionada);printf("%c",166);
            color(47);
        }
        color(240);
        do
        {
            tecla=getch();

        }while(tecla!=TECLA_ARRIBA&&tecla!=TECLA_ABAJO&&tecla!=TECLA_ENTER);
    switch(tecla)
    {
        case TECLA_ARRIBA:
            opcionSeleccionada--;
            if(opcionSeleccionada<1)
            {
                opcionSeleccionada=n;
            }
        break;
        case TECLA_ABAJO:
            opcionSeleccionada++;
            if(opcionSeleccionada>n)
            {
                opcionSeleccionada=1;
            }
        break;
        case TECLA_ENTER:
            repite=false;
        break;
    }

    }while(repite);
    return opcionSeleccionada;

}

int menu(){
    int opcion=1,tecla;
    bool repite=true;
    const char *opciones[] ={"Insertar","Eliminar","Modificar","Listar","Guardar","Salir"};
    do{
        system("cls");
        /*color()*/
        printf("\t\t     _______________________________________\n");
        gotoxy(15,2);printf("\t\tOpciones con Listas Simples\n");
        printf("\t\t     _______________________________________\n");

        gotoxy(5,3+opcion);printf("-->");

        for(int i=0;i<6;i++){
            gotoxy(10,4+i);
            printf("%s",opciones[i]);
        }

        do{
            tecla=getch();
        }while(tecla!=72 && tecla!=80 && tecla!=13); //CODIGO ASCCI DE LAS TECLAS
        switch(tecla){
        case 72:

            opcion--;
            if(opcion<1){
                opcion=6;
            }
            break;

        case 80:

            opcion++;
            if(opcion>6){
                opcion = 1;
            }
            break;

        case 13:
            repite=false;
           // opcLista=opcion;
            break;
        }

    }while(repite!=false);

    return(opcion);

}

int main()
{
    int opcion,contador=0;
    ListaSimple lista;
    lista=NULL;
    boolean verifica=false;
    FILE *archivo;
    system("color F0");
    const char *titulo="MENU PRINCIPAL-OPCIONES CON LISTAS SIMPLES";
    const char *opciones[]={"Insertar Dato",
                            "Eliminar Dato",
                            "Modificar Dato",
                            "Listar Datos Ingresados",
                            "Guardar Datos",
                            "Salir"};
    int n=6;//numero de opciones
    do{
        opcion=menu(titulo,opciones,n);
        if(opcion==1){
            verifica=true;
            contador++;
        }
        if(opcion==2&&verifica!=false){
            contador--;
            if(contador==0){
                verifica=false;
                lista=NULL;
            }
        }
        opcionesListaSimple(opcion,lista,verifica,contador,archivo);
    }while(opcion!=6);

    return 0;
}
