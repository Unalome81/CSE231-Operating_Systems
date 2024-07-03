#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int f = 1;
    int n_i = 10; // No. of iterations.
    int n_p = 3; // No. of Processes

    int policy[] = {SCHED_OTHER, SCHED_RR, SCHED_FIFO};
    const char* policy_name[] = {"SCHED_OTHER", "SCHED_RR", "SCHED_FIFO"};
    struct sched_param params[n_p];

    //Assigning Default priorities
    params[0].sched_priority = 0;
    params[1].sched_priority = 1;
    params[2].sched_priority = 1;

    long long int time;

    for(int i = 0; i < n_p; ++i)
    {
        FILE* fp;
        fp = fopen(policy_name[i], "w");
        if(fp == NULL)
            perror("File not opened");
        fclose(fp);
    }

    for (int i = 0; i < n_i; ++i)
    {
        for (int j = 0; j < n_p; ++j)
        {
            f = fork();
            if (f < 0)
            {
                perror("Fork Failed");
                exit(1);
            }
            else if (f == 0)
            {

                int s = sched_setscheduler(0, policy[j], &params[j]);
                if (s == -1)
                {
                    perror("Scheduling Failed");
                    exit(1);
                }

                int e = execl("./Counting", "./Counting", policy_name[j], NULL);
                if (e == -1)
                {
                    perror("Exec Failed");
                    exit(1);
                }
            }
            else
            {
                continue;
            }
        }

        for (int k = 0; k < n_p; ++k) // Waits for all child processes to end before the next iteration begins
        {
            wait(NULL);
        }
    }
    return 0;
}
