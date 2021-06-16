#include <stdint.h>
#define N 8

int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}

int checkOddArray1(int8_t a[]) {
    int i, odd;
 
    odd = 0;
    for (i = 0; i < N ; i++) {  odd = odd + a[i]; }
    odd = mod( odd , 2 );
    return odd;
}

int checkOddArray2(int8_t a[])  {
    int i, odd, tmp;
 
    odd = 0;
    for (i = 0; i < N ; i++) { 
        tmp = (odd + a[i])  %  2;
        if(tmp<0){
            tmp = tmp * -1;
        }
        odd = tmp;
    }
    return odd;
}

int checkOdd( ) {
  int8_t  a[N], t; 
  int i;

  for (i = 0; i < N; ++i){ __CPROVER_assume(a[i] >= -18 && a[i] <= 18);  }

  // Write here assertions to check if checkOddArray1
  // and checkOddArray2 return the same result for the
  // same input
  __CPROVER_assert( checkOddArray1(a) == checkOddArray2(a), "check if return the same value.");
}
