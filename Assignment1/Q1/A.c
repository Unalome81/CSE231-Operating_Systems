#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t P_pid= getpid();
    printf("Parent (P) is having ID : %d \n",P_pid); //A
    pid_t chk=fork();
    if(chk<0)
        fprintf(stderr,"Fork failed");
    else if(chk == 0)
    {
        printf("Child is having ID: %d\n", getpid()); //C
        printf(" My Parent ID is %d\n", P_pid); //D
    } 
    else
    {
        pid_t cpid=wait(NULL);
        printf("ID of P\'s Child is %d\n",cpid); //B
    }
    return 0;
}