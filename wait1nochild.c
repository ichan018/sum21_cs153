#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h>

int main(int argc, char *argv[]){
    printf(1,"running wait1 (new wait and syscall) \n\n");
    
    int procid = wait1(NULL);
    
    printf(1, "Following should be -1 \nprocid: %d\n", procid);
    
    exit();
    
    return 0;
}
