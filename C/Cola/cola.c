#include <stdlib.h>
#include "cola.h"

/* ******************************************************************
 *    			   Profesor: Maximiliano Curia
 * -Integrantes del grupo:                  -Padron:
 * 		Vázquez Matías..........................91523
 * *****************************************************************/


/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

typedef struct nodo{
	void* dato;
	struct nodo *prox;
}nodo_t;

struct cola{
	nodo_t* primero;
	nodo_t* ultimo;
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

// Crea una cola.
// Post: devuelve una nueva cola vacía.
cola_t* cola_crear(void)
{
	cola_t* cola = malloc(sizeof(cola_t));
	if (cola == NULL) return NULL;
	
	/* NULL a los nodos de la cola */	
	cola->primero = NULL;
	cola->ultimo = NULL;
	
	return cola;
}


// Destruye la cola. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la cola llama a destruir_dato.
// Pre: la cola fue creada. destruir_dato es una función capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la cola.
void cola_destruir(cola_t *cola, void destruir_dato(void*))
{
	/* Declaro nodo_aux para recorrer la cola y nodo_para_destruir para 
	 * guardar el nodo que será destruido. */
	nodo_t* nodo_aux = cola->primero, *nodo_para_destruir;

	while(nodo_aux)	{
		
		/* Destruimos el dato del nodo si se recibe destruir_dato */
		if (destruir_dato) destruir_dato(nodo_aux->dato);
			
		nodo_para_destruir = nodo_aux;
		nodo_aux = nodo_aux->prox;
		free(nodo_para_destruir);
	}
	free(cola);
}

// Devuelve verdadero o falso, según si la cola tiene o no elementos encolados.
// Pre: la cola fue creada.
bool cola_esta_vacia(const cola_t *cola)
{
	return (cola->primero == NULL);
}

// Agrega un nuevo elemento a la cola. Devuelve falso en caso de error.
// Pre: la cola fue creada.
// Post: se agregó un nuevo elemento a la cola, valor se encuentra al final
// de la cola.
bool cola_encolar(cola_t* cola, void* valor)
{
	/* Creamos el nuevo nodo. */
	nodo_t* nodo_nuevo = crear_nodo(valor);
	if (nodo_nuevo == NULL) return false;
	
	/*Si la cola esta vacía el nodo será el primero de la cola. */
	if (cola_esta_vacia(cola)){
		cola->primero = nodo_nuevo;
		cola->ultimo = nodo_nuevo;
	}else{
		/* Obtenemos el ultimo nodo y le agregamos el nuevo nodo al miembro prox. */
		cola->ultimo->prox = nodo_nuevo;
		cola->ultimo = nodo_nuevo;
	}
	
	return true;
}

// Obtiene el valor del primer elemento de la cola. Si la cola tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el primer elemento de la cola, cuando no está vacía.
void* cola_ver_primero(const cola_t *cola)
{
	if (cola_esta_vacia(cola)) return NULL;
	
	return cola->primero->dato;
}

// Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
// primero de la cola, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el valor del primer elemento anterior, la cola
// contiene un elemento menos, si la cola no estaba vacía.
void* cola_desencolar(cola_t *cola)
{	
	if (cola_esta_vacia(cola)) return NULL;
	
	/* Obtengo el primer dato y primer nodo. */
	void* primer_dato = cola_ver_primero(cola);
	nodo_t* primer_nodo = cola->primero;
	
	/* Asigno la primer posición al segundo nodo. */
	cola->primero = cola->primero->prox;
	free(primer_nodo);
	
	return primer_dato;
}
