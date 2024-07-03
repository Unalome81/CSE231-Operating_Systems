To compile all the files and run the shell -> make
-------------------------------------------------------------------------------------------------------------------------------------
Q2)
1. Overview:
    This question deals with scheduling policies. We generate several processes with various scheduling policies and then compare
    their execution times.

2. Code Description:
We have 2 C programs and 1 python program in this question.
Scheduling.c 
Counter.c 
Histogram.py 

3. Code Explanation:
- Scheduling.c:
    -This program starts with initializing the scheduling parameters, number of iterations and the number of processes.
    -After that, we run a for loop as per the number of iterations.
    -Then, for every iteration we create 3 child processes in another for loop. These child processes run parallely and independent
     to each other. 
    -In each of these processes we use execl command to replace the current process image with the process image of the Counter.c file.
    -We wait for every child process to die using wait(NULL) at the end of every iteration.

- Counter.c:
    -This program, counts from 1 to 2^32
    -We note the time stamp at the start and at the end of this program using clock_gettime()
    -Based on the arguments that we recieve, we write the time elapsed in either SHED_FIFO, SHED_OTHER or SHED_RR text files
   
- Histogram.py:
    -This program reads the input from the 3 text files and stores them as lists.
    -We then plot these lists as histogram in pairs of 3 for the 10 iterations that we used in Scheduling.C
    -After that, we print the average time of SHED_FIFO, SHED_OTHER, SHED_RR to draw inference.