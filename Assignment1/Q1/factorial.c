#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int i = 4, res  = 1;
    do
    {
        res *= i;
    }while(--i);
    printf("Child Process: Factorial of 4 is - %d \n", res);
    return 0;
}