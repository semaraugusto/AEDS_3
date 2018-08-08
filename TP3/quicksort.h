#ifndef QUICKSORT_H
#define QUICKSORT_H

void printArray(int *aux, int arr[], int size);

void swap(int* a, int* b, int*c, int *d);

int partition (int *aux, int arr[], int low, int high);

void quickSort(int *aux, int arr[], int low, int high);

#endif // QUICKSORT_H
