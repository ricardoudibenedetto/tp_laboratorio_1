#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    int opcion=0, aux, resultadoInt=1;
    float a=0 , b=0;
    double resultado;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%.2f)\n", a);
        printf("2- Ingresar 2do operando (B=%.2f)\n",b);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("ingrese un numero :");
                scanf("%f", &a);
                while(a>9999999)
                    {
                        printf("la operacion que intenta realizar es demaciado grande\npor favor ingrese un numero mas chico\n\ningrese un numero : ");
                        scanf("%f", &a);
                    }
                break;
            case 2:
                printf("ingrese un numero :");
                scanf("%f", &b);
                while(b>9999999)
                    {
                        printf("la operacion que intenta realizar es demaciado grande\npor favor ingrese un numero mas chico\n\ningrese un numero : ");
                        scanf("%f", &b);
                    }
                break;
            case 3:
                resultado=suma(a , b);
                printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\tSUMA\t\t\t\t\t*\n\t\t\t%.2f+%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*\n\n\t\t*************************************************\n\n", a,b,resultado);
                system("pause");
                break;
            case 4:
                resultado=resta(a , b);
                printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\tRESTA\t\t\t\t\t*\n\t\t\t%.2f-%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*\n\n\t\t*************************************************\n\n", a,b,resultado);
                system("pause");
                break;
            case 5:
                if(b==0)
                    {
                        printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\t\t\t\t\t\t*\n\t\t\tError en la division\n\t\t*\t no es posible realizar esa operacion\t*\n\n\t\t*************************************************\n\n");
                        system("pause");
                        break;
                    }
                else
                    {
                        resultado=division(a,b);

                    }
                printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\tDIVISION\t\t\t\t*\n\t\t\t%.2f/%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*\n\n\t\t*************************************************\n\n", a,b,resultado);
                system("pause");
                break;
            case 6:
                resultado=multiplicar(a , b);
                printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\tMULTIPLICACION\t\t\t\t*\n\t\t\t%.2f*%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*\n\n\t\t*************************************************\n\n", a,b,resultado);
                system("pause");
                break;
            case 7:
                if(a<0)
                    {
                        printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\t\t\t\t\t\t*\n\t\t\tError en el factoreo\n\t\t*\t no es posible realizar esa operacion\t*\n\n\t\t*************************************************\n\n");
                        system("pause");
                        break;
                    }
                else
                    {
                        aux=(int)a;
                        resultadoInt=factorial(aux);
                    }
                printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\tFACTOREO\t\t\t\t*\n\t\t\t%d!\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %d\n\t\t*\t\t\t\t\t\t*\n\n\t\t*************************************************\n\n", aux,resultadoInt);
                system("pause");
                break;
            case 8:
                resultado=suma(a , b);
                printf("\t\t*************************************************\n\t\t\t\tCALCULADORA\t\t\t\n\t\t*\tSUMA\t\t\t\t\t*\n\t\t\t%.2f+%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*", a,b,resultado);
                resultado=resta(a , b);
                printf("\t\t\n\t\t\t\t\t\t\n\t\t*\tRESTA\t\t\t\t\t*\n\t\t\t%.2f-%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*", a,b,resultado);
                resultado=multiplicar(a , b);
                printf("\t\t\n\t\t\t\t\t\t\n\t\t*\tMULTIPLICACION\t\t\t\t*\n\t\t\t%.2f*%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*", a,b,resultado);
                if(a<0)
                        {
                            printf("\n\t\t\n\t\t\t\t\t\t\n\t\t*\tFACTOREO\t\t\t\t*\n\t\t\tNO SE PUEDE REALIZAR\n\t\t*\t\t\t\t\t\t*\n\t\t\n\t\t*\t\t\t\t\t\t*");
                            if(b==0)
                            {
                                printf("\n\t\t\tError en la division\n\t\t*\t no es posible realizar esa operacion\t*\n\n\t\t*************************************************\n\n");
                                system("pause");
                                break;
                            }
                            else
                            {
                                resultado=division(a,b);
                            }
                        printf("\t\t\n\t\t\t\t\t\t\n\t\t*\tDIVISION\t\t\t\t*\n\t\t\t%.2f/%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*\n\n\t\t*************************************************\n\n", a,b,resultado);
                        system("pause");
                        break;
                    }
                else
                {
                    aux=(int)a;
                    resultadoInt=factorial(aux);
                }
                printf("\n\t\t\t\n\t\t*\tFACTOREO\t\t\t\t*\n\t\t\t%d!\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %d\n\t\t*\t\t\t\t\t\t*\n", aux,resultadoInt);
                if(b==0)
                {
                    printf("\n\t\t\tError en la division\n\t\t*\t no es posible realizar esa operacion\t*\n\n\t\t*************************************************\n\n");
                    system("pause");
                    break;
                }
                else
                {
                    resultado=division(a,b);
                }
                printf("\t\t\n\t\t\t\t\t\t\n\t\t*\tDIVISION\t\t\t\t*\n\t\t\t%.2f/%.2f\n\t\t*\t\t\t\t\t\t*\n\t\t\t\tResultado: %.2f\n\t\t*\t\t\t\t\t\t*\n\n\t\t*************************************************\n\n", a,b,resultado);
                system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
        }
}
    return 0;
}
