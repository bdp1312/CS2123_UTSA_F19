/*
Author: Benjamin Parrish
Assignment Number: Lab Assignment 3
File Name: driver.c
Course/Section: CS 2123 Section 003
Due Date: 11/8/2019
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
        printSpecs(pRoot);
        printf("Items to insert (-999 to stop): ");
        scanf("%d", &data);
    }
    report(pRoot);

    //searches tree for requested item, reports when finished
    printf("Now testing the contains() operation.\n Try both items in the BST and some not in it:\n");

    printf("Item to find (-999 to stop): ");
    scanf("%d", &data);

    while(data!=-999){
      nodeT *targetPtr =findNode(pRoot, data);
      if(targetPtr!=NULL){
        printf("Found %d.\n", targetPtr->value);
      } else {
        printf("Value '%d' not found.\n", data);
      }
      printf("Item to find (-999 to stop): ");
      scanf("%d", &data);
    }

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
