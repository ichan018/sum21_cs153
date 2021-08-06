//This is an example program to test our priority scheduler, follows similar format of waitpid from lab1
#include "types.h"
#include "stat.h"
#include "user.h"


#define NULL 0

int
main(void)
{
    int parentPid, pid1, pid2;

    printf(1, "Begin priority scheduling test\n");
    parentPid = getpid();
    printf(1, "Parent PID:%d\n", parentPid);
    changeProcPriority(1); // make parent process high priority so it will keep running 
                           // while first child priority is changed to high priority and is waiting

    pid1 = fork();

    if(pid1==0){
      changeProcPriority(7); // set to higher priority than default, main program will keep running since it is higher
      sleep(1000);
      printf(1, "Exiting child process with priority 7: %d\n", getpid());
      exit();
    }

    pid2 = fork();
    
    if(pid2 == 0){
      changeProcPriority(5);  // set to higher priority than default and first child, main program will keep running since it is higher
      sleep(1000);
      printf(1, "Exiting child process with priority 5: %d\n", getpid());
      exit();
    }
    if(pid1>0 && pid2>0){ //main process waits for two children to finish before exiting
       printf(1, "Now wait in parent process %d for children to exit\n", getpid());
       wait();
       wait();
    }
   printf(1, "Exiting parent\n"); 
   exit();
   return 0; 
}