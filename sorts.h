#ifndef SORTS_H
#define SORTS_H
#include<iostream>
using namespace std;
class Sorts
{
public:
//    int *array;
    void mergeSort(int arr[], int l, int r);
    void merge(int arr[], int l, int m, int r);
    void swap(int *m, int *n);
    void heapsort( int a[], int N);
    void siftDown( int *a, int k, int N);
    void quicksort(int * arr, int izq, int der);
    void binsort(int arr[], int n);
    void bubbleSort(int arr[], int n);
    Sorts();
};

#endif // SORTS_H
