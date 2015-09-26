#ifndef PRIMGRAPH_H
#define PRIMGRAPH_H
#include"prim.h"
#include <QWidget>
#include<QString>
#include"grafograph.h"
namespace Ui {
class PrimGraph;
}

class PrimGraph : public QWidget
{
    Q_OBJECT

public:
    void setGrafo(Grafo *g);
    explicit PrimGraph(QWidget *parent = 0);
    vector<AristaGraph*>visuales;
    void setVisuales(AristaGraph *&a);
    bool entro;
    void setOrigen(int v);
    Prim *prim;
    ~PrimGraph();

private slots:
    void on_origen_clicked();

    void on_pushButton_clicked();

private:
    int cont;
    void insertar();
    Nodo* actual;
    Grafo * grafo;
    Ui::PrimGraph *ui;
    enum Columna{
        VERTICE, VISITADO,COSTO, CAMINO
    };
};

#endif // PRIMGRAPH_H
