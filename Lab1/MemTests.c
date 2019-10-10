

//Bible Reversal program
//program will read in text from bible.txt write the text in reverse to the file

#include<stdio.h>



int main(void){
	FILE *fp;
	fp=fopen("bible.txt", "r+");
	if(fp==NULL){printf("No file found\n");}
	
	long begin=ftell(fp);
	printf("%ld\n", begin);	

	fseek(fp, 0L, SEEK_END);
	long end=ftell(fp);
	printf("index is: %ld\n", end);
//	for 
//	printf("%c %c %c\n", 

	return 0;
}
