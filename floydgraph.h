#ifndef FLOYDGRAPH_H
#define FLOYDGRAPH_H
#include "floyd.h"
#include <QWidget>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>

namespace Ui {
class FLoydGraph;
}

class FLoydGraph : public QWidget
{
    Q_OBJECT

public:
    void initTabla();
    void setGrafo(Grafo * g);
    explicit FLoydGraph(QWidget *parent = 0);
    ~FLoydGraph();

private:
    Floyd * f;
    Grafo* grafo;
    Ui::FLoydGraph *ui;
};

#endif // FLOYDGRAPH_H
