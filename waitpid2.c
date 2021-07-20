#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h>

//waitpid test file 
int main(int argc, char *argv[]){
    printf(1,"running waitpid and exit1 (new wait and exit syscalls) \n\n");
    int exitstatus;
    int options = 2; //placeholder for argument
    int parent = getpid();
    printf(1, "parent pid is: %d\n\n", parent);

    int proc = fork();
    int proc2 = fork();
    
    //overall parent
    //waits for first child process
    if(proc>0 && proc2>0){
       int procid = waitpid(proc2, &exitstatus, options);
       waitpid(proc, &exitstatus, options);
       printf(1, "\nexit status: %d \nterminated pid: %d\n", exitstatus, procid);
       printf(1, "exiting parent: %d\n", getpid());
       exit1(5);
    }

    //child process
    //from second call to fork in original parent
    if(proc>0 && proc2==0){
       printf(1, "\nexiting child: %d\n", getpid()); 
       exit1(5);
    }

    //child of child process
    //grandchild of parent process
    if(proc==0 && proc2==0){
       printf(1, "\nexiting child of child: %d\n" , getpid());
       exit1(5);
    }
    //parent process and child process
    //from first call to fork, waits for grandchild to terminate
    if(proc==0 && proc2>0){
       int procid = waitpid(proc2, NULL, options);
       printf(1, "\nexit status: %d \nterminated pid: %d\n", exitstatus, procid);
       printf(1, "exiting first child of parent: %d\n" , getpid());
       exit1(5);
    }
    
        
    return 0;
}
