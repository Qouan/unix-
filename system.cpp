#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int status;
    if((status=system("date"))<0)perror("system() error:");

    printf("%d",status);  
}
