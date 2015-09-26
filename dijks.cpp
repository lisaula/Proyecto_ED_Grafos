#include "dijks.h"

Dijks::Dijks(Grafo *g)
{
    grafo =g;
    cont=0;
}

void Dijks::setTabla(int nodos, Nodo* origen)
{
//    vertices;
    distancia = new int[nodos];
//    cout<<"hizo"<<endl;
    path= new QString [nodos];
    visitado= new bool[nodos];
//    cout<<"size of "<<sizeof(distancia)<<"-"<<endl;
    Nodo*temp = grafo->actual;
    for(int i=0; i<nodos;i++){
        vertices.push_back(temp);
        distancia[i]=9999;
        path[i]="-1";
        visitado[i]=false;
        temp=temp->Ady;
    }
}

void Dijks::Analisis(Nodo *origen)
{
    cout<<"AQUI EMPEZO************************************************"<<endl;
    setTabla(grafo->nodos,origen);
    Nodo * actual = origen;
    int pos = getMyPos(actual);
    distancia[pos]=0;
    int cont =0;
    while(checkVisited()){
        cout<<"evaluando a "<<actual->valor<<endl;
        this->adyacentes=setAdyacentes(actual,actual->arcos);
        cout<<"entro3"<<endl;
        int pos_actual = getMyPos(actual);
        cout<<"mi pos "<<pos_actual<<endl;
        //distancia[pos]=0;
        visitado[pos_actual]=true;

        cout<<"seteo a "<<actual->valor<<" "<<"positivo"<<endl;
        cout<<pos_actual<<endl;

        //path[pos]+=QString::number(-1);
        int peso_actual = distancia[pos_actual];
        int peso_arista =0;
        Nodo* current;
        multimap<int,Nodo*>::iterator ady = adyacentes.begin();
        int peso_visitando=0;
        for(int i=0;i<actual->arcos.size();i++){
            cout<<actual->valor<<" "<<actual->arcos.size()<<"AQUI EMPEZO************************************************"<<endl;
            cout<<"Numero de arcos en adyancentes "<<i<<endl;
            cout<<"paso 3 "<<endl;

            peso_arista=ady->first;
            current=ady->second;
            pos=getMyPos(current);
            peso_visitando=distancia[pos];
            cout<<current->valor<<endl;
            ady++;
            if(visitado[pos])continue;

            if(peso_actual+peso_arista <peso_visitando){
                distancia[pos]=peso_actual+peso_arista;
                cout<<"Entro distancia "<<endl;
                QString t = QString("%1").arg(actual->valor);
                if(actual == origen){
                    if(path[pos]=="-1"){
                        path[pos]=QString::number(actual->valor);
                    }
                }else{
                    if(path[pos]=="-1"){
                        path[pos]=path[pos_actual]+QString::number(actual->valor);
                    }else{
                        path[pos]=path[pos_actual]+QString::number(actual->valor);
                    }
                }

            }
            for(int i =0;i<grafo->nodos;i++){
                cout<<distancia[i]<<"  ";
            }
            cout<<endl;


        }
        cout<<"whosminor"<<endl;
        actual=whosMinor();
        cout<<"Whosminor 2"<<endl;

    }
    cout<<"termino"<<endl;

    for(int i =0;i<grafo->nodos;i++){
        cout<<vertices[i]->valor<<"  ";
    }
    cout<<endl;
    for(int i =0;i<grafo->nodos;i++){
        cout<<distancia[i]<<"  ";
    }
    cout<<endl;
    for(int i =0;i<grafo->nodos;i++){
        QString p =path[i];
        string im="";
                im+=p.toStdString();
        cout<<im<<"  ";
    }
    cout<<endl;
    for(int i =0;i<grafo->nodos;i++){
        cout<<visitado[i]<<"  ";
    }
//    cout<<endl;
//    Nodo * menor = whosMinor();
//    cout<<menor->valor<<endl;
//    int cont=adyacentes.size();
//    while(cont>0){
//        Nodo* actual = ady->second;
//        ady--;
//        pos=getMyPos(actual);
//        if(visitado[pos])continue;

//        visitado[pos]=true;
//        cont--;

    //    }
}

Nodo *Dijks::whosMinor()
{
    multimap<int,Nodo*>map;
    Nodo* temp=NULL;
    for(int i =0;i<grafo->nodos;i++){
        cout<<visitado[i]<<"  ";
    }
    for(int i=0;i<grafo->nodos;i++){
        if(!visitado[i]){
            map.insert(pair<int,Nodo*>(distancia[i],vertices[i]));
        }
    }
    cout<<"Size mapa "<<map.size()<<endl;
    multimap<int,Nodo*>::iterator i = map.begin();
    while(i!=map.end()){
        cout<<i->first<<" nodo "<<i->second->valor<<" ";
        i++;
    }
    cout<<endl;
    i=map.begin();
    temp = i->second;
    cout<<temp->valor<<"Mandado este";
    return temp;
}

bool Dijks::checkVisited()
{
    for(int i=0;i<grafo->nodos;i++){
        if(!visitado[i]){
            return true;
        }
    }
    return false;
}

int Dijks::getMyPos(Nodo* n)
{
    for(int i =0;i<vertices.size();i++){
        if(vertices[i]->valor==n->valor){
            return i;
        }
    }
    return -1;
}

multimap<int,Nodo*> Dijks::setAdyacentes(Nodo* o,vector<Arista *> aristas)
{
    multimap<int, Nodo*>temp2;
    Nodo* n;\
    Arista* v;
    cout<<"-----------"<<endl;
    o->printArcos();
    for(int i =0;i<o->arcos.size();i++){
        v=aristas[i];
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


