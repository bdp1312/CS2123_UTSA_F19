#include<stdio.h>
#include<string.h>
#include "stackar.h"

/*
//returns integer based on the operand and the two values
int calculate(int oprand1, int oprand2, char oprtr){
	if(oprtr=='+'){return oprand1 + oprand2;} 	//add if +
	if(oprtr=='-'){return oprand1 - oprand2;}	//subtract if -
	if(oprtr=='*'){return oprand1 * oprand2;}	//multiply if *
	if(oprtr=='/'){
		if(oprand2==0){ 		//check for divide by 0
			printf("Error! Divide by 0.");
		}
		else{return oprand1 / oprand2;}	//divide if /
	}
	return 0;
} 
*/

int isOprand(char c){
	if(c=='0'
	||c=='1'
	||c=='2'
	||c=='3'
	||c=='4'
	||c=='5'
	||c=='6'
	||c=='7'
	||c=='8'
	||c=='9'){return 1;}
	else{return 0;}
}

int isOperator(char c){
	if(c=='+'
	||c=='-'
	||c=='*'
	||c=='/'){return 1;}
	else{return 0;}
}
//Funtion takes character [0-9], matches to coresponding int value, returns int
int charToInt(char c){
	if(c=='0'){return 0;}
	if(c=='1'){return 1;}
	if(c=='2'){return 2;}
	if(c=='3'){return 3;}
	if(c=='4'){return 4;}
	if(c=='5'){return 5;}
	if(c=='6'){return 6;}
	if(c=='7'){return 7;}
	if(c=='8'){return 8;}
	if(c=='9'){return 9;}
	else{return -1;}		//returns value -1 if matching digit isnt found
}

//Function takes a string in postfix form, returns calculated value of postfix equation 
int processPostFix(char*postFix, int *error, Stack myStack){ 
	int retVal;				//varible to be returned
	int i;					//increment index
	int opRand1, opRand2; 			//Operand Variables
	long len = strlen(postFix);		//length of postfix equation string
	printf("string length:%lu\n", len);	
	for(i=0;i<len;++i){
		printf("postFix[%d]=%c\n", i, postFix[i]);
		if(isOprand(postFix[i])==1){	//checks if postFix[i] is valid operand
			Push(charToInt(postFix[i]), myStack); //pushes valid operand to myStack
		}
		else if(isOperator(postFix[i])){	//checks if postFix[i] is a valid operator
			if(IsEmpty(myStack)==1){	//if stack is empty, print error, set error to 1, return 0 		
				*error=1;	
				return 0;
			}
			else{				
			opRand2=TopAndPop(myStack);		//Set opRand 1 && 2 to second and first values from top of myStack, respectivly
			}
			if(IsEmpty(myStack)==1){	//if stack is empty, set error to 1, return 0
				*error=1;	
				return 0;
			}
			else{
			opRand1=TopAndPop(myStack);	//see 79
			}
			//performs math operations based on the operand and the two values
			if(postFix[i]=='+'){retVal = opRand1 + opRand2;} 	//add if +
			if(postFix[i]=='-'){retVal = opRand1 - opRand2;}	//subtract if -
			if(postFix[i]=='*'){retVal = opRand1 * opRand2;}	//multiply if *
			if(postFix[i]=='/'){
				if(opRand2 == 0){ 		//check for divide by 0
				*error=2;
				return 0;
				}
			else{return opRand1 / opRand2;}	//divide if /
			}
			Push(retVal, myStack);		//push calculated value value back onto myStack
		}
		else{
		*error=3;
		return 0;
		}
	}
	retVal=TopAndPop(myStack);		//sets retVal to last value in myStack, which is our final result
	if(IsEmpty(myStack)==0){	//if myStack is not empty, sets error, returns one

		*error=4;
		return 0;
		}
	return retVal;
	
}


int main(){
	char postFix[30];			//string that holds postfix expression

	Stack myStack = CreateStack(10);	//create calculation stack 
	int errorVal, mode, input;
	int exit = 0;				//program stays in main loop while exit equals 0
	char *fileName;				//string that holds file name input by user
	FILE *fp = NULL;			//pointer to data fail
	
	printf("Welcome to bash terminal calculator.\n");
	
	while(input!=1 && input!=0){ 		//ensures input is valid
		printf("Enter '1' to input equations from the command line.\n Enter '2' to input equations from a file.\n");
		scanf("%d", &input);		
		if(input!=1){	
			mode=1;			//sets mode varible to value corespoding to terminal input
		}
		if(input!=2){
			mode=2;			//sets mod variable to value corresponding to file input 
		}
		else{printf("Invalid input\n");}		
	}
	if(mode==2){				//protocal for reading in file		
		while(fp==NULL){	
			printf("What file do you want to read from?");	//prompt user for file name
			scanf("%s", fileName);				
			fp = fopen(fileName, "r");			//try to open file
			if(fp==NULL){
				printf("%s not found.\n", fileName);
				do{					//if file name is not present in local directory ask user to specify new file name or quit program	
					printf("Enter '0' to exit.\n Enter '1' to try another file name.\n");
					scanf("%d", &input);		
				} while(input != 1 && input != 0);
				if(input==0){exit = 1; break;} //this will set exit to one and break from loop "while(fp==NULL)" program will skip main while loop and exucute exit lines
			}	//if input == 1, program will prompt user for another file name
		} 
	}

/*MAIN LOOP*/
	while(exit == 0){
	

		errorVal=0; //set to 0 if there are no errors
	
		if(mode==1){
			printf("Enter a postfix string\nNo more than 30 characters\n");
			scanf("%s", postFix);//postfix expression input by keyboard
		}
		else if(mode==2){

		}
		else{
			break;
		}
	//printf("%d\n", strLen);	
	
/*	int i;	
	for(i=0;i<30;++i){
		printf("%d, ", inLine[i]);
	}
	
	printf("\n%s\n", inLine);
*/	
//	printf("Calling processPostfix()\n");
		int result= processPostFix(postFix, &errorVal, myStack);//Calculates postFix expression
		if(errorVal==0){printf("%d\n",result);}
		else if(errorVal==1){printf("Error! Invalid syntax: No opperand for calculation\n");}
		else if(errorVal==2){printf("Error! Divide by 0.\n");}
		else if(errorVal==3){printf("Error! Invalid character input\n");}
		else if(errorVal==4){printf("Error! Stack Not empty\n");}
		else{printf("Calculation terminated due to errors.\n");}
		

		if(mode==1){
			while(input!=0 && input!=1){	
				printf("Enter '1' to exit. Enter '0' to perform another calculation.");
				scanf("%d",&input); 
			}
			input=exit;
		}
		if(mode==2){
			
		}	
	}

/*EXIT STEPS*/
	DisposeStack(myStack);		//frees dynamically alocated memory associated with calculation stack

	return 0;
}
