#include "kruskalgraph.h"
#include "ui_kruskalgraph.h"
#include<QGraphicsScene>
#include<QGraphicsSimpleTextItem>
void KruskalGraph::setGrafo(Grafo *g)
{
    grafo=g;
    k=new Kruskal(grafo);
    insertar();

}

KruskalGraph::KruskalGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KruskalGraph)
{
    ui->setupUi(this);
    setWindowTitle("Kruskal");
}

KruskalGraph::~KruskalGraph()
{
    delete ui;
}

void KruskalGraph::insertar()
{
    k->analisis();
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setParent(ui->graphicsView);
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString t ="ARBOL DEVUELTO\n";
    Arista* m=NULL;
    for(int i =0;i<k->aristas.size();i++){
        m= k->aristas[i];
        t+=QString("%1 peso %2 apunto A %3\n").arg(m->origen->valor).arg(m->valor).arg(m->apuntoA->valor);
    }
    text->setText(t);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
}

void KruskalGraph::on_pushButton_clicked()
{
    NuevoGrafo *ng = new NuevoGrafo();
    ng->setGrafp(k->g2);
    cout<<"GRAFO DADO SIZE ARCOS"<<endl;
    cout<<k->g2->arcos.size()<<endl;
    ng->show();
}
