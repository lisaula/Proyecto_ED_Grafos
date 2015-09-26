#ifndef NODOC_H
#define NODOC_H
#include <iostream>
#include "arista.h"
class NodoC
{
public:
    Arista* valor;
    NodoC* next, *prev;
    NodoC(Arista * a);
};

#endif // NODOC_H
