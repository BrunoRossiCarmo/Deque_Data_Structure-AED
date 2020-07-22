/*
 * Deque.h
 *
 *  Created on: 22/05/2020
 *      Author: Bruno Rossi Carmo
 */

#ifndef DEQUE_H
#define DEQUE_H

//Bibliotecas necessarias para retornar string:
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef int DequeEntry; // tipo de dado colocado no Deque

class Deque
{ public:
    Deque();
    ~Deque();
    bool empty();
    bool full();
    void clear();
    void front(DequeEntry &x);
    void rear(DequeEntry &x);
    int  size();

    void appendAtRear(DequeEntry x);
    void serveAtFront(DequeEntry &x);

    void appendAtFront(DequeEntry x);
    void serveAtRear(DequeEntry &x);
    string toString();

  private:
    // Defina aqui os campos do objeto
    struct DequeNode;
    
    //Representa os ponteiros de nosso DequeNode:
    typedef DequeNode *DequePointer;
    
    //Nossa estrutura Node de Deque:
    struct DequeNode
	{ DequeEntry entry;
	  DequePointer nextNode;
	};
	
	//Ponteiro no qual ira apontar para o elemento final da fila:
	DequePointer end; 
	//Ponteiro no qual ira apontar para o elemento inicial da fila:
	DequePointer start;
	//Valor ira contar a quantidade de elementos na fila:
	int contador;

};

#endif /* DEQUE_H */

