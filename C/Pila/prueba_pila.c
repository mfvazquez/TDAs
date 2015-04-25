#include <stdio.h>
#include "pila.h"


/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

/* Función auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result)
{
    printf("%s: %s\n", name, result? "OK" : "ERROR");
}

/* Prueba que las primitivas del vector funcionen correctamente. */
void prueba_pila()
{
    /* Declaro las variables a utilizar */
	pila_t *p1, *p2;
	char* valor = "Hola";

    /* Creación de la pila */
	printf("Se crean dos pilas vacias p1 y p2\n");
	p1 = pila_crear();
	p2 = pila_crear();
	
	/* Pruebo pila apilar */
	printf("Probaremos apilar 85 valores en p1:\n");
	for ( int x = 0; x < 85 ; x++)
		pila_apilar(p1, valor);
	print_test("Prueba de pila apilar en p1", pila_apilar(p1, valor) == true);
	
	/* Pruebo ver tope de una pila */
	print_test("Prueba ver tope de la pila p1", pila_ver_tope(p1) == valor);
	print_test("Prueba ver tope de la pila p2", pila_ver_tope(p2) == NULL);
	
	/* Pruebo pila esta vacia*/
	print_test("Prueba de pila esta vacia p1", pila_esta_vacia(p1) == false);
	print_test("Prueba de pila esta vacia p2", pila_esta_vacia(p2) == true);
	
    /* Pruebo desapilar pila */
    printf("Probaremos desapilar los 85 valores de p1\n");
    for ( int x = 85; x > 0 ; x--)	
    	pila_desapilar(p1);
	print_test("Prueba de desapilar la pila p1", pila_desapilar(p1) == valor);
	print_test("Prueba de desapilar la pila p2", pila_desapilar(p2) == NULL);
		
    /* Destruimos las pilas*/
	pila_destruir(p1, NULL);
	pila_destruir(p2, NULL);
}


/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

/* Programa principal. */
int main(void)
{
    prueba_pila();
    return 0;
}
