#include <stdio.h>
#include "utility.h"


int number;
int min;
int max;
int count(int min, int max){
	printf("enter a number\n");
	scanf("%d", &number);
	while(number<min ||  number>max){
		printf("enter a number\n");
		scanf("%d", &number);
	}
	
	return number; 

}
