#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sig_handler(int signum)
{
    printf("Alarm delivered signum is %d\n", signum);
    exit(0);
}

int main()
{
    char * string = "Creating folder: ";
    size_t length = strlen(string);
    size_t i = 0;

    for(; i < length; i++)
    {
        printf("%c", string[i]);
    }+

    // We can iterate over the array regardless of its size and stop
    // iterating once we reach a null-character:

   printf ("%s", "\n");


    
    alarm(5);
    signal(SIGALRM, sig_handler);
    
    for(;;)
        sleep(1);

    
}