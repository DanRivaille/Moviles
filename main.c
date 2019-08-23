/**
 * Autor       : Dan Santos
 * GitHub User : github.com/DanSantosAA
 * Proposito   : Dado un movil, el programa comprueba si este esta en equilibrio, para mas info vea README.MD
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "TDA-Pila/Stack.h"

/** ----------- Tipos de Datos ----------- */
typedef struct Movil{
    int peso_izq;                                   //peso de la izquierda de un sub-movil, 0 si hay un sub-movil
    int peso_der;                                   //peso de la derecha de un sub-movil, 0 si hay un sub-movil
    int dist_izq;                                   //distancia del punto de anclaje del nodo, al peso izquierdo
    int dist_der;                                   //distancia del punto de anclaje del nodo, al peso derechp

    struct Movil *left;                              //puntero al sub-movil izquierdo, NULL si no tiene
    struct Movil *right;                             //puntero al sub-movil derecho, NULL si no tiene

}Movil;

/** --------- Prototipos --------- */
bool evaluarEquilibrio(Movil *nodo_inicial);
void leerInfo(Movil *nodo_actual);
Movil *crearNodo(void);
int pesoTotal(Movil *nodo_act);

int main()
{
    Movil *nodo_inicial = crearNodo();

    leerInfo(nodo_inicial);

    if(evaluarEquilibrio(nodo_inicial) == true)
        printf("SI");
    else
        printf("NO");

    return 0;
}

/** Funcion que evalua si el movil ingresado esta en equilibrio, si lo esta retorna true, sino false */
bool evaluarEquilibrio(Movil *nodo_inicial)
{
    Stack *pila = createStack();
    push(pila, nodo_inicial);

    while(stackCount(pila) != 0)
    {
        Movil *nodo_act = pop(pila);

        if((nodo_act->peso_izq * nodo_act->dist_izq) != (nodo_act->peso_der * nodo_act->dist_der))
            return false;

        if(nodo_act->left != NULL)
            push(pila, nodo_act->left);

        if(nodo_act->right != NULL)
            push(pila, nodo_act->right);
    }

    return true;
}

/** Procedimiento recursivo, que va leyendo la informacion de los nodos del movil. */
void leerInfo(Movil *nodo_actual)
{
    scanf("%i %i %i %i", &(nodo_actual->peso_izq), &(nodo_actual->dist_izq), &(nodo_actual->peso_der), &(nodo_actual->dist_der));

    if(nodo_actual->peso_izq == 0)
    {
        nodo_actual->left = crearNodo();
        leerInfo(nodo_actual->left);
        nodo_actual->peso_izq = pesoTotal(nodo_actual->left);
    }

    if(nodo_actual->peso_der == 0)
    {
        nodo_actual->right = crearNodo();
        leerInfo(nodo_actual->right);
        nodo_actual->peso_der = pesoTotal(nodo_actual->right);
    }
}

/** Funcion que retorna un nuevo nodo creado. */
Movil *crearNodo(void)
{
   Movil *nuevo_nodo = (Movil *) calloc(1, sizeof(Movil));

   return nuevo_nodo;
}

/** Funcion que retorna la suma de los pesos izq. y der. del nodo ingresado. */
int pesoTotal(Movil *nodo_act)
{
    return nodo_act->peso_izq + nodo_act->peso_der;
}
