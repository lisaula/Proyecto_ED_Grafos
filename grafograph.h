#ifndef GRAFOGRAPH_H
#define GRAFOGRAPH_H

#include <QWidget>

namespace Ui {
class GrafoGraph;
}

class GrafoGraph : public QWidget
{
    Q_OBJECT

public:
    explicit GrafoGraph(QWidget *parent = 0);
    ~GrafoGraph();

private:
    Ui::GrafoGraph *ui;
};

#endif // GRAFOGRAPH_H
