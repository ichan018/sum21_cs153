//
// This example program tries to call the system call page_fault() recursively to show the stack grows correctly.
//
// Usage: page_fault_test a b c d e
// Argument a: The number of times you want to call function page_fault_test()
// Argument b, c, d, e: Can be any arbitary integer which we just pass to page_fault_test() as argument to put on the stack 
// 
// Example: page_fault_test 1000 2 3 4 5      
// Note: the above example should cause a page fault and our trap handler will account for this,
// also the address of a0 will be printed out along with this and we can see where the stack stores it

#include "types.h"
#include "stat.h"
#include "user.h"
int k;
int m = 10;

void page_fault_test(int a, int b, int c, int d, int e){
    if(a == 0) {
        printf(1, "level %d address %p\n", a,  &a); //finish when a is 0
        exit();
    }else{
        printf(1, "level %d address %p\n", a, &a); //print out address of a to show location on stack
        //execute function page_fault_test() recursively
        page_fault_test(a-1, b, c, d, e); 
    }
}

int
main(int argc, char *argv[])
{

    printf(1, "Begin page_fault_test test\n");

    k = atoi(argv[1]);
    if(k == 0) {
        printf(1, "level %d\n", k);
        printf(1, "Exiting code... input argv[1] > 0 please!\n");
        exit();
    }else{
        page_fault_test(k - 1, 2, 3, 4, 5);
    }

    exit();

}
