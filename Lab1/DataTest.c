

//Bible Reversal program
//program will read in text from bible.txt write the text in reverse to the file

#include<stdlib.h>
#include<stdio.h>



int main(void){
	FILE *fp;
	fp=fopen("bible.txt", "r");
	if(fp==NULL){printf("No file found\n");}
	
	fseek(fp, 0L, SEEK_END);
	long int end=ftell(fp);
	
	printf("%li\n", end);
		
	char *cntnr = malloc(sizeof(char)*(end+1));
	
	fseek(fp, 0L, SEEK_SET);
	unsigned cnt = fread(cntnr, sizeof(char), end+1, fp);

	printf("%li, %u\n", end+1, cnt);
	
	
	for(int i=0;i<30;++i){printf("%c", cntnr[i]);}	// prints first 30 chars
	printf("\n");
	for(int i=end-30; i<end; ++i){printf("%c", cntnr[i]);}	//print last 30 chars	
	free(cntnr);	

	return 0;
}
