#include "bst.h"

//Creat A new Node
TNode* newNode(int num)
{
	TNode* new = malloc(sizeof(TNode));
	new->left = NULL;
	new->right = NULL;
	new->data = num;
	return new;
}

//Printing the main menu
void displayMenu()
{
	printf("Please choose: \n");
	printf("A|a - Add a new item to the tree \n");
	printf("F|f - Find a number in the tree \n");
	printf("P|p - Print the tree \n");
	printf("B|b - Find maximum \n");
	printf("S|s - Find minimum \n");
	printf("L|l - Flip tree \n");
	printf("D|d - Delete the tree \n");
	printf("X|x - Exit \n");
}

//The function accepts a number and returns a pointer to the node containing the number
TNode* find(Tree* pt, int num)
{
	TNode* temp = pt->root;
	if (pt->isFlipped == 0)
	{
		while (temp != NULL)
		{
			if (num > temp->data)
			{
				temp = temp->right;
				continue;
			}
			if (num < temp->data)
			{
				temp = temp->left;
				continue;
			}
			return temp;
		}
		return NULL;
	}

	if (pt->isFlipped == 1)
	{
		while (temp != NULL)
		{
			if (num > temp->data)
			{
				temp = temp->left;
				continue;
			}
			if (num < temp->data)
			{
				temp = temp->right;
				continue;
			}
			return temp;
		}
		return NULL;
	}
}

//The function insert a number into a binary tree
void insert(Tree* pt, int num)
{
	if (pt->root == NULL)
	{
		pt->root = newNode(num);
		return;
	}

	TNode* temp = pt->root;

	if (pt->isFlipped == 0)
	{
		while (1)
		{
			if (num > temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = newNode(num);
					return;
				}
				temp = temp->right;
				continue;
			}
			if (num <= temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = newNode(num);
					return;
				}
				temp = temp->left;
				continue;
			}
		}
	}

	if (pt->isFlipped == 1)
	{
		while (1)
		{
			if (num > temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = newNode(num);
					return;
				}
				temp = temp->left;
				continue;
			}
			if (num <= temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = newNode(num);
					return;
				}
				temp = temp->right;
				continue;
			}
		}
	}
}

//The function printting A tree
void print(Tree t)
{
	if (t.root == NULL)
	{
		printf("The tree is empty");
		return;
	}
	printf("The numbers in the tree are: ");
	
	if (t.isFlipped==0)
		print_rec_notFlipped(t.root);

	else if (t.isFlipped == 1)
	{
		print_rec_Flipped(t.root);
		printf("[Flipped tree]");
	}
		
}
void print_rec_notFlipped(TNode* t)
{
	if (t->left != NULL)
	{
		print_rec_notFlipped(t->left);
	}
	printf("%d ", t->data);
	if (t->right != NULL)
	{
		print_rec_notFlipped(t->right);
	}
}
void print_rec_Flipped(TNode* t) 
{
	if (t->right != NULL)
	{
		print_rec_Flipped(t->right);
	}
	printf("%d ", t->data);
	if (t->left != NULL)
	{
		print_rec_Flipped(t->left);
	}
}

//The function returns the maximum number in the tree
int Max(Tree t)
{
	TNode* temp = t.root;
	if (t.isFlipped == 0)
	{
		while (temp != NULL)
		{
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			else
			{
				return temp->data;
			}
		}
	}
	if (t.isFlipped==1)
	{
		while (temp != NULL)
		{
			if (temp->left != NULL)
			{
				temp = temp->left;
			}
			else
			{
				return temp->data;
			}
		}
	}
}

//The function returns the minimum number in the tree
int Min(Tree t)
{
	TNode* temp = t.root;

	if (t.isFlipped==0)
	{
		while (temp != NULL)
		{
			if (temp->left != NULL)
			{
				temp = temp->left;
			}
			else
			{
				return temp->data;
			}
		}
	}
	if (t.isFlipped==1)
	{
		while (temp != NULL)
		{
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			else
			{
				return temp->data;
			}
		}
	}
	
}

//The function flip the tree
void flip(Tree* pt)
{
	if (pt->root == NULL)
		return;
	flip_rec(pt->root);
	pt->isFlipped = (pt->isFlipped+1)%2 ;  //smart change// Replaces if.
}
void flip_rec(TNode* pt)
{
	TNode* temp;
	temp = pt->left;
	pt->left = pt->right;
	pt->right = temp;
	if (pt->right != NULL)
	{
		flip_rec(pt->right);
	}
	if (pt->left != NULL)
	{
		flip_rec(pt->left);
	}
}

//The function delete A tree
void freeTree(Tree* pt)
{
	if (pt->root == NULL)
		return;

	freeTree_rec(pt->root);
	pt->isFlipped = 0;
}
void freeTree_rec(TNode* pt)
{
	if (pt->left != NULL)
	{
		freeTree_rec(pt->left);
	}
	if (pt->right != NULL)
	{
		freeTree_rec(pt->right);
	}
	free(pt);
}
