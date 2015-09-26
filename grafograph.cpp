#include "grafograph.h"
#include "ui_grafograph.h"


GrafoGraph::GrafoGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GrafoGraph)
{
    ui->setupUi(this);
    setWindowTitle("Grafo Form");
    //insertarObjeto();
    scene = new QGraphicsScene();
    grafo = new Grafo();
    e=0;
}

void GrafoGraph::setAristasInTree(vector<Arista*> arcos)
{
    Arista *m;
    AristaGraph *v;
    Nodo* origen;
    Nodo* destino;
    QPen pen(Qt::red);
    for(int i =0;arcos.size();i++){
        cout<<arcos.size()<<endl;
        cout<<i<<endl;
        m=arcos[i];
        origen = m->origen;
        destino = m->apuntoA;
        v= seekArista(origen,destino);
        if(v){
            v->setColor(pen);
            seekNodeg(origen->valor)->setColor(pen);
            seekNodeg(destino->valor)->setColor(pen);
        }
    }
}

void GrafoGraph::insertarObjeto(int valor)
{
    GraphicNode *n= seekNodeg(valor);
    if(n==NULL){
        n = new GraphicNode(valor);
        nodesg.push_back(n);
        scene->addItem(n);
        scene->addItem(n->texto);
        ui->graphicsView->setScene(scene);
        grafo->agregarNodo(valor);
    }else{
        QMessageBox::information(this,"Warning","No puedes agregar un nodo ya existente");
    }
}

GraphicNode *GrafoGraph::seekNodeg(int valor)
{
    for(int i =0;i<nodesg.size();i++){
        if(nodesg[i]->peso ==  valor){
            return nodesg[i];
            cout<<"retorno"<<endl;
        }
    }
    return NULL;
}

AristaGraph *GrafoGraph::seekArista(Nodo *o, Nodo *d)
{
    AristaGraph* m;
    GraphicNode *origen ,*destino;
    for(int i =0; i<aristas.size();i++){
        origen = m->origen;
        destino=m->destino;
        if(origen->peso==o->valor && destino->peso == d->valor){
            return m;
        }
    }
    return NULL;
}



GrafoGraph::~GrafoGraph()
{
    delete ui;
}

void GrafoGraph::on_AddNodo_clicked()
{
    insertarObjeto(ui->Nodo_value->value());
}

void GrafoGraph::on_AddArista_clicked()
{
    int p = ui->Peso->value();
    GraphicNode * o, *d;
    int origen_value=ui->OValue->value();
    int destino_value=ui->DValue->value();
    o = seekNodeg(origen_value);
    d = seekNodeg(destino_value);
    if(o && d){
        AristaGraph *a = new AristaGraph(o,d,p);
        scene->addItem(a->texto);
        scene->addItem(a);
        ui->graphicsView->setScene(scene);
        grafo->addArco(origen_value,destino_value,p);
        aristas.push_back(a);
    }else{
        QMessageBox::warning(this,"Error","Nodo Origen o Nodo Destino no fueron encontrados.");
    }
}

void GrafoGraph::on_Dijkstra_clicked()
{
    dt = new DijkstTable();
    dt->setGrafo(grafo);
    dt->show();
}

void GrafoGraph::on_Floyd_clicked()
{
    f= new FLoydGraph();
    f->show();
    f->setGrafo(grafo);
}

void GrafoGraph::on_Prim_clicked()
{
    p= new Dialog(this);
    p->setGrafo(grafo);
    int res=p->exec();
    if(res == QDialog::Rejected){
        return;
    }
    setAristasInTree(p->getAristas());

//    if(p->entro){
//        //setAristasInTree(p->prim->aristas);
//    }

}

void GrafoGraph::on_origen_clicked()
{
    setAristasInTree(p->prim->aristas);
}

void GrafoGraph::on_Kruskal_clicked()
{
    k = new KruskalGraph();
    k->setGrafo(grafo);
    //setAristasInTree(k->k->aristas);
    k->show();
}
