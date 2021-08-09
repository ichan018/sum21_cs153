//This is an example program to test our priority scheduler, follows similar format of waitpid from lab1
#include "types.h"
#include "stat.h"
#include "user.h"


#define NULL 0

int
main(void)
{
    int parentPid, pid1, pid2, pid3;

    printf(1, "Begin priority scheduling test\n");
    parentPid = getpid();
    printf(1, "Parent PID:%d\n", parentPid);

    pid1 = fork();

    if(pid1==0){
      changeProcPriority(15); // set to higher priority than default, main program will keep running 
      sleep(1500);
      printf(1, "Exiting child process with priority 15: %d\n", getpid());
      exit();
    }
 
    pid2 = fork();
    
    if(pid2 == 0){
      changeProcPriority(12);  // set to higher priority than default and first child, main program will keep running 
      sleep(1500);
      printf(1, "Exiting child process with priority 12: %d\n", getpid());
      exit();
    }
 

    pid3 = fork();
    
    if(pid3 == 0){
      changeProcPriority(10);  // set to higher priority than default and first child, main program will keep running 
      sleep(1500);
      printf(1, "Exiting child process with priority 10: %d\n", getpid());
      exit();
    } 


    if(pid1>0 && pid2>0){ //main process waits for two children to finish before exiting (no zombie)
       printf(1, "Now wait in parent process %d for children to exit\n", getpid());
       wait();
       wait();
       wait();
    }
   printf(1, "Exiting parent\n"); 
   exit();
   return 0; 
}
