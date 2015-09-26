#include "widget.h"
#include "ui_widget.h"
#include "grafograph.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("MENU");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    GrafoGraph * g = new GrafoGraph();
    g->show();
}

void Widget::on_pushButton_2_clicked()
{
    SortsGraph *s = new SortsGraph();
    s->show();
}
