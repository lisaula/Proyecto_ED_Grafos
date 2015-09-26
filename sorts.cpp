#include "sorts.h"
void Sorts::mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void Sorts::merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Sorts::swap(int *m, int *n)
{
    int tmp;
    tmp = (*m);
    (*m) = (*n);
    (*n) = tmp;
}

void Sorts::heapsort(int a[], int N)
{
    /* heapify */
    for (int k = N/2; k >= 0; k--)
    {
        siftDown( a, k, N);
    }

    while (N-1 > 0) {
        /* swap the root(maximum value) of the heap
        with the last element of the heap */
        swap((&a[N-1]), (&a[0]));
        /* put the heap back in max-heap order */
        siftDown(a, 0, N-1);
        /* N-- : decrease the size of the heap by one
        so that the previous max value will
            stay in its proper placement */
        N--;
    }
}

void Sorts::siftDown(int *a, int k, int N)
{
    while ( k*2 + 1 < N ) {
        /* For zero-based arrays, the children are 2*i+1 and 2*i+2 */
        int child = 2*k + 1;

        /* get bigger child if there are two children */
        if ((child + 1 < N) && (a[child] < a[child+1]))
        {
            child++;
        }

        if (a[k] < a[child])
        {   /* out of max-heap order */
            swap( (&a[child]), (&a[k]) );
            /* repeat to continue sifting down the child now */
            k = child;
        }
        else
            return;
    }
}

void Sorts::quicksort(int *arr, int izq, int der)
{
    int i = izq, j=der, tmp;
    int p = arr[(izq + der)/2];
    while(i<=j){
        while(arr[i]<p)i++;
        while(arr[j]>p)j--;
        if(i<=j){
            tmp = arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i++; j--;

        }
    }
    if (izq < j)
        quicksort(arr,izq,j);
    if (i < der)
        quicksort(arr,i,der);
}

void Sorts::binsort(int arr[], int n)
{
    int m =501;
    int buckets[m];

    for(int i =0; i<m;i++){
        buckets[i]=0;
    }

    for(int i =0;i <n;i++)
        ++buckets[arr[i]];

    for(int i =0, j=0;j<m;j++)
        for(int k = buckets[j];k>0;k--)
            arr[i++]=j;
}

void Sorts::bubbleSort(int arr[], int n)
{
    int temp=0;
    for(int i =0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

Sorts::Sorts()
{

}



