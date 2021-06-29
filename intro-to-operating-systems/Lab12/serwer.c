#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 2048

int main(int argc, char** argv) {
    int i, filedes[2];
    char message[BUF_SIZE];
    char buffer[BUF_SIZE];

    for (i = 0; i < 10; ++i){
        sleep (1);
        snprintf(message, sizeof(message),"Serwer: wysyłam linie nr %d\n",i);
        printf("%s",message);
        fflush(stdout);
    }

    return (EXIT_SUCCESS);
}