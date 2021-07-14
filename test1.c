#include "types.h"
#include "stat.h"
#include "user.h"
//#include "stdio.h"

int main(int argc, char *argv[]){
    printf(1,"running wait1 and exit1 (new wait and exit syscalls) \n\n");
    int exitstatus;

    int proc = fork();
    
    //child process
    if(proc==0){
       exit1(3);
    }
 
    //parent process
    else{
       int procid = wait1(&exitstatus);
       printf(1, "exit status: %d , procid: %d\n", exitstatus, procid);
       exit();
    }
    
        
    return 0;
}
