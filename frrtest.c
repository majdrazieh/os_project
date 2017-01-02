/*

#include "types.h"
#include "stat.h"
#include "user.h"

int main (void){

int pids[5];
int i;
int n = 5;

int w;

	 
	for(i= 0;i<n;i++){
pids[i]=fork();//create n child

if (pids[i]< 0)
 printf(1,"fork failed");

else if(pids[i]== 0){

for( w = 0 ; w<15 ; w++)
printf(1,"w=%d \n" ,w);
printf(1,"my pid=%d \n" ,getpid());

exit();

}
	}


	wait();


  

return 0;
}


*/




#include "types.h"
#include "user.h"
int main (void)
{
 int Pid[10];
int j;
int n=10;
//int k;
int i;
 for( j = 0; j<n ; j++){
  	Pid[j] = fork();
	if(Pid[j] == 0){
	  for( i =0 ; i<8 ; i++);
printf(1,"my pid=%d \n" ,getpid());
		exit();
	}	
		

 for( k = 0 ; k<n ; k++)
	wait();
}
	//exit();
	return 0;
}
