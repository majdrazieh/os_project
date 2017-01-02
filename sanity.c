#include "types.h"
#include "stat.h"
#include "user.h"


     int wch=0;
	int tch=0;
	int count_q1=0;
	int count_q2=0;
	int count_q3=0;
	int wq1=0;
	int tq1=0;
	int wq2=0;
	int tq2=0;
	int wq3=0;
	int tq3=0;



int main(void)
{
	int cid[30];
	int i;
	int n = 30;
	int wtime;
	int wwtime;
	int rtime;
	int k;


	/* Start children. */
	for (i = 0; i < n; i++) {
	cid[i] = fork();

	  if (cid[i] < 0)
  	   printf(1,"fork faild\n");

	   else if (cid[i] == 0) {

			if (((getpid())%3)==0){
			count_q2++;
			nice();}
		else if(((getpid())%3)==1){
                     nice();
			nice();
			count_q1++;//low
			}
			else
			count_q3++;//high


		for(k=0;k<5;k++)
			printf(1," < i am the child %d my pid is %d > \n ",i,getpid());
		    exit();
       	 }
	printf(1," (i am the parent child %d is finish ) \n", i);
		getPerformanceData(&wwtime,&rtime);
          wtime=-1 * wwtime;
//______________________________
		wch=wch+wtime;
		tch=tch+wtime+rtime;
//________________________________
if (((getpid())%3)==0){
wq2=wq2+wtime;
tq2=wtime+rtime+tq2;}
//____________________________________
if (((getpid())%3)==1){//counter of low
wq1=wq1+wtime;
tq1=wtime+rtime+tq1;}
//___________________________________
if (((getpid())%3)==2){//counter of high
wq3=wq3+wtime;
tq3=wtime+rtime+tq3;}


	printf(1," / child %d : wtime = %d , rtime = %d , ttime = %d /\n" , cid[i], (-1)*wtime, rtime, ((-1)*wtime)+rtime);
		}
printf(1," / average of wtime of childs is %d  and  average of turnaround time = %d /\n" , (int)(wch/n) ,(int)(tch/n));
printf(1," / average of wtime of queue low is %d  and  average of turnaround = %d /\n" , (int)(wq1/count_q1) ,(int)(tq1/count_q1));
printf(1," / average of wtime of queue medium is %d  and  average of turnaround = %d /\n" , (int)(wq2/count_q2) ,(int)(tq2/count_q2));
printf(1," / average of wtime of queue high is %d  and  average of turnaround= %d /\n" , (int)(wq3/count_q3) ,(int)(tq3/count_q3));



	return 0;

}//main

