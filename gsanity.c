#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
int child_id;
int n;
 int m;
printf(1,"Father pid is <%d>\n" , getpid());

sleep(100);

    child_id = fork();
	if(child_id <0)
printf(1,"fork faied\n");

    else if (child_id == 0)
    {

for(n=0; n<50 ;n++)
printf(1,"***chiled process <%d> is printing for the <%d>.\n",getpid(),n);
exit();   
 }
    else
    {
     
for(m=0; m<50 ;m++)
printf(1,"*process <%d> is printing for the <%d>.\n",getpid(),m);
exit();  
}

return 0;
}
