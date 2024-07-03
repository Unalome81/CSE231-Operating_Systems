#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>
#include<stdlib.h>
int Counter(char* fname, int type)
{
    int n = 0;
    FILE *fp;
    char* text = NULL;
    char* token = NULL;
    fp = fopen(fname, "r");
    if(fp == NULL)
    {
        printf("File Not Found\n");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    text = (char *)malloc(size + 1);
    fread(text, 1, size, fp);    
    text[size] = '\0';

    fclose(fp);

    token = strtok(text, " ");
    while (token != NULL)
    {
        if ( !(type == 1 && !strcmp("\n", token)) )
            n++;
        token = strtok(NULL, " ");
    }
    free(text);
    return n;
}

int main()
{
    char inp[100];
    char* token;
    char str[50][100];
    int count;
    int type;
    while(1)
    {
        count = 0;
        fgets(inp, sizeof(inp), stdin);

        char *newline = strchr(inp, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        if(!strcmp(inp, "EXIT"))
            break;

        token = strtok(inp, " ");
        while (token != NULL  && count <50)
        {
            strcpy(str[count], token);
            count++;
            token = strtok(NULL, " ");
        }

        char **str_final = (char **)malloc((count + 1) * sizeof(char *));
        if (str_final == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        for (int i = 0; i < count; i++) {
            str_final[i] = (char *)malloc((strlen(str[i]) + 1) * sizeof(char));
            if (str_final[i] == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            strcpy(str_final[i], str[i]);
        }

        str_final[count] = NULL;

        if(!strcmp(str[0], "word"))
        {
            if(count<2)
            {
                printf("Error: Too few arguments for word command\n");
            }
            else
            {
                if(!strcmp(str[1], "-d"))
                {
                    char fname1[100];
                    char fname2[100];
                    strcpy(fname1, str_final[2]);
                    strcpy(fname2, str_final[3]);
                    type = 2;

                    int n1, n2;
                    n1 = Counter(fname1, type);
                    if(n1 >= 0)
                    {
                        n2 = Counter(fname2, type);
                        printf("n1 = %d\n", n1);
                        printf("n2 = %d", n2);
                        if(n2 >= 0)
                        {
                            printf("\n %d\n", n1 - n2);
                        }
                    }
                }       
                else
                {
                    int n = 0; // Number of words in file
                    char fname[100];
                    if (!strcmp(str[1], "-n"))
                    {
                    strcpy(fname, str_final[2]);
                    type = 1;
                    }
                    else
                    {
                        strcpy(fname, str_final[1]);
                        type = 2;
                    }
                    n = Counter(fname, type);
                    if(n>=0)
                    {
                        printf("n = %d\n", n);
                    }
                }     
            }
        }
        else if(!strcmp(str_final[0], "dir"))
        { 
            pid_t chk=fork();
            if(chk < 0)
            {
                printf("\n Fork Failed");
            }
            else if(chk == 0)
            {
                int chk = execv("./dir", str_final);
                if(chk == -1)
                    perror("execv");
            }
            else
            {
                wait(NULL);
            }
        }
        else if(!strcmp(str[0], "date"))
        {
            pid_t chk=fork();
            if(chk < 0)
            {
                printf("\n Fork Failed");
            }
            else if(chk == 0)
            {
                int chk = execv("./date", str_final);
                if(chk == -1)
                    perror("execv");
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            printf("%s  is not recognized as an internal or external command, operable program or batch file.\n", str[0]);
        }
    }   
    printf("\n");
    
    return 0;
}