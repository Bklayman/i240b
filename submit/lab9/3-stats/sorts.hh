#ifndef SORTS_HH_
#define SORTS_HH_

#include <cassert>

#include "ops.hh"

void insertionSort(int a[], int n, Ops* ops);
void bubbleSort(int a[], int n, Ops* ops);
void selectionSort(int a[], int n, Ops* ops);
void mergeSort(int a[], int n, Ops* ops) ;
void quickSort(int a[], int n, Ops* ops);

#endif //ifndef SORTS_HH_

