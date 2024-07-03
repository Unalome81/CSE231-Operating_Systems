#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>
#include <sys/stat.h>
#include<dirent.h>
#include<linux/limits.h>
#include<stdlib.h>
int remove_file(char* fpath)
{
    if (remove(fpath) == 0)  
    {
        return 0; 
    } else 
    {  
        perror("Error: Could not delete file");      
        return 1; 
    }
}

int remove_directory(char *fpath) 
{
    
    DIR *dir;
    if (!(dir = opendir(fpath))) 
    {
        perror("opendir");
        return 1; 
    }

    struct dirent *entry;
    int flag = 0;
    while ((entry = readdir(dir))) 
    {
        
        char fpath_complete[PATH_MAX];
        snprintf(fpath_complete, sizeof(fpath_complete), "%s/%s", fpath, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        struct stat statbuf;
        if (stat(fpath_complete, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            if (remove_directory(fpath_complete) == 1) {
                closedir(dir);
                flag = 1;
                break;
            }
        } else 
        {
            if (remove_file(fpath_complete) == 1) 
            {
                closedir(dir);
                flag = 1;
                break;
            }
        }
    }

    if(flag)
        return 1;

    closedir(dir);

    if (rmdir(fpath) == -1) {
        perror("rmdir");
        return 1;
    }

    return 0; 
}

int main(int argc, char *argv[])
{
    if(argc<2){
        fprintf(stderr,"Too less arguments for date!!");
        return 1;
    }

    char* fname = NULL;

    if(!strcmp("-r", argv[1]))
    {
        fname = argv[2];
        if (access(fname, F_OK) != -1) 
        {
            char fpath[PATH_MAX];

            if (realpath(fname, fpath) == NULL) 
            {
                perror("Error: Could Not get the complete path of the directory");
                return 1;
            }

            if(remove_directory(fpath) == -1)
            {
                perror("Error: Could not remove directory");
                return 1;
            }
        }
        int check =  mkdir(fname, 0777);
        if(check)
        {
            perror("Error creating directory");
            return 1;
        }
    }
    else if(!strcmp("-v", argv[1]))
    {
        fname = argv[2];
        if (access(fname, F_OK) != -1) 
        {
            printf("Directory %s already exists exist", fname);
        }
        else
        {
            int check =  mkdir(fname, 0777);
            if(check)
            {
                perror("Error creating directory");
                return 1;
            }
            else
            {
                printf("Directory Successfully Created\n");
            }
        }
    }
    else
    {
        fname = argv[1];
        if (access(fname, F_OK) != -1) 
        {
            printf("Directory %s already exists exist", fname);
        }
        else
        {
            int check =  mkdir(fname, 0777);
            if(check)
            {
                perror("Error creating directory");
                return 1;
            }
        }
    }

    chdir(fname);
    char buffer[1024];
    if(getcwd(buffer, sizeof(buffer)) != NULL)
    {
        if(!strcmp("-v", argv[1]))
        {
            printf("Path changed to %s \n", buffer);
        }
    }
    else
    {
        perror("getcwd");
    }  
    return 0;
}