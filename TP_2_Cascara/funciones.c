#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int validarNumero(char mensaje[])
{
    int validar;
    int numero;
    int i;
    long tam=256;
    char val, numeroCadena[tam];
    int tamCadena;
    printf("%s", mensaje);
    fflush(stdin);
    gets(numeroCadena);
    tamCadena=strlen(numeroCadena);
    for(i=0;i<tamCadena;i++)
    {
        if(!isdigit( numeroCadena[i]))
        {
            validar=1;
            break;
        }
    }
        while(validar==1)
        {
            printf("Error ,ingrese un numero : ");
            fflush(stdin);
            gets(numeroCadena);
            tamCadena=strlen(numeroCadena);
            for(i=0;i<tamCadena;i++)
            {
               if(!isdigit( numeroCadena[i]))
                {
                    validar=1;
                    break;
                }else
                {
                    validar=0;
                }
            }
        }
     numero=atoi(numeroCadena);
  return numero;
}


int validarLetras(char cadena[])
{
    int i=0;
    int validar;
    int tamCadena;
    tamCadena=strlen(cadena);
    for(i=0;i<tamCadena;i++)
    {

        if(isdigit(cadena[i]))
        {
            validar=1;
            break;
        }
        else
        {
            validar=0;
        }
    }
return validar;
}




void iniciarEstado(EPersona vec[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
        {
                    vec[i].estado=0;
        }
}

int buscarLibre(EPersona vec[], int tam)
{
   int indice=-1;
   for(int i=0;i<tam;i++)
    {
        if(vec[i].estado==0)
            {
               indice=i;
                break;
            }

    }
     return indice;
}


int buscarPersona(EPersona vec[], int tam, int dni)
{
    int indice=-1;
    for(int i=0;i<tam;i++)
        {
            if(vec[i].dni==dni&&vec[i].estado==1)
                {
             indice=i;
                }
        }
         return indice;
}
void altaPersona(EPersona vec[],int tam)
{
    EPersona nuevaPersona;
    int dni, esta, indice, largoCadena;
    char nombreAux[300];
    indice=buscarLibre(vec, 20);
    if(indice==-1)
    {
        printf("No hay espacio para almacenar otra persona\n");
    }
    else
    {
        dni=validarNumero("ingrese DNI: ");
        esta = buscarPersona(vec, tam, dni);
        if(esta != -1)
            {
                printf("El dni ya existe, corresponde a la persona\n\n");
                printf("nombre\t\tedad\t\tDNI\n");
                mostrarPersona(vec[esta]);
                system("pause");

            }
        else
        {
            printf("ingrese un nombre: ");
            fflush(stdin);
            scanf("%s",&nombreAux);

           while(validarLargoCadena(nombreAux,49)==1 || validarLetras(nombreAux)==1)
           {
                printf("Error, ingrese un nombre sin numeros y que no exceda los 50 caracteres: ");
                fflush(stdin);
                scanf("%s",&nombreAux);
           }
           strcpy(nuevaPersona.nombre, nombreAux);

            fflush(stdin);
            nuevaPersona.edad=validarNumero("ingrese una edad: ");
            while(nuevaPersona.edad>120)
            {

                 fflush(stdin);
                nuevaPersona.edad=validarNumero("Error ingrese una edad menor a 120: ");
            }

            nuevaPersona. dni = dni;
            nuevaPersona.estado = 1;

            vec[indice]=nuevaPersona;
            printf("\n carga exitosa!!\n");
            system("pause");
        }
    }
}

void mostrarPersonas(EPersona vec[],int tam)
{
    printf(" nombre\t\tedad\tdni\n");
    for(int i=0;i<tam;i++)
        {
            if(vec[i].estado==1)
                {
                    mostrarPersona(vec[i]);
                }
        }
}
void mostrarPersona(EPersona vec)
{
    printf(" %s        %d          %d\n",vec.nombre,vec.edad,vec.dni);
}


void baja(EPersona vec[],int tam, int dni)
{

     int esta;
     esta=buscarPersona(vec, tam , dni);
      if(esta==-1)
            {
               printf("\n El numero de DNI no existe.\n");
            }
            else
            {
                vec[esta].estado=0;
                   printf("\n Baja exitosa !\n") ;
            }


}


void ordenaPorNombre(EPersona vec[],int tam)
{
        EPersona aux;
      for(int i=0;i<tam-1;i++)
                {
                    for(int j=i+1;j<tam;j++)
                    {
                        if(strcmp(vec[i].nombre,vec[j].nombre)>0)
                        {
                        aux=vec[i];
                        vec[i]=vec[j];
                        vec[j]=aux;
                         }
                         if(strcmp(vec[i].nombre,vec[j].nombre)==0)
                         {
                             if(vec[i].edad > vec[j].edad)
                             {
                                aux.edad=vec[i].edad;
                                vec[i].edad=vec[j].edad;
                                vec[j].edad=aux.edad;
                             }

                         }
                    }
                }
}

void graficoPorEdad(EPersona persona[],int tam)
{
    int contador=0;
    int cont18=0;
    int contMas18=0;
    int contMas35=0;
    int i;
    int val=0;
    int mayor;

            for(int i=0;i<tam;i++)
                {
               if(persona[i].edad<19 && persona[i].estado==1)
               {
                   cont18++;
               }

               if(persona[i].edad>35 && persona[i].estado==1)
                {
                    contMas35++;
                }
                if(persona[i].edad<35 && persona[i].edad>18 && persona[i].estado==1)
                {
                    contMas18++;
                }
                }

                 if(cont18 >= contMas18 && cont18 >= contMas35){
                        mayor = cont18;
                    }else{
                        if(contMas18 >= cont18 && contMas18 >= contMas35)
                        {
                            mayor = contMas18;
                        }
                        else{
                        mayor = contMas35;
                        }
                    }


                        for(i=mayor; i>0; i--){

                        if(i<= cont18){
                            printf("*");
                        }
                        if(i<= contMas18){
                            val=1;
                            printf("\t*");
                        }
                        if(i<= contMas35){
                            if(val==0)
                                printf("\t\t*");
                            if(val==1)
                                printf("\t*");

                        }

                        printf("\n");
                        }
                        printf("|<18|\t|19-35|\t|>35|\n");


                printf("18: %d 18-35: %d 35+ %d\n", cont18 , contMas18 , contMas35);
                system("pause");
}


int validarLargoCadena(char cadena[],int  LargoMaximo)
{
            int largoCadena;
            largoCadena=strlen(cadena);
            if(largoCadena<LargoMaximo)
            {
               return 0;
            }
            else
            {
                return 1;

            }
}


