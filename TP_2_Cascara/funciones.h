#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


/**
 * valida que solo se ingrese caracteres
 * \param cadena el array a validar como parametro
 * \return 0 si se valida como char y 1 si contiene algun digito en el array
 *
 */
int validarLetras(char cadena[]);

/**
 * pide un entero y valida que solo sea numerico
 * \param mensaje el mensaje a mostrar
 * \return el numero validado
 *
 */
int validarNumero(char mensaje[]);

/**
 * inicializa los estados de el vec en 0
 * \param vel el array pasado como parametro
 * \param tam el tamaño del array
 *
 */
void iniciarEstado(EPersona vec[], int tam);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int buscarLibre(EPersona vec[],int tam);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param vec el array se pasa como parametro.
 * \param tam el tamaño del array
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPersona(EPersona vec[], int tam, int dni);


/**
 * Da de alta una persona en el sistema pidiendo al usuario que ingrese todos los datos
 * \param vec el array se pasa como parametro.
 * \param tam el tamaño del array
 */
void altaPersona(EPersona vec[],int tam);


/**
 *  recorre el array y muestra el contenido de cada indice
 * \param vec el array se pasa como parametro
 * \param tam el tamaño del array se pasa como parametro
 * \return
 *
 */
void mostrarPersonas(EPersona vec[],int tam);


/**
 * muestra el array de la persona indicada
 * \param vec el array pasado como parametro
 */
void mostrarPersona(EPersona vec);


/**
 * baja logica de un indice del array buscando por dni
 * \param vec el array pasado como parametro
 * \param  tam el tamaño del array
 * \param dni un valor a buscar dentro de los array
 *
 */
void baja(EPersona vec[],int tam, int dni);


/**
 * ordena los nombres en forma acendente y si hay dos nombres iguales ordena por edad de forma acendente
 * \param vec el array pasado como parametro
 * \param tam el tamaño pasado como parametro
 */
void ordenaPorNombre(EPersona vec[],int tam);


/**
 * hace un grafico por edad ordenando menores de 18 , mayores y menores de 35 , mayores de 35
 * \param persona el array pasado como parametro
 * \param  tam el tamaño del array
 */
void graficoPorEdad(EPersona persona[], int tam);


/**
 * valida el largo de una cadena
 * \param cadena el array pasado como parametro
 * \param largoMaximo el valor maximo que admite la cadena
 * \return  0 si la cadena es admitida y 1 si la cadena se exede del maximo
 *
 */
int validarLargoCadena(char cadena[], int largoMaximo);


#endif // FUNCIONES_H_INCLUDED
