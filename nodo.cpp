#include "nodo.h"

Arista *Nodo::seekArista(Nodo *d)
{
    Arista *m;
    Nodo* destino;
    for(int i=0; i<arcos.size();i++){
        m = arcos[i];
        destino=m->origen;
        if(destino->valor==this->valor){
            destino=m->apuntoA;
        }

        if(destino->valor==d->valor){
            return m;
        }
    }
    return NULL;
}

void Nodo::addArco(Arista* v)
{
    arcos.push_back(v);
}

QString Nodo::imprimirArcos()
{
    QString texto="";
    for(int i=0;i<arcos.size();i++){
        Arista *a = arcos[i];
        if(a->apuntoA==this){
            texto+=QString(" Peso: %1 Apunto a: %2 \n").arg(a->valor).arg(a->origen->valor);
        }else{
            texto+=QString(" Peso: %1 Apunto a: %2 \n").arg(a->valor).arg(a->apuntoA->valor);
        }
    }
    return texto;
}

void Nodo::setTree(int v)
{
    tree=v;
}

void Nodo::printArcos()
{
    for(int i=0;i<arcos.size();i++){
        Arista *a = arcos[i];
        if(a->apuntoA==this){
            cout<<" Peso: "<<a->valor<<" Apunto a: "<<a->origen->valor<<endl;
        }else{
            cout<<" Peso: "<<a->valor<<" Apunto a: "<<a->apuntoA->valor<<endl;
        }

    }
}

Nodo::Nodo(int valor)
{
    this->valor=valor;
    this->Ady=NULL;
    this->aristas= new ListaAristas();
    tree=-1;
}

Nodo::Nodo(){
    valor=0;
    Ady=NULL;
    aristas=NULL;
    tree=-1;
}

