#ifndef PRIM_H
#define PRIM_H
#include "grafo.h"
#include<QString>
#include<vector>
#include<map>
class Prim
{
public:
    vector<Nodo*>vertices;
    vector<Arista*>aristas;
    int *costo;
    bool *visitado;

    QString *path;
    int getMyPos(Nodo* n);
    void setTable(int nodos, Nodo* origen);
    bool checkVisited();
    Nodo* whosMinor();
    void analisis(Nodo* origen);
    multimap<int,Nodo*> setAdyacentes(Nodo* o);
    Grafo * grafo;
    Prim(Grafo* g);
};

#endif // PRIM_H
