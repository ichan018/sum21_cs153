//
// Usage: page_fault a0
// a0 determines how many times the stack is run // explanation may be wrong
// The numbers 2,3, 4,5 in the page_fault argument just add to the stack.

#include "types.h"
#include "stat.h"
#include "user.h"
int k;
int m = 10;
/*
void page_fault(int a, int b, int c, int d, int e){
    m = m + 1;
    if(m == k) {
        printf(1, "level %d\n", m);
        exit();
    }else{
    //    printf(1, "level %d\n", m);
        page_fault(1, 2, 3, 4, 5);
    }
}
*/



int
main(int argc, char *argv[])
{
    //int parentPid;
    int i = 0; // counter for for loop

    printf(1, "Begin page_fault_test test\n");
    //printf(1, "Begin change_pri test\n");
    //parentPid = getpid();
    //printf(1, "Parent PID:%d\n", parentPid);

    k = atoi(argv[1]);
    if(k == 0) {
        printf(1, "level %d\n", i);
        printf(1, "Exiting code...\n", i);
        exit();
    }else{
        //printf(1, "level %d\n", i);
        page_fault(k - 1, 2, 3, 4, 5);
    }

    exit();

}
