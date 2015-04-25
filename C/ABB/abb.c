/*
 * abb.c
 *
 *  Created on: 10/10/2011
 *      Author: Matías Vázquez
 *      Padron: 91523
 *      Professor: Maximiliano Curia
 */

#include "abb.h"
#include <stdlib.h>
#include <string.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * ******************************************************************/
typedef struct nodo{
	void* dato;
	char* clave;
	struct nodo* izq;
	struct nodo* der;
}nodo_t;

struct abb{
	nodo_t* raiz;
	size_t cantidad;
	abb_comparar_clave_t cmp;
	abb_destruir_dato_t destruir_dato;
};

struct abb_iter{
	pila_t* pila;
};


/* ******************************************************************
 * 					FUNCIONES AUXILIARES
 * ******************************************************************/

/*
 * Crea el nodo, guardando sus datos, y hace una copia de la clave.
 * Pre: ~
 * Post: Se devolvió un puntero a nodo.
 */
nodo_t* nodo_crear(const char* clave, void* dato)
{
	size_t len = strlen(clave);

	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (!nodo) return NULL;

	nodo->clave = malloc( (len + 1) * sizeof(char) );
	if ( !nodo->clave ){
		free(nodo);
		return NULL;
	}

	for( int i = 0; i < len; i++ )
		nodo->clave[i] = clave[i];
	nodo->clave[len] = '\0';
	nodo->dato = dato;
	nodo->izq = NULL;
	nodo->der = NULL;

	return nodo;
}

/*
 * Libera el espacio de memoria recervado por el nodo, y devuelve
 * su dato
 * Pre: EL nodo fué creado.
 * Post: Se liberó espacio en memoria y se devolvió el dato.
 */
void* nodo_destruir(nodo_t* nodo)
{
	void* dato = nodo->dato;
	free(nodo->clave);
	free(nodo);
	return dato;
}

/*
 * Funcion que recorre el abb, en busca del nodo con la clave ingresada,
 * y asigna ese nodo al puntero actual, y guardara en actual_cmp la
 * comparación de la clave del nodo actual y la clave ingresada.
 * De ser distintos de NULL, anterior apuntará al nodo anterior a actual,
 * y guardará en anterior_cmp la comparación de la clave del nodo anterior
 * y la clave ingresada.
 * Pre: el arbol fue creado, los punteros actual y actual_cmp deben estar
 * creados.
 * Post: el puntero actual apunta a un nodo y actual_cmp guardó el valor
 * de la comparación, tambien se guardó el nodo anterior y la comparación
 * anterior en caso de ser requerido.
 */
void nodo_obtener(const abb_t* arbol, const char* clave, nodo_t** actual, int* actual_cmp, nodo_t** anterior, int* anterior_cmp)
{
	if (anterior) *anterior = NULL;

	if (!arbol->raiz){
		*actual = NULL;
		return;
	}
	*actual = arbol->raiz;
	*actual_cmp = arbol->cmp((*actual)->clave, clave);
	while ((*actual_cmp > 0 && (*actual)->izq) || (*actual_cmp < 0 && (*actual)->der)){
		if (anterior) *anterior = *actual;
		if (anterior_cmp) *anterior_cmp = *actual_cmp;

		if ( *actual_cmp > 0 ) *actual = (*actual)->izq;
		else if(*actual_cmp < 0 ) *actual = (*actual)->der;

		*actual_cmp = arbol->cmp((*actual)->clave, clave);
	}
}

/*
 * Funcion recursiva que recorre los nodos en preorder y le aplica la
 * funcion a los datos.
 * Pre: el nodo fue creado.
 * Post: Se destruyeron todos los nodos y datos.
 */
void destruir_nodos_postorder(nodo_t* nodo, abb_destruir_dato_t destruir_dato)
{
	if(!nodo) return;
	destruir_nodos_postorder(nodo->izq, destruir_dato);
	destruir_nodos_postorder(nodo->der, destruir_dato);
	void* dato = nodo_destruir(nodo);
	if (destruir_dato) destruir_dato(dato);
}

/*
 * Funcion recursiva que recorre los nodos en inorder y le aplica la
 * funcion a los nodos.
 * Pre: El nodo fue creado y la funcion declarada.
 * Post: Se aplico la funcion a cada nodo del arbol.
 */
void nodos_recorrer_inorder(nodo_t* nodo, bool funcion(const char *, void *, void *), void* extra)
{
	if (!nodo) return;
	nodos_recorrer_inorder(nodo->izq, funcion, extra);
	funcion(nodo->clave, nodo->dato, extra);
	nodos_recorrer_inorder(nodo->der, funcion, extra);
}


/* ******************************************************************
 *                 PRIMITIVAS  BASICAS DEL ABB
 * ******************************************************************/

/*
 * Crea un abb y guarda las funciones cmp y destruir_dato.
 * Pre: cmp y destruir_dato deben estar declaradas.
 * Post: se devolvió un abb y se guardaron las funciones.
 */
abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato)
{
	abb_t* arbol = malloc(sizeof(abb_t));
	if (!arbol) return NULL;

	arbol->raiz = NULL;
	arbol->cantidad = 0;
	arbol->cmp = cmp;
	arbol->destruir_dato = destruir_dato;

	return arbol;
}

/*
 * Guarda el dato ingresado en el abb y devuelve true. En caso de error
 * devuelve false.
 * Pre: El abb debe estar creado.
 * Post: Se guardó un dato en el abb y se devolvió true, o false en caso de error.
 */
bool abb_guardar(abb_t *arbol, const char *clave, void *dato)
{
	int cmp;
	nodo_t* nodo = NULL;
	nodo_obtener(arbol, clave, &nodo, &cmp, NULL, NULL);

	if ( nodo && cmp == 0){
		if (arbol->destruir_dato) arbol->destruir_dato(nodo->dato);
		nodo->dato = dato;
	}else{
		nodo_t* nodo_nuevo = nodo_crear(clave, dato);
		if (!nodo_nuevo) return false;

		if (!nodo) arbol->raiz = nodo_nuevo;
		else if (cmp > 0) nodo->izq = nodo_nuevo;
		else nodo->der = nodo_nuevo;

		arbol->cantidad++;
	}
	return true;
}

/*
 * Borra del abb el dato correspondiente a la clave ingresada y lo devuelve.
 * En caso de no encontrarse el dato, devuelve NULL.
 * Pre: El abb fue creado.
 * Post: Se borró del abb el dato correspondiente a la clave ingresada y fue
 * devuelto, en caso de no encontrarse se devolvió NULL.
 */
void *abb_borrar(abb_t *arbol, const char *clave)
{
	int cmp_actual, cmp_anterior;
	nodo_t *actual = NULL, *anterior = NULL;

	nodo_obtener(arbol, clave, &actual, &cmp_actual, &anterior, &cmp_anterior);
	
	if (!actual || cmp_actual != 0) return NULL; // el arbol está vacío o no se encuentra la clave
	
	if (!actual->izq && !actual->der){ // el nodo no tiene hijos
		if (anterior){
			if (cmp_anterior > 0) anterior->izq = NULL;
			else anterior->der = NULL;
		}else
			arbol->raiz = NULL;

	}else if (actual->izq && actual->der){ // el nodo tiene 2 hijos
		nodo_t *mayor = actual->izq, *ant_mayor = NULL;
		while(mayor->der){
			ant_mayor = mayor;
			mayor = mayor->der;
		}
		if (mayor->izq && ant_mayor) ant_mayor->der = mayor->izq;
		else if (ant_mayor) ant_mayor->der = NULL;

		mayor->der = actual->der;
		if (actual->izq != mayor) mayor->izq = actual->izq;

		if (anterior){
			if (cmp_anterior > 0) anterior->izq = mayor;
			else anterior->der = mayor;
		}else{
			arbol->raiz = mayor;
		}

	}else if (actual->izq && !actual->der){ // el nodo solo tiene un hijo izquierdo
		if (anterior){
			if (cmp_anterior < 0) anterior->der = actual->izq;
			else anterior->izq = actual->izq;
		}else arbol->raiz = actual->izq;

	}else{ // el nodo solo tiene un hijo derecho
		if(anterior){
			if (cmp_anterior < 0) anterior->der = actual->der;
			else anterior->izq = actual->der;
		}else arbol->raiz = actual->der;
	}

	arbol->cantidad--;
	return nodo_destruir(actual);
}

/*
 * Devuelve el dato guardado en el abb correspondiente a la clave
 * ingresada. En caso de no encontrarse la clave devuelve, NULL.
 * Pre: El abb fue creado.
 * Post: Se devolvió el dato correspondiente a la clave ingresada, en caso
 * de no encontrarse se devolvió NULL.
 */
void *abb_obtener(const abb_t *arbol, const char *clave)
{
	nodo_t* nodo = NULL, **nodo_aux = &nodo;
	int cmp;
	nodo_obtener(arbol, clave, nodo_aux, &cmp, NULL, NULL);
	nodo = *nodo_aux;

	if (!nodo) return NULL; // arbol vacío

	return (cmp == 0)? nodo->dato : NULL;
}

/*
 * Devuelve true si se encuentra un dato en el abb correspondiente
 * a la clave ingresada, en caso de no encontrarse devuelve false.
 * Pre: El abb fue creado.
 * Post: Se devolvió true si se encontró un dato en el abb correspondiente
 * a la clave, caso contrario se devolvió false
 */
bool abb_pertenece(const abb_t *arbol, const char *clave)
{
	return ( abb_obtener(arbol, clave) != NULL );
}

/*
 * Devuelve la cantidad de elementos guardados en el abb.
 * Pre: El abb fue creado.
 * Post: Se devolvió la cantidad de elementos almacenados en el abb.
 */
size_t abb_cantidad(abb_t *arbol)
{
	return arbol->cantidad;
}

/*
 * Destruye el abb y aplica la función destruir_dato a cada dato almacenado
 * en el abb.
 * Pre: El abb fue creado.
 * Post: Se liberó el espacio ocupado en la memoria por el abb.
 */
void abb_destruir(abb_t *arbol)
{
	destruir_nodos_postorder(arbol->raiz, arbol->destruir_dato);
	free(arbol);
}

/* *****************************************************************
 *                PRIMITIVAS  BASICAS DE ITERACIÓN
 * *****************************************************************/

/*
 * Recorre el abb en inorder, aplicandole a todos los datos la funcion
 * pasada por parametro.
 * Pre: La función debe estar definida.
 * Post: Se aplico la funcion a cada dato del abb.
 */
void abb_in_order(abb_t *arbol, bool funcion(const char *, void *, void *), void *extra)
{
	nodos_recorrer_inorder(arbol->raiz, funcion, extra);
}

/*
 * Crea un iterador en el abb. Recorrerá el arbol en inorder.
 * Devuelve NULL en caso de error.
 * Pre: EL arbol fue creado.
 * Post: Se devolvió un iterador, o NULL en caso de error.
 */
abb_iter_t *abb_iter_in_crear(const abb_t *arbol)
{
	abb_iter_t* iter = malloc(sizeof(abb_iter_t));
	if (!iter) return NULL;

	iter->pila = pila_crear();
	nodo_t* nodo = arbol->raiz;
	if (nodo){ 
		pila_apilar(iter->pila, nodo);
		while(nodo->izq){
			pila_apilar(iter->pila, nodo->izq);
			nodo = nodo->izq;
		}
	}
	return iter;
}

/*
 * Avanza el iterador a la siguiente posición y devuelve true.
 * Devuelve false si ya se encuentra al final del arbol.
 * Pre: el iterador fue creado.
 * Post: Se devolvió true y el iter avanzó de posición, o bien
 * se devolvió false.
 */
bool abb_iter_in_avanzar(abb_iter_t *iter)
{
	nodo_t* nodo = pila_desapilar(iter->pila);
	if(!nodo) return false;

	if(nodo->der){
		nodo = nodo->der;
		pila_apilar(iter->pila, nodo);
		while(nodo->izq){
			nodo = nodo->izq;
			pila_apilar(iter->pila, nodo);
		}
	}
	return true;
}

/*
 * Devuelve la clave del nodo en el que esta posicionado el iterador
 * o NULL si ya se encuentra al final.
 * Pre: El iter fue creado.
 * Post: Se devolvió la clave del nodo actual o NULL si el iter está al final.
 */
const char *abb_iter_in_ver_actual(const abb_iter_t *iter)
{
	nodo_t* nodo = pila_ver_tope(iter->pila);
	if (!nodo) return NULL;
	return nodo->clave;
}

/*
 * Devuelve true si el iter está al final del abb, false en caso contrario.
 * Pre: El iter fue creado.
 * Post: se devolvio true o false, segun corresponda.
 */
bool abb_iter_in_al_final(const abb_iter_t *iter)
{
	return pila_esta_vacia(iter->pila);
}

/*
 * Destruye el iter, liberando el espacio de la memoria reservado.
 * Pre: El iter fue creado.
 * Post: se destruyó el iter.
 */
void abb_iter_in_destruir(abb_iter_t* iter)
{
	pila_destruir(iter->pila);
	free(iter);
}
