3.SIMULATION OF UNIX COMMANDS 
1. Write a program for the simulation of ls command. 
#include<stdio.h> 
#include<dirent.h> 
main() 
{ 
char dirname[10]; 
DIR*p; 
struct dirent *d; 
printf("Enter directory name\n"); 
scanf("%s",dirname); 
p=opendir(dirname); 
if(p==NULL) 
{ 
perror("Cannot find directory"); 
exit(-1); 
} 
while(d=readdir(p)) 
printf("%s\n",d->d_name); 
} 
2. Write a program for the simulation for grep command. 
#include<stdio.h> 
#include<string.h> 
main() 
{ 
char fn[10],pat[10],temp[200]; 
FILE *fp; 
printf("Enter file name\n"); 
scanf("%s",fn); 
printf("Enter pattern to be searched\n"); 
scanf("%s",pat); 
fp=fopen(fn,"r"); 
while(!feof(fp)) 
{ 
fgets(temp,1000,fp); 
if(strstr(temp,pat)) 
printf("%s",temp); 
} 
fclose(fp); 
} 
29
4. CPU SCHEDULING ALGORITHMS I 
FIRST COME FIRST SERVED (FCFS) 
Program: 
#include<stdio.h> 
struct process 
{ 
int burst,wait; 
}p[20]={0,0}; 
int main() 
{ 
int n,i,totalwait=0,totalturn=0; 
printf("\nEnter The No Of Process  :"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("Enter The Burst Time (in ms) For Process #%2d :",i+1); 
scanf("%d",&p[i].burst); 
} 
printf("\nProcess \t Waiting Time  TurnAround Time "); 
printf("\n        
\t   (in ms)         
for(i=0;i<n;i++) 
{ 
(in ms)"); 
printf("\nProcess # %-12d%-15d%-15d",i+1,p[i].wait,p[i].wait+p[i].burst); 
p[i+1].wait=p[i].wait+p[i].burst; 
totalwait=totalwait+p[i].wait; 
totalturn=totalturn+p[i].wait+p[i].burst; 
} 
printf("\n\nAVERAGE\n--------- "); 
printf("\nWaiting    Time : %f ms",totalwait/(float)n); 
printf("\nTurnAround Time : %f ms\n\n",totalturn/(float)n); 
return 0; 
} 
Output: 
Enter The No Of Process  :3 
Enter The Burst Time (in ms) For Process # 1 :10 
Enter The Burst Time (in ms) For Process # 2 :30 
Enter The Burst Time (in ms) For Process # 3 :20 
Process          
Process # 1           
Process # 2           
Process # 3           
AVERAGE --------- 
Waiting Time  TurnAround Time 
(in ms)         
(in ms) 
0              
10             
40             
10 
40 
60 
Waiting    Time : 16.666667 ms 
TurnAround Time : 36.666667 ms 
30
SHORTEST JOB FIRST(SJF) 
Program: 
#include<stdio.h> 
struct process{ 
int burst,wait,no; 
}p[20]={0,0}; 
int main(){ 
int n,i,j,totalwait=0,totalturn=0; 
printf("\nEnter The No Of Process  :"); 
scanf("%d",&n); 
for(i=0;i<n;i++){ 
printf("Enter The Burst Time (in ms) For Process #%2d :",i+1); 
scanf("%d",&p[i].burst); 
p[i].no=i+1; 
} 
for(i=0;i<n;i++) 
for(j=0;j<n-i-1;j++) 
if(p[j].burst>p[j+1].burst){ 
p[j].burst^=p[j+1].burst^=p[j].burst^=p[j+1].burst; 
p[j].no^=p[j+1].no^=p[j].no^=p[j+1].no; 
} 
printf("\nProcess \t Waiting Time  TurnAround Time "); 
for(i=0;i<n;i++){ 
printf("\nProcess # %-12d%-15d%-15d",p[i].no,p[i].wait,p[i].wait+p[i].burst); 
p[i+1].wait=p[i].wait+p[i].burst; 
totalwait=totalwait+p[i].wait; 
totalturn=totalturn+p[i].wait+p[i].burst; 
} 
printf("\n\nAverage\n---------"); 
printf("\nWaiting    Time : %f ms",totalwait/(float)n); 
printf("\nTurnAround Time : %f ms\n\n",totalturn/(float)n); 
return 0; 
} 
Output: 
Enter The No Of Process  :3 
Enter The Burst Time (in ms) For Process # 1 :20 
Enter The Burst Time (in ms) For Process # 2 :30 
Enter The Burst Time (in ms) For Process # 3 :10 
Process          
Process # 3           
Process # 1           
Process # 2           
Average --------- 
Waiting Time  TurnAround Time 
0              
10             
30             
10 
30 
60 
Waiting    Time : 13.333333 ms 
TurnAround Time : 33.333333 ms 
31
 32
 
5.CPU SCHEDLING ALGORITHMS II 
 
PRIORITY SCHEDULING 
 
Program: 
 
#include<stdio.h> 
struct process{ 
int burst,wait,no,priority; 
}p[20]={0,0}; 
int main(){ 
int n,i,j,totalwait=0,totalturn=0; 
printf("\nEnter The No Of Process  :"); 
scanf("%d",&n); 
for(i=0;i<n;i++){ 
printf("Enter The Burst Time (in ms) For 
Process #%2d :",i+1); 
scanf("%d",&p[i].burst); 
printf("Enter The Priority           For Process 
#%2d :",i+1); 
scanf("%d",&p[i].priority); 
p[i].no=i+1; 
} 
for(i=0;i<n;i++) 
for(j=0;j<n-i-1;j++) 
if(p[j].priority>p[j+1].priority){ 
p[j].burst^=p[j+1].burst^=p[j].burst^=p[j+1]
 .burst; 
p[j].no^=p[j+1].no^=p[j].no^=p[j+1].no; 
//Simple way to swap 2 var’s 
p[j].priority^=p[j+1].priority^=p[j].priority^
 =p[j+1].priority; 
//printf("j"); 
} 
printf("\nProcess \t Starting   Ending  
Waiting   TurnAround  "); 
printf("\n        \t   Time       Time    Time       
Time  "); 
for(i=0;i<n;i++){ 
printf("\nProcess # %-11d%-10d%-10d%
10d%10d",p[i].no,p[i].wait,p[i].wait+p[i].bu
 rst,p[i].wait,p[i].wait+p[i].burst);  
p[i+1].wait=p[i].wait+p[i].burst; 
totalwait=totalwait+p[i].wait; 
totalturn=totalturn+p[i].wait+p[i].burst; 
} 
printf("\n\nAverage\n---------"); 
printf("\nWaiting    Time : %f 
ms",totalwait/(float)n); 
printf("\nTurnAround Time : %f 
ms\n\n",totalturn/(float)n); 
return 0; 
} 
 
Output: 
 
Enter The No Of Process  :3 
Enter The Burst Time (in ms) For Process # 
1 :30 
Enter The Priority           For Process # 1 :2 
Enter The Burst Time (in ms) For Process # 
2 :20 
Enter The Priority           For Process # 2 :1 
Enter The Burst Time (in ms) For Process # 
3 :40 
Enter The Priority           For Process # 3 :3 
 
Process          Starting   Ending  Waiting   
TurnAround 
                   Time       Time    Time       Time 
Process # 2          0         20        0         20 
Process # 1          20        50        20        50 
Process # 3          50        90        50        90 
 
Average --------- 
Waiting    Time : 23.333333 ms 
TurnAround Time : 53.333333 ms 
 
 
 
 
 
 
 
 
 
 
 33
 
ROUND ROBIN SCHEDULING 
Program: 
#include<stdio.h> 
struct process{ 
int burst,wait,comp,f; 
}p[20]={0,0}; 
int main(){ 
int 
n,i,j,totalwait=0,totalturn=0,quantum,flag=1,
 time=0; 
printf("\nEnter The No Of Process         :"); 
scanf("%d",&n); 
printf("\nEnter The Quantum time (in ms)  
:"); 
scanf("%d",&quantum); 
for(i=0;i<n;i++){ 
printf("Enter The Burst Time (in ms) For 
Process #%2d :",i+1); 
scanf("%d",&p[i].burst); 
p[i].f=1; 
} 
printf("\nOrder Of Execution \n"); 
printf("\nProcess      Starting     Ending     
Remaining"); 
printf("\n       Time        Time        Time"); 
while(flag==1){ 
flag=0; 
for(i=0;i<n;i++){ 
if(p[i].f==1){ 
flag=1; 
j=quantum; 
if((p[i].burst-p[i].comp)>quantum){ 
p[i].comp+=quantum; 
} 
else{ 
p[i].wait=time-p[i].comp; 
j=p[i].burst-p[i].comp; 
p[i].comp=p[i].burst; 
p[i].f=0; 
} 
printf("\nprocess # %-3d  %-10d   %-10d   
%-10d",i+1,time,time+j,p[i].burst
p[i].comp); 
time+=j; 
}}} 
printf("\n\n------------------"); 
printf("\nProcess \t Waiting Time  
TurnAround Time "); 
for(i=0;i<n;i++){ 
printf("\nProcess # %-12d%-15d%
15d",i+1,p[i].wait,p[i].wait+p[i].burst); 
totalwait=totalwait+p[i].wait; 
totalturn=totalturn+p[i].wait+p[i].burst; 
} 
printf("\n\nAverage\n------------------"); 
printf("\nWaiting    Time : %f 
ms",totalwait/(float)n); 
printf("\nTurnAround Time : %f 
ms\n\n",totalturn/(float)n); 
return 0; 
} 
Output: 
Enter The No Of Process         :3 
Enter The Quantum time (in ms)  :5 
Enter The Burst Time (in ms) For Process # 
1 :25 
Enter The Burst Time (in ms) For Process # 
2 :30 
Enter The Burst Time (in ms) For Process # 
3 :54 
Order Of Execution 
Process      Starting     Ending     Remaining 
               Time        Time        Time 
process # 1    0            5            20 
process # 2    5            10           25 
process # 3    10           15           49 
process # 1    15           20           15 
process # 2    20           25           20 
process # 3    25           30           44 
process # 1    30           35           10 
process # 2    35           40           15 
process # 3    40           45           39 
process # 1    45           50           5 
process # 2    50           55           10 
process # 3    55           60           34 
process # 1    60           65           0 
process # 2    65           70           5 
process # 3    70           75           29 
process # 2    75           80           0 
process # 3    80           85           24 
process # 3    85           90           19 
process # 3    90           95           14 
process # 3    95           100          9 
process # 3    100          105          4 
process # 3    105          109          0 
Process      Waiting Time  TurnAround Time 
Process # 1           40             65 
Process # 2           50             80 
Process # 3           55             109 
Average 
Waiting    Time : 48.333333 ms 
TurnAround Time : 84.666667 ms 
7.PRODUCER CONSUMER PROBLEM USING SEMAPHORE 
#include<stdio.h>    /*standard I/O 
routines*/ 
#include<stdlib.h>   /*rand() and strand() 
function*/ 
#include<unistd.h>  /*fork(),etc*/  
#include<time.h>   /*nanosleep,etc*/ 
#include<sys/types.h>/*various type 
definitions*/   
#include<sys/ipc.h>/* general SysV IPC 
structures */  
#include<sys/sem.h>/* semephore fuctions 
and structs*/ 
#define NUM_LOOPS 10 /* number of 
loops to perform*/ 
int main (int argc,char * argv[]) 
{ 
int sem_set_id; /*ID of the semephore set*/ 
int child_pid;/*PID of our chiold process*/ 
int i;/*counter for loop operation*/ 
struct sembuf sem_op;/*structure for 
semaphoreops.*/ 
int rc;/*return value of system calls*/ 
struct timespec delay;/*used for wasting 
time*/ 
/* create a privete semaphore set with one 
semaphore in it */ 
/* with access only to the owner */ 
sem_set_id=semget(IPC_PRIVATE,1,0600)
 ; 
printf("semaphore set created,semaphore set 
id'%d'\n",sem_set_id); 
rc=semctl(sem_set_id,0,SETVAL,0); 
/* fork-off a child process and start a 
producer/consumer job*/ 
child_pid=fork(); 
switch(child_pid) 
{ 
case 0: /*child process here */ 
for(i=0;i<NUM_LOOPS;i++) 
/* block on the semaphore,unless its value 
is non negative*/ 
{ 
sem_op.sem_num=0; 
sem_op.sem_op=-1; 
sem_op.sem_flg=0; 
semop(sem_set_id,&sem_op,1); 
printf("consumer:'%d'\n",i); 
fflush(stdout); 
} 
break; 
default: /* parent process here*/ 
for(i=0;i<NUM_LOOPS;i++) 
{ 
printf("producer:'%d'\n",i); 
fflush(stdout); 
/* increase the value of the semaphore by 
1*/ 
sem_op.sem_num=0; 
sem_op.sem_op=1; 
sem_op.sem_flg=0; 
semop(sem_set_id,&sem_op,1); 
/*pause execution for a little bit,to allow the 
child process to run  and handle some 
request */ 
/* this is done about 25% of the time*/ 
if(rand()>3*(RAND_MAX/4)) 
{ 
delay.tv_sec=0; 
delay.tv_nsec=10; 
nanosleep(&delay,NULL); 
} 
} 
break; 
} 
return 0; 
}
 34
FIRST  FIT 
8.MEMORY MANAGEMENT SCHEMES I 
Program: 
#include<stdio.h> 
struct process{ 
int size; 
char name[20]; 
int id; 
}p[20]={0,0}; 
struct block{ 
int size; 
int id; 
}b[20]={0,0}; 
int main(){ 
int 
nb,np,i,j,totalwait=0,totalturn=0,quantum=4,
 flag=1,time=0; 
printf("\nEnter The No Of Blocks         
scanf("%d",&nb); 
for(i=0;i<nb;i++){ 
:"); 
printf("Enter The Size of Block $ %-3d  
:",i+1); 
scanf("%d",&b[i].size); 
} 
printf("\nEnter The No Of Processes         
:"); 
scanf("%d",&np); 
for(i=0;i<np;i++){ 
printf("Enter The Name of process # %-3d 
:",i+1); 
scanf("%s",p[i].name); 
printf("Enter The Size of process # %-3d     
:",i+1); 
scanf("%d",&p[i].size); 
} 
for(i=0;i<np;i++){ 
for(j=0;j<nb;j++){ 
if(b[j].id==0&&p[i].size<=b[j].size){ 
b[j].id=i+1; 
p[i].id=j+1; 
flag=1; 
break; 
}} 
} 
printf("Block \n\n-----------"); 
printf("\nBlock ID   Block_Size  
Process_Name Process_Size"); 
for(i=0;i<nb;i++){ 
if(b[i].id) 
printf(" \nBlock #%-7d%-10d%-10s%-10d 
",i+1,b[i].size,p[b[i].id-1].name, p[b[i].id
1].size); 
else 
printf(" \nBlock #%-7d%-10dEmpty     
Empty   ",i+1,b[i].size); 
} 
printf("\n\nProcess \n-----------"); 
printf("\nProcess_Name  Process_Size  
Block ID    Block_Size"); 
for(i=0;i<np;i++){ 
if(p[i].id) 
printf(" \nProcess $ %-10s%-10d%-10d%
10d ",p[i].name,p[i].size,p[i].id, b[p[i].id
1].size); 
else 
printf(" \nProcess $ %-10s%-10dWaiting   
Waiting       
",p[i].name,p[i].size); 
} 
printf("\n"); 
} 
Output: 
Enter The No Of Blocks         
:3 
Enter The Size of Block $ 1    :30 
Enter The Size of Block $ 2    :20 
Enter The Size of Block $ 3    :10 
Enter The No Of Processes         
:3 
Enter The Name of process # 1   :P 
Enter The Size of process # 1       
:10 
Enter The Name of process # 2   :Q 
Enter The Size of process # 2       
:30 
Enter The Name of process # 3   :R 
Enter The Size of process # 3       
:20 
Block ----------- 
Block ID   Block_Size  Process_Name 
Process_Size 
Block #1      
Block #2      
Block #3      
Process ----------- 
30        
20        
10        
P         
R         
10 
20 
Empty     Empty 
Process_Name  Process_Size  Block ID    
Block_Size 
Process $ P         
Process $ Q         
10        
30        
1         
30 
Waiting   Waiting 
Process $ R         
20        
2         
20 
35
BEST  FIT 
Program: 
#include<stdio.h> 
#include<conio.h> 
struct process{ 
int size; 
int id; 
}p[20]={0,0}; 
struct block{ 
int no; 
int size; 
int id; 
}b[20]={0,0}; 
int main(){ 
int 
nb,np,i,j,totalwait=0,totalturn=0,quantum=4,
 flag=1,time=0; 
clrscr(); 
printf("\nEnter The No Of Blocks         
scanf("%d",&nb); 
for(i=0;i<nb;i++){ 
printf("Enter The Size of Block $ %-3d  
:",i+1); 
scanf("%d",&b[i].size); 
b[i].no=i+1; 
} 
printf("\nEnter The No Of Processes         
:"); 
scanf("%d",&np); 
for(i=0;i<np;i++){ 
printf("Enter The Size of process # %-3d     
:",i+1); 
scanf("%d",&p[i].size); 
} 
for(i=0;i<nb;i++) 
for(j=0;j<nb-i-1;j++) 
if(b[j].size>b[j+1].size){ 
b[j].size^=b[j+1].size^=b[j].size^=b[j+1].siz
 e; 
b[j].no^=b[j+1].no^=b[j].no^=b[j+1].no; 
} 
for(i=0;i<np;i++){ 
for(j=0;j<nb;j++){ 
if(b[j].id==0&&p[i].size<=b[j].size){ 
b[j].id=i+1; 
p[i].id=b[j].no; 
flag=1; 
break; 
}}} 
printf("Block \n\n-----------"); 
printf("\nBlock_ID   Block_Size  
Process_ID Process_Size"); 
for(i=0;i<nb;i++) 
//for(j=0;j<nb;j++) 
{ 
//if(j+1==b[j].no){ 
if(b[i].id) 
printf(" \nBlock #%-7d%-10d%-10d%-10d 
",b[i].no,b[i].size,b[i].id, p[b[i].id-1].size); 
else 
printf(" \nBlock #%-7d%-10dEmpty     
Empty   ",b[i].no,b[i].size); 
} 
//} 
:"); 
printf("\n\nProcess \n-----------"); 
printf("\nProcess_ID  Process_Size  
Block_ID    Block_Size"); 
for(i=0;i<np;i++){ 
if(p[i].id) 
printf(" \nProcess $ %-3d%-14d%-10d%
10d ",i+1,p[i].size,p[i].id, b[p[i].id-1].size); 
else 
printf(" \nProcess $ %-3d%-14dWaiting   
Waiting       
} 
printf("\n"); 
getch(); } 
Output: 
",i+1,p[i].size); 
Enter The No Of Blocks         
:3 
Enter The Size of Block $ 1    :30 
Enter The Size of Block $ 2    :20 
Enter The Size of Block $ 3    :10 
Enter The No Of Processes         
:3 
Enter The Size of process # 1       
Enter The Size of process # 2       
Enter The Size of process # 3       
Block ----------- 
:10 
:20 
:30 
Block_ID   Block_Size  Process_ID 
Process_Size 
Block #3      
Block #2      
Block #1      
Process ----------- 
10        
20        
30        
1         
2         
3         
10 
20 
30 
Process_ID  Process_Size  Block_ID    
Block_Size 
Process $ 1  10            
Process $ 2  20            
Process $ 3  30            
3         
2         
1         
30 
20 
10
