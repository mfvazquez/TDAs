/*
 * abb.h
 *
 *  Created on: 10/10/2011
 *      Author: Matías Vázquez
 *      Padron: 91523
 *      Professor: Maximiliano Curia
 */

#ifndef ABB_H_
#define ABB_H_

#include <stdbool.h>
#include <stddef.h>
#include "pila.h"

/* *****************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/*
 * Nota: Utilizaremos de ahora en adelante la abreviatura abb para
 * referirnos a un árbol binario de búsqueda.
 */

typedef struct abb abb_t;

/*
 * Tipo de función que compara dos arreglos de caracteres,
 * devuelve 1 si el primer arreglo es mayor, 0 si son iguales
 * o -1 en caso de que el segundo sea mayor.
 */
typedef int (*abb_comparar_clave_t) (const char *, const char *);

/*
 * Tipo de función que destruye los datos guardados en el abb.
 */
typedef void (*abb_destruir_dato_t) (void *);

typedef struct abb_iter abb_iter_t;

/* *****************************************************************
 *                 PRIMITIVAS  BASICAS DEL ABB
 * *****************************************************************/

/*
 * Crea un abb y guarda las funciones cmp y destruir_dato.
 * Pre: cmp y destruir_dato deben estar declaradas.
 * Post: se devolvió un abb y se guardaron las funciones.
 */
abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato);

/*
 * Guarda el dato ingresado en el abb y devuelve true. En caso de error
 * devuelve false.
 * Pre: El abb debe estar creado.
 * Post: Se guardó un dato en el abb y se devolvió true, o false en caso de error.
 */
bool abb_guardar(abb_t *arbol, const char *clave, void *dato);

/*
 * Borra del abb el dato correspondiente a la clave ingresada y lo devuelve.
 * En caso de no encontrarse el dato, devuelve NULL.
 * Pre: El abb fue creado.
 * Post: Se borró del abb el dato correspondiente a la clave ingresada y fue devuelto,
 * en caso de no encontrarse se devolvió NULL.
 */
void *abb_borrar(abb_t *arbol, const char *clave);

/*
 * Devuelve el dato guardado en el abb correspondiente a la clave
 * ingresada. En caso de no encontrarse la clave devuelve, NULL.
 * Pre: El abb fue creado.
 * Post: Se devolvió el dato correspondiente a la clave ingresada, en caso
 * de no encontrarse se devolvió NULL.
 */
void *abb_obtener(const abb_t *arbol, const char *clave);

/*
 * Devuelve true si se encuentra un dato en el abb correspondiente
 * a la clave ingresada, en caso de no encontrarse devuelve false.
 * Pre: El abb fue creado.
 * Post: Se devolvió true si se encontró un dato en el abb correspondiente
 * a la clave, caso contrario se devolvió false
 */
bool abb_pertenece(const abb_t *arbol, const char *clave);

/*
 * Devuelve la cantidad de elementos guardados en el abb.
 * Pre: El abb fue creado.
 * Post: Se devolvió la cantidad de elementos almacenados en el abb.
 */
size_t abb_cantidad(abb_t *arbol);

/*
 * Destruye el abb y aplica la función destruir_dato a cada dato almacenado
 * en el abb.
 * Pre: El abb fue creado.
 * Post: Se liberó el espacio ocupado en la memoria por el abb.
 */
void abb_destruir(abb_t *arbol);

/* *****************************************************************
 *                PRIMITIVAS  BASICAS DE ITERACIÓN
 * *****************************************************************/

/*
 * Recorre el abb en inorder, aplicandole a todos los datos la funcion pasada por parametro.
 * Pre: La función debe estar definida.
 * Post: Se aplico la funcion a cada dato del abb.
 */
void abb_in_order(abb_t *arbol, bool funcion(const char *, void *, void *), void *extra);

/*
 * Crea un iterador en el abb. Recorrerá el arbol en inorder.
 * Devuelve NULL en caso de error.
 * Pre: EL arbol fue creado.
 * Post: Se devolvió un iterador, o NULL en caso de error.
 */
abb_iter_t *abb_iter_in_crear(const abb_t *arbol);

/*
 * Avanza el iterador a la siguiente posición y devuelve true.
 * Devuelve false si ya se encuentra al final del arbol.
 * Pre: el iterador fue creado.
 * Post: Se devolvió true y el iter avanzó de posición, o bien
 * se devolvió false.
 */
bool abb_iter_in_avanzar(abb_iter_t *iter);

/*
 * Devuelve la clave del nodo en el que esta posicionado el iterador
 * o NULL si ya se encuentra al final.
 * Pre: El iter fue creado.
 * Post: Se devolvió la clave del nodo actual o NULL si el iter está al final.
 */
const char *abb_iter_in_ver_actual(const abb_iter_t *iter);

/*
 * Devuelve true si el iter está al final del abb, false en caso contrario.
 * Pre: El iter fue creado.
 * Post: se devolvio true o false, segun corresponda.
 */
bool abb_iter_in_al_final(const abb_iter_t *iter);

/*
 * Destruye el iter, liberando el espacio de la memoria reservado.
 * Pre: El iter fue creado.
 * Post: se destruyó el iter.
 */
void abb_iter_in_destruir(abb_iter_t* iter);

#endif /* ABB_H_ */
