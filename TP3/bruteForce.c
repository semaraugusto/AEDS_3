#include <stdio.h>
#include <stdlib.h>
#include "bruteForce.h"

int bruteForceLIS(int *v, int n) {
       int *aux = (int*) calloc(n, sizeof(int));
       int i = 0, j, count, temp, answer = 0;

       while(i >= 0) {
              temp = 0;
              count = 0;
              for(j = 0; j < n; j++) {
                     if(aux[j] == 1) {
                            if(v[j] > temp) {
                                   temp = v[j];
                                   count++;
                            }
                            else
                                   break;

                            }
                     }
                     if(answer < count)
                            answer = count;

              for (i = n - 1; i >= 0 && ++aux[i] == 2; i--) {
                     aux[i] = 0;
              }
       }
       free(aux);
       return answer;
}
