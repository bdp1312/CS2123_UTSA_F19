#include <stdio.h>

long int calc(long int i){
	if(i==1){return 1;}
	return ((i/i)+calc(i-1));
}

int main(){
	long int value;
	printf("enter a positive interger: ");
	scanf("%ld", &value);
	value = calc(value);	
	printf("calculated value is: %ld\n", value);
	return 0;
}
