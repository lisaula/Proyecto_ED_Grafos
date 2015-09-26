#ifndef NODO_H
#define NODO_H

#include <iostream>
#include<vector>
#include "listaaristas.h"
#include<QString>

using namespace std;
class Arista;
class ListaAristas;
class Nodo
{
public:
    int valor;
    int tree;
    bool visitado=false;
    vector<Arista*>arcos;
    Arista* seekArista(Nodo *d);
    void addArco(Arista*);
    QString imprimirArcos();
    void setTree(int v);
    Nodo *Ady;
    void printArcos();
    ListaAristas* aristas;
    Nodo(int valor);
    Nodo();
};

#endif // NODO_H
