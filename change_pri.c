//This is an example program for waitpid.

#include "types.h"
#include "stat.h"
#include "user.h"

#define NULL 0

int
main(int argc, char *argv[])
{
    int parentPid, pid1, i;

    printf(1, "Begin waitpid test\n");
    parentPid = getpid();
    printf(1, "Parent PID:%d\n", parentPid);

    pid1 = fork();
    if(pid1 < 0)
       exit();
    
    if(pid1 == 0){
       pid1 = getpid();
       printf(1, "Child #1 pid: %d. Now exit.\n", pid1);
       printf(1, "Before changing child priority to %d, below are the process info\n", atoi(argv[2]));
       debug();
       changeProcPriority(atoi(argv[2]));
       for (i = 0;;i++) {
          
          printf(1, "After changing child priority to %d, below are the process info\n", atoi(argv[2]));
          debug(); 
          exit();
      //   changeProcPriority(atoi(argv[2]));
//          printf(1, "Inside child process: %d\n", pid1);
            if (i%10000 == 0)
               sleep(10000);
       }  
    }else{

       printf(1, "Before changing parent priority to %d, below are the process info\n", atoi(argv[1]));
       debug();
        
        changeProcPriority(atoi(argv[1]));
        for(i = 0;;i++){
 
       printf(1, "After changing parent priority to %d, below are the process info\n", atoi(argv[1]));
          debug();
           exit();         
 //changeProcPriority(atoi(argv[1]));
  //        printf(1, "Inside parent process\n");
           if (i%10000 == 0)
               sleep(10000);
        }
    }
}
