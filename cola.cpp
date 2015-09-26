#include "cola.h"

Cola::Cola()
{
    root = NULL;
    end = NULL;
    s=0;
}

void Cola::push(Arista* valor){
    if(!root){
        root = new NodoC(valor);
        end = root;
    }else{
        end->next= new NodoC(valor);
        end->next->prev=end;
        end= end->next;
    }
    s++;
}

NodoC* Cola::pop(){
    if(!root)
        return NULL;

    NodoC* temp= root;
    root = root->next;
    temp->next=NULL;
    temp->prev=NULL;
    s--;
    return temp;
}

NodoC* Cola::first(){
    return root;
}

void Cola::limpiar(){
    if(root){
        pop();
        limpiar();
    }
    s=0;
}


void Cola::anular(){
    if(root){
        delete pop();
        anular();
    }
    s=0;
}

int Cola::size()
{
    return s;
}

QString Cola::imprimir(){
    QString t="";
    if(root){
        NodoC* temp = root;
        while(temp){
            t+=QString("Vengo de %1 peso %2 apunto A %3\n").arg(temp->valor->origen->valor).arg(
                        temp->valor->valor).arg(temp->valor->apuntoA->valor);
            temp = temp->next;
        }
        t+="\n";
        return t;
    }
    return t;
}
