#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t chk=fork();
    if(chk<0)
        fprintf(stderr,"Fork failed");
    else if(chk == 0)
    {
        waitpid(getppid(), 0, 0);
        int i = 4, res  = 1;
        do
        {
            res *= i;
        }while(--i);
        printf("\nChild Process: Factorial of 4 is - %d \n", res);
    } 
    else
    {
       printf("Parent Process Fibonacci Numbers: \n");
       int first =  0;
       int second = 1;
       int n = 16;
       int res = 0;
       if(n>=0)
       {
            printf("0");
       }
       if(n>=1)
       {
            printf("\t1");
       }
       for(int i = 0; i< n - 2; ++i)
       {
            res = first + second;
            first = second;
            second = res;
           
            printf("\t%d", res);
       }
    }
    return 0;
}