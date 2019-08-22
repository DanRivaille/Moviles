/**
 MIT License
 
 Copyright (c) 2018 Matias Barrientos.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef Stack_h
#define Stack_h

typedef struct Stack Stack;

/**
 Crea un puntero de tipo Stack e inicializa sus variables.

 @return Puntero al nuevo Stack.
 */
Stack * createStack(void);

/**
 Inserta un elemento en la parte superior del Stack.
 
 Complejidad: O(1)

 @param stack Puntero al Stack.
 @param data Puntero al dato que quiere ser insertado en el Stack.
 */
void push(Stack * stack, const void * data);

/**
 Elimina el elemento en la parte superior del Stack y retorna el puntero del elemento eliminado.
 
 Complejidad: O(1)

 @param stack Puntero al Stack.
 @return Puntero al objeto en la parte superior del Stack.
 */
void * pop(Stack * stack);

/**
 Retorna el elemento de la parte superior del Stack sin eliminarlo del Stack.
 
 Complejidad: O(1)

 @param stack Puntero al Stack.
 @return Puntero al objeto en la parte superior del Stack.
 */
void * top(Stack * stack);

/**
 Devuelve la cantidad de elementos en el Stack.
 
 Complejidad: O(1)

 @param stack Puntero al Stack.
 @return La cantitdad de elementos en el stack.
 */
long stackCount(Stack * stack);

/**
 Prueba si el Stack está vacía.
 
 Complejidad: O(1)

 @param stack Puntero al Stack.
 @return 1 (true) si y solo si el Stack no contiene elementos; 0 (false) lo contrario.
 */
int emptyStack(Stack * stack);

/**
 Elimina todo los elementos del Stack, pero no los libera de la memoria.
 
 Complejidad: O(n)

 @param stack Puntero al Stack.
*/
void removeAllStack(Stack * stack);

#endif /* Stack_h */
