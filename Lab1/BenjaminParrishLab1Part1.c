#include<stdio.h>
#include<math.h>

double recursivePow(double base, int expo){	//recursively raises the base by a power equal to one more than expo
	//printf("base: %f, expo: %d\n", base, expo);	//dummy print for error testing
	if(base==0){return 0;}	//catches any instance of 0^n
	if(expo>0){return base*recursivePow(base, expo-1);}	//recursivly multiplies base by itself a number of times == the value of expo
	else if(expo<0){return 1/(recursivePow(base, -expo));}	//deals with negative exponents 
	else{return 1;}	//Base case when exponent==0
}	
