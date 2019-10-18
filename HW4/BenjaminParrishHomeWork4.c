#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{ //holds data for runner
  char name[20];
  double time;
  int rank;
}runData;
typedef runData*runner; //named runData pointer
/*
typedef struct{
  runner r1;
  runner r2;
  runner r3;
}runData;
typedef runData*race;
*/
void setRank(runner r1, runner r2, runner r3){ //sets the rank of r1
  if(r1->time > r2->time && r1->time > r3->time){ // checks if time is more than both other runners
    r1->rank = 3;   //assigns third palce rank
  }
  else if(r1->time <= r2->time && r1->time <= r3->time){ //chekcs if time is less then or equal tow both other runners
    r1->rank = 1;   //assigns first place rank
  }
  else{           //if not first and not third, then second is the only other option
    r1->rank = 2; //assigns second place rank
  }
}

void printFinish(runner r){ //prints apropriate output string bassed on runner rank
  if(r->rank==1){
    printf("%s - %lf - First Place\n", r->name, r->time);
  }
  if(r->rank==2){
    printf("%s - %lf - Second Place\n", r->name, r->time);
  }
  if(r->rank==3){
    printf("%s - %lf - Third Place\n", r->name, r->time);
  }
}

void printOrder(runner r1, runner r2, runner r3){  //ensures runner's output strings are printed in apropriate order
  int i;
  for(i=1; i<4; ++i){   //iterating through rank ensures rank 1 racers are printed first folowed by rank 2 then rank 2
    if(r1->rank == i){   //since arrays of runners are banned for this assingment must use series of if statments insted
      printFinish(r1);
    }
    if(r2->rank == i){
      printFinish(r2);
    }
    if(r3->rank == i){
      printFinish(r3);
    }
  }
}

runData *makeRunner(char* name, double *time){ //creates a runData node given a name and a time
  runData *runner = malloc(sizeof(runData));    //allocates memory
  strcpy(runner->name, name);
  runner->time=*time;
  return runner;    //returns node referance
}




int main(int argc, char **argv){
  int i;
  char temp;        //used to clear the buffer for fgets()
  char name[20];    //input buffer for the names
  double time;
  printf("Enter the name of the first runner: ");
  //scanf("%c",&temp);
  fgets(name, 20, stdin); //get name from stdin
  for(i=0; i<20; ++i){  //removes trailing '\n' from name
    if(name[i]=='\n'){
      name[i]='\0';
      break;
    }
  }
  printf("Enter the time of the first runner: ");
  scanf("%lf", &time);
  runner r1 = makeRunner(name, &time); //creates runData

  printf("Enter the name of the second runner: ");
  scanf("%c",&temp);    //clear buffer for fgets()
  fgets(name, 20, stdin);
  for(i=0; i<20; ++i){
    if(name[i]=='\n'){
      name[i]='\0';
      break;
    }
  }
  printf("Enter the time of the second runner: ");
  scanf("%lf", &time);
  runner r2 = makeRunner(name, &time);

  printf("Enter the name of the third runner: ");
  scanf("%c",&temp);
  fgets(name, 20, stdin);
  for(i=0; i<20; ++i){
    if(name[i]=='\n'){
      name[i]='\0';
      break;
    }
  }
  printf("Enter the time of the third runner: ");
  scanf("%lf", &time);
  runner r3 = makeRunner(name, &time);

  setRank(r1, r2, r3);  //calls setRank() to give each runner a rank
  setRank(r2, r1, r3);
  setRank(r3, r2, r1);

  printOrder(r1, r2, r3); //prints runners in order of rank

  free(r1);   //free the dynamically alocated runData memory
  free(r2);
  free(r3);

  return 0;
}
