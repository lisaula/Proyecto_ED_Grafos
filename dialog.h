#ifndef DIALOG_H
#define DIALOG_H
#include"grafo.h"
#include"prim.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    void setOrigen(int v);
    int cont;
    Nodo* actual;
    bool entro;
    Prim* prim;
    Grafo* grafo;
    void insertar();
    void setGrafo(Grafo *g);
    vector<Arista*> getAristas();
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_Origen_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    enum Columna{
        VERTICE, VISITADO,COSTO, CAMINO
    };
};

#endif // DIALOG_H
