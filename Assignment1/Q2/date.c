#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include<string.h>
#include<time.h>
int main(int argc, char *argv[])
{
    if(argc<2){
        fprintf(stderr,"Too less arguments for date!!");
        exit(1);
        return 1;
    }
    struct stat prop;
    if (!strcmp(argv[1], "-d"))
    {
        if(!stat(argv[2],&prop))
        {
            time_t ti=prop.st_mtime;
            printf("The Last Modification Time of the given file is : %s\n",ctime(&ti));
        }
        else
        perror(NULL);
    }
    else if(!strcmp(argv[1], "-R"))
    {   char buff[70];
        if(!stat(argv[2],&prop)){
        time_t ti=prop.st_mtime;
        strftime(buff,sizeof(buff),"%a, %d %b %Y %H:%M:%S %z",localtime(&ti));
        printf("The Last Modification Time of the given file is : %s\n",buff);}
        else
        perror(NULL);
    }
    else 
    {
        if(!stat(argv[1],&prop)){
        time_t ti=prop.st_mtime;
        printf("The Last Modification Time of the given file is : %s\n",ctime(&ti));}
        else
        perror(NULL);
    }
    return 0;
}