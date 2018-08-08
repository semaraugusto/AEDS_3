#include "dynamic.h"
#include "quicksort.h"
#include <stdlib.h>
#include <stdio.h>

int CeilIndex(int *v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
    return r;
}

int dynamicLIS(int *v, int n) {
       int i;
    if (n == 0)
        return -1;

    int *tail;
    tail = (int*) calloc(n , sizeof(int));

    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (i = 1; i < n; i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
    free(tail);
    return length;
}
