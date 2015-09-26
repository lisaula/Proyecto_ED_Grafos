#ifndef SORTSGRAPH_H
#define SORTSGRAPH_H

#include <QWidget>
#include <QMessageBox>
#include "sorts.h"
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include<vector>
using namespace std;
namespace Ui {
class SortsGraph;
}

class SortsGraph : public QWidget
{
    Q_OBJECT

public:
    explicit SortsGraph(QWidget *parent = 0);
    ~SortsGraph();

private slots:
    void on_Merge_clicked();

    void on_Introduce_clicked();

    void on_init_clicked();

    void on_quick_clicked();

    void on_Heap_clicked();

    void on_Bin_clicked();

    void on_pushButton_clicked();

private:
    Sorts *sort = new Sorts();
    void print();
    void printArray(int A[], int size)
    {
        int i;
        for (i=0; i < size; i++)
            printf("%d ", A[i]);
        cout<<endl;
    }
    int *array, cont, s;
    Ui::SortsGraph *ui;
};

#endif // SORTSGRAPH_H
