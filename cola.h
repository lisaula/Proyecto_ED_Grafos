#ifndef COLA_H
#define COLA_H
#include"nodoc.h"
#include<QString>
using namespace std;
class Cola
{
public:
    int s;
    NodoC* root, *end;
    void push(Arista* valor);
    NodoC* pop();
    NodoC* first();
    void limpiar();
    void anular();
    int size();
    QString imprimir();
    Cola();

};

#endif // COLA_H
