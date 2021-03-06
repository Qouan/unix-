#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <pwd.h>
#include <iostream>

#include <string.h>
static void
my_alarm(int signo)
{
    struct passwd*rootptr;

    printf("in signal handler\n");
    if((rootptr=getpwnam("root"))==NULL)
        perror("getpwanm(root) error:");

    alarm(1);

}
int main()
{
    struct passwd*ptr;
    signal(SIGALRM,my_alarm);
    alarm(1);
    for(;;)
    {
        if((ptr=getpwnam("sar"))==NULL)
            perror("getpwnan error");
        if(strcmp(ptr->pw_name,"sar")!=0)
            printf("return value corrupted!,pw_name=%s\n",ptr->pw_name);
    }
}
