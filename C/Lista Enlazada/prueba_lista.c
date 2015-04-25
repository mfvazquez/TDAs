#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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
// Post: Se libera el espacio ocupado por el puntero. 
void destruir_dato(void* dato)
{	
	free(dato);
}

/* Función auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result)
{
    printf("%s: %s\n", name, result? "OK" : "ERROR");
}

/* Prueba que las primitivas de la lista funcionen correctamente. */
void prueba_lista(void)
{
	/* Declaro las variables a utilizar */
	static int *valores[5];
	for(int n = 0; n<5 ; n++){
		valores[n] = malloc(5 * sizeof(int));
		*valores[n] = n;
	}
	int acumulador_exitos1 = 0, acumulador_exitos2 = 0, acumulador_exitos3 = 0;

	/* Creación de las listas */
	printf("Creamos tres listas enlazadas lista1, lista2 y lista3\n");
	lista_t* lista1 = lista_crear();
	lista_t* lista2 = lista_crear();
	lista_t* lista3 = lista_crear();
	
	/* Verificamos que las dos listas están vacías */
	print_test("Prueba de lista esta vacia en lista1",lista_esta_vacia(lista1));
	print_test("Prueba de lista esta vacia en lista2",lista_esta_vacia(lista2));
	print_test("Prueba de lista esta vacia en lista3",lista_esta_vacia(lista3));
	
	/* Probamos insertar primero en lista1 */
	for(int i = 0; i < 5; i++)
		if(lista_insertar_primero( lista1, valores[4-i]))
			acumulador_exitos1++;
	print_test("Prueba de lista insertar primero en lista1", acumulador_exitos1 == 5);
	
	/* Probamos lista esta vacia, ver largo y ver primero */
	print_test("Prueba de lista esta vacia en lista1",!lista_esta_vacia(lista1));
	print_test("Prueba de lista ver primero en lista1",lista_ver_primero(lista1) == valores[0]);
	print_test("Prueba de lista ver primero en lista1",lista_ver_primero(lista1) == valores[0]);
	print_test("Prueba de lista ver largo en lista1", lista_largo(lista1) == 5);
	
	print_test("Prueba de lista ver primero en lista2", lista_ver_primero(lista2) == NULL);
	print_test("Prueba de lista ver primero en lista2", lista_ver_primero(lista2) == NULL);
	print_test("Prueba de lista ver largo en lista2", lista_largo(lista2) == 0);
	
	print_test("Prueba de lista ver primero en lista3", lista_ver_primero(lista3) == NULL);
	print_test("Prueba de lista ver primero en lista3", lista_ver_primero(lista3) == NULL);
	print_test("Prueba de lista ver largo en lista3", lista_largo(lista3) == 0);
	
	/* Probamos lista insertar ultimo en lista2 */
	for (int i = 0; i < 5; i++)
		if(lista_insertar_ultimo(lista2, valores[i]))
			acumulador_exitos2++;
	print_test("Prueba de lista insertar ultimo en lista2", acumulador_exitos2 == 5);
	
	/* Probamos lista esta vacia, ver largo y ver primero */
	print_test("Prueba de lista esta vacia en lista2",!lista_esta_vacia(lista2));
	print_test("Prueba de lista ver primero en lista2",lista_ver_primero(lista2) == valores[0]);
	print_test("Prueba de lista ver primero en lista2",lista_ver_primero(lista2) == valores[0]);
	print_test("Prueba de lista ver largo en lista2", lista_largo(lista2) == 5);
	
	/* Creamos un iterador en cada lista */
	printf("Creamos 3 iteradores: iter1, iter2 e iter3 en lista1, lista2 y lista3 respectivamente\n");
	lista_iter_t* iter1 = lista_iter_crear(lista1);
	lista_iter_t* iter2 = lista_iter_crear(lista2);
	lista_iter_t* iter3 = lista_iter_crear(lista3);
	
	/* Probamos iter al final */
	print_test("Prueba de lista iter al final en iter1", !lista_iter_al_final(iter1));
	print_test("Prueba de lista iter al final en iter2", !lista_iter_al_final(iter2));
	print_test("Prueba de lista iter al final en iter3", lista_iter_al_final(iter3));
	
	/* Probamos iter ver actual dos veces seguidas en cada iterador */
	print_test("Prueba de lista iter ver actual en iter1", lista_iter_ver_actual(iter1) == valores[0]);
	print_test("Prueba de lista iter ver actual en iter1", lista_iter_ver_actual(iter1) == valores[0]);
	print_test("Prueba de lista iter ver actual en iter2", lista_iter_ver_actual(iter2) == valores[0]);
	print_test("Prueba de lista iter ver actual en iter2", lista_iter_ver_actual(iter2) == valores[0]);
	print_test("Prueba de lista iter ver actual en iter3", !lista_iter_ver_actual(iter3));
	print_test("Prueba de lista iter ver actual en iter3", !lista_iter_ver_actual(iter3));
	
	/* Probamos avanzar en la lista vacía */
	print_test("Prueba de lista iter avanzar en iter3", !lista_iter_avanzar(iter3));
	
	/* Probamos lista insertar */
	for(int i = 0; i < 5; i++)
		if (lista_insertar(lista3, iter3, valores[4-i]))
			acumulador_exitos3++;
	print_test("Prueba de lista insertar en lista3", acumulador_exitos3 == 5);
	print_test("Prueba de lista iter al final en iter3", !lista_iter_al_final(iter3));
	
	/* Probamos avanzar los dos iteradores en la lista y comprobar que tengan sus respectivos valores */
	acumulador_exitos1 = acumulador_exitos2 = acumulador_exitos3 = 0;
	int contador = 0;
	while (!lista_iter_al_final(iter1) && !lista_iter_al_final(iter2) && !lista_iter_al_final(iter3) ){
		if (lista_iter_ver_actual(iter1) == valores[contador] && lista_iter_avanzar(iter1))
			acumulador_exitos1++;
		if (lista_iter_ver_actual(iter2) == valores[contador] && lista_iter_avanzar(iter2))
			acumulador_exitos2++;
		if (lista_iter_ver_actual(iter3) == valores[contador] && lista_iter_avanzar(iter3))
			acumulador_exitos3++;
		contador++;
	}
	print_test("Prueba de lista iter avanzar y lista iter ver actual en iter1", acumulador_exitos1 == 5);
	print_test("Prueba de lista iter avanzar y lista iter ver actual en iter2", acumulador_exitos2 == 5);
	print_test("Prueba de lista iter avanzar y lista iter ver actual en iter3", acumulador_exitos3 == 5);
	
	/* Probamos iter al final */
	print_test("Prueba de lista iter al final en iter1", lista_iter_al_final(iter1));
	print_test("Prueba de lista iter al final en iter2", lista_iter_al_final(iter2));
	print_test("Prueba de lista iter al final en iter3", lista_iter_al_final(iter3));
	
	/* Probamos lista borrar primero en lista1, destruimos iter1 */
	acumulador_exitos1 = 0;
	lista_iter_destruir(iter1);
	for(int i = 0; i < 5; i++)
		if(lista_borrar_primero(lista1) == valores[i])
			acumulador_exitos1++;
	print_test("Prueba de lista borrar en lista1", acumulador_exitos1 == 5);
	
	/* Probamos lista borrar en lista3 */
	print_test("Prueba de lista borrar en iter3", lista_borrar(lista3,iter3) == NULL);
	
	/* Destruimos iter3 y creamos iter3 nuevamente para estar al comienzo de la lista */
	lista_iter_destruir(iter3);
	iter3 = lista_iter_crear(lista3);
	printf("Destruimos iter3 y creamos iter3 nuevamente para reiniciarlo\n");
	
	/* Probamos lista insertar con el iter en el ultimo elemento de la lista */
	for( int x = 0; x < 5 ; x++)
		lista_iter_avanzar(iter3);
	
	print_test("Prueba de lista iter al final en iter3", lista_iter_al_final(iter3));
	print_test("Prueba de lista insertar en lista3", lista_insertar(lista3, iter3, valores[0]));
	print_test("Prueba de lista insertar ultimo en lista3", lista_insertar_ultimo(lista3, valores[1]));
	print_test("Prueba de lista borrar en lista3", lista_borrar(lista3, iter3)==valores[0]);
	print_test("Prueba de lista borrar en lista3", lista_borrar(lista3, iter3)==valores[1]);
	print_test("Prueba de lista iter al final en iter3", lista_iter_al_final(iter3));
	
	/* Destruimos iter3 y creamos iter3 nuevamente para estar al comienzo de la lista */
	lista_iter_destruir(iter3);
	iter3 = lista_iter_crear(lista3);
	printf("Destruimos iter3 y creamos iter3 nuevamente para reiniciarlo\n");
	
	/* Probamos lista borrar en lista3 */
	acumulador_exitos3 = 0;
	contador = 0;
	while(!lista_iter_al_final(iter3)){
		if(lista_ver_primero(lista3) == valores[contador] && valores[contador] == lista_borrar(lista3,iter3))
			acumulador_exitos3++;
		contador++;
	}
	print_test("Prueba de lista borrar y lista ver primero en lista3", acumulador_exitos3 == 5);
	
	/* Verificamos que esté vacía */
	print_test("Prueba de lista esta vacia en lista1",lista_esta_vacia(lista1));
	print_test("Prueba de lista esta vacia en lista3",lista_esta_vacia(lista3));
	
	/* Verificamos los largos de las listas */
	print_test("Prueba de lista largo en lista1", lista_largo(lista1)==0);
	print_test("Prueba de lista largo en lista3", lista_largo(lista3)==0);
	
	/* Destruimos los iteradores */
	lista_iter_destruir(iter2);
	lista_iter_destruir(iter3);
	
	/* Destruimos las listas */
	lista_destruir(lista1, NULL);
	lista_destruir(lista2, destruir_dato);
	lista_destruir(lista3, NULL);
}
/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

/* Programa principal. */
int main(void)
{
    /* Ejecuta todas las pruebas unitarias. */
    prueba_lista();
    return 0;
}
