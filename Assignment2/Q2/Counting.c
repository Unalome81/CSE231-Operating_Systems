#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<math.h>
#include <time.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    struct timespec start_time;
    struct timespec end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    long long int i = 1;
    while(i <= pow(2, 30))
    {
        ++i;
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    long long time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000;


    FILE *fp = NULL;

    fp = fopen(argv[1], "a");
    if(fp == NULL)
        perror("File not opened");
    else
    {
        fprintf(fp, "%lld \n", time);
        printf("%s: %lld\n\n", argv[1], time);
    }

    fclose(fp);

    return 0;
}