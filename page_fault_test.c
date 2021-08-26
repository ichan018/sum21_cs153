//
// This example program tries to call the system call page_fault() recursively to show the stack grows correctly.
//
// Usage: page_fault_test a0 a1 a2 a3 a4
// Argument a0: The number of times you want to call system call page_fault()
// Argument a1, a2, a3, a4: Can be any arbitary integer which we just pass to page_fault() as argument to put on the stack 
// 
// Example: page_fault_test 1000 2 3 4 5 

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
        
        //execute system call page_fault() recursively
        page_fault(a-1, b, c, d, e);
    }
}

int
main(int argc, char *argv[])
{
    int i = 0; // counter for for loop

    printf(1, "Begin page_fault_test test\n");

    k = atoi(argv[1]);
    if(k == 0) {
        printf(1, "level %d\n", i);
        printf(1, "Exiting code...\n", i);
        exit();
    }else{
        page_fault_s(k - 1, 2, 3, 4, 5);
    }

    exit();

}
