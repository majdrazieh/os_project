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
  int wtime=0;
  int wwtime=0;
  int rtime=0;
  int wwtime1=0;
  int rtime1=0;
  int wwtime2=0;
  int rtime2=0;
  int wwtime3=0;
  int rtime3=0;
int wtime1=0;
int wtime2=0;
int wtime3=0;



int main(void)
{
  int cid[30];
  int i;
  int n = 30;
  
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
  //printf(1," (i am the parent child %d is finish ) \n", i);
    

}
/*int t;
for(t=0;t<n;t++){
getPerformanceData(&wwtime,&rtime);
         wtime=-1 * wwtime;
   wch=wch+wtime;
    tch=tch+wtime+rtime;

 printf(1," / child %d : wtime = %d , rtime = %d , ttime = %d /\n" , cid[t], wtime, rtime, wtime+rtime);}

 printf(1," / average of wtime of childs is %d  and  average of turnaround time = %d /\n" , (int)(wch/n) ,(int)(tch/n));

*/
int x;
for(x=0;x<n;x++){
if (((getpid())%3)==0){

 getPerformanceData(&wwtime2,&rtime2);
        wtime2=-1 * wwtime2;
printf(1," / child %d : wtime = %d , rtime = %d , ttime = %d /\n" , getpid(), wtime2, rtime2, wtime2+rtime2);

        wq2=wq2+wtime2;
        tq2=wtime2+rtime2+tq2;}
///____________________________________


if (((getpid())%3)==1){//counter of low

getPerformanceData(&wwtime1,&rtime1);
        wtime1=-1 * wwtime1;
printf(1," / child %d : wtime = %d , rtime = %d , ttime = %d /\n" , getpid(), wtime1, rtime1, wtime1+rtime1);      
  wq1=wq1+wtime1;
        tq1=wtime1+rtime1+tq1;
}

//___________________________________

if (((getpid())%3)==2){//counter of high
 getPerformanceData(&wwtime3,&rtime3);
      wtime3=-1 * wwtime3;
printf(1," / child %d : wtime = %d , rtime = %d , ttime = %d /\n" , getpid(), wtime3, rtime3, wtime3+rtime3);
      wq3=wq3+wtime3;
      tq3=wtime3+rtime3+tq3;

}
}

wch=wq3+wq2+wq1;
    tch=tq1+tq2+tq3;
printf(1," / average of wtime of childs is %d  and  average of turnaround time = %d /\n" , (int)(wch/n) ,(int)(tch/n));


printf(1," / average of wtime of queue high is %d  and  average of turnaround= %d /\n" , (int)(wq3/count_q3) ,(int)(tq3/count_q3));
printf(1," / average of wtime of queue low is %d  and  average of turnaround = %d /\n" , (int)(wq1/count_q1) ,(int)(tq1/count_q1));
printf(1," / average of wtime of queue medium is %d  and  average of turnaround = %d /\n" , (int)(wq2/count_q2) ,(int)(tq2/count_q2));

  return 0;

}//main
