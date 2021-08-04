//This is an example program for waitpid.

#include "types.h"
#include "stat.h"
#include "user.h"

#define NULL 0

int
main(void)
{
    int parentPid, pid1;
    //, pid2,  pid3, pid4, options, waitVal;
    //int status;

    printf(1, "Begin waitpid test\n");
    parentPid = getpid();
    printf(1, "Parent PID:%d\n", parentPid);

    pid1 = fork();
    if(pid1 < 0)
       exit();
    
    if(pid1 == 0){
       pid1 = getpid();
       printf(1, "Child #1 pid: %d. Now exit.\n", pid1);

      // changeProcPriority(1);
       for (;;) {
        //  changeProcPriority(1);
          printf(1, "Inside child process: %d\n", pid1);
       }  
    }else{
       changeProcPriority(16);
       for(;;){
          //changeProcPriority(16);
          printf(1, "Inside parent process\n");
        }
    }
}
