//This is an example program to test our priority scheduler, follows similar format of waitpid from lab1
// LAB 2 PS test case
#include "types.h"
#include "stat.h"
#include "user.h"
<<<<<<< Updated upstream
 
   
#define NULL 0 
 
int 
main(void)
{
    int parentPid, pid1, pid2; // three processes, two children one parent
    
    printf(1, "Begin priority scheduling test\n");
    parentPid = getpid();
    printf(1, "Parent PID:%d\n", parentPid); //print parent pid
    
    pid1 = fork(); // fork first child process
    
    //enter if first child
    if(pid1==0){
      changeProcPriority(9); // set to  priority 9 main program will keep running 
      sleep(400); //wait 4 seconds, during this time child two should change its priority
      printf(1, "Exiting child process with priority 9: %d\n", getpid()); //done sleeping, this should be printed after child 2 finishes
      debug(); //print out process information
      printf(1, "\n");
      exit(); //exit process
    }
    
    pid2 = fork(); // fork second child process
       
    if(pid2 == 0){
      changeProcPriority(3);  // set to higher priority than default and first child, main program will keep running 
      sleep(400);  //wait 4 seconds, after this time, this process should finish first
      printf(1, "Exiting child process with priority 3: %d\n", getpid()); //let user know this process will exit soon
      debug(); //print out process info
      printf(1, "\n");
      exit(); //exit process
    }
    
    if(pid1>0){ //main process waits for two children to finish before exiting (no zombie)
       printf(1, "Now wait in parent process %d for children to exit\n", getpid());
       wait();
       wait();    //purpose of these wait statements are so there are no zombies
       debug();   //print out process info
    } 
   printf(1, "Exiting parent\n"); 
   exit();  //finish test case
   return 0; 
} 




