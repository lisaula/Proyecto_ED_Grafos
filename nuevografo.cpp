#include "nuevografo.h"
#include "ui_nuevografo.h"

void NuevoGrafo::insertar()
{
    int o;
    int d;
    int ap;
    Arista*a;
    for(int i = 0;i<grafo->arcos.size();i++){
        cout<<grafo->arcos.size()<<endl;
        a=grafo->arcos[i];
        ap=a->valor;
        o=a->origen->valor;
        d=a->apuntoA->valor;
        GraphicNode * gn = new GraphicNode(o);
        GraphicNode * gn2 = new GraphicNode(d);
        s->addItem(gn);
        s->addItem(gn->texto);
        s->addItem(gn2);
        s->addItem(gn2->texto);
        AristaGraph* v = new AristaGraph(gn,gn2,ap);
        s->addItem(v);
        s->addItem(v->texto);

    }
    ui->graphicsView->setScene(s);

}

void NuevoGrafo::setGrafp(Grafo *g)
{
    grafo=g;
    insertar();
}

NuevoGrafo::NuevoGrafo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NuevoGrafo)
{
    ui->setupUi(this);
    setWindowTitle("Nuevo Grafo");
    s = new QGraphicsScene();

}

NuevoGrafo::~NuevoGrafo()
{
    delete ui;
}
