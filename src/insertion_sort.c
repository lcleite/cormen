//
// Created by leandro on 18/08/17.
//

#include <stdio.h>
#include "cormen.h"

void print_array(int_array A){
  printf("A = { ");
  for(int i = 0; i < A.length; i++){
    printf("%d ", A.elements[i]);
  }
  printf("};");
}

void insertion_sort(int_array A){
  for(int j = 1; j < A.length; j++){
    int key = A.elements[j];
    int i = j-1;

    while(i >= 0 && A.elements[i] > key){
      A.elements[i + 1] = A.elements[i];
      i -= 1;
    }

    A.elements[i + 1] = key;
  }

  print_array(A);
}
