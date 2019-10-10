#include<stdio.h>
#include"BenjaminParrishLab1Part1.c"

int main(void){
	double b;
	int e;
	printf("enter a real number, then an integer: ");
	scanf("%lf %d", &b, &e);
	printf("The fuction returns: %f\n", recursivePow(b,e));
	return 0;
}
