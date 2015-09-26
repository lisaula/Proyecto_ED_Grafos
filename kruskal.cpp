#include "kruskal.h"

bool Kruskal::checkCounter(Nodo *f)
{
    if((f->tree*-1) == grafo->nodos)
        return true;

    return false;
}

int Kruskal::seekFinal(Nodo *o)
{
    int n = o->tree;
    Nodo* f=NULL;
    cout<<"SeekFinal"<<endl;
    if(n>0){
        f=grafo->buscarNodo(n);
        if(f->tree<0){
            cout<<"Retorno n"<<n<<endl;
            return n;
        }
        else{
            cout<<"Retorno f-tree"<<f->tree<<endl;
            return f->tree;
        }
    }else{
        cout<<"Retorno o-valor"<<o->valor<<endl;
        return o->valor;
    }

}

bool Kruskal::checkSiblings(Nodo *n, int tree, Arista *v)
{
    Arista *a;
    Nodo* temp;
    bool t1=false, t2=false;
    if(v->origen->tree!=0 || v->apuntoA->tree !=0){
        for(int x=0;x<trees.size();x++){
            if(v->origen->tree==trees[x]){
                t1=true;
                break;
            }
        }
        for(int x=0;x<trees.size();x++){
            if(v->apuntoA->tree==trees[x]){
                t2=true;
                break;
            }
        }
        if(t1 && t2)return true;
    }

    //for(int i =0; i<n->arcos.size();i++){

    //a=n->arcos[i];
//        temp=a->origen;
//        if(temp==n){
//            temp=a->apuntoA;
      //  }

//        bool ver=false;
//        for(int i =0;i<aristas.size();i++){
//            if(a==aristas[i]){
//                ver=true;
//                break;
//            }
//        }
//        if(a==v || ver)continue;
//        if(temp->tree!=0){
//            if(temp->tree==n->tree){
//                cout<<"tree "<<tree<<endl;
//                cout<<"return true entre "<<n->valor<<" con "<<n->tree<<" "<<temp->valor<<" con "<<temp->tree<<endl;
//                return true;
//            }
//        }
//    }
    return false;
}

bool Kruskal::checkTrees(Nodo *n, Arista *a)
{
    for(int i =0;i<trees.size();i++){
        if(checkSiblings(n,trees[i],a))
            return true;
    }
    return false;
}

bool Kruskal::checkAristas(Nodo *n)
{
    Arista* a;
    for(int i =0;i<n->arcos.size();i++){
        a=n->arcos[i];
        if(a->intree)
            return true;
    }
    return false;
}


void Kruskal::newTree()
{
    cont++;
    trees.push_back(cont);
}

bool Kruskal::isNewTree(int tree)
{
    for(int i=0;i<trees.size();i++){
        if(trees[i]==tree){
            return true;
        }
    }
    return false;
}

bool Kruskal::checkNodes(Nodo *o, Nodo *d)
{
    cout<<"CheckNodes"<<endl;
    cout<<"o-tree "<<o->tree<<" d-tree "<<d->tree<<endl;
    if(o->tree ==-1 &&  d->tree==-1){
        cout<<"retorno false 1er if -1s"<<endl;
        return false;
    }


    int n = seekFinal(o);
    int n2 = seekFinal(d);
    cout<<"Aqui en CN"<<endl;
    cout<<o->valor<<" o final: "<<n<<" "<<d->valor<<" d final: "<<n2<<endl;
    if(n==n2){
        cout<<"comparo "<<n<<" y "<<n2<<endl;
        cout<<"retorno true..."<<endl;
        return true;
    }
    cout<<"retorno false"<<endl;
    return false;
}

multimap<int, Arista *> Kruskal::sortAristas(vector<Arista *> arcos)
{
    multimap<int, Arista*>map;
    Arista* v=NULL;
    for(int i =0; i<arcos.size();i++){
        v= arcos[i];
        map.insert(pair<int,Arista*>(v->valor,v));
    }
    return map;
}

void Kruskal::analisis()
{
    multimap<int, Arista*>::iterator ari =sortAristas(grafo->arcos).begin();
    Arista*v;
    for(int i =0; i<grafo->arcos.size();i++){
        v=ari->second;

        cola->push(v);
        ari++;
    }
    Arista *a=NULL;
    Nodo* o=NULL, *d=NULL, *final=NULL;
    int c =0;

    final=grafo->buscarNodo(1);
    while(!checkCounter(final)){

        c++;
        if(cola->size()==0)break;
        a=cola->pop()->valor;
        o=a->origen;
        d=a->apuntoA;
        cout<<"Evaluando "<< o->valor<<"pesa "<<a->valor<<" apunta "<<d->valor<<endl;
        if(c==1){
            if(!checkNodes(o,d)){
                a->setIntree(true);
                aristas.push_back(a);
                o->setTree(d->valor);
                d->setTree(d->tree-1);
                final = d;
                contNode++;
                cout<<"Seteo c==1"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                g2->agregarNodo(o->valor);
                g2->agregarNodo(d->valor);
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
        }
        if(!checkNodes(o,d)){
            cout<<"Entro"<<endl;
            a->setIntree(true);
            aristas.push_back(a);
            //int of=, df;
            if(o->tree<-1 && d->tree==-1){
                d->setTree(o->valor);
                o->setTree(o->tree-1);
                cout<<"Entro 1"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                final=o;
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(o->tree==-1 && d->tree<-1){
                o->setTree(d->valor);
                d->setTree(d->tree-1);
                cout<<"Entro 2"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                final = d;
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(o->tree>0 && d->tree>0){
                int n=seekFinal(o);
                final = grafo->buscarNodo(n);
                int m = seekFinal(d);
                Nodo* temp = grafo->buscarNodo(m);
                cout<<"Entro 5"<<endl;
                if((final->tree*-1)>(temp->tree*-1)){
                    cout<<final->tree<<endl;
                    final->setTree(final->tree+temp->tree);
                    cout<<final->tree<<endl;
                    d->setTree(final->valor);
                    temp->setTree(final->valor);
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                    cout<<"final "<<temp->tree<<" Final sumo "<<final->tree<<endl;
                    Nodo* onuevo = g2->buscarNodo(o->valor);
                    Nodo* dnuevo = g2->buscarNodo(d->valor);
                    if(onuevo==NULL){
                        g2->agregarNodo(o->valor);
                    }
                    if(dnuevo==NULL){
                        g2->agregarNodo(d->valor);
                    }
                    g2->addArco(o->valor,d->valor,a->valor);
                    continue;
                }else{
                    cout<<temp->tree<<endl;
                    temp->setTree(temp->tree+final->tree);
                    cout<<temp->tree<<endl;
                    o->setTree(temp->valor);
                    final->setTree(temp->valor);
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                    cout<<"final "<<final->tree<<" Final sumo "<<temp->tree<<endl;
                    final = temp;
                    Nodo* onuevo = g2->buscarNodo(o->valor);
                    Nodo* dnuevo = g2->buscarNodo(d->valor);
                    if(onuevo==NULL){
                        g2->agregarNodo(o->valor);
                    }
                    if(dnuevo==NULL){
                        g2->agregarNodo(d->valor);
                    }
                    g2->addArco(o->valor,d->valor,a->valor);
                    continue;
                }

            }
            if(o->tree<0 && d->tree<0){
                int n=seekFinal(o);
                final = grafo->buscarNodo(n);
                int m = seekFinal(d);
                Nodo* temp = grafo->buscarNodo(m);
                cout<<"Entro 6"<<endl;
                if((final->tree*-1)>(temp->tree*-1)){
                    cout<<final->tree<<endl;
                    final->setTree(final->tree+temp->tree);
                    cout<<final->tree<<endl;
                    d->setTree(final->valor);
                    temp->setTree(final->valor);
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                    cout<<"final "<<temp->tree<<" Final sumo "<<final->tree<<endl;
                    Nodo* onuevo = g2->buscarNodo(o->valor);
                    Nodo* dnuevo = g2->buscarNodo(d->valor);
                    if(onuevo==NULL){
                        g2->agregarNodo(o->valor);
                    }
                    if(dnuevo==NULL){
                        g2->agregarNodo(d->valor);
                    }
                    g2->addArco(o->valor,d->valor,a->valor);
                    continue;
                }else{
                    cout<<temp->tree<<endl;
                    temp->setTree(temp->tree+final->tree);
                    cout<<temp->tree<<endl;
                    o->setTree(temp->valor);
                    final->setTree(temp->valor);
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                    cout<<"final "<<final->tree<<" Final sumo "<<temp->tree<<endl;
                    final=temp;
                    Nodo* onuevo = g2->buscarNodo(o->valor);
                    Nodo* dnuevo = g2->buscarNodo(d->valor);
                    if(onuevo==NULL){
                        g2->agregarNodo(o->valor);
                    }
                    if(dnuevo==NULL){
                        g2->agregarNodo(d->valor);
                    }
                    g2->addArco(o->valor,d->valor,a->valor);
                    continue;
                }

            }
            if(d->tree<-1&& o->tree==-1){
                o->setTree(d->valor);
                d->setTree(d->tree-1);
                cout<<"Entro 3"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                final=d;
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(d->tree==-1 && o->tree<-1){
                d->setTree(o->valor);
                o->setTree(o->tree-1);
                cout<<"Entro 4"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                final=o;
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(o->tree==-1 && d->tree==-1){
                o->setTree(d->valor);
                d->setTree(d->tree-1);
                contNode++;
                cout<<"Seteo -1 -1"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                final=d;
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(o->tree==-1 && d->tree>0){
                int f =seekFinal(d);
                o->setTree(f);
                final = grafo->buscarNodo(f);
                final->setTree(final->tree-1);
                contNode++;
                cout<<"Seteo o=-1 d>0"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(d->tree==-1 && o->tree>0){
                int f = seekFinal(o);
                d->setTree(f);
                final = grafo->buscarNodo(f);
                final->setTree(final->tree-1);
                cout<<"Seteo d=-1 o>0"<<endl;
                cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(d->tree<0 && o->tree>0){
                int m = d->tree;
                final = grafo->buscarNodo(seekFinal(o));
                int n = final->tree;
                if((m*-1)>=(n*-1)){
                    d->setTree(d->tree+n);
                    o->setTree(d->valor);
                    final=d;
                    cout<<"Seteo d<0 o>0 1er if"<<endl;
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                }else{
                    final->setTree(final->tree+m);
                    d->setTree(final->valor);
                    cout<<"Seteo o<0 d>0 else"<<endl;
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                }
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
            if(o->tree<0 && d->tree>0){
                int m = o->tree;
                final = grafo->buscarNodo(seekFinal(d));
                int n = final->tree;
                if((m*-1)>=(n*-1)){
                    o->setTree(o->tree+n);
                    d->setTree(o->valor);
                    final=o;
                    cout<<"Seteo o<0 d>0 1er if"<<endl;
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                }else{
                    final->setTree(final->tree+m);
                    o->setTree(final->valor);
                    cout<<"Seteo o<0 d>0 else"<<endl;
                    cout<<"o final: "<<o->tree<<" d final: "<<d->tree<<endl;
                }
                Nodo* onuevo = g2->buscarNodo(o->valor);
                Nodo* dnuevo = g2->buscarNodo(d->valor);
                if(onuevo==NULL){
                    g2->agregarNodo(o->valor);
                }
                if(dnuevo==NULL){
                    g2->agregarNodo(d->valor);
                }
                g2->addArco(o->valor,d->valor,a->valor);
                continue;
            }
        }
    }

    Arista* m=NULL;
    cout<<"Size aristas "<<aristas.size()<<endl;
    for(int i =0;i<aristas.size();i++){
        m= aristas[i];
        cout<<m->origen->valor<<" peso "<<m->valor<<" apunto A "<<m->apuntoA->valor<<endl;
    }
}

Kruskal::Kruskal(Grafo *g)
{
    grafo = g;
    cola = new Cola();
    deshechos = new Cola();
    cont=0;
    contNode=0;
    g2 = new Grafo();
}

