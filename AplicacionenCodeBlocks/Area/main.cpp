#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;

int main()
{

    system("color 6b");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("||                                       Universidad de las Fuerzas Armadas ESPE                                    ||\n");
    printf("||                                                                                                                  ||\n");
    printf("||  Integrantes: Carvajal, A                                                                         ||\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    int opc;
    double  cuadradoa,cuadradop,base,altura,rectanguloa,rectangulop,lado,trapecioa,baset,baset2,alturat,lado1,trapeciop,romboidea,romboidep,diagonalma,diagonalme,romboa,rombop,lador,baserom,alturarom,lado2;

    printf("                                      AREAS Y PERIMETROS DE LOS SIGUIENTES CUADRILATEROS\n");
    printf("     1 Rectangulo   \n");
    printf("        |--------|      \n");
    printf("        |--------|      \n\n");
    printf("     2 Cuadrado         \n");
    printf("        |--|      \n");
    printf("        |--|      \n\n");
    printf("     3 Trapecio\n");
    printf("         .`--`.      \n");
    printf("       .`______`.      \n\n");
    printf("     4 Romboide\n");
    printf("         /------/      \n");
    printf("        /______/     \n\n");
    printf("     5 Rombo               \n");
    printf("      /`.        \n");
    printf("      `./     \n\n");
    printf("Ingrese la opcion deseada\n");
    scanf("%d",&opc);
    switch (opc)
     {
    case 1:
        printf("Rectangulo:\n",opc);
        if (opc==1)
            {
                printf("Ingrese la base del rectangulo\n");
                scanf("%lf",&base);
                while(base<=0){
                    printf("Ingrese la base del rectangulo\n");
                    scanf("%lf",&base);
                }
                printf("Ingrese la altura del rectangulo\n");
                scanf("%lf",&altura);
                while(altura<=0){
                    printf("Ingrese la altura del rectangulo\n");
                    scanf("%lf",&altura);
                }
                rectanguloa=base*altura;
                printf("El area es :%lf\n",rectanguloa);
                rectangulop=base+altura+base+altura;
                printf("El perimetro es :%lf\n",rectangulop);


            }
    break;
    case 2:
        printf("Cuadrado:\n",opc);
         if (opc==2)
            {

                printf("Ingrese el lado del cuadrado\n ");
                scanf("%lf",&lado);
                while(lado<=0){
                    printf("Ingrese el lado del cuadrado\n");
                    scanf("%lf",&lado);
                }
                cuadradoa=lado*lado;
                printf("El area es :%lf\n",cuadradoa );
                cuadradop=lado+lado+lado+lado;
                printf("El perimetro es :%lf       \n",cuadradop);
            }
    break;
    case 3:
        printf(" Trapecio \n",opc);
         if (opc==3)
            {
                printf("Ingrese la base 1 del trapecio\n ");
                scanf("%lf",&baset);
                printf("Ingrese la base 2 del trapecio\n ");
                scanf("%lf",&baset2 );
                printf("Ingrese la altura del trapecio\n ");
                scanf("%lf",&alturat);
                printf("Ingrese  lado1 \n ");
                scanf("%lf",&lado1  );
                printf("Ingrese lado2 trapecio\n ");
                scanf("%lf",&lado2 );
                trapecioa=(baset+baset2)*alturat/2;
                printf("El area es :%lf\n",trapecioa );
                trapeciop=baset+baset2+lado1+lado2;
                printf("El perimetro es :%lf   \n", trapeciop);

            }
        break;
    case 4:
        printf("Romboide\n",opc);
         if (opc==4)
                {

               printf("Ingrese la base del romboide \n");
                scanf("%lf",&baserom);
                printf("Ingrese la altura del romboide \n");
                scanf("%lf",&alturarom);
                romboidea =baserom*alturarom;
                printf("El area es :%lf\n",    romboidea    );
                romboidep=baserom+alturarom+baserom+alturarom;
                printf("El perimetro es :%lf\n",romboidep);

                }
        break;
    case 5:
        printf("Rombo\n",opc);
         if (opc==5)
                {
                printf("Ingrese la diagonal mayor del rombo\n ");
                scanf("%lf",&diagonalma           );
                printf("Ingrese la diagonal menor del rombo\n ");
                scanf("%lf",&diagonalme          );
                printf("Ingrese el lado del rombo\n ");
                scanf("%lf",&lador   );
                romboa=diagonalma*diagonalme/2;
                printf("El area es :%lf\n",romboa  );
                rombop=lador+lador+lador+lador;
                printf("El perimetro es :%lf\n",rombop);

                }

    break;
    default:
        printf("La opcion ingresada %d no es valido",opc);

 return 0;

     }
}
