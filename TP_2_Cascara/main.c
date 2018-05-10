#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    int opcion=0;
    int tam=20;
    int dni;
    EPersona persona[20];
    EPersona personaAux;
    iniciarEstado(persona,tam);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                altaPersona(persona, 20);
                break;
            case 2:
                dni=validarNumero("ingrese DNI: ");
                baja(persona,20,dni);
                system("pause");
                break;
            case 3:
                ordenaPorNombre(persona,20);
                mostrarPersonas(persona, 20);
                system("pause");
                break;
            case 4:
                printf("\n\n");
                graficoPorEdad(persona, tam);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("opcion incorrecta\n");
                system("pause");
                break;
        }
    }
    return 0;
}
