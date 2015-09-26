#include "floydgraph.h"
#include "ui_floydgraph.h"
#include<QStringList>
#include<QString>
void FLoydGraph::initTabla()
{
    f->analisis();
    QGraphicsScene *scene = new QGraphicsScene(),*scene2 = new QGraphicsScene();
    scene->setParent(ui->TablaP);
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem(),*text2 = new QGraphicsSimpleTextItem();
    QString t = f->imprimirP();
    text->setText(t);
    text2->setText(f->imprimirTabla());

    scene->addItem(text);
    scene2->addItem(text2);
    ui->TablaP->setScene(scene);
    ui->Tabla->setScene(scene2);

}

void FLoydGraph::setGrafo(Grafo *g)
{
    grafo=g;
    f= new Floyd(grafo);
    initTabla();
}

FLoydGraph::FLoydGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FLoydGraph)
{
    ui->setupUi(this);
    setWindowTitle("Floyd");

}

FLoydGraph::~FLoydGraph()
{
    delete ui;
}
