#ifndef GRAFOGRAPH_H
#define GRAFOGRAPH_H
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>
#include<QGraphicsSimpleTextItem>
#include"graphicnode.h"
#include <QWidget>
#include<vector>
#include <iostream>
#include"grafo.h"
#include"dijksttable.h"
#include"floyd.h"
#include<QMessageBox>
#include"floydgraph.h"
#include<nodo.h>
#include"primgraph.h"
#include"dialog.h"
#include"kruskalgraph.h"

using namespace std;

namespace Ui {
class GrafoGraph;
}
class PrimGraph;
class GrafoGraph : public QWidget
{
    Q_OBJECT

public:
    Grafo * grafo;
    vector<GraphicNode*>nodesg;
    vector<AristaGraph*>aristas;
    explicit GrafoGraph(QWidget *parent = 0);
    void setAristasInTree(vector<Arista *> arcos);
    void insertarObjeto(int valor);
    GraphicNode* seekNodeg(int valor);
    AristaGraph* seekArista(Nodo *o, Nodo *d);
    ~GrafoGraph();

private slots:
    void on_AddNodo_clicked();

    void on_AddArista_clicked();

    void on_Dijkstra_clicked();

    void on_Floyd_clicked();

    void on_Prim_clicked();

    void on_origen_clicked();

    void on_Kruskal_clicked();

private:
    int e;
    DijkstTable * dt;
    FLoydGraph *f;
    //PrimGraph * p;
    Dialog *p;
    QGraphicsScene *scene;
    KruskalGraph *k;
    Ui::GrafoGraph *ui;
};

#endif // GRAFOGRAPH_H
