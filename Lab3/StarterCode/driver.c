/*
Author:
Assignment Number: Lab Assignment 3
File Name: driver.c
Course/Section: CS 2123 Section 00x
Due Date:
Instructor: Dr. Ku
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BST.h"



/*
 *
 */
int main(int argc, char** argv) {
    nodeT *pRoot = NULL;        //root
    int data;                   //holds the int data
   
    //Insertion of new items, reports when done
    printf("Items to insert (-999 to stop): ");
    scanf("%d", &data);
  
        
    while(data != -999){
        pRoot = insert(pRoot, data);
        printf("Items to insert (-999 to stop): ");
        scanf("%d", &data);
    }
    report(pRoot);

    //deletion of items, reports after each deletion
    printf("Items to delete (-999 to stop): ");
    scanf("%d", &data);
    while(data != -999){
        pRoot = deleteNode(pRoot, data);
        report(pRoot);
        printf("Items to delete (-999 to stop): ");
        scanf("%d", &data);
    }

    return 0;
}




