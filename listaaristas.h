#ifndef LISTAARISTAS_H
#define LISTAARISTAS_H
#include"arista.h"
#include <iostream>
using namespace std;
class Arista;
class Nodo;
class ListaAristas
{
public:
    Arista * raiz, *final;
    Arista * buscar(int valor, Arista * raiz);
    void print(Arista *raiz);
    void agregar(int valor, Nodo* apuntado);
    bool buscarExistente(Nodo* buscado, Arista *raiz);
    ListaAristas();
};

#endif // LISTAARISTAS_H
