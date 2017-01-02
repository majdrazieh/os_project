#include "types.h"
#include "stat.h"
#include "user.h"
int main(void)
{

	

	int pids[5];
	int i;
	int n = 5;
	int wtme;
	int rtime;
int wtime;


	/* Start children. */
	for (i = 0; i < n; i++) {
	pids[i] = fork();

	  if (pids[i] < 0) 
  
		printf(1,"fork faild\n");
		   
	   else if (pids[i] == 0) {
 		int k;
		for(k=0;k<5;k++)
			printf(1," < i am the child %d my pid is %d > \n ",i,getpid());
		    exit();
       	 }


	/* Wait for children to exit. */
	
		printf(1," (i am the parent child %d is finish ) \n", i);	
		getPerformanceData(&wtme,&rtime);
wtime=(-1)*wtme;

		printf(1," / child %d : wtime = %d , rtime = %d , ttime = %d /\n" , pids[i], wtime, rtime, wtime+rtime);
		}
	

	return 0;

}//main
