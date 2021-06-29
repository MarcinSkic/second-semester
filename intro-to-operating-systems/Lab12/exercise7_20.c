#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 2048

int main(int argc, char** argv) {
    int i;
    int filedes[2];
    char message[BUF_SIZE];
    char buffer[BUF_SIZE];
    pipe(filedes);

    for (i = 0; i < 10; ++i){
        sleep (1);

        snprintf(message, sizeof(message),"Serwer: wysyłam linie nr %d\n",i);
        write(filedes[1],message,strlen(message));
        read(filedes[0],buffer,BUF_SIZE);

        sleep (2);
        printf("Serwer wysłał: %s", buffer);
        buffer[BUF_SIZE] = 0;

    }

    return (EXIT_SUCCESS);
}