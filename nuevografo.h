#ifndef NUEVOGRAFO_H
#define NUEVOGRAFO_H
#include"grafo.h"
#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>
#include<QGraphicsSimpleTextItem>
#include<QString>
#include"graphicnode.h"
namespace Ui {
class NuevoGrafo;
}

class NuevoGrafo : public QWidget
{
    Q_OBJECT

public:
    QGraphicsScene *s;
    void insertar();
    Grafo * grafo;
    void setGrafp(Grafo *g);
    explicit NuevoGrafo(QWidget *parent = 0);
    ~NuevoGrafo();

private:
    Ui::NuevoGrafo *ui;
};

#endif // NUEVOGRAFO_H
