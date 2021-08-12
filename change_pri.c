//This is an example program for changing process priority and starvation scheduling policy.
// Usage: change_pri arg1 arg2 arg3
// arg1: new priority for parent process
// arg2: new priority for child process
// arg3: number of times for debug system call (procdump function call)
//
// Example: change_pri 10 16 10
//
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int parentPid, pid1;
    int i; // counter for for loop
    int j; // counter for debug system call

    printf(1, "Begin change_pri test\n");
    parentPid = getpid();
    printf(1, "Parent PID:%d\n", parentPid);

    pid1 = fork();
    if(pid1 < 0)
       exit();
    
    if(pid1 == 0){
       pid1 = getpid();
       printf(1, "\n\nChild PID: %d\n", pid1);
       printf(1, "\nBefore changing child (PID %d) priority to %d, below is the procdump output\n\n", pid1, atoi(argv[2]));
       debug();
      
       changeProcPriority(atoi(argv[2]));
       printf(1, "\nAfter changing child (PID %d) priority to %d, below is the procdump output\n\n", pid1, atoi(argv[2]));
       debug();
 
       sleep(1);
      
       // for every other iteration, debug is called once
       for (i = 0, j = 0;j < atoi(argv[3]);i++) {
            if (i % 2 == 1) {
               printf(1, "\nWhen Child (PID %d) is running at iteration %d in the for loop, below is the procdump output\n\n", pid1, i);
               debug(); 
               j++; // debug is called, so j incremented
            }
       }  
    }else{
       printf(1, "\nBefore changing parent (PID %d) priority to %d, below is the procdump output\n\n", parentPid, atoi(argv[1]));
       debug();
        
       changeProcPriority(atoi(argv[1]));
       printf(1, "\nAfter changing parent (PID %d) priority to %d, below is the procdump output\n\n", parentPid, atoi(argv[1]));
       debug();
 
       sleep(1);  

       for (i = 0, j = 0;j < atoi(argv[3]);i++) {
            if (i % 2 == 1) {
               printf(1, "\nWhen Parent (PID %d) is running at iteration %d in the for loop, below is the procdump output\n\n", parentPid, i);
               debug();
               j++; 
            }
      }
    }
   
    exit();
}
