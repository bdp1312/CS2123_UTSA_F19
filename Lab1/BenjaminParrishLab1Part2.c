

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

typedef struct charNode{
	char data;
	struct charNode *next;
	struct charNode *last;
}charNode;

typedef struct headNode{
	charNode*next;
} headNode;

typedef headNode *LinkedList;

charNode *createNode(char data){
	charNode*myNode=malloc(sizeof(charNode));
	myNode->data=data;
	myNode->next=NULL;
	myNode->last=NULL;
	return myNode;
}

LinkedList makeList(){	//initalizes an empty list
	LinkedList myList = malloc(sizeof(headNode));
	myList->next = NULL;	//head pointer points at nothing
	return myList;
}

//checks if lList is empty, returns 0 if empty, else 1
int isEmpty(LinkedList lList){
	if(lList->next==NULL){return 0;}
	else{return 1;}
}

//returns pointer to last node in list, NULL if list is empty 
//ALWAYS CHECK FUNCTION OUTPUT BEFORE USING
charNode *lastNode(LinkedList lList){
	charNode* nodeptr = lList->next;
	if(nodeptr != NULL){
		while(nodeptr->next != NULL){nodeptr = nodeptr->next;}
	}
	return nodeptr;
}

//creates and adds node to end of list
void pushNode(LinkedList lList, char data){	//takes a headNode referance and pushed character
	charNode *myNode = createNode(data);
	if(isEmpty(lList)==0){
		myNode->last=NULL;
		lList->next=myNode;
	}else{
		myNode->last = lastNode(lList);
		myNode->last->next=myNode;
	}
}
			

LinkedList toList(char *string, int length){	//takes char pointer and array length
	LinkedList myList=makeList();	//initialize list
	int i ;
	for(i=0; i<length; ++i){pushNode(myList, string[i]);}
	return myList;
}	


void deleteList(LinkedList myList){
	while(myList->next!=NULL){
		charNode*temp=myList->next;
		myList->next=myList->next->next;
		free(temp);
	}
	free(myList);
	myList==NULL;
}


charNode *index(LinkedList myList, int i){
	charNode *rover=myList->next;
	int n;
	for(n=0;n<i;++n){
		if(rover==NULL){return rover;}
		else{rover=rover->next;}
	}
	return rover;
}

int size(LinkedList myList){
	charNode *rover=myList->next;
	int s=0;
	while(rover!=NULL){
		++s;
		rover=rover->next;
	}
	return s;
}

void recursiveReverse(LinkedList myList, long start, long end){
	if(start>=end){return;}
	long mid = (end+1-start)/2;
	long lowBreak=start+mid-1;
	long highBreak=end+1-mid;
	recursiveReverse(myList, start, lowBreak);
	recursiveReverse(myList, highBreak, end);
	
	charNode*newStart=index(myList, highBreak);
	charNode*newEnd=index(myList, end)->next;
	
	index(myList, end)->next=index(myList, start);
	index(myList, lowBreak)->next=newEnd;

	if(myList->next==index(myList, start)){
		myList->next=newStart;
	}else{
		index(myList, start-1)->next=newStart;
	}
}
/*

index(myList, end)->next=index(myList, start)->next;
	charNode*temp=index(myNode, lowBreak)->next;
			temp

	index(myList, lowBreak)->next = index(myList, end)->next;

	
*/
	
int main(){
	LinkedList list0=makeList();
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
}
