//Author:		Benjamin Parrish
//Assignment Number:	HW 1
//File Name: 		BenjaminParrishHw1.c
//Course/Section:	CS 2123 Section 003
//Date			8/29/2019
//Instructor		Dr. Bernard Ku


#include <stdio.h>
#include <math.h>
int main(void) {
	int x, y;	//initialize two ints
	float val;	//initialize one float
	printf("Enter x and y: ");
	scanf("%d %d", &x, &y); 	//set x and y to values from stdin
	printf("pow(%d,%d) = %f\n", x, y, pow(x,y));	//prints results of x to the power of y
	printf("Enter value: ");
	scanf("%f", &val);	// set val to result of stdin
	printf("sqrt(%f) = %f\n", val, sqrt(val));	//prints result of sqrt(val), the square root of val
	return 0;
}
