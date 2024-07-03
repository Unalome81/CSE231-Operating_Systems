To compile all the files and run the shell -> make
-------------------------------------------------------------------------------------------------------------------------------------
Q2)
1. Overview:
This C program acts as a shell to build a special unix system with the help of fork(), exec() and wait() system calls.

2. Code Explanation:
- Word Process:
    - We start in the word process.
    - We use a while loop to simulate a terminal that keeps on accepting commands and until we "EXIT" to exit the shell.
    - We read the input line using fgets()
    - After taking the input, we use strtok() to split the input line into words.
    - Based, on what the command's first word is we process it further. If it is word, we treat it as an internal command and process it further.
    - If it is, dir or date, we treat it as an external command and create a child prcess using fork() and then using execvp() 
    we start a new process dir/dat based on the input. Otherwise, for any other first word (except EXIT )it throws an error.
    - When the command is of word type, we check futher if its a valid command and then open the required text files accordingly.
    - Once we have opened the text file, we read all the content as a whole,using fread(), then using strtok() we again count the
     number of words in it. 
    - If the command has option -n, we ignore /n(newline character) word
    - After this, we go back to accepting input from the user.

- Dir Process:
    - This process takes the processed (split into words) input from the dir process as string arguments.
    - Based on the option provided we proceed further.
    - For the default case, when the directory already exists, we don't have to do anything else.
    - For the -v option, when the directory already exists, we simply print that it already exists.
    - For the -r option, when the directory already exists, we call the remove_directory() function and send it the directory name.
    - In the remove_directory() function, we recursively remove all the files in it using remove_file() function  and when we reach the final empty directory,
      we remove it using rmdir() function. After that we create a new directory using mkdir()
    - When the directory does not exist, for the default, -v and -r option, a new directory is created using mkdir() function.
    - After this, the path is changed to the new directory
    - In the case of -v directory is created, path changed is also printed.

- Date Process:
    - This process takes the processed (split into words) input from the dir process as string arguments.
    - Based on the option provided we proceed further.
    - For the default case and the -d case, time is displayed as a String using ctime()
    - For -R option, RFC 5322 format time is displayed using strfttime() function.