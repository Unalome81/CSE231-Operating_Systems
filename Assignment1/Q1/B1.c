#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t chk=vfork();
    if(chk<0)
        fprintf(stderr,"Fork failed");
    else if(chk == 0)
    {   char* arr[]={"./factorial",'\0'};
        int ckk = execv("./factorial", arr);
        if(ckk == -1)
            perror("execv");
    } 
    else
    {
    wait(NULL);
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
       printf("\n");
    }
    return 0;
}