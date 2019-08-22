/**
 * Autor : Dan Santos
 * GitHub : github.com/DanSantosAA
 * Proposito : Dado un movil, el programa comprueba si este esta en equilibrio, para mas info vea README.MD
 */

#include <stdio.h>
#include <stdlib.h>

#include "TDA-Pila/Stack.h"

/** ----------- Tipos de Datos ----------- */
typedef struct {
    int peso_izq;                                   //peso de la izquierda de un sub-movil, 0 si hay un sub-movil
    int peso_der;                                   //peso de la derecha de un sub-movil, 0 si hay un sub-movil
    int dist_izq;                                   //distancia del punto de anclaje del nodo, al peso izquierdo
    int dist_der;                                   //distancia del punto de anclaje del nodo, al peso derechp

    struct Node *left;                              //puntero al sub-movil izquierdo, NULL si no tiene
    struct Node *right;                             //puntero al sub-movil derecho, NULL si no tiene

}Node;

/** --------- Prototipos --------- */
void leerInfo(Node *nodo_actual);
Node *crearNodo(void);
int pesoTotal(Node *nodo_act);

int main()
{



    return 0;
}

/** Procedimiento recursivo, que va leyendo la informacion de los nodos del movil. */
void leerInfo(Node *nodo_actual)
{

}

/** Funcion que retorna un nuevo nodo creado. */
Node *crearNodo(void)
{
   return NULL;
}

/** Funcion que retorna la suma de los pesos izq. y der. del nodo ingresado. */
int pesoTotal(Node *nodo_act)
{
    return 0;
}
