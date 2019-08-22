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

#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
};

struct Stack {
    Node * head;
    long count;
};

static Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    
    assert(new != NULL);
   
    new->data = data;
    new->next = NULL;
    
    return new;
}

Stack * createStack() {
    Stack * new = (Stack *)malloc(sizeof(Stack));
    
    assert(new != NULL);

    new->head = NULL;
    new->count = 0;
    
    return new;
}

void push(Stack * stack, const void * data) {
    assert(stack != NULL);
    
    Node * new = createNode(data);
    
    if (stack->head != NULL) {
        new->next = stack->head;
    }
    
    stack->head = new;
    stack->count += 1;
}

void * pop(Stack * stack) {
    assert(stack != NULL);

    if (stack->head == NULL) return NULL;
    
    Node * aux = stack->head;
    
    void * data = (void *)aux->data;
    
    stack->head = stack->head->next;
    
    free(aux);
    
    stack->count -= 1;
    
    return data;
}

void * top(Stack * stack) {
    assert(stack != NULL);

    if (stack->head == NULL) return NULL;
    
    return (void *)stack->head->data;
}

long stackCount(Stack * stack) {
    assert(stack != NULL);

    if (stack->head == NULL) return 0;
    
    return stack->count;
}

int emptyStack(Stack * stack) {
    assert(stack != NULL);
    return stack->count == 0;
}

void removeAllStack(Stack * stack) {
    assert(stack != NULL);
    
    while (stack->head != NULL) {
        pop(stack);
    }    
}
