#ifndef bst_h
#define bst_h
#define _CRT_SECURE_NO_WARNINGS

/*includs*/
#include <stdio.h>
#include <stdlib.h>

/*strucks*/
typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
} TNode;

typedef  struct {
	TNode* root;
	int isFlipped;
} Tree;


/*Functions*/

//Printing the main menu
void displayMenu(); 

//The function accepts a number and returns a pointer to the node containing the number
TNode* find(Tree* pt, int num);

//The function insert a number into a binary tree
void insert(Tree* pt, int num);

//The function printting A tree
void print(Tree t); //use this by start
void print_rec_notFlipped(TNode* t);
void print_rec_Flipped(TNode* t);

//The function returns the maximum number in the tree
int Max(Tree t);

//The function returns the minimum number in the tree
int Min(Tree t);

//The function flip the tree
void flip(Tree* pt); //use this by start
void flip_rec(TNode* pt);

//The function delete A tree
void freeTree(Tree* pt);  //use this by start
void freeTree_rec(TNode* pt);

//Creat A new Node
TNode* newNode(int num);

#endif // !bst_h
