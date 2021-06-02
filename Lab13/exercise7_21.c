#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 2048

int main(void) {

    int fd;
    char * myfifo = "/tmp/myfifo";
    char message[50];

    mkfifo(myfifo, 0666);

    if (fork()) {
        fd = open(myfifo, O_WRONLY);

        for (int i = 0; i < 10; ++i) {
            snprintf(message,50,"Serwer: wysyłam linie nr %d\n", i);
            printf("%s", message);
            fflush(stdout);
            write(fd,&message,50);
            sleep(1);
        }

    } else {
        fd = open(myfifo, O_RDONLY);
        int temp=1;
        while (temp > 0) {
            temp = read(fd,&message,50);
            printf("Serwer wysłał: %s\n", message);
        }
    }
    close(fd);
    return 0;
}