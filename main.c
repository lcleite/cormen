#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "src/cormen.h"

//static void test_divide(void **state) {
//  (void) state; /* unused */
//
//  assert_int_equal(1 / 2, 5);
//}

int main(){
  int arr[] = {5, 2, 4, 6, 1, 3};
  int_array A;
  A.elements = arr;
  A.length = *(&arr + 1) - arr;

  insertion_sort(A);

  printf("\n");
  printf("&arr: %p \n", &arr);
  printf("&arr+1: %p \n", &arr+1);
  printf("*(&arr+1): %p \n", *(&arr+1));
  printf("dec *(&arr+1): %llu \n", *(&arr+1));
  printf("arr: %p \n", arr);
  printf("dec arr: %llu \n", arr);
  printf("*(&arr+1) - arr: %lu \n", *(&arr+1) - arr);

  /*
   * Considering the array arr[] :
    1) &arr is a pointer to the array. It points at the same memory address as arr. But arr decays to a pointer to first element.
    2) Hence &arr + 1 points at the address after the end of the array.
    3) Dereferencing to *(&arr + 1) gives the address after the end of the last element
      (which is again the same address as &arr + 1 with a different type;
      Similar to arr and &arr  as  *&arr is equivalent to arr).
    4) Finally, we can subtract the pointer to the first element to get the length of the array: *(&arr + 1) - arr.
      (Remember this is pointer arithmetic; Subtraction gives the total number of objects between them).
   */
}


//int main() {
//  const struct CMUnitTest tests[] = {
//    cmocka_unit_test(test_divide),
//  };
//
//  return cmocka_run_group_tests(tests, NULL, NULL);
//}

//gcc -o main main.c -l cmocka