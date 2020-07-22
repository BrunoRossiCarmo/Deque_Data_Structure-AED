#include "Deque.h"
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{Deque A,B,C,J, D;
 DequeEntry x;		
 A.appendAtRear(1);
 A.appendAtRear(2);
 A.appendAtRear(3);
 cout << "A: (" << A.toString() << ")" << endl;
 A.serveAtRear(x);
 cout << A,size() << endl;
 cout << "A: (" << A.toString() << ")" << endl;
 cout << "x: " << x << endl << endl;
 C.appendAtRear(23);
 C.appendAtRear(33);
 C.appendAtRear(43);
 cout << "C: (" << C.toString() << ")" << endl;
 C.serveAtFront(x);
 cout << "C: (" << C.toString() << ")" << endl;
 cout << "x: " << x << endl << endl;
 J.appendAtFront(35);
 J.appendAtFront(45);
 J.appendAtFront(55);
 cout << "D: (" << J.toString() << ")" << endl;
 J.serveAtRear(x);
 cout << "D: (" << J.toString() << ")" << endl;
 cout << "x: " << x << endl << endl;
 J.appendAtFront(35);
 J.appendAtFront(45);
 J.appendAtFront(55);
 J.appendAtRear(43);
 cout << "D: (" << J.toString() << ")" << endl;
 J.clear();
 cout << "D: (" << J.toString() << ")" << endl;
 return 0;
 
}

