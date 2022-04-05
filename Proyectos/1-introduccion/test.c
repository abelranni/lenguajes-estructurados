#include <stdio.h>

int main () {

   printf("hola mundo \n");

   printf("test breakpoint \n");

   /* an array with 5 elements */
   int balance[5][2] = {{10,1}, {11,2}, {12,3}, {13,4}, {14,6}};
   int balance2[3] = {20, 21, 22};
   int *p;

   p = (int *)balance;
 
   /* output each array element's value */
   printf( "Array values using pointer\n");
	
   for ( int i = 0; i <= 5 ; i++ ) {
      printf("*(p + %d) : %d\n",  i, *(p + i) );
   }

 
   return 0;
}