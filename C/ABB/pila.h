/*
 * pila.c
 *
 *  Created on: ~
 *      Author: Mat�as V�zquez
 *      Padron: 91523
 *      Professor: Maximiliano Curia
 */


#ifndef PILA_H
#define PILA_H

#include <stdbool.h>

/* *****************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* Se trata de una pila que contiene datos de tipo void* 
 * (punteros gen�ricos).  La pila en s� est� definida en el .c.  */

typedef struct _pila pila_t;

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// Crea una pila.
// Post: devuelve una nueva pila vac�a.
pila_t* pila_crear();

// Destruye la pila.
// Pre: la pila fue creada.
// Post: se eliminaron todos los elementos de la pila.
void pila_destruir(pila_t *pila);

// Devuelve verdadero o falso, seg�n si la pila tiene o no elementos apilados.
// Pre: la pila fue creada.
bool pila_esta_vacia(const pila_t *pila);

// Agrega un nuevo elemento a la pila. Devuelve falso en caso de error.
// Pre: la pila fue creada.
// Post: se agreg� un nuevo elemento a la pila, valor es el nuevo tope.
bool pila_apilar(pila_t *pila, void* valor);

// Obtiene el valor del tope de la pila. Si la pila tiene elementos,
// se devuelve el valor del tope. Si est� vac�a devuelve NULL.
// Pre: la pila fue creada.
// Post: se devolvi� el valor del tope de la pila, cuando la pila no est�
// vac�a, NULL en caso contrario.
void* pila_ver_tope(const pila_t *pila);

// Saca el elemento tope de la pila. Si la pila tiene elementos, se quita el
// tope de la pila, y se devuelve ese valor. Si la pila est� vac�a, devuelve 
// NULL.
// Pre: la pila fue creada.
// Post: si la pila no estaba vac�a, se devuelve el valor del tope anterior 
// y la pila contiene un elemento menos.
void* pila_desapilar(pila_t *pila);

#endif // PILA_H
