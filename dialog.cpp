#include "dialog.h"
#include "ui_dialog.h"

void Dialog::setOrigen(int v)
{
    actual = grafo->buscarNodo(v);
    cont++;
    insertar();
}

void Dialog::insertar()
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

void Dialog::setGrafo(Grafo *g)
{
    grafo=g;
    prim=new Prim(grafo);
    entro=false;
    insertar();
}

vector<Arista*> Dialog::getAristas()
{
   return prim->aristas;
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("PRIM Dialog");
    entro =false;
    cont=0;

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Origen_clicked()
{
    cont++;
    actual = grafo->buscarNodo(ui->init->value());
    insertar();
    entro=true;
}

void Dialog::on_buttonBox_accepted()
{
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}
