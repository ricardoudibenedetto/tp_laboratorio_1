/** \brief La funcion suma toma dos valores y los suma
 *
 * \param Toma un valor de tipo float
 * \param Toma un valor de tipo float
 * \return Retorna un valor de tipo float resultante de la operacion
 *
 */
float suma(float a, float b)
{

 float resultado;

 resultado=(float)a+b;

 return resultado;


}
/** \brief La funcion resta toma dos valores y los resta
 *
 * \param Toma un valor de tipo float
 * \param Toma un valor de tipo float
 * \return Retorna un valor de tipo float resultante de la operacion
 *
 */
float resta(float a, float b)
{
 float resultado;

 resultado=(float)a-b;

 return resultado;
}
/** \brief La funcion division toma dos valores y el segundo divide al primero
 *
 * \param Toma un valor de tipo float
 * \param Toma un valor de tipo float
 * \return Retorna un cociente de tipo float resultante de la operacion
 *
 */
float division(float a, float b)
{
 float resultado;

 resultado=(float)a/b;

 return resultado;
}
/** \brief La funcion multiplicar toma dos valores y los multiplica
 *
 * \param Toma un valor de tipo float
 * \param Toma un valor de tipo float
 * \return Retorna un valor de tipo float resultante de la operacion
 *
 */

float multiplicar(float a, float b)
{
 float resultado;

 resultado=(float)a*b;

 return resultado;
}
/** \brief La funcion factorial toma un valor y lo factoriza
 *
 * \param Toma un valor de tipo int
 * \return Retorna un valor de tipo long resultante de la operacion
 *
 */
long factorial(int aux)
{
   int contador;
   long result = 1;

   for( contador = 1 ; contador <=aux ; contador++ )
         result = result*contador;

   return ( result );
}
