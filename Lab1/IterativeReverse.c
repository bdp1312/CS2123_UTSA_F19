

//Bible Reversal program
//program will read in text from bible.txt write the text in reverse to the file

#include<stdlib.h>
#include<stdio.h>


int iterativeReversal(char *string,long int endp){
	int long midp= endp/2;
	char temp;
	for(long int l=0;l<=midp;++l){
		temp=string[l];
		string[l]=string[endp-l];
		string[endp-l]=temp;
	}
	return 0;
}


int main(void){
	FILE *fp;
	fp=fopen("bible.txt", "r");
	if(fp==NULL){printf("No file found\n");}
	
	fseek(fp, 0L, SEEK_END);
	long int end=ftell(fp);
	
	printf("%li\n", end);
		
	char *cntnr = malloc(sizeof(char)*(end+1));
	
	fseek(fp, 0L, SEEK_SET);
	unsigned cnt = fread(cntnr, sizeof(char), end, fp);
	fclose(fp);

	printf("%li, %u\n", end+1, cnt);
	printf("%d, %c\n", cntnr[end-1], cntnr[end-1]);
	
	
/*	for(int i=0;i<30;++i){printf("%c", cntnr[i]);}	// prints first 30 chars
	printf("\n");
	for(int i=end-29; i<=end; ++i){printf("%c", cntnr[i]);}	//print last 30 chars
	*/iterativeReversal(cntnr, end);
	
/*	printf("\n");

	for(int i=0;i<30;++i){printf("%c", cntnr[i]);}	// prints first 30 chars
	printf("\n");
	for(int i=end-29; i<=end; ++i){printf("%c", cntnr[i]);}	//print last 30 chars
*/

/*	for(int i=0; i<=end;++i){
		printf("%c", cntnr[i]);}*/
	fp=fopen("bible1.txt","w");
	fwrite(cntnr, sizeof(char), end, fp);

	free(cntnr);	
	cntnr=NULL;	

	return 0;
}
