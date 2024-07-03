-----------------------------------------------------------------------------------------------------------------
Readme Starts here
This readme file Belongs to Os-assignment2 Q3 written by Animesh Pareek and Vivaswan Nawani.

1) How to run->

=> To build : make build
=> To clean : make clean
=> To load module : make load
=> To unload module : make unload
=> To run module: make run
=> To do everything : make
=> To view kernel messages : dmesg

2) What is the code->

=> Include kernel.h , signal.h ,init.h and module.h
=> First we provide info of our module and set is description and License
=> Next we define a function that will run our code for counting processes.
=> This will make use of task_struct and macro for_each_process to iterate over tasks and then updating the count of  process
=> Next we define a function which will be called when our module will exit
=> In last step we will set these two functions in macros module_init and module_exit 

Readme Ends here
------------------------------------------------------------------------------------------------------------------