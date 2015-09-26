#include "primgraph.h"
#include "ui_primgraph.h"

void PrimGraph::setGrafo(Grafo *g)
{
    grafo=g;
    prim=new Prim(grafo);
    entro=false;
    insertar();
}

PrimGraph::PrimGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimGraph)
{
    ui->setupUi(this);
    setWindowTitle("PRIM");
    entro =false;
    cont=0;
}

void PrimGraph::setVisuales(AristaGraph * &a)
{
    AristaGraph* ab = a;
    visuales.push_back(ab);
}


PrimGraph::~PrimGraph()
{
    delete ui;
}

void PrimGraph::insertar()
{
    QStringList titulos;
    titulos <<"Verices"<< "Visitado"<< "Costo"<<"Camino";
    //QString t = "";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    if(cont!=0){
        int fila;
        prim->analisis(actual);
        int v;
        int dis;
        QString p="";
        bool vi;
        for(int i = 0;i<grafo->nodos;i++){
            p="";
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            fila = ui->tableWidget->rowCount()-1;
            v=prim->vertices[i]->valor;
            ui->tableWidget->setItem(fila,VERTICE,new QTableWidgetItem(QString::number(v)));
            dis = prim->costo[i];
            ui->tableWidget->setItem(fila,COSTO, new QTableWidgetItem(QString::number(dis)));
            ui->tableWidget->setItem(fila,VISITADO, new QTableWidgetItem("1"));

            p+=prim->path[i];
            if(prim->vertices[i]!=actual){
                p+=QString::number(v);
            }
            ui->tableWidget->setItem(fila,CAMINO, new QTableWidgetItem(p));
        }
    }
}

void PrimGraph::setOrigen(int v)
{
    actual = grafo->buscarNodo(v);
    cont++;
    insertar();
//    Arista* m;
//    AristaGraph* visual;
//    Nodo*origen; Nodo* destino;
//    QPen pen(Qt::red);
//    for(int i =0; i<prim->aristas.size();i++){
//        m= prim->aristas[i];
//        origen=m->origen;
//        destino=m->apuntoA;
//        for(int x=0;x<visuales.size();x++){
//            visual=visuales[x];
//            if(visual->origen->peso== origen->valor && visual->destino->peso== destino->valor){
//                visual->setColor(pen);
//                break;
//            }
//        }
//    }
    entro =true;
}

void PrimGraph::on_origen_clicked()
{
    cont++;
    actual = grafo->buscarNodo(ui->init->value());
    insertar();
    entro=true;

}

void PrimGraph::on_pushButton_clicked()
{
    setVisible(false);
}
