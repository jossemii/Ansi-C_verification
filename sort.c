#include <stdint.h>

#define N 8

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort (int8_t a[], int size) {
	// write your favorite sorting algorithm
   int i, j;
   for (i = 0; i < size-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < size-i-1; j++) 
           if (a[j] > a[j+1])
              swap(&a[j], &a[j+1]);
}

void checkSort() {

 	int8_t	array[N];
	for (int i = 0; i < N; ++i){
        // Assume numbers in array are integers in range [0,16]
		//__CPROVER_assume(array[i] >= 0 && array[i] <= 16);
	}

	sort (array, N);

	// check if the array is sorted.
	unsigned is_sorted = 1;
	for (int i=1; i <  N; ++i){
		// write the assertions to check that the array is sorted
		//__CPROVER_assert( array[i-1] <= array[i] ,"check that the previous is upper or equal.");
		if (array[i-1] > array[i]){
			is_sorted = 0;
			break;
		}
	}

	// write the assertions to check that the array is sorted
	//__CPROVER_assert( is_sorted==1 ,"check that the array is sorted.");

}


void main() {
	checkSort();
}