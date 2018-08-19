#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <iostream>

static void sig_usr(int);
int main()
{ 
    if(signal(SIGUSR1,sig_usr)==SIG_ERR)
        perror("signal error:");
    if(signal(SIGUSR2,sig_usr)==SIG_ERR)
        perror("signal 2 error:");

    for(;;)pause();
}

static void
sig_usr(int signo)
{
    if(signo==SIGUSR1)
        printf("receieve signal SIGUSR1\n");
    if(signo==SIGUSR2)
        printf("receieve signal SIGUSR2\n");
    else
        std::cerr<<"reveieve singal"<<signo<<std::endl;
}
