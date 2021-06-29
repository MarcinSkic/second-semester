#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
	pid_t pid_potomka, pid_parent, pid_off;
	char *komunikat;
	int powtorzen, status;
	printf("Na razie działa jeden proces\n");
	pid_potomka = fork();
	switch (pid_potomka) {
	case -1:
		printf("rozwidlenie procesu nie powiodło się\n");
		exit(1);
	case 0:
		komunikat = "\nJestem potomkiem";
		pid_parent = getppid();
		powtorzen = 5;
		break;
	default:
		komunikat = "\nJestem rodzicem";
		powtorzen = 5;
		pid_off = waitpid(-1,&status,WNOHANG);	//Zad 7.7
		do{
			if(pid_off != 0){
				break;			
			}
			printf("Oczekiwanie na zakonczenie procesu\n");
			sleep (1);
		}while (pid_off == 0);
		
		
		system("ps | grep forkScript");	//Zad 7.4/3
		printf("Koniec dzialania");	//Zad 7.4/2
		exit(0);	//Zad 7.4/1
		break;
	}
	for (; powtorzen > 0; powtorzen--) {
		puts(komunikat);
		if(pid_parent != 0){
			printf("PID rodzica %d\n",pid_parent);	//Zad 7.3
		}
		printf("PID moj %d\n",getpid());	//Zad 7.3
		if(pid_potomka != 0){
			printf("PID potomka %d\n",pid_potomka);	//Zad 7.3
		} else {
			printf("Nie posiadam potomka\n");	
		}
		
		sleep(1);
	}
	system("ps | grep forkScript");	//Zad 7.4/3
	printf("Koniec dzialania");	//Zad 7.4/2
	exit(0);
}
