#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int child(int *arr, int i, int j){
	int count = 0;
	for(i; i<j; i++){
		if(arr[i] == 3){
			count++;
		}
	}
	return count;
}

int main(int argc, char **argv) {
	int len = 1024;
	int n = 4;
	int arr[len];
	int a = len/n;
	pid_t pids[n];
	int i=0;
	int j=0;
	srand(time(NULL));
	for(i; i<len; i++){
		arr[i] = rand()%11;
	}
	for(j; j<n; j++){
		if((pids[j] = fork()) < 0) {
			printf("Error");
			abort();
		} else if(pids[j] == 0) {
			exit(child(arr, a*j, a*(j+1)));
		}
	}
	int status;
	pid_t pid;
	int sum = 0;
	while(n>0){
		pid = wait(&status);
		sum += status/255;
		n--;
	}
	printf("%d sum\n", sum);
}
