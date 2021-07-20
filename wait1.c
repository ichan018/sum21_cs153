#include "types.h"
#include "stat.h"
#include "user.h"


//test for wait1 and exit1 functionality
//return exit status and have parent wait for child, also return pid
int main(int argc, char *argv[]){
    printf(1,"running wait1 and exit1 (new wait and exit syscalls) \n\n");
    int exitstatus;

    int proc = fork();
    
    //child process
    if(proc==0){
       printf(1, "exiting child process: %d\n", getpid());
       exit1(3);
    }
 
    //parent process
    else{
       int procid = wait1(&exitstatus);
       printf(1, "exiting parent process\n");
       printf(1, "exit status: %d , procid: %d\n", exitstatus, procid);
       exit();
    }
    
        
    return 0;
}
