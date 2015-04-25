#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

/* ******************************************************************
 *    			   Profesor: Maximiliano Curia
 * -Integrantes del grupo:                  -Padron:
 * 		Vázquez Matías..........................91523
 * *****************************************************************/

/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/
 
// Destruye el dato ingresado.
// Pre: Se ingresa un puntero guardado en el heap.
// Post: Se libera el espacio ocupado por dicho puntero. 
void destruir_dato(void* dato)
{	
	free(dato);
}

/* Función auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result)
{
    printf("%s: %s\n", name, result? "OK" : "ERROR");
}

/* Prueba que las primitivas de la cola funcionen correctamente. */
void prueba_cola()
{
    /* Declaro las variables a utilizar */
    cola_t *c1, *c2;
	int *valor1, *valor2, *valor_aux;
	valor1 = malloc(sizeof(int));
	valor2 = malloc(sizeof(int));
	*valor1 = 2;
	*valor2 = 4;
	bool exito;
	int acumulador_exitos = 0;

    /* Creación de las colas */
    printf("Se crean dos colas vacias c1 y c2\n");
	c1 = cola_crear();
	c2 = cola_crear();
		
	/* Pruebo cola encolar */
	printf("Probaremos encolar 20 valores en c1:\n");
	for (int x = 0; x < 20 ; x++){
		if (x%2 == 0)
			exito = cola_encolar(c1, valor1);
		else
			exito = cola_encolar(c1,valor2);
		if (exito == true)
			acumulador_exitos++;
	}
	print_test("Prueba cola encolar de la cola c1", acumulador_exitos == 20);
	
	/* Pruebo cola ver primero 2 veces seguidas en c1 y en la cola vacia c2 */
	print_test("Prueba ver primero de la cola c1", cola_ver_primero(c1) == valor1);
	print_test("Prueba ver primero de la cola c1", cola_ver_primero(c1) == valor1);
	print_test("Prueba ver primero de la cola c2", cola_ver_primero(c2) == NULL);
		
	/* Pruebo cola esta vacia*/
	print_test("Prueba de cola esta vacia c1", cola_esta_vacia(c1) == false);
	print_test("Prueba de cola esta vacia c2", cola_esta_vacia(c2) == true);
	print_test("Prueba de encolar en la cola c2", cola_encolar(c2,valor1) == true);
	print_test("Prueba de desencolar en la cola c2", cola_desencolar(c2) == valor1);
	print_test("Prueba de cola esta vacia c2", cola_esta_vacia(c2) == true);
	
    /* Pruebo desencolar cola */
    printf("Probaremos desencolar 18 valores de c1\n");
    acumulador_exitos = 0;
    for ( int x = 0; x < 18 ; x++){
		valor_aux = cola_desencolar(c1);
		if (x % 2 == 0 && valor_aux == valor1)
			acumulador_exitos++;			
		else if (valor_aux == valor2)
			acumulador_exitos++;
	}
	print_test("Prueba de desencolar la cola c1", acumulador_exitos==18);
	print_test("Prueba de desencolar la cola c2", cola_desencolar(c2) == NULL);
	print_test("Prueba de cola esta vacia c1", cola_esta_vacia(c1) == false);
	
	/* Destruimos las colas */
	cola_destruir(c1,destruir_dato);
	cola_destruir(c2, NULL);
}

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

/* Programa principal. */
int main(void)
{
    /* Ejecuta todas las pruebas unitarias. */
    prueba_cola();
    return 0;
}
