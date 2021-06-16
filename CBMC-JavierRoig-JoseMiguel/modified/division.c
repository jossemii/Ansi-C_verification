#include <stdio.h>

int main( void ) {
  int D,d, r, q;

  __CPROVER_assume( (D < 0) &&  (D >= -300) &&
                   (d > 0) );
  r = D; 
  q = 0;
  while ( r < 0 ) {
     r = r + d;
     q--;   
  }
  // Post-condition
 __CPROVER_assert( (D == (q*d + r)) && (r >= 0) && (q < 0),
 " q and r are the quotient and the ramainder of D div d" );

  printf( " quotient: %d,  reminder: %d\n", q, r );
}

