#include "floyd.h"

void Floyd::setTabla(int nodos)
{
    tabla = new int*[nodos];
    p= new int*[nodos];
    multimap<int,Nodo*>::iterator it = sortNodes(grafo->actual).begin();
    for(int i = 0; i < nodos; ++i) {
        tabla[i] = new int[nodos];
        p[i] = new int[nodos];
        vertices.push_back(it->second);
        it++;
    }

    for(int i =0;i<nodos;i++){
        for(int x =0;x<nodos;x++){
            tabla[i][x]=9999;
            p[i][x]=-1;
        }
    }
    setValues();
    for(int i =0;i<nodos;i++){
        tabla[i][i]=0;
    }
}

void Floyd::setValues()
{
    int pos_actual=0;
    Nodo* actual=NULL;
    Arista *v= NULL;
    int pos_visitado=0;
    int peso=0;
    Nodo* current=NULL;
    for(int i =0;i<vertices.size();i++){
        actual = vertices[i];
        multimap<int,Nodo*>::iterator ady = setAdyacentes(actual).begin();
        pos_actual=getMyPos(actual);
        for(int x =0; x<actual->arcos.size();x++){
            peso = ady->first;
            current = ady->second;
            pos_visitado = getMyPos(current);
            tabla[pos_actual][pos_visitado]=peso;
            ady++;
        }
    }
}

multimap<int,Nodo*> Floyd::setAdyacentes(Nodo* o)
{
    multimap<int, Nodo*>temp2;
    Nodo* n;
    Arista* v;
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

int Floyd::getMyPos(Nodo *n)
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

void Floyd::analisis()
{
    setTabla(grafo->nodos);
    int nodos = vertices.size();

    for(int k=0;k<nodos;k++){
        for(int i=0;i<nodos;i++){
            for(int j=0;j<nodos;j++){
                if(tabla[i][k]+tabla[k][j]<tabla[i][j]){
                    tabla[i][j]=tabla[i][k]+tabla[k][j];
                    p[i][j]=k;
                }
            }
        }
    }

}

multimap<int, Nodo *> Floyd::sortNodes(Nodo *o)
{
    multimap<int, Nodo*>map;
    Nodo* temp = o;
    for(int i = 0; i< grafo->nodos;i++){
        map.insert(pair<int,Nodo*>(temp->valor,temp));
        temp = temp->Ady;
    }
    return map;
}

void Floyd::print(int o, int d)
{

    int k=p[o][d];
    if(k==-1)return;

    print(o,k);
    cout<<vertices[k]->valor<<" ";
    cout<<"CAMINO"<<endl;
    print(k,d);
}

void Floyd::camino(int origen, int destino)
{
    int o = origen;// -1;
    int d = destino;// -1;
    cout<<"CAMINO"<<endl;
    print(o,d);
}

void Floyd::printTabla()
{
    int t;
    for(int i =0;i<grafo->nodos;i++){
        for(int x =0;x<grafo->nodos;x++){
            t=tabla[i][x];
            cout<<t<<" ";
        }
        cout<<endl;
    }
}

QString Floyd::imprimirTabla()
{
    QString Texto="";
    Texto+="\n";
    for(int i =0;i<grafo->nodos;i++){
        Texto+=QString("%1 -").arg(i);
    }
    Texto+="\n";
    for(int i =0;i<grafo->nodos;i++){
        Texto+=QString("%1 ").arg(i);
        for(int x =0;x<grafo->nodos;x++){
            int t=tabla[i][x];
            Texto+=QString("%1 ").arg(t);
        }
        Texto+="\n";
    }
    Texto+="\n";
    return Texto;
}

QString Floyd::imprimirP()
{
    QString Texto="";
    Texto+="\n";
    for(int i =0;i<grafo->nodos;i++){
        Texto+=QString("%1 -").arg(i);
    }
    Texto+="\n";
    for(int i =0;i<grafo->nodos;i++){
        Texto+=QString("%1 ").arg(i);
        for(int x =0;x<grafo->nodos;x++){
            int t=p[i][x];
            Texto+=QString("%1 ").arg(t);
        }
        Texto+="\n";
    }
    Texto+="\n";
    return Texto;
}

void Floyd::printP()
{
    int t=0;
    for(int i =0;i<grafo->nodos;i++){
        for(int x =0;x<grafo->nodos;x++){
            t=p[i][x];
                cout<<t<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}



Floyd::Floyd(Grafo *g)
{
    grafo = g;
}

