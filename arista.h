#ifndef ARISTA_H
#define ARISTA_H

#include <iostream>
#include <nodo.h>

class Nodo;

class Arista
{
public:
    int valor;
    bool intree;
    Nodo *apuntoA;
    Nodo* origen;
    Arista *sig;
    void setIntree(bool v);
    Arista(int valor, Nodo* destino);
    Arista(int valor, Nodo* origen, Nodo *destino);
};

#endif // ARISTA_H

