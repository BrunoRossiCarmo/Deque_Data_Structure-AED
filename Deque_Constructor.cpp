/*
 * Deque.cpp
 *
 *  Created on: 22/05/2020
 *      Author: Bruno Rossi Carmo
 *  Obs: Foi optado utilizar como nome dos ponteiros principais como "start" e "end", diferente de "head" e "tail".
 *  Obs2: O ponteiro "start" representa o "front", enquanto o ponteiro "end" representa nosso "rear".
 */
#include "Deque.h"
#include<string.h>
#include<sstream>

// pre: nenhuma
// pos: Deque criado vazio (sem elementos)
// Pior caso O(1) -> parametro constante de complexidade. 
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
Deque::Deque()

{ contador = 0;                   //Para iniciar, zeramos o contador e direcionamos os ponteiros para o espaco das operacoes.
  end = start = NULL;             //Aterramos os ponteiros iniciais.
}

// pre: Deque criado
// pos: Deque eh destruido, liberando espaço ocupado pelos seus elementos
// Pior caso O(n) -> parametro linear de complexidade, onde n é o tamanho do Deque.
//Como foi utilizado uma operacao dependente do tamanho do Deque, entao eh um complexidade linear.
Deque::~Deque()

{  clear();                       //Deleta tudo para evitar vazamento de memoria.
}

// pre: Deque criado
// pos: retorna true se o deque esta vazio; false caso contrario
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
bool Deque::empty()

{ return(start == NULL);         //Como start (front) é nosso ponteiro que ficara no primeiro Node, entao se ele for NULL, nao tera nenhum elemento na Lista
}

// pre: Deque criado
// pos: retorna true se o deque esta cheio; false caso contrario
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
bool Deque::full()

{ return false;                  //Nao existe limites em implementacao dinamica.
}

// pre: Deque nao estah cheio
// pos: O item x eh armazenado no inicio do deque
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
void Deque::appendAtFront(int x)

{ DequePointer iniciador;
  iniciador = new DequeNode;    //Vai criar Node para receber a carga X.
  
  if(iniciador == NULL)         //Caso memoria seja insuficiente.
  { cout << "\nMemoria Nao Suficiente\n";
    abort();
  }
  
  iniciador->entry = x;         //Recebe como carga de Node o valor X.
  
  if(empty())                   //Caso seja o primeiro elemento inserido no Deque.
  { end = start = iniciador;
    end->nextNode = NULL;
  }
  
  else                          //Caso nao for o primeiro elemento inserido.
  { DequePointer auxiliar;
    auxiliar = iniciador; 
    auxiliar->nextNode = start; 
    start = auxiliar; 
  }
  
  contador++;                   //Soma ao size.
}

// pre: Deque nao estah cheio
// pos: O item x eh armazenado no final do deque
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
void Deque::appendAtRear(int x)

{ DequePointer iniciador; 
  iniciador = new DequeNode;    //Vai criar Node para receber a carga X.
  
  if(iniciador == NULL)         //Caso memoria seja insuficiente.
  { cout << "\nMemoria Nao Suficiente\n";
    abort();
  }
  iniciador->entry = x;         //Recebe como carga de Node o valor X.
  
  if(empty())                   //Caso seja o primeiro elemento inserido no Deque.
  { end = start = iniciador;
  }
  
  else                          //Caso nao for o primeiro elemento sendo inserido.
  { end->nextNode = iniciador; 
    end = end->nextNode; 
  }
  
  end->nextNode = NULL; 
  contador++;                   //Soma ao size.
}

// pre: Deque nao vazio
// pos: O item do inicio do deque eh removido e seu valor eh retornado na variavel x
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
void Deque::serveAtFront(int &x)

{ if(empty())                   //Caso nao tenha nenhum elemento:
  { cout << "\nNao existe nada para ser retirado\n";
    abort();
  }
  
  front(x);                    //X ira receber o valor do elemento na carga do Node front.
  
  DequePointer auxiliar;      //Ira ser nosso ponteiro de auxilio.
  auxiliar = start; 
  
  if(end == start)            //Caso fosse o mesmo elemento.
  { delete auxiliar;
    end = start = NULL;
  }
  
  else                        //Caso tivesse mais que um elemento.
  { start=start->nextNode; 
    delete auxiliar;
  }
  
  contador--;                 //Decrementa o size.
}

// pre: Deque nao vazio
// pos: O item do final do deque eh removido e seu valor eh retornado na variavel x
// Pior caso O(n) -> parametro linear de complexidade, onde n é o tamanho do Deque.
//Como foi utilizado uma operacao dependente do tamanho do Deque, entao eh um complexidade linear.
void Deque::serveAtRear(int &x)

{ if(empty())                 //Caso nao tenha nenhum elemento:
  { cout << "\nNao existe nada para ser retirado\n";
    abort();
  }
  
  rear(x);                    //X ira receber o valor do elemento na carga do Node rear.
  
  DequePointer auxiliar;      //Ira ser nosso ponteiro de auxilio.
  auxiliar = start;
  
  if(start == end)            //Caso tenha apenas um elemento.
  { delete auxiliar;
    end = start = NULL;
  }
  
  else                                              //Caso tenha varios.
  {   while(auxiliar->nextNode!=end)                //Encontrar o anterior do nosso Rear.
	  { auxiliar = auxiliar->nextNode;
	  }
	  end = auxiliar;
	  auxiliar = auxiliar->nextNode;
	  delete auxiliar;
	  end->nextNode = NULL; 
  }
  
  contador--;                 //Decrementa o size.
}

// pre: Deque criado
// pos: Todos os itens do deque sao descartados e ele se torna um deque vazio
// Pior caso O(n) -> parametro linear de complexidade, onde n é o tamanho do Deque.
//Como foi utilizado uma operacao dependente do tamanho do Deque, entao eh um complexidade linear.
void Deque::clear()

{
  int x;
  while(! empty())            //Enquanto nao chegar no Node end, eliminara os elementos que permanecem antes.
  { serveAtRear(x);
  }
  contador = 0;               //Zera todo o contador (size).
}

// pre: deque nao estah vazio
// pos:  x recebe uma copia do item que se encontra no inicio do deque; o deque permanece inalterado
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
void Deque::front(int &x)

{ if(empty())                 //Se estiver vazio.
  { cout << "\nNao existe nada para ser recebido\n";
    return;
  }
  
  x = start->entry;           //X recebe o valor da carga de front.
}

// pre: deque nao estah vazia
// pos:  x recebe uma copia do item que se encontra no final do deque; o deque permanece inalterado
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
void Deque::rear(int &x)

{ if(empty())                //Se estiver vazio.
  { cout << "\nNao existe nada para ser recebido\n";
    abort();
  }
  
  x = end->entry;            //X recebe o valor da carga de rear.
}

// pre: Deque criado
// pos: retorna o numero de itens no deque
// Pior caso O(1) -> parametro constante de complexidade.
//Como nao foi utilizado nenhuma operacao dependente do tamanho do Deque, o parametro de complexidade eh constante.
int Deque::size()

{ return contador;           //Retorna o contador, que de modo geral, nos mostra o tamanho do Deque.
}

// pre: Deque criado
// pos: retorna o deque como string, um elemento apos o outro, iniciando pelo comeco do deque
//      Os elementos sao separados por um unico espaco e nao deve haver espacos adicionais no
//      inicio nem no final da string retornada
// Pior caso O(n) -> parametro linear de complexidade, onde n é o tamanho do Deque.
//Como foi utilizado uma operacao dependente do tamanho do Deque, entao eh um complexidade linear.
string Deque::toString()

{ DequePointer auxiliar; 
  auxiliar = start;          //Inicia no front do Deque.
  
  string total_elements;     //String total com elementos.
  stringstream elements;     //Recebe elemento por elemento.
 
  while(auxiliar!=NULL)      //Transfere os elementos para string.
  { elements << auxiliar->entry << " ";
    auxiliar = auxiliar->nextNode;
  }
 
  total_elements = elements.str();                            //Junta as string dos elementos.
  return total_elements.substr(0,total_elements.length()-1) ; 
  //Retorna a string desde seu primeiro elemento ate o penultimo, pois o ultimo elemento de uma string eh o elemento 0 que demarca seu fim.
}

