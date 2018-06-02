#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
//int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
//int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(EMovie lista[], char nombre[]);
typedef struct
{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[150];
    int puntaje;
    char linkImagen[1001];
    int estado;
    int codigoPelicula;
} EMovie;
/**
 *  le asigna un numero a un puntero.
 *  @param puntero de pelicula .
 *  @param numero a asiganrle a la duracion.
 */
int setDuracion(EMovie*,int);
/**
 *  le asigna un numero a un puntero.
 *  @param puntero de pelicula .
 *  @param numero a asiganrle al puntaje.
 */
int setPuntaje(EMovie*,int);
/**
 *  le asigna un texto a un puntero.
 *  @param puntero de pelicula.
 *  @param texto a asiganrle a titulo.
 */
char* setTitulo(EMovie*, char*);
/**
 *  le asigna un texto a un puntero.
 *  @param puntero de pelicula.
 *  @param texto a asiganrle a genero.
 */
char* setGenero(EMovie*, char*);
/**
 *  le asigna un texto a un puntero.
 *  @param puntero de pelicula.
 *  @param texto a asiganrle a descipion.
 */
char* setDescipcion(EMovie*, char*);
/**
 *  le asigna un texto a un puntero.
 *  @param puntero de pelicula.
 *  @param texto a asiganrle a link .
 */
char* setLinkImagen(EMovie*, char*);
/**
 *  despliega el menu para modificar.
 *
 */
int menuModifica();
/**
 *  modifica campo de la estructura.
 *  @param puntero pelicula.
 *  @param tamaño .
 */
void modifica(EMovie* vec, int tam);
/**
 *  incia los estados de las estructuras en 0.
 *  @param puntero de pelicula.
 *  @param tamaño total  .
 */
void iniciarEstado(EMovie* vec, int tam);
/**
 *  valida que halla lugar en la estructura.
 *  @param puntero de pelicula.
 *  @param tamaño.
 */
int buscarLibre(EMovie* vec, int tam);
/**
 *  busca una pelicula por codigo.
 *  @param puntero de pelicula.
 *  @param tamaño
 *  @param codigo a buscar en el vector
 */
int buscarPelicula(EMovie* vec, int tam, int codigoPelicula);
/**
 *  valida el largo de una cadena .
 *  @param texto a validar.
 *  @param tamano maximo de la cadena
 */
int validarLargoCadena(char cadena[],int  LargoMaximo);
/**
 *  valida el solo numeros.
 *  @param mensaje a mostrar.
 *  @return numero validado
 */
int validarNumero(char mensaje[]);
/**
 *  carga una pelicula a la estructura.
 *  @param vector puntero como parametro.
 *  @param tamano del vector.
 *  @param cantidad de peliculas cargadas en el archivo.
 */
void altaPelicula(EMovie* vec,int tam, int contadorPeliculas);
/**
 *  baja una pelicula a la estructura.
 *  @param vector puntero como parametro.
 *  @param tamano del vector.
 *  @param cantidad de peliculas cargadas en el archivo.
 */
void bajaPelicula(EMovie *vec,int tam, int codigopelicula);
/**
 *  baja una pelicula a la estructura.
 *  @param puntero al archivo.
 *  @param vector puntero como parametro.
 *  @param cantidad de peliculas a cargar.
 */
void paginaWeb(FILE *,EMovie*,int);

#endif // FUNCIONES_H_INCLUDED
