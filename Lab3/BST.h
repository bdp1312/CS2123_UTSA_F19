/*
Author: Benjamin Parrish
Assignment Number: Lab Assignment 3
File Name: BST.h
Course/Section: CS 2123 Section 003
Due Date: 11/8/2019
Instructor: Dr. Ku
*/
#ifndef _BST_H
#define _BST_H

//structure for the tree nodes
typedef struct nodeT{
    struct nodeT *pLeft, *pRight;
    int value;
}nodeT;

//prototypes
nodeT* insert(nodeT *p, int x);
nodeT* newNodeT(int x);
void printTree(nodeT *p, int space);
void printInOrder(nodeT *p);
void report(nodeT *p);
nodeT* deleteNode(nodeT *pRoot, int value);
nodeT *minValueNode(nodeT *p);
nodeT* build(int left, int mid, int right);

//METHODS TO ADD
nodeT* findNode(nodeT *pRoot, int value);//writen, compiled, working
int getHeight(nodeT *pRoot);//writen, compiled, working
int getNumberOfNodes(nodeT* pRoot);//writen, compiled, working
int getNumberOfLeaves(nodeT* pRoot);//writen, compiled, working
void printPreOrder(nodeT* pRoot);//writen, compiled, working
void printPostOrder(nodeT* pRoot);//writen, compiled, working
void printSpecs(nodeT *pRoot);//writen, compiled, working
#endif
