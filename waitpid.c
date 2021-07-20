//This is an example program for waitpid.

#include "types.h"
#include "stat.h"
#include "user.h"

#define NULL 0

int
main(void)
{
    int parentPid, pid1, pid2,  pid3, pid4, options, waitVal;
    int status;

    printf(1, "Begin waitpid test\n");
    parentPid = getpid();
    printf(1, "Parent PID:%d\n", parentPid);
   
    pid1 = fork();
    if(pid1 < 0)
      exit();
    if(pid1 == 0){
       pid1 = getpid();
       printf(1, "Child #1 pid: %d. Now exit.\n", pid1);
       exit();
    }
    
    options = 0;
    status = 10;
    waitVal = waitpid(12345,&status, options); 
    printf(1, "Waitpid output: Nonexistent PID: 12345, exit status : %d, return value: %d \n", status, waitVal);
    
    waitVal = waitpid(pid1,&status, options); 
    printf(1, "Waitpid output: PID: %d , exit status : %d, return value: %d \n", pid1, status, waitVal);

    pid2 = fork();
    if(pid2 < 0)
      exit();
    if(pid2 == 0){
      pid2 = getpid();
      printf(1, "Child #2 pid: %d. Now exit.\n", pid2);
      exit();
    }
    
    waitVal = waitpid(pid2,NULL, options); 
    printf(1, "Waitpid output: PID: %d , exit status : NULL, return value: %d \n", pid2, waitVal);

    pid3 = fork();
    if(pid3 < 0)
      exit();
    if(pid3 == 0){
       pid3 = getpid();
       printf(1, "Child #3 pid: %d. Now exit.\n", pid3);
       exit();
    }

    pid4 = fork();
    if(pid4 < 0)
      exit();
    if(pid4 == 0){
       pid4 = getpid();
       
       options = 0;
       status = 10;
       waitVal = waitpid(pid3,&status, options); 
       printf(1, "Child #4 pid: %d finished waiting for Child #3 pid: %d , exit status : %d, waitpid return value: %d \n", pid4,pid3, status, waitVal);
       printf(1, "Child #4 pid: %d. Now exit.\n", pid4);
       exit();
    }
    
    options = 0;
    status = 10;
    waitVal = waitpid(pid4,&status, options); 

    printf(1, "Parent finished waiting for Child #4 pid: %d , exit status : %d, waitpid return value: %d \n", pid4, status, waitVal);

    exit();
}
