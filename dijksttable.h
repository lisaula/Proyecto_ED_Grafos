#ifndef DIJKSTTABLE_H
#define DIJKSTTABLE_H
#include "grafo.h"
#include "dijks.h"
#include<QString>
#include <QWidget>

namespace Ui {
class DijkstTable;
}

class DijkstTable : public QWidget
{
    Q_OBJECT

public:
    void setGrafo(Grafo * g);
    explicit DijkstTable(QWidget *parent = 0);
    ~DijkstTable();

private slots:
    void on_inicio_clicked();

private:
    Grafo * grafo;
    Dijks * d;
    Nodo * origen;
    int o;
    void initTable();
    int cont;
    Ui::DijkstTable *ui;
    enum Columna{
        VERTICE, VISITADO,DISTANCIA, CAMINO
    };
};

#endif // DIJKSTTABLE_H
