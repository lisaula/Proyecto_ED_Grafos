#include "sortsgraph.h"
#include "ui_sortsgraph.h"
#include<QTime>
SortsGraph::SortsGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortsGraph)
{
    ui->setupUi(this);
    cont =0;
    s=100000;
    setWindowTitle("Sorts");

}

SortsGraph::~SortsGraph()
{
    delete ui;
}

void SortsGraph::on_Merge_clicked()
{
    QTime inicio = QTime::currentTime();
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }

    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("MERGESORT \n");
//    printArray(arr, arr_size);

    sort->mergeSort(arr, 0, arr_size - 1);

    printf("--------------------\n");
    printArray(arr, arr_size);
    QTime final = QTime::currentTime();
    cout<<inicio.secsTo(final)<<endl;
    ui->merge->setText(ui->merge->text()+QString::number(inicio.secsTo(final)));
}

void SortsGraph::on_Introduce_clicked()
{
//    int v= ui->values->value();
//    if(cont<s){
//        array[cont]=v;
//        print();
//        cont++;
//    }else{
//        QMessageBox::warning(this,"Error","Index out of bound (Exception)");
//    }

}


void SortsGraph::on_init_clicked()
{
    cont=0;
    //s = ui->size->value();
    array = new int[100000];
//        srand(unsigned(time(0)));
//        for(int i =0;i<size;i++){
//            numbers[i]=(rand()%100)+1;
//        }
    for(int i =0;i<100000;i++){
        array[i]=(rand()%500)+1;;
    }
    cout<<"arreglo inicializado con "<<100000<<" posiciones."<<endl;
    printArray(array,100000);
}

void SortsGraph::print()
{
    for(int i =0;i<s;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void SortsGraph::on_quick_clicked()
{
    QTime inicio = QTime::currentTime();
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }
    cout<<"QUIKSORT"<<endl;
    //printArray(arr,s);
    printf("--------------------\n");
    sort->quicksort(arr,0,s-1);
    printArray(arr,s);
    cout << endl;
    QTime final = QTime::currentTime();
    cout<<inicio.secsTo(final)<<endl;

    ui->quick_2->setText(ui->quick_2->text()+QString::number(inicio.secsTo(final)));
}

void SortsGraph::on_Heap_clicked()
{
    QTime inicio = QTime::currentTime();
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }
    const size_t sz = sizeof(arr)/sizeof(arr[0]);
    cout<<"HEAPSORT"<<endl;
    //printArray(arr, sz);
    cout << "----------------------------------" << endl;
    sort->heapsort(arr, sz);
    printArray(arr, sz);
    cout << endl;
    QTime final = QTime::currentTime();
    cout<<inicio.secsTo(final)<<endl;
    ui->heap->setText(ui->heap->text()+QString::number(inicio.secsTo(final)));
}

void SortsGraph::on_Bin_clicked()
{
    QTime inicio = QTime::currentTime();
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"BINSORT"<<endl;
    //printArray(arr,s);
    sort->binsort(arr,n);
    cout << "----------------------------------" << endl;
    printArray(arr,s);
    QTime final = QTime::currentTime();
    cout<<inicio.secsTo(final)<<endl;
    ui->Bin_2->setText(ui->Bin_2->text()+QString::number(inicio.secsTo(final)));
}
//001-813-385-8027;
////telefono
//908-337-3592;

////noe
//813-361-9823

void SortsGraph::on_pushButton_clicked()
{
    QTime inicio = QTime::currentTime();
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }
    cout<<"BUBBLESORT"<<endl;
    //printArray(arr,s);
    sort->bubbleSort(arr,s);
    cout << "----------------------------------" << endl;
    printArray(arr,s);
    QTime final = QTime::currentTime();
    cout<<inicio.secsTo(final)<<endl;
    ui->Buble->setText(ui->Buble->text()+QString::number(inicio.secsTo(final)));

}
