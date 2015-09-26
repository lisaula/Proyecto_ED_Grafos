#ifndef GRAFO_H
#define GRAFO_H
#include"arista.h"
#include "nodo.h"
using namespace std;
class Grafo
{
public:
    Nodo* actual;
    int nodos, vertices;
    vector<Arista*>arcos;
    Grafo();
    void agregarNodo(int nuevo);
    void agregarArista(int inicio, int final, int valor);
    void addArco(int origen, int destino, int valor);
    Nodo *buscarNodo(int valor);
    Arista* buscarArista(Nodo* o, Nodo* d);
};

#endif // GRAFO_H
