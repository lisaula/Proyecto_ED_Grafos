#include "prim.h"



int Prim::getMyPos(Nodo *n)
{
    Nodo* temp;
    for(int i=0;i<grafo->nodos;i++){
        temp = vertices[i];
        if(temp->valor == n->valor){
            return i;
        }
    }
    return -1;
}

void Prim::setTable(int nodos, Nodo *origen)
{
    costo = new int[nodos];
    visitado= new bool[nodos];
    path = new QString[nodos];
    Nodo * temp = grafo->actual;
    for(int i =0; i<nodos;i++){
        vertices.push_back(temp);
        temp= temp->Ady;
        costo[i]=9999;
        visitado[i]=false;
        path[i]="-1";
    }
}

bool Prim::checkVisited()
{
    for(int i=0;i<grafo->nodos;i++){
        if(!visitado[i]){
            return true;
        }
    }
    return false;
}

Nodo *Prim::whosMinor()
{
    multimap<int,Nodo*>map;
    Nodo* temp=NULL;
    for(int i=0;i<grafo->nodos;i++){
        if(!visitado[i]){
            map.insert(pair<int,Nodo*>(costo[i],vertices[i]));
        }
    }
    cout<<"Size mapa "<<map.size()<<endl;
    multimap<int,Nodo*>::iterator i = map.begin();
//    while(i!=map.end()){
//        cout<<i->first<<" nodo "<<i->second->valor<<" ";
//        i++;
//    }
//    cout<<endl;
//    i=map.begin();
    temp = i->second;
    cout<<endl;
    cout<<temp->valor<<"Mandado este"<<endl;
    return temp;
}


void Prim::analisis(Nodo *origen)
{
    setTable(grafo->nodos,origen);
    int pos_origen= getMyPos(origen);
    Nodo* actual = origen;
    costo[pos_origen]=0;
    int pos_actual;
    multimap<int,Nodo*>adyacentes;
    Nodo* current=NULL;
    int peso_visitado=0;
    int pos_visitado=0;
    int peso_arista=0;
    multimap<int, Nodo*>::iterator ady;
    while(checkVisited()){
        cout<<"Evaluando a "<<actual->valor<<endl;
        pos_actual= getMyPos(actual);
        visitado[pos_actual]=true;
        adyacentes = setAdyacentes(actual);
        ady=adyacentes.begin();
        cout<<"size adyacentes "<<adyacentes.size()<<endl;
        for(int i =0; i<actual->arcos.size();i++){

            cout<<endl;
            current = ady->second;
            cout<<"Current "<<current->valor<<endl;

            pos_visitado=getMyPos(current);


            peso_visitado=costo[pos_visitado];
            peso_arista=ady->first;
            cout<<"PESO arista "<<peso_arista<<" Peso visitado "<<peso_visitado<<endl;
            ady++;
            if(visitado[pos_visitado])continue;

            if(peso_arista<peso_visitado){
                costo[pos_visitado]=peso_arista;
                path[pos_visitado]=QString::number(actual->valor);
                Arista *m = actual->seekArista(current);
                if(m){
                    m->setIntree(true);
                    aristas.push_back(m);
                }
            }

            for(int i =0;i<grafo->nodos;i++){
                cout<<costo[i]<<"  ";
            }
        }
        actual = whosMinor();
    }
    cout<<endl;
    for(int i =0;i<grafo->nodos;i++){
        cout<<vertices[i]->valor<<"  ";
    }
    cout<<endl;
    for(int i =0;i<grafo->nodos;i++){
        cout<<costo[i]<<"  ";
    }
    cout<<endl;
    string im="";
    for(int i =0;i<grafo->nodos;i++){
        im=path[i].toStdString();
        cout<<im<<"  ";
    }
    cout<<endl;
    for(int i =0;i<grafo->nodos;i++){
        cout<<visitado[i]<<"  ";
    }
    for(int i =0;i<aristas.size();i++){
        cout<<"----------------------"<<endl;
        cout<<aristas[i]->origen<<"  apunto a "<<aristas[i]->apuntoA<<endl;
    }
    cout<<endl;
}

multimap<int, Nodo *> Prim::setAdyacentes(Nodo *o)
{
    multimap<int, Nodo*>temp2;
    Nodo* n;
    Arista* v;
    cout<<"-----------"<<endl;
    o->printArcos();
    for(int i =0;i<o->arcos.size();i++){
        v=o->arcos[i];
        n=v->origen;

        if(n==o){
            n=v->apuntoA;
             cout<<n->valor<<endl;
        }
         cout<<n->valor<<endl;
        temp2.insert(pair<int,Nodo*>(v->valor,n));
    }
    cout<<"-----------"<<endl;
    return temp2;
}

Prim::Prim(Grafo *g)
{
    grafo =g;
}

