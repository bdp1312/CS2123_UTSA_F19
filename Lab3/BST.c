/*
Author: Benjamin Parrish
Assignment Number: Lab Assignment 3
File Name: BST.c
Course/Section: CS 2123 Section 003
Due Date: 11/8/2019
Instructor: Dr. Ku
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BST.h"

nodeT* findNode(nodeT *pRoot, int value){
    // base case
    if (pRoot == NULL) {
        return pRoot;
    }

    // If the value to be deleted is smaller than the pRoot's value,
    // then it lies in left subtree
    if (value < pRoot->value){
        return findNode(pRoot->pLeft, value);
    }
    // If the value to be deleted is greater than the pRoot's value,
    // then it lies in right subtree
    else if (value > pRoot->value){
        return findNode(pRoot->pRight, value);
    }
    // if value is same as pRoot's value, then This is the node
    else{return pRoot;}
}

/******************** deleteNode **************************************
Purpose:
 * Deletes a node from a binary tree, replacing it with the node that has the
 * smallest value that is greater than the value of the deleted node.
Parameters:
 * I    nodeT *pRoot    the root of the tree
 * I    int value       the value that needs deleting
Returns:
 * The head of the tree that now has the node deleted. If the value is not in
 * the tree, it will print an error message and return the root.
Notes:
 * Recursive. Uses minValueNode().
**************************************************************************/
nodeT* deleteNode(nodeT *pRoot, int value){
    // base case
    if (pRoot == NULL) {
        printf("Value not found.\n");
        return pRoot;
    }

    // If the value to be deleted is smaller than the pRoot's value,
    // then it lies in left subtree
    if (value < pRoot->value)
        pRoot->pLeft = deleteNode(pRoot->pLeft, value);

    // If the value to be deleted is greater than the pRoot's value,
    // then it lies in right subtree
    else if (value > pRoot->value)
        pRoot->pRight = deleteNode(pRoot->pRight, value);

    // if value is same as pRoot's value, then This is the node
    // to be deleted
    else
    { // node with only one child or no child
        if (pRoot->pLeft == NULL)
        {
            nodeT *temp = pRoot->pRight;
            free(pRoot);
            return temp;
        }
        else if (pRoot->pRight == NULL)
        {
            nodeT *temp = pRoot->pLeft;
            free(pRoot);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        nodeT *temp = minValueNode(pRoot->pRight);

        // Copy the inorder successor's content to this node
        pRoot->value = temp->value;

        // Delete the inorder successor
        pRoot->pRight = deleteNode(pRoot->pRight, temp->value);
    }
    return pRoot;
}

/******************** minValueNode **************************************
Purpose:
 * Finds the smallest value in a tree.
Parameters:
 * I    nodeT *p    the root of the tree
Returns:
 * A pointer to the smallest value in the tree.
Notes:
 * Recursive. If given an empty tree it will display an error message and return
 * the NULL pointer.
**************************************************************************/
nodeT *minValueNode(nodeT *p){
    //if given a null pointer
    if(p==NULL){
        printf("Error");
        return p;
    }
    //returns p when it is the smallest value
    if(p->pLeft==NULL)
        return p;
    minValueNode(p->pLeft);
}


/******************** printTree **************************************
Purpose:
 * Prints the input tree in a horizontal hierarchy.
Parameters:
 * I    nodeT *p    the root of the tree
 * I    int space   Used for spacing of the tree levels
Returns:
 * N/A
Notes:
 * Recursive. If given an empty tree it will do nothing.
**************************************************************************/
void printTree(nodeT *p, int space){
    int i;          //iterator

    //if given an empty tree
    if (p == NULL)
        return;

    space += 5; //increases space between levels

    //processes right side first
    printTree(p->pRight, space);
    printf("\n");

    //where the printing actually happens
    //i starts at 5 so the root is flush with the edge of the screen
    for (i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", p->value);

    //processes left side
    printTree(p->pLeft, space);
}

/******************** printInOrder **************************************
Purpose:
 * Prints the tree's values in order
Parameters:
 * I    nodeT *p    the root of the tree
Returns:
 * N/A
Notes:
 * Recursive. If given an empty tree it will do nothing.
**************************************************************************/
void printInOrder(nodeT *p){
    if(p == NULL)
        return;
    printInOrder(p->pLeft);
    printf("%d ", p->value);
    printInOrder(p->pRight);
}

/***************treeHeightTrace********************************************
Purpose:
  * Helper function for getHeight()
  * Sets passed in int* to tallest value under pRoot
Parameters:
  * nodeT *pRoot  -pointer to the root node of the BST
  * int *recordHeight  -pointer to int that stores the currant maximum height
  * int currentHeight  -stores the value of the curren
Returns:
  * void
Notes:
  recursive, does nothing if given an empty tree
*************************************************************************/
void treeHeightTrace(nodeT* pRoot, int *recordHeight, int currentHeight)
{
  if(pRoot!=NULL){
    if(*recordHeight<currentHeight){
      *recordHeight=currentHeight;
    }
    treeHeightTrace(pRoot->pLeft, recordHeight, currentHeight+1);
    treeHeightTrace(pRoot->pRight, recordHeight, currentHeight+1);
  }
}

/*******************getHeight********************************************
Purpose:
  * Prints the height of tree referanced by pRoot
Parameters:
  * nodeT *pRoot    pointer to the root node of the BST
Returns:
  * int  -height of the tallest branch under pRoot
Notes:
  calls treeHeightTrace() with the values of pRoot and -1
*************************************************************************/
int getHeight(nodeT *pRoot)
{
  int maxHeight = -1;
  treeHeightTrace(pRoot, &maxHeight, 0);
  return maxHeight;
}

void treeNodeTrace(nodeT *pRoot, int *nodeCount)
{
  if(pRoot!=NULL){
    *nodeCount+=1;
    treeNodeTrace(pRoot->pLeft, nodeCount);
    treeNodeTrace(pRoot->pRight, nodeCount);
  }
}

int getNumberOfNodes(nodeT* pRoot)
{
  int nodeCount = 0;
  treeNodeTrace(pRoot, &nodeCount);
  return nodeCount;
}

void treeLeafTrace(nodeT *pRoot, int *leafCount)
{
  if(pRoot!=NULL){
    if(pRoot->pRight!=NULL || pRoot->pLeft!=NULL)
    //check if pRoot has either left or right children
    //recursive call on children if they exist
    //checks each children inividually to reduce recursive calls
    {
      if(pRoot->pLeft != NULL){
        treeLeafTrace(pRoot->pLeft, leafCount);
      }
      if(pRoot->pRight != NULL){
        treeLeafTrace(pRoot->pRight, leafCount);
      }
    }
    //if pRoot exists and has no childern, it is a leaf
    else{ //increament the count by one
      *leafCount+=1;
    }
  }
}

int getNumberOfLeaves(nodeT* pRoot)
{
  int leafCount = 0;
  treeLeafTrace(pRoot, &leafCount);
  return leafCount;
}

void printPreOrder(nodeT* pRoot)
{
  if(pRoot!=NULL){
    printf("%d, ", pRoot->value);
    printPreOrder(pRoot->pLeft);
    printPreOrder(pRoot->pRight);
  }
}

void printPostOrder(nodeT* pRoot)
{
  if(pRoot!=NULL){
    printPostOrder(pRoot->pLeft);
    printPostOrder(pRoot->pRight);
    printf("%d, ", pRoot->value);
  }

}

/******************** report **************************************
Purpose:
 * Displays all information on the Binary tree
Parameters:
 * I    nodeT *p    the root of the tree
Returns:
 * N/A
Notes:
 * Recursive. If given an empty tree it will do nothing. Uses getHeight(),
 * getNumberOfNodes(), getNumberofLeaves(), printTree(), printInOrder(),
 * printPreOrder(), and printPostOrder().
**************************************************************************/
void report(nodeT *p){
    printTree(p, 0);
	printf("\n");
    printf("In Order: \n");
    printInOrder(p);
    printf("\n");

    printf("Pre-order: \n");
    printPreOrder(p);
    printf("\n");

    printf("Post-order: \n");
    printPostOrder(p);
    printf("\n");

    printf("The number of nodes is: %d.\n", getNumberOfNodes(p));
    printf("The number of of leaves is %d.\n", getNumberOfLeaves(p));
    printf("Tree height is: %d.\n", getHeight(p));
    printf("\n");
}

void printSpecs(nodeT *p){
  printf("Tree height is: %d.\n", getHeight(p));
  printf("The number of nodes is: %d.\n", getNumberOfNodes(p));
  printf("The number of of leaves is; %d.\n", getNumberOfLeaves(p));
}

/******************** insert **************************************
Purpose:
 * Inserts Values into a binary tree
Parameters:
 * I    nodeT *p    the root of the tree
 * I    int x       the value to insert
Returns:
 * the root of the tree (pointer).
Notes:
 * Recursive.
**************************************************************************/
nodeT* insert(nodeT *p, int x){
    //If tree is empty or if reached the end of a branch, creates a nodeT
    //and and inserts it
    if(p==NULL){
        return newNodeT(x);
    }
    //if x already exists, it returns a pointer to it.
    //This does not create a new node or overwrite the old one
    if(x == p->value)
        return p;
    //if x is less than p's value, it will overwrite
    //pLeft with the return of the recursion moving left
    else if(x < p->value)
        p->pLeft = insert(p->pLeft, x);
    //if x is greater than p's value, it will overwrite
    //pRight with the return of the recursion moving right
    else
        p->pRight = insert(p->pRight, x);
    //returns p. At end of recursion this will be the pRoot.
    return p;
}

/******************** newNodeT **************************************
Purpose:
 * Creates a new nodeT with initialized values
Parameters:
 * I    int x       the value fro the node
Returns:
 * Pointer to the newly created nodeT
Notes:
 * Recursive.
**************************************************************************/
nodeT* newNodeT(int x){
    //creates a new node
    nodeT *pNew = (nodeT *) malloc(sizeof(nodeT));
    //Prints error if there is a problem with the memory allocation
    if (pNew == NULL){
        printf("Memory allocation error");
        return NULL;
    }
    //initializes the values
    pNew->value = x;
    pNew->pLeft = NULL;
    pNew->pRight = NULL;
    //returns newly created node
    return pNew;
}


nodeT* build(int left, int mid, int right){
    if(left==mid||mid==right)
        return NULL;
    nodeT *pRoot = newNodeT(mid);
    pRoot->pLeft= build(left, ceil((left+mid)/2), mid);
    pRoot->pRight= build(mid, (mid+right)/2, right);
    return pRoot;
}
