/* C implementation QuickSort */
#include<stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b, int*c, int *d)
{
    int t = *a;
    *a = *b;
    *b = t;

    	t = *c;
	*c = *d;
	*d = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int *aux, int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j], &aux[i], &aux[j]);
        }
    }
    swap(&arr[i + 1], &arr[high], &aux[i+1], &aux[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int *aux, int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(aux, arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(aux, arr, low, pi - 1);
        quickSort(aux, arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int *aux, int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d %d\n", arr[i], aux[i]);
    printf("\n");
}
