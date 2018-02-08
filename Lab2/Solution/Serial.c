#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int serial(int *arr){
	int i =0;
	int count = 0;
	for(i; i<1024; i++){
		if(arr[i] == 3){
			count++;
		}
	}
	return count;
}

int main(int argc, char **argv) {
	int arr[1024];
	int i=0;
	srand(time(NULL));
	for(i; i<1024; i++){
		arr[i] = rand()%11;
	}
	printf("%d\n",serial(arr));
}
