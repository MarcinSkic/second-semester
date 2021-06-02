#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//podstawowa wersja programu wyświetla cykliczne 3 napisy po
//naciśnięciu CTRL+C
//zakończenie programu CTRL+\ (SIGQUIT)

char napisy[3][80]={"Ha! Ha! Ha! To tylko sygnał powierzchowny!\
    n", "Tylko proces %d śmieje się sygnałowi %d prosto w twarz!\n",
    "Auć - to bolało!\n"};
int nr_napisu=0;

void druga_obsluga_sig_int(int sig){
    printf("Dobrze! Dobrze! Juz koncze!");
    exit(0);
}

void obsluga_sig_int(int sig) {
    printf(napisy[nr_napisu],getpid(),sig);
    nr_napisu=((nr_napisu + 1)%3);
    if(nr_napisu == 3){
        signal(SIGINT,druga_obsluga_sig_int);
    }
    sleep (3);
}


int main(int argc, char** argv) {
    struct sigaction cos;

    
    sigaddset(&cos.sa_mask,SIGINT);
    sigaddset(&cos.sa_mask,SIGQUIT);
    
    cos.sa_handler = obsluga_sig_int;
    cos.sa_flags = 0;
    
    sigaction(SIGINT,&cos, NULL);
    //signal(SIGINT,obsluga_sig_int);

    while (1) {
        printf("Cześć tu proces: %d\n",getpid());
        sleep(1);
    }
    return 0;
}
