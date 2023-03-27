#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(int argc,char *argv[])
{
int pid;
pid =fork();
if(pid<0)
{
fprintf(stderr,"Fork failed \n");
exit(-1);
}
else if(pid==0)
{
execlp("/bin/ls","ls",NULL);
}
else
{
printf("Child Complete");
exit(0);
}
}
