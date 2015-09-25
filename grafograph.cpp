#include "grafograph.h"
#include "ui_grafograph.h"

GrafoGraph::GrafoGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GrafoGraph)
{
    ui->setupUi(this);
    setWindowTitle("Grafo Form");
}

GrafoGraph::~GrafoGraph()
{
    delete ui;
}
