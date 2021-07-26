#include "bst.h"

int main()
{
	char action;
	int num;

	Tree t;
	t.root = NULL;
	t.isFlipped = 0;

	displayMenu();
	while (1)
	{
		printf("-------------------------------------------- ");
		printf("\nselect an option from the menu: ");
		fseek(stdin, 0, SEEK_END);
		scanf("%c", &action);
		fseek(stdin, 0, SEEK_END);
		switch (action)
		{
		case 'A': case 'a':
			printf("Insert number: ");
			scanf("%d", &num);
			insert(&t, num);
			break;
		case 'F': case 'f':
			printf("Insert number: ");
			scanf("%d", &num);
			if (find(&t, num)) printf("The number %d is in the tree\n", num);
			else printf("The number %d is NOT in the tree\n", num);
			break;
		case 'P': case 'p':
			print(t);
			printf("\n");
			break;
		case 'B': case 'b':
			if (t.root == NULL) printf("The tree is empty\n");
			else printf("The maximum value in the tree is: %d\n", Max(t));
			break;
		case 'S': case 's':
			if (t.root == NULL) printf("The tree is empty\n");
			else printf("The minimum value in the tree is: %d\n", Min(t));
			break;
		case 'L': case 'l':
			if (t.root == NULL) printf("The tree is empty\n");
			else 
			{
				printf("Before flip- ");
				print(t);
				flip(&t);
				printf("\nAfter flip- ");
				print(t);
				printf("\n");
			}
			break;
		case 'D': case 'd':
			freeTree(&t);
			t.root = NULL;
			printf("The tree was deleted\n");
			break;
		case 'X': case 'x':
			if (t.root) printf("The tree is NOT empty.. Cannot exit\n");
			else {
				printf("Bye Bye\n");
				return 0;
			}
			break;
		default:
			printf("Illegal action: %c. Try again.\n", action);
		}
	}
	return 0;
}
