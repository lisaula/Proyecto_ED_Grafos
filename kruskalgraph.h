#ifndef KRUSKALGRAPH_H
#define KRUSKALGRAPH_H
#include "kruskal.h"
#include <QWidget>
#include"nuevografo.h"

namespace Ui {
class KruskalGraph;
}

class KruskalGraph : public QWidget
{
    Q_OBJECT

public:
    Kruskal * k;
    void setGrafo(Grafo *g);
    explicit KruskalGraph(QWidget *parent = 0);
    ~KruskalGraph();

private slots:
    void on_pushButton_clicked();

private:
    void insertar();
    Grafo * grafo;

    Ui::KruskalGraph *ui;
};

#endif // KRUSKALGRAPH_H
