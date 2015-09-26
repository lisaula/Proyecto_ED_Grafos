#include "listaaristas.h"

Arista *ListaAristas::buscar(int valor, Arista *raiz)
{
    if(raiz){
        if(raiz->valor==valor){
            return raiz;
        }else{
            return buscar(valor,raiz->sig);
        }
    }
    return NULL;
}

void ListaAristas::print(Arista *raiz)
{
 if(raiz){
     cout<<"\t";
     cout<<"Apunto a: "<<raiz->apuntoA->valor<<" Peso: "<<raiz->valor<<endl;
     print(raiz->sig);
 }
}

void ListaAristas::agregar(int valor, Nodo *apuntado)
{
    if(raiz){
        final->sig = new Arista(valor,apuntado);
        final = final->sig;
    }else{
        raiz = new Arista(valor,apuntado);
        final = raiz;
    }
}

bool ListaAristas::buscarExistente(Nodo *buscado, Arista *raiz)
{
    Arista * temp = raiz;
    if(temp){
        if(temp->apuntoA==buscado){
            return true;
        }
        return buscarExistente(buscado,temp->sig);
    }
        return false;




}

ListaAristas::ListaAristas()
{
    raiz=NULL;
    final=NULL;
}

