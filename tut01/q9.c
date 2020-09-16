#include <stdlib.h>

int main (void) { 
    int  x;  // a variable located at address 1000 with initial value 0
    int *p;  // a variable located at address 2000 with initial value 0


    // address of p = &p
    // address that p stores = p
    // value at the adress that p stores = *p

    p = &x;     // p set to address of x; p = 1000
    x = 5;      // x=5, p=1000
    *p = 3;     // p=1000, x=3
    x = (int)p; // x=1000, p=1000
    x = (int)&p;// x=2000, p=1000
    p = NULL;   // x=2000, p=NULL
    *p = 1;     // ERROR x=2000, p=NULL
    
    return 0;   
}