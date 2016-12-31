#include "types.h"
#include "user.h"

int main(void)
{
int cpid=fork();
if(cpid<0)
printf(1,"fork faild %d \n" ,cpid);
else if(cpid>0)
{
printf(1,"i am the parent my pid is %d childpid is %d \n" ,getpid(),cpid);
wait();
}
else{
printf(1,"i am the child my pid is %d my parent is %d \n ", getpid(),getppid());}
exit();
}
