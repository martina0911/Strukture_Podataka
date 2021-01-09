/*Napisati program koji omogućava rad s binarnim stablom pretraživanja.
Treba omogućiti unošenje novog elementa u stablo, ispis elemenata, brisanje i pronalaženje nekog elementa.*/


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct _node;
typedef struct _node* Position;
typedef struct _node
{
	int number;
	Position left;
	Position right;
}Node;

Position insert(Position current, Position El);
Position find(Position current, int number);
void printInOrder(Position current);
Position deleteNode(Position current, int number);
Position findMax(Position current);
Position findMin(Position current);

int main()
{
	Position root = NULL;
  root = (Position) malloc (sizeof (Node));
	Position El;
  int selection = 1;
  
  while (selection)
  {
    printf("\nIzaberite broj:\n);
    printf("\n1-Unesite element u stablo\n2-Pronadite element\n3-Izbrisi\n4-Ispis\n\n);
    scanf("%d ", &selection);
           switch(selection)
           {
             case 1:
                     {
                      
  
	return 0;
}

Position insert(Position current, Position El)
{
	if (NULL == current)
		return El;
	if (current->number > El->number)
	{
		current->left = insert(current->left, El);
	}
	else if (current-> number < El->number)
	{
		current->right = insert(current->right, El);
	}
	else
	{
		free(El);
	}

	return current;
}

Position find(Position current, int number)
{
	if (NULL == current)
		return NULL;

	if (current->number > number)
	{
		return find(current->left, number);
	}
	else if (current->number < number)
	{
		return find(current->right, number);
	}
	else
    return current;
}

void printInOrder(Position current)
{
	if (NULL == current)
		return;

	printInOrder(current->left);
	printf("%d ", current->number);
	printInOrder(current->right);

}

Position deleteNode(Position current, int number)
{
	if (NULL == current)
		return NULL;

	if (current->number == number)
	{
		/*if (current->left == NULL && current->right == NULL)
		{
			free(current);
			return NULL;
		}*/
		
		if (current->left != NULL)
		{
			Position tmp = findMax(current->left);
			current->number = tmp->number;
			current->left = deleteNode(current->left, tmp->number);
		}
		else if (current->right != NULL)
		{
			Position tmp = findMin(current->right);
			current->number = tmp->number;
			current->right = deleteNode(current->right, tmp->number);
		}
		else
		{
			free(current);
			return NULL;
		}
	}
	else if (current->number > number)
	{
		current->left = deleteNode(current->left, number);
	}
	else //if (current->number < number)
	{
		current->right = deleteNode(current->right, number);
	}

  return current;
}

Position findMax(Position current) 
{
	if (NULL == current)
		return NULL;

	while (current->right != NULL)
		current = current->right;

	return current;
}
Position findMin(Position current)
{
	if (NULL == current)
		return NULL;

	while (current->left != NULL)
		current = current->left;

	return current;
}
