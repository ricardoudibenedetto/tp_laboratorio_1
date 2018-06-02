#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int setPuntaje(EMovie* pelicula,int valor)
{
    int ret=0;
    if(pelicula!=NULL)
    {
        pelicula->puntaje=valor;
        ret=1;
    }
    return ret;
}
char* setGenero(EMovie* pelicula, char* valor)
{
    int ret=0;
    int longi;
    if(pelicula!=NULL)
    {
        strcpy(pelicula->genero,valor);
        ret=1;
    }
    return ret;

}
char* setDescipcion(EMovie* pelicula, char* valor)
{
    int ret=0;
    int longi;
    if(pelicula!=NULL)
    {
        strcpy(pelicula->descripcion,valor);
        ret=1;
    }
    return ret;

}
char* setLinkImagen(EMovie* pelicula, char* valor)
{
    int ret=0;
    int longi;
    if(pelicula!=NULL)
    {
        strcpy(pelicula->linkImagen,valor);
        ret=1;
    }
    return ret;
}





int setDuracion(EMovie* pelicula,int valor)
{
    int ret=0;
    if(pelicula!=NULL)
    {
        pelicula->duracion=valor;
        ret=1;
    }
    return ret;
}
char* setTitulo(EMovie* pelicula, char* valor)
{
    int ret=0;
    int longi;

    if(pelicula!=NULL)
    {
        strcpy(pelicula->titulo,valor);
        ret=1;
    }
    return ret;
}
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
    for(i=0; i<tamCadena; i++)
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
        for(i=0; i<tamCadena; i++)
        {
            if(!isdigit( numeroCadena[i]))
            {
                validar=1;
                break;
            }
            else
            {
                validar=0;
            }
        }
    }
    numero=atoi(numeroCadena);
    return numero;
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
void iniciarEstado(EMovie* vec, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vec[i].estado=0;
    }
}
int buscarLibre(EMovie* vec, int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].estado==0)
        {
            indice=i;
            break;
        }

    }
    return indice;
}

int buscarPelicula(EMovie* vec, int tam, int codigoPelicula)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].codigoPelicula==codigoPelicula&&vec[i].estado==1)
        {
            indice=i;
        }
    }
    return indice;
}
void altaPelicula(EMovie* vec,int tam,int contadorPeliculas)
{
    int codigoPelicula, esta, indice, largoCadena;
    char nombreAux[300];
    char generoAux[300];
    char descriAux[300];
    char linkAux[300];
    int t;
    int dura;
    int tamPel=tam;
    int puntajeAux;
    indice=buscarLibre(vec, 20);
    if(indice==-1)
    {
        printf("No hay espacio para almacenar otra pelicula\n");
    }
    else
    {
        printf("ingrese el codigo de la pelicula : ");
        scanf("%d", &codigoPelicula);

        esta=buscarPelicula(vec, tam, codigoPelicula);
        if(esta!=-1)
        {
            printf("\n La pelicula ya existe .\n");
        }
        else
        {
            printf("Ingrese el nombre de la pelicula: ");
            fflush(stdin);
            scanf("%[^\n]",nombreAux);
            t=validarLargoCadena(nombreAux,50);
            if(t==1)
            {

                while(t==1)
                {
                    printf("\nError.\nel nombre no debe superar los 20 caracteres: ");
                    fflush(stdin);
                    scanf("%[^\n]",nombreAux);
                    t=validarLargoCadena(nombreAux,50);
                }
            }
            setTitulo(vec+contadorPeliculas,nombreAux);



            printf("Ingrese el genero de la pelicula: ");
            fflush(stdin);
            scanf("%[^\n]",generoAux);
            t=validarLargoCadena(generoAux,20);
            if(t==1)
            {

                while(t==1)
                {
                    printf("\nError.\nel genero no debe superar los 20 caracteres: ");
                    fflush(stdin);
                    scanf("%[^\n]",generoAux);
                    t=validarLargoCadena(generoAux,20);
                }
            }
            setGenero(vec+contadorPeliculas,generoAux);


            printf("Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            scanf("%[^\n]",descriAux);
            t=validarLargoCadena(descriAux,150);
            if(t==1)
            {

                while(t==1)
                {
                    printf("\nError.\nla descripcion no debe superar los 50 caracteres: ");
                    fflush(stdin);
                    scanf("%[^\n]",descriAux);
                    t=validarLargoCadena(descriAux,150);
                }
            }
            setDescipcion(vec+contadorPeliculas,descriAux);

            fflush(stdin);
            printf("Ingrese el puntaje de la pelicula: ");
            fflush(stdin);
            scanf("%d",&puntajeAux);
            while(puntajeAux<0||puntajeAux>10)
            {
                printf("\nError.\nel puntaje debe ser mayor de 0 y menor que 10: ");
                fflush(stdin);
                scanf("%d",&puntajeAux);
            }
            setPuntaje(vec+contadorPeliculas,puntajeAux);


            fflush(stdin);

            printf("ingrese la duracion de la pelicula en minutos : ");
            scanf("%d", &dura);
            while(dura<0)
            {
                printf("Error, la duracion debe ser mayor a 0 : ");
                scanf("%d", &dura);
            }
            (vec+contadorPeliculas)->duracion=dura;

            printf("Ingrese Link de imagen: ");
            fflush(stdin);
            scanf("%[^\n]",linkAux);
            t=validarLargoCadena(linkAux,1000);
            if(t==1)
            {

                while(t==1)
                {
                    printf("\nError.\nel link no debe superar los 50 caracteres: ");
                    fflush(stdin);
                    scanf("%[^\n]",linkAux);
                    t=validarLargoCadena(linkAux,1000);
                }
            }
            setLinkImagen(vec+contadorPeliculas,linkAux);
            (vec+contadorPeliculas)->estado = 1;
            (vec+contadorPeliculas)->codigoPelicula=codigoPelicula;

            if(contadorPeliculas>=tamPel)
            {
                tamPel+=10;
                vec = realloc(vec,sizeof(EMovie)*tamPel);
            }


            printf("\n carga exitosa!!\n");
        }


        system("pause");

    }
}

void bajaPelicula(EMovie *vec,int tam, int codigopelicula)
{
    int esta;
    esta=buscarPelicula(vec, tam, codigopelicula);
    if(esta==-1)
    {
        printf("\n El codigo de la pelicula no existe.\n");
    }
    else
    {
        vec[esta].estado=0;
        printf("\n Baja exitosa !\n") ;
    }
    system("pause");
}


void modifica(EMovie* vec, int tam)
{
    char nombreAux[300];
    char generoAux[300];
    char descriAux[300];
    char linkAux[300];
    int t;
    int dura;
    int puntajeAux;
    int esta;
    char confirma;
    int salir = 0;
    int codigo;

    float nuevoImporte;
    int nuevaCantidad;
    system("cls");
    printf("Modificar pelicula: \n\n");
    printf("Ingrese el codigo de la pelicula que desea modificar : ");
    scanf("%d", &codigo);
    esta = buscarPelicula(vec, tam, codigo);
    if(esta == -1)
    {
        printf("\nEl codigo %d no se encuentra en el sistema\n\n", codigo);
    }
    else
    {

        do
        {
            switch(menuModifica())
            {
            case 1:
                printf("Ingrese el nuevo titulo de la pelicula: ");
                fflush(stdin);
                scanf("%[^\n]",nombreAux);
                t=validarLargoCadena(nombreAux,50);
                if(t==1)
                {

                    while(t==1)
                    {
                        printf("\nError.\nel nombre no debe superar los 20 caracteres: ");
                        fflush(stdin);
                        scanf("%[^\n]",nombreAux);
                        t=validarLargoCadena(nombreAux,50);
                    }
                }
                setTitulo(vec+esta,nombreAux);
                printf("Titulo modificado\n\n");
                system("pause");
                break;
            case 2:
                printf("Ingrese nuevo genero de la pelicula: ");
                fflush(stdin);
                scanf("%[^\n]",generoAux);
                t=validarLargoCadena(generoAux,20);
                if(t==1)
                {

                    while(t==1)
                    {
                        printf("\nError.\nel genero no debe superar los 20 caracteres: ");
                        fflush(stdin);
                        scanf("%[^\n]",generoAux);
                        t=validarLargoCadena(generoAux,20);
                    }
                }
                setGenero(vec+esta,generoAux);

                printf("genero modificado \n\n");
                system("pause");
                break;
            case 3:
                fflush(stdin);
                scanf("%[^\n]",descriAux);
                t=validarLargoCadena(descriAux,150);
                if(t==1)
                {

                    while(t==1)
                    {
                        printf("\nError.\nla descripcion no debe superar los 50 caracteres: ");
                        fflush(stdin);
                        scanf("%[^\n]",descriAux);
                        t=validarLargoCadena(descriAux,150);
                    }
                }
                setDescipcion(vec+esta,descriAux);
                printf("descripcion modificada !\n");
                system("pause");
                break;
            case 4:
                scanf("%d", &dura);
                while(dura<0)
                {
                    printf("Error, la duracion debe ser mayor a 0 : ");
                    scanf("%d", &dura);
                }
                (vec+esta)->duracion=dura;
                printf("duracion modificada !\n");
                system("pause");
                break;
            case 5:
                fflush(stdin);
                printf("Ingrese el nuevo puntaje de la pelicula: ");
                fflush(stdin);
                scanf("%d",&puntajeAux);
                while(puntajeAux<0||puntajeAux>10)
                {
                    printf("\nError.\nel puntaje debe ser mayor de 0 y menor que 10: ");
                    fflush(stdin);
                    scanf("%d",&puntajeAux);
                }
                setPuntaje(vec+esta,puntajeAux);
                printf("puntaje modificado!!\n");

                system("pause");
                break;
            case 6:
                fflush(stdin);
                scanf("%[^\n]",linkAux);
                t=validarLargoCadena(linkAux,1000);
                if(t==1)
                {

                    while(t==1)
                    {
                        printf("\nError.\nel link no debe superar los 50 caracteres: ");
                        fflush(stdin);
                        scanf("%[^\n]",linkAux);
                        t=validarLargoCadena(linkAux,1000);
                    }
                }
                setLinkImagen(vec+esta,linkAux);
                printf("link de imagen modificado !!\n");
                system("pause");
                break;
            case 7:
                salir = 1;
                break;
            default:
                printf("Opcion incorrecta ");
                break;
            }
        }
        while(salir != 1);
        printf("\nSe ha realizado la modificacion\n\n");
    }

    system("pause");
}

int menuModifica()
{
    int opcion;

    system("cls");
    printf("Modificar pelicula \n\n");
    printf("1-Titulo\n");
    printf("2-Genero\n");
    printf("3-Descripcion\n");
    printf("4-Duracion\n");
    printf("5-Puntaje\n");
    printf("6-Link de imagen\n");
    printf("7-salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void paginaWeb(FILE *f,EMovie* vec,int tam)
{
    char titulo[50]="hello word!";
    f=fopen("index.html", "w");
//https://www.rockandpop.cl/wp-content/uploads/2018/03/parque-e1520612168895.png
//http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg
    fprintf(f,"<!DOCTYPE html><html lang='en'>");
    fprintf(f,"<head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'>");
    fprintf(f,"<title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head>");
    fprintf(f,"<body><div class='container'><div class='row'>");
    for(int i=0; i<tam; i++)
    {
        if((vec+i)->estado==1)
        {
            fprintf(f,"<article class='col-md-4 article-intro'>");
            fprintf(f," <a href='#'><img class='img-responsive img-rounded' src=' %s ' alt=''></a>",(vec+i)->linkImagen);
            fprintf(f,"<h3><a href='#'> %s </a></h3>", (vec+i)->titulo);
            fprintf(f,"<ul>");
            fprintf(f,"<li>Genero: %s </li>",(vec+i)->genero);
            fprintf(f,"<li>Puntaje: %d </li>",(vec+i)->puntaje);
            fprintf(f,"<li>Duracion: %d </li>",(vec+i)->duracion);
            fprintf(f,"</ul>");
            fprintf(f,"<p> %s </p>",(vec+i)->descripcion);
            fprintf(f,"</article>");
        }



    }

    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script>");
    fprintf(f,"<script src='js/bootstrap.min.js'></script>");
    fprintf(f,"<script src='js/ie10-viewport-bug-workaround.js'></script>");
    fprintf(f,"<script src='js/holder.min.js'></script>");
    fprintf(f,"</body>");
    fprintf(f,"</html>");

    fclose(f);
}
