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
    char * myfifo = "/student/Desktop/Lab13/myfifo";
    char message[50];

    mkfifo(myfifo, 0666);
    fd = open(myfifo, O_RDONLY);

    int temp=1;

    while (temp > 0) {
        temp = read(fd,&message,50);
        printf("Serwer wysłał: %s", message);
    }
    
    close(fd);
    return 0;
}