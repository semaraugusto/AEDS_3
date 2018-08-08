#include <stdio.h>
#include <stdlib.h>
#include "dynamic.h"
#include "bruteForce.h"
#include "quicksort.h"
#include "greedy.h"

int main (void) {
       char c;
       int n, *right, *left, i, mod, temp, res;
       scanf("%c", &c);
       scanf("%d", &n);
       right = (int*) malloc(n * sizeof(int));
       left = (int*) malloc(n * sizeof(int));

       for(i = 0; i < n; i++) {
              scanf("%d %d", &left[i], &right[i]);
       }

       mod = left[0] % 2;
       for(i = 0; i < n; i++) {
              if((left[i] % 2) != mod) {
                     temp = left[i];
                     left[i] = right[i];
                     right[i] = temp;
              }
       }
       quickSort(right, left, 0, n-1);
       if(c == 'g')
              res = patienceSorting(right, n);
       else if(c == 'b')
              res = bruteForceLIS(right, n);
       else
              res = dynamicLIS(right, n);

       printf("%d\n", res);

       free(right);
       free(left);
}
