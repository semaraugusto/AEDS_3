#include "greedy.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_INT_SIZE 2147483647

int patienceSorting (int *v, int n) {
       int i, cont = 0, j;
       listType *patience;
       patience = (listType*) malloc(n * sizeof(listType));
       for(i = 0; i < n; i++) {
              createEmptyList(&patience[i]);
              insertOnList(&patience[i], MAX_INT_SIZE);
       }


       for(i = 0; i < n; i++) {
              j = 0;
              if(v[i] < patience[j].last->item.value) {
                     insertOnList(&patience[j], v[i]);
                     continue;
              }
              while(v[i] > patience[j].last->item.value) {
                     j++;
                     if(v[i] < patience[j].last->item.value) {
                            insertOnList(&patience[j], v[i]);
                            break;
                     }
              }
       }
       for(i = 0; i < n; i++) {
              if(patience[i].last->item.value != MAX_INT_SIZE)
                     cont++;
       }

       return cont;
}
