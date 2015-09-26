#ifndef GRAPHICNODE_H
#define GRAPHICNODE_H
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>
#include<QGraphicsTextItem>
#include"arista.h"
class GraphicNode : public QGraphicsEllipseItem
{
public:
    GraphicNode(int valor);
    QGraphicsTextItem * texto;
    int peso;
    int x;
    int y;
    int w;
    int h;
    int posx;
    int posy;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    void setColor(QPen pen);

};

class AristaGraph : public QGraphicsLineItem {
public:
    int x=0;
    int y=0;
    void setColor(QPen pen);
    bool entro;
    vector<Arista*> arcos;
    QGraphicsTextItem * texto;
    QPoint mitad;
    GraphicNode *origen,*destino;
    void setAristasInTree();
    void setVector(vector<Arista*> arcos);
    AristaGraph(GraphicNode* O,GraphicNode* d,int peso);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
};

#endif // GRAPHICNODE_H
