

//Bible Reversal program
//program will read in text from bible.txt write the text in reverse to the file

#include<stdio.h>



int main(void){
	FILE *fp;
	fp=fopen("bible.txt", "r+");
	if(fp==NULL){printf("No file found\n");}
	
	long begin=ftell(fp);
	printf("%ld\n", begin);	

	fseek(fp, -7, SEEK_END);
	long readpt=ftell(fp);
	for(int i=0;i<7;++i){
		printf("at index %ld ", ftell(fp));
		printf("%d, ", fgetc(fp));
		if(feof(fp)){printf("\nEND OF FILE\n");}}
	long end=ftell(fp);
	printf("index is: %ld\n", end);
	

	
	//char
	//cntnr = malloc(sizeof(int)*end);
	fread(cntnr, sizeof(int), end, fp);
	for(int i =0;i<end; ++i){
		printf("%c", cntnr[i]);
	}
	
//	for 
//	printf("%c %c %c\n", 

	return 0;
}
