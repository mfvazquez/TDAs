/*
 * pila.c
 *
 *  Created on: ~
 *      Author: Matías Vázquez
 *      Padron: 91523
 *      Professor: Maximiliano Curia
 */

#include <stdlib.h>
#include "pila.h"

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

typedef struct nodo{
	void* dato;
	struct nodo *prox;
}nodo_t;

struct pila{
    nodo_t* tope;
};

/* ******************************************************************
 *                        IMPLEMENTACION
 * *****************************************************************/

// Crea un nodo.
// Post: devuelve un nuevo nodo con un valor.
nodo_t* crear_nodo(void* valor)
{
	/* Defino el nodo. */
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (!nodo) return NULL;
	
	/* Asigno valores a sus respectivos miembros. */
	nodo->prox = NULL;
	nodo->dato = valor;
	
	return nodo;
}

// Crea una pila.
// Post: devuelve una nueva pila vacía.
pila_t* pila_crear(void)
{
	pila_t *pila = malloc(sizeof(pila_t));
	if (!pila) return NULL;
		
	pila->tope = NULL;		

	return pila;
}

// Destruye la pila.
// Pre: la pila fue creada.
// Post: se eliminaron todos los elementos de la pila.
void pila_destruir(pila_t *pila, void destruir_dato(void*))
{
	nodo_t* nodo_aux = pila->tope, *nodo_para_destruir;
	
	while(nodo_aux){	
		
		if (destruir_dato) destruir_dato(nodo_aux->dato);
			
		nodo_para_destruir = nodo_aux;
		nodo_aux = nodo_aux->prox;
		free(nodo_para_destruir);
	}
	
	free(pila);
}

// Devuelve verdadero o falso, según si la pila tiene o no elementos apilados.
// Pre: la pila fue creada.
bool pila_esta_vacia(const pila_t *pila)
{
	return pila->tope == NULL;
}

// Agrega un nuevo elemento a la pila. Devuelve falso en caso de error.
// Pre: la pila fue creada.
// Post: se agregó un nuevo elemento a la pila, valor es el nuevo tope.
bool pila_apilar(pila_t *pila, void* valor)
{
	nodo_t* nodo = crear_nodo(valor);
	if (!nodo) return false;
	
	nodo->prox = pila->tope;
	pila->tope = nodo;
	
	return true;
}

// Obtiene el valor del tope de la pila. Si la pila tiene elementos,
// se devuelve el valor del tope. Si está vacía devuelve NULL.
// Pre: la pila fue creada.
// Post: se devolvió el valor del tope de la pila, cuando la pila no está
// vacía, NULL en caso contrario.
void* pila_ver_tope(const pila_t *pila)
{
	if (!pila->tope) return NULL;
	return pila->tope->dato;
}

// Saca el elemento tope de la pila. Si la pila tiene elementos, se quita el
// tope de la pila, y se devuelve ese valor. Si la pila está vacía, devuelve 
// NULL.
// Pre: la pila fue creada.
// Post: si la pila no estaba vacía, se devuelve el valor del tope anterior 
// y la pila contiene un elemento menos.
void* pila_desapilar(pila_t *pila)
{
	if (!pila->tope) return NULL;
	
	nodo_t* nodo = pila->tope;
	void* dato = nodo->dato;
	pila->tope = nodo->prox;
	
	free(nodo);
	return dato;
}
