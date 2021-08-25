//
// Usage: page_fault a0
// a0 determines how many times the stack is run // explanation may be wrong
// The numbers 2,3, 4,5 in the page_fault argument just add to the stack.

#include "types.h"
#include "stat.h"
#include "user.h"
int k;
int m = 10;

void page_fault_s(int a, int b, int c, int d, int e){
    if(a == 0) {
        printf(1, "level %d\n", a);
        exit();
    }else{
        printf(1, "level %d address %p\n", a, &a);
        page_fault(a-1, b, c, d, e);
    }

    //return 0;
}





int
main(int argc, char *argv[])
{
    printf(1, "Begin page_fault_test test\n");

    k = atoi(argv[1]);
    if(k == 0) {
        printf(1, "level %d\n", i);
        printf(1, "Exiting code...\n", i);
        exit();
    }else{
        //printf(1, "level %d\n", i);
        page_fault_s(k - 1, 2, 3, 4, 5);
    }

    exit();

}
