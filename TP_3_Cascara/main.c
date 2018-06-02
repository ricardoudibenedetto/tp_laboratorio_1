#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    int opcion=0;
    int contadorPeliculas=0;
    int codigoPelicula;
    FILE* f;
    FILE* b;
    EMovie *pPelicula;
    pPelicula=(EMovie*)malloc(sizeof(EMovie)*20);
    b=fopen("peliculasDB.dat", "rb");
    fread(&contadorPeliculas,sizeof(int),1,b);
    fread(pPelicula, sizeof(EMovie),contadorPeliculas,b);
    fclose(b);
    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            altaPelicula(pPelicula,20,contadorPeliculas);
            contadorPeliculas++;
            break;
        case 2:
            printf("ingrese el codigo de la pelicula que desea dar de baja: ");
            scanf("%d", &codigoPelicula);
            while(codigoPelicula<1)
            {
                printf("Error\nel codigo de la pelicula debe ser mayor a 0 : ");
                scanf("%d", &codigoPelicula);
            }
            bajaPelicula(pPelicula,20,codigoPelicula);
            break;
        case 3:
            modifica(pPelicula,20);
            break;
        case 4:
            paginaWeb(f,pPelicula,contadorPeliculas);
            for(int i=0; i<5; i++)
            {
                if((pPelicula+i)->estado==1)
                {
                    printf("nombre : %s\ngenero: %s\ndescripcion: %s\nduracion: %d\npuntuacion: %d\ncodigo de la pelicula: %d\nLink de imagen: %s\nestado: %d\n\n", (pPelicula+i)->titulo,(pPelicula+i)->genero,(pPelicula+i)->descripcion,(pPelicula+i)->duracion,(pPelicula+i)->puntaje,(pPelicula+i)->codigoPelicula,(pPelicula+i)->linkImagen, (pPelicula+i)->estado );
                }
            }
            system("pause");
            break;
        case 5:
            b=fopen("peliculasDB.dat", "wb");
            fwrite(&contadorPeliculas,sizeof(int),1,b);
            for(int i=0; i<contadorPeliculas; i++)
            {
                fwrite(pPelicula+i, sizeof(EMovie), 1, b);
            }
            fclose(b);
            seguir = 'n';
            break;
        }
    }

    return 0;
}
