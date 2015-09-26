#ifndef FLOYD_H
#define FLOYD_H
#include "grafo.h"
#include <iostream>
#include <vector>
#include <map>
class Floyd
{
public:
    Grafo * grafo;
    vector<Nodo*>vertices;
    int **tabla, **p;
    void setTabla(int nodos);
    void setValues();
    int getMyPos(Nodo* n);
    void analisis();
    multimap<int,Nodo*>sortNodes(Nodo* o);
    void print(int o, int d);
    void camino(int origen, int destino);
    void printTabla();
    QString imprimirTabla();
    QString imprimirP();
    void printP();
    multimap<int, Nodo *> setAdyacentes(Nodo *o);
    Floyd(Grafo * g);
};

#endif // FLOYD_H
