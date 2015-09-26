#include "grafo.h"


Grafo::Grafo()
{
    actual = NULL;
    nodos=0;
    vertices=0;
}

void Grafo::agregarNodo(int valor)
{
    Nodo* nuevo= new Nodo(valor);
    if(!actual){
        actual = nuevo;
    }else{
        Nodo *tmp = actual;
        while(tmp->Ady){
            tmp=tmp->Ady;
        }
        tmp->Ady=nuevo;
    }
    nodos++;
}
Nodo* Grafo::buscarNodo(int valor)
{
    Nodo * temp = actual;
    while(temp){
        if(temp->valor==valor){
            return temp;
        }
        temp=temp->Ady;
    }

    return NULL;
}

Arista *Grafo::buscarArista(Nodo *o, Nodo *d)
{
    Arista *m;
    Nodo *origen, *destino;
    for(int i =0; i<arcos.size();i++){
        m =arcos[i];
        origen=m->origen;
        destino = m->apuntoA;
        if(origen->valor==o->valor && destino->valor==d->valor){
            return m;
        }
    }
    return NULL;
}

void Grafo::agregarArista(int Nodoini, int Nodofinal, int valor)
{
    Nodo *inicio = buscarNodo(Nodoini);
    Nodo *final= buscarNodo(Nodofinal);
    if(final !=NULL && inicio !=NULL){
        if(inicio->aristas==NULL){
            inicio->aristas->agregar(valor,final);
        }else{
            if(!inicio->aristas->buscarExistente(final,inicio->aristas->raiz)){
                inicio->aristas->agregar(valor,final);
            }
        }
    }
}

void Grafo::addArco(int origen, int destino, int valor)
{
    Nodo* inicio = buscarNodo(origen);
    Nodo* final = buscarNodo(destino);
    if(inicio != NULL && final !=NULL){
        if(arcos.size()==0){
            Arista * a =new Arista(valor,inicio,final);
            arcos.push_back(a);
            inicio->addArco(a);
            final->addArco(a);
        }else{
            Arista * a = new Arista(valor,inicio,final);
            bool found=false;
            for(int i=0;i<arcos.size();i++){
                if(arcos[i]==a){
                    found = true;
                    break;
                }
            }
            if(!found){
                arcos.push_back(a);
                inicio->addArco(a);
                final->addArco(a);
            }
        }
    }
    vertices++;
}



