#include "arista.h"

void Arista::setIntree(bool v)
{
    intree=v;
}

Arista::Arista(int valor, Nodo* destino)
{
    this->valor=valor;
    apuntoA=destino;
    sig=NULL;
    intree=false;
}

Arista::Arista(int valor, Nodo *origen, Nodo *destino)
{
    this->valor=valor;
    apuntoA=destino;
    this->origen=origen;
    intree=false;
}

