#include <stdio.h>
#include <stdlib.h>
#include "myfunction.h"

int main(int argc, char* args[]){
	if(argc == 3){
		int a = atoi(*(args+1));
		int b = atoi(*(args+2));
		int r = myfunction(a,b);
		printf("the answer is %d\n", r);
		return r;
	} else{
		printf("missing arguments\n");
		return -1;
	}
}
