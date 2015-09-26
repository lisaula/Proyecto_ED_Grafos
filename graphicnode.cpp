#include "graphicnode.h"

GraphicNode::GraphicNode(int valor)
{
    peso=valor;
    this->setRect(0,0, 50, 50);
    this->setPos(0,0);
    QPen azul(Qt::blue);
    //QBrush rojo(Qt::white);
    this->setPen(azul);
    //this->setBrush(rojo);
    x = this->pos().x();
    y = this->pos().y();
    w = this->rect().width();
    h = this->rect().height();
    posx=x+w*0.2+5;
    posy=y+h*0.2+5;
    this->setAcceptDrops(true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    texto =new QGraphicsTextItem(QString::number(valor));
    texto->setPos(QPointF(x+posx,y+posy));

}

void GraphicNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsEllipseItem::paint(painter,option,widget);
    x = pos().x();
    y = this->pos().y();
    w = this->rect().width();
    h = this->rect().height();
    posx=x+(w*0.2)+5;
    posy=y+(h*0.2)+5;
    texto->setPos(QPointF(posx,posy));
    //texto->paint(painter,option,widget);
}

void GraphicNode::setColor(QPen pen)
{
    this->setPen(pen);
}


void AristaGraph::setColor(QPen pen)
{
    this->setPen(pen);
}

void AristaGraph::setAristasInTree()
{
    Arista *m;
    //AristaGraph *v;
    Nodo* origen;
    Nodo* destino;
    QPen pen(Qt::red);
    for(int i =0;arcos.size();i++){
        m=arcos[i];
        origen = m->origen;
        destino = m->apuntoA;
        //v= seekArista(origen,destino);
        if(origen->valor==this->origen->peso && destino->valor == this->destino->peso){
            this->setColor(pen);
            this->origen->setColor(pen);
            this->destino->setColor(pen);
        }
    }
}

void AristaGraph::setVector(vector<Arista *> arcos)
{
    this->arcos=arcos;
    entro =true;
}

AristaGraph::AristaGraph(GraphicNode *O, GraphicNode *d, int peso)
{
    origen = O;
    destino=d;
    setColor(QPen(Qt::black));
    texto = new QGraphicsTextItem(QString::number(peso));
    x =(origen->pos().x()+destino->pos().x())/2;
    y = (origen->pos().y()+destino->pos().y())/2;

    mitad= QPoint(x,y);
     entro =false;
}

void AristaGraph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsLineItem::paint(painter,option,widget);
    setLine(origen->pos().x()+(origen->rect().width()/2),origen->pos().y()+(origen->rect().height()/2),
            destino->pos().x()+(destino->rect().width()/2),destino->pos().y()+(destino->rect().height()/2));

//    x =(origen->pos().x()+destino->pos().x())/2;
//    y =(origen->pos().y()+destino->pos().y())/2;
    x =(origen->pos().x()+destino->pos().x())/2;
    y = (origen->pos().y()+destino->pos().y())/2;
    mitad= QPoint(x,y);
    texto->setPos(mitad);
    if(entro){
        setAristasInTree();
        entro=false;
    }

}
