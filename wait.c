#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
int i,pid,exitstat,status;
pid=fork();
if(pid==0)
{
printf("enter exit stat:");
scanf("%d",&i);
exit(1);
}
else
{
wait(&status);
if((status & 0xff)!=0)
{
printf("Signal interrupted\n");
}
else
{
exitstat=(int)status/256;
printf("Exit status from %d was %d\n",pid,exitstat);
}
}
}
