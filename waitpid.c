// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

#define N  1000
/*
void
printf(int fd, const char *s, ...)
{
  write(fd, s, strlen(s));
}
*/
void
forktest(void)
{
  //int n, 
  int pid, options, waitVal;
  int status;

  printf(1, "fork test\n");

//  for(n=0; n<N; n++){
    pid = fork();
    if(pid < 0)
      exit();
    if(pid == 0){
      exit();
    }else {
       options = 0;
       status = 10;
       waitVal = waitpid(22,&status, options); 
       printf(1, "parent of %d , status : %d, waitval %d \n", pid, status, waitVal);
       waitVal = waitpid(pid,&status, options); 
       printf(1, "parent of %d , status : %d, waitval %d \n", pid, status, waitVal);
    }
  //}
/*
  if(n == N){
    printf(1, "fork claimed to work N times!\n", N);
    exit();
  }

  for(; n > 0; n--){
    if(wait() < 0){
      printf(1, "wait stopped early\n");
      exit();
    }
  }

  if(wait() != -1){
    printf(1, "wait got too many\n");
    exit();
  }

  printf(1, "fork test OK\n");
  */
}

int
main(void)
{
  forktest();
  exit();
}
