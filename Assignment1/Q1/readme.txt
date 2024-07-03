
To compile all the files -> make; make run<A/B1/B2>
-------------------------------------------------------------------------------------------------------------------------------------
A) (1)
1. Overview:
This C program demonstrates the use of fork() to create a child process and provides insight into how process IDs (PIDs) are assigned and displayed.

2. Code Explanation:
- The program starts with the parent process and prints its own PID.
- It uses fork() to create a child process.
- The parent process waits for the child process to finish.
- In the child process, it prints its own PID and the PID of its parent.
- After the child process ends, the parent process displays the PID of the terminated child.
Done
-------------------------------------------------------------------------------------------------------------------------------------
B) (1)

1. Overview:
   This C program demonstrates the use of vfork() to create a child process.

2. Code Explanation:
   - The program starts by using the vfork() system call to create a child process.
   - In the child process:
     - The current process image is replaced using execvp() with the executable file generated from the "factorial.c" source code.
     - The factorial of 4 is calculated using a simple while loop, and the result is printed.
   - In the parent process:
     - It waits for the child process to end.
     - It calculates the Fibonacci sequence up to the 16th number and prints the sequence.


-------------------------------------------------------------------------------------------------------------------------------------
B) (2)
1. Overview:
   This C program is similar to the past one, but in this case, the child process waits for the parent process to end.

2. Code Explanation:
   - The program starts by using the fork() system call to create a child process.
   - In the parent process it calculates the Fibonacci sequence up to the 16th number and prints the sequence.
   - In the child process:
    -  It waits for the parent process to end using waitpid(getppid(), 0, 0);
    - The factorial of 4 is calculated using a simple while loop, and the result is printed.
 