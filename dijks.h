#ifndef DIJKS_H
#define DIJKS_H
#include "grafo.h"
#include <QString>
#include <map>
#include<iostream>
using namespace std;
class Dijks
{
public:
    Grafo * grafo;
    vector<Nodo*>vertices;
    bool *visitado;
    int *distancia;
    QString *path;
    multimap<int,Nodo*>adyacentes;
    Dijks(Grafo * g);
    void setTabla(int nodos, Nodo *origen);
    void Analisis(Nodo *origen);
    void setcambio(Nodo* actual, Nodo* ady, int peso);
    Nodo* whosMinor();
    bool checkVisited();
    int getMyPos(Nodo *n);
    multimap<int, Nodo *> setAdyacentes(Nodo *o, vector<Arista*> aristas);
    int cont;
};

#endif // DIJKS_H
