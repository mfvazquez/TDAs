/*
 * prueba_ABB.c
 *
 *  Created on: 10/10/2011
 *      Author: Matías Vázquez
 *      Padron: 91523
 *      Professor: Maximiliano Curia
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "abb.h"
#include "pila.h"

/* ******************************************************************
 *                      FUNCIONES AUXILIARES
 * *****************************************************************/

/* Función auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result)
{
    printf("%s: %s\n", name, result? "OK" : "ERROR");
}

/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

/* Prueba que las primitivas funcionen correctamente. */
void prueba_crear_abb_vacio(void)
{
	abb_t* arbol = abb_crear(NULL, NULL);

	print_test("Prueba abb crear arbol vacio", arbol);
	print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(arbol) == 0);
	print_test("Prueba abb obtener clave A, es NULL, no existe", !abb_obtener(arbol, "A"));
	print_test("Prueba abb pertenece clave A, es false, no existe", !abb_pertenece(arbol, "A"));
	print_test("Prueba abb borrar clave A, es NULL, no existe", !abb_borrar(arbol, "A"));

	abb_destruir(arbol);
}

void prueba_abb_guardar(void)
{
	abb_t* arbol = abb_crear(strcmp, NULL);

	char *clave0 = "00", *valor0 = "-00-";
	char *clave1 = "20", *valor1 = "-20-";
	char *clave2 = "10", *valor2 = "-10-";
	char *clave3 = "05", *valor3 = "-05-";
	char *clave4 = "15", *valor4 = "-15-";
	char *clave5 = "30", *valor5 = "-30-";
	char *clave6 = "25", *valor6 = "-25-";
	char *clave7 = "35", *valor7 = "-35-";

	/* Inserta 1 valor y luego lo borra */
	print_test("Prueba abb insertar clave0", abb_guardar(arbol, clave0, valor0));
	print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(arbol) == 1);
	print_test("Prueba abb obtener clave0 es valor0", abb_obtener(arbol, clave0) == valor0);
	print_test("Prueba abb obtener clave0 es valor0", abb_obtener(arbol, clave0) == valor0);
	print_test("Prueba abb pertenece clave0, es true", abb_pertenece(arbol, clave0));
	print_test("Prueba abb borrar clave0, es valor0", abb_borrar(arbol, clave0) == valor0);
	print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

	/* Inserta otros valores y no los borra */
	print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
	print_test("Prueba abb obtener clave1 es valor1", abb_obtener(arbol, clave1) == valor1);
	print_test("Prueba abb obtener clave1 es valor1", abb_obtener(arbol, clave1) == valor1);
	print_test("Prueba abb pertenece clave1, es true", abb_pertenece(arbol, clave1));
	
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2));
	print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);
	print_test("Prueba abb obtener clave2 es valor2", abb_obtener(arbol, clave2) == valor2);
	print_test("Prueba abb obtener clave2 es valor2", abb_obtener(arbol, clave2) == valor2);
	print_test("Prueba abb pertenece clave2, es true", abb_pertenece(arbol, clave2));

	print_test("Prueba abb insertar clave3", abb_guardar(arbol, clave3, valor3));
	print_test("Prueba abb la cantidad de elementos es 3", abb_cantidad(arbol) == 3);
	print_test("Prueba abb obtener clave3 es valor3", abb_obtener(arbol, clave3) == valor3);
	print_test("Prueba abb obtener clave3 es valor3", abb_obtener(arbol, clave3) == valor3);
	print_test("Prueba abb pertenece clave3, es true", abb_pertenece(arbol, clave3));

	print_test("Prueba abb insertar clave4", abb_guardar(arbol, clave4, valor4));
	print_test("Prueba abb la cantidad de elementos es 4", abb_cantidad(arbol) == 4);
	print_test("Prueba abb obtener clave4 es valor4", abb_obtener(arbol, clave4) == valor4);
	print_test("Prueba abb obtener clave4 es valor4", abb_obtener(arbol, clave4) == valor4);
	print_test("Prueba abb pertenece clave4, es true", abb_pertenece(arbol, clave4));

	print_test("Prueba abb insertar clave5", abb_guardar(arbol, clave5, valor5));
	print_test("Prueba abb la cantidad de elementos es 5", abb_cantidad(arbol) == 5);
	print_test("Prueba abb obtener clave5 es valor5", abb_obtener(arbol, clave5) == valor5);
	print_test("Prueba abb obtener clave5 es valor5", abb_obtener(arbol, clave5) == valor5);
	print_test("Prueba abb pertenece clave5, es true", abb_pertenece(arbol, clave5));

	print_test("Prueba abb insertar clave6", abb_guardar(arbol, clave6, valor6));
	print_test("Prueba abb la cantidad de elementos es 6", abb_cantidad(arbol) == 6);
	print_test("Prueba abb obtener clave6 es valor6", abb_obtener(arbol, clave6) == valor6);
	print_test("Prueba abb obtener clave6 es valor6", abb_obtener(arbol, clave6) == valor6);
	print_test("Prueba abb pertenece clave6, es true", abb_pertenece(arbol, clave6));

	print_test("Prueba abb insertar clave7", abb_guardar(arbol, clave7, valor7));
	print_test("Prueba abb la cantidad de elementos es 7", abb_cantidad(arbol) == 7);
	print_test("Prueba abb obtener clave7 es valor7", abb_obtener(arbol, clave7) == valor7);
	print_test("Prueba abb obtener clave7 es valor7", abb_obtener(arbol, clave7) == valor7);
	print_test("Prueba abb pertenece clave7, es true", abb_pertenece(arbol, clave7));


	abb_destruir(arbol);
}

void prueba_abb_reemplazar(void)
{
	abb_t* arbol = abb_crear(strcmp, NULL);

	char *clave1 = "20", *valor1a = "-20-", *valor1b = "-020-";
	char *clave2 = "10", *valor2a = "-10-", *valor2b = "-010-";
	char *clave3 = "05", *valor3a = "-05-", *valor3b = "-005-";
	char *clave4 = "15", *valor4a = "-15-", *valor4b = "-015-";

	/* Inserta valores y luego los reemplaza */
	print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1a));
	print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
	print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2a));
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave3, valor3a));
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave3) == valor3a);
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave3) == valor3a);
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave4, valor4a));
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave4) == valor4a);
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave4) == valor4a);
	print_test("Prueba abb la cantidad de elementos es 4", abb_cantidad(arbol) == 4);

	print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(arbol, clave1, valor1b));
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
	print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(arbol, clave2, valor2b));
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
	print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(arbol, clave3, valor3b));
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave3) == valor3b);
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave3) == valor3b);
	print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(arbol, clave4, valor4b));
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave4) == valor4b);
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave4) == valor4b);
	print_test("Prueba abb la cantidad de elementos es 4", abb_cantidad(arbol) == 4);

	abb_destruir(arbol);
}

void prueba_abb_reemplazar_con_destruir(void)
{
	abb_t* arbol = abb_crear(strcmp, free);

	char *clave1 = "20", *valor1a, *valor1b;
	char *clave2 = "10", *valor2a, *valor2b;
	char *clave3 = "05", *valor3a, *valor3b;
	char *clave4 = "15", *valor4a, *valor4b;

	/* Pide memoria para 8 valores */
	valor1a = malloc(10 * sizeof(char));
	valor1b = malloc(10 * sizeof(char));
	valor2a = malloc(10 * sizeof(char));
	valor2b = malloc(10 * sizeof(char));
	valor3a = malloc(10 * sizeof(char));
	valor3b = malloc(10 * sizeof(char));
	valor4a = malloc(10 * sizeof(char));
	valor4b = malloc(10 * sizeof(char));
		

	/* Inserta 4 valores y luego los reemplaza (debe liberar lo que reemplaza) */
	print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1a));
	print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
	print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2a));
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
	print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave3, valor3a));
	print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave3) == valor3a);
	print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave3) == valor3a);
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave4, valor4a));
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave4) == valor4a);
	print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave4) == valor4a);
	print_test("Prueba abb la cantidad de elementos es 4", abb_cantidad(arbol) == 4);
	
	print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(arbol, clave1, valor1b));
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
	print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(arbol, clave2, valor2b));
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
	print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(arbol, clave3, valor3b));
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave3) == valor3b);
	print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave3) == valor3b);
	print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(arbol, clave4, valor4b));
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave4) == valor4b);
	print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave4) == valor4b);
	print_test("Prueba abb la cantidad de elementos es 4", abb_cantidad(arbol) == 4);

	/* Se destruye el abb (se debe liberar lo que quedó dentro) */
	abb_destruir(arbol);
}

void prueba_abb_borrar(void)
{
	abb_t* arbol = abb_crear(strcmp, NULL);

	char *clave1 = "20", *valor1 = "-20-";
	char *clave2 = "10", *valor2 = "-10-";
	char *clave3 = "05", *valor3 = "-05-";
	char *clave4 = "15", *valor4 = "-15-";

	/* Inserta 3 valores y luego los borra */
	print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2));
	print_test("Prueba abb insertar clave3", abb_guardar(arbol, clave3, valor3));
	print_test("Prueba abb insertar clave4", abb_guardar(arbol, clave4, valor4));

	/* Al borrar cada elemento comprueba que ya no está pero los otros sí. */
	print_test("Prueba abb pertenece clave1, es verdadero", abb_pertenece(arbol, clave1));
	print_test("Prueba abb borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
	print_test("Prueba abb borrar clave1, es NULL", !abb_borrar(arbol, clave1));
	print_test("Prueba abb pertenece clave1, es falso", !abb_pertenece(arbol, clave1));
	print_test("Prueba abb obtener clave1, es NULL", !abb_obtener(arbol, clave1));
	print_test("Prueba abb la cantidad de elementos es 3", abb_cantidad(arbol) == 3);

	print_test("Prueba abb pertenece clave2, es verdadero", abb_pertenece(arbol, clave2));
	print_test("Prueba abb borrar clave2, es valor2", abb_borrar(arbol, clave2) == valor2);
	print_test("Prueba abb borrar clave2, es NULL", !abb_borrar(arbol, clave2));
	print_test("Prueba abb pertenece clave2, es falso", !abb_pertenece(arbol, clave2));
	print_test("Prueba abb obtener clave2, es NULL", !abb_obtener(arbol, clave2));
	print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

	print_test("Prueba abb pertenece clave3, es verdadero", abb_pertenece(arbol, clave3));
	print_test("Prueba abb borrar clave3, es valor3", abb_borrar(arbol, clave3) == valor3);
	print_test("Prueba abb borrar clave3, es NULL", !abb_borrar(arbol, clave3));
	print_test("Prueba abb pertenece clave3, es falso", !abb_pertenece(arbol, clave3));
	print_test("Prueba abb obtener clave3, es NULL", !abb_obtener(arbol, clave3));
	print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(arbol) == 1);

	print_test("Prueba abb pertenece clave4, es verdadero", abb_pertenece(arbol, clave4));
	print_test("Prueba abb borrar clave4, es valor4", abb_borrar(arbol, clave4) == valor4);
	print_test("Prueba abb borrar clave4, es NULL", !abb_borrar(arbol, clave4));
	print_test("Prueba abb pertenece clave4, es falso", !abb_pertenece(arbol, clave4));
	print_test("Prueba abb obtener clave4, es NULL", !abb_obtener(arbol, clave4));
	print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

	abb_destruir(arbol);
}

void prueba_iterar_abb_vacio(void)
{
	abb_t* arbol = abb_crear(strcmp,NULL);
	abb_iter_t* iter = abb_iter_in_crear(arbol);
	print_test("Prueba abb iter in crear iterador arbol vacio", iter);
	print_test("Prueba abb iter esta al final", abb_iter_in_al_final(iter));
	print_test("Prueba abb iter avanzar es false", !abb_iter_in_avanzar(iter));
	print_test("Prueba abb iter ver actual es NULL", !abb_iter_in_ver_actual(iter));

	abb_iter_in_destruir(iter);
	abb_destruir(arbol);
}

bool guardar(const char* clave, void* dato, void* pila)
{
	return pila_apilar(pila, dato);
}

void prueba_abb_iterar(void)
{
	abb_t* arbol = abb_crear(strcmp, NULL);
	int exitos = 0;
	char *claves[14] = {"25","15","30","10","20","28","35","05","13","22","32","40","50","45"};
	const char *anterior, *actual;
	for(int i = 0; i < 14; i++)
		if (abb_guardar(arbol, claves[i], claves[i]))
			exitos++;

	print_test("Prueba abb insertar 14 elementos", exitos == 14);

	abb_iter_t* iter = abb_iter_in_crear(arbol);
	
	print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));
	
	/* Creamos una pila y almacenamos los datos en inorder, deben ir desapilandose de mayor a menor */
	pila_t* pila = pila_crear();
	abb_in_order(arbol, guardar, pila);
	exitos = 0;
	
	anterior = pila_desapilar(pila);
	while(!pila_esta_vacia(pila)){
		actual = pila_desapilar(pila);
		if(strcmp(anterior, actual) > 0)
			exitos++;
	}
	print_test("Prueba abb in order", exitos == 13);
	pila_destruir(pila);
	
	anterior = abb_iter_in_ver_actual(iter);
	print_test("Prueba iter avanzar es true", abb_iter_in_avanzar(iter));
	for (int i = 0, exitos = 0; i < 13; i++){
		actual = abb_iter_in_ver_actual(iter);
		if (strcmp(anterior, actual) < 0){
			exitos++;
			abb_iter_in_avanzar(iter);
		}
	}
	print_test("Prueba iter recorre ordenado", exitos == 13);
	print_test("Prueba iter al final es true", abb_iter_in_al_final(iter));
	print_test("Prueba iter avanzar es false", !abb_iter_in_avanzar(iter));
	
	abb_iter_in_destruir(iter);
	abb_destruir(arbol);

}

void prueba_abb_borrar2(void)
{
	abb_t* arbol = abb_crear(strcmp, NULL);
	char *claves[14] = {"50","25","30","28","35","29","32","33","80","70","71","73","72","99"};
	int *valores[14];
	printf("Se guardaran 14 elementos en el arbol\n");
	int exitos = 0;
	for (int i = 0; i < 14; i++){
		valores[i] = malloc(sizeof(int));
		if (abb_guardar(arbol, claves[i], valores[i])) exitos++;
	}

	print_test("Prueba de guardar 14 elementos", exitos == 14);

	for (int i = 13, exitos = 0; i >= 0; i--){
		if (abb_cantidad(arbol) == i && abb_borrar(arbol, claves[i])) exitos++;
		free(valores[i]);
	}

	print_test("Prueba de borrar 14 elementos", exitos == 14);

	abb_destruir(arbol);

}

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

/* Programa principal. */
int main(int argc, char** argv)
{
	prueba_crear_abb_vacio();
	prueba_iterar_abb_vacio();
	prueba_abb_guardar();
	prueba_abb_reemplazar();
	prueba_abb_reemplazar_con_destruir();
	prueba_abb_iterar();
	prueba_abb_borrar2();
	
	return 0;
}
