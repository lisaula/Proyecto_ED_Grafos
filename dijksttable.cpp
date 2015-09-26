#include "dijksttable.h"
#include "ui_dijksttable.h"

void DijkstTable::setGrafo(Grafo *g)
{
    grafo = g;
    d= new Dijks(grafo);
}

DijkstTable::DijkstTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DijkstTable)
{
    ui->setupUi(this);
    setWindowTitle("Dijkstra Table");
    cont=0;
    initTable();
}

DijkstTable::~DijkstTable()
{
    delete ui;
}

void DijkstTable::on_inicio_clicked()
{
    cont++;
    origen = grafo->buscarNodo(ui->first->value());
    initTable();
}

void DijkstTable::initTable()
{

    QStringList titulos;
    titulos <<"Verices"<< "Visitado"<< "Distancia"<<"Camino";
    //QString t = "";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    if(cont!=0){

        int fila;
        d->Analisis(origen);
        int v;
        int dis;
        QString p="";
        bool vi;
        for(int i = 0;i<grafo->nodos;i++){
            p="";
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            fila = ui->tableWidget->rowCount()-1;
            v=d->vertices[i]->valor;
            ui->tableWidget->setItem(fila,VERTICE,new QTableWidgetItem(QString::number(v)));
            dis = d->distancia[i];
            ui->tableWidget->setItem(fila,DISTANCIA, new QTableWidgetItem(QString::number(dis)));
            ui->tableWidget->setItem(fila,VISITADO, new QTableWidgetItem("1"));

            p+=d->path[i];
            if(d->vertices[i]!=origen){
                p+=QString::number(v);
            }
            ui->tableWidget->setItem(fila,CAMINO, new QTableWidgetItem(p));

        }
    }
}
