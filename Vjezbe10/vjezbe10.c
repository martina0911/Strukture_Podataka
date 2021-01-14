#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATA_SIZE (11)

struct _treeNode;
typedef struct _treeNode* TreeNodePosition;
typedef struct _treenode
{
	char data[DATA_SIZE];
	TreeNodePosition left;
	TreeNodePosition right;
}TreeNode;

struct _listNode;
typedef struct _listNode* ListNodePosition;
typedef struct _listNode
{
	TreeNodePosition treeNode;
	ListNodePosition next;
}ListNode;

TreeNodePosition create(char* data)
{
	TreeNodePosition node = NULL;

	node = (TreeNodePosition)malloc(sizeof(TreeNode));

	if (NULL == node)
	{
		printf("Greska u alokaciji!\n");
		return NULL;
	}

	strcpy(node->data, data);
	node->right = ;
	node->left = ;

	return node;
}

TreeNodePosition create(char* data);
int pushFront(ListNodePosition head, TreeNodePosition treeNode);
int pushBack(ListNodePosition head, TreeNodePosition treeNode);
TreeNodePosition popFrong(ListNodePosition head);
TreeNodePosition readFromFile(char* fileName);
int IsNumber(char* data);

int main(void)
{



	return 0;
}

int pushFront(ListNodePosition head, TreeNodePosition treeNode)
{
	ListNodePosition listNode = (ListNodePosition)malloc(sizeof(ListNode));

	if (NULL == listNode)
	{
		printf("Greska u alokaciji!\n");
		return -1;
	}	

	listNode->treeNode = treeNode;
	listNode->next = head->next;
	head->next = listNode;

	return 0;
}

int pushBack(ListNodePosition head, TreeNodePosition treeNode)
{
	ListNodePosition p = head;

	while (p->next != NULL)
		p = p->next;


	return pushFront(p, treeNode);
}

TreeNodePosition popFrong(ListNodePosition head)
{
	ListNodePosition first = head->next;
	TreeNodePosition result = NULL;

	if (NULL == first)
		return NULL;

	head->next = first->next;
	result = first->treeNode;
	free(first);

	return result;
}
TreeNodePosition readFromFile(char* fileName)
{
	FILE* fp = NULL;
	ListNode head ;
	TreeNodePosition result;

	fp = fopen(fileName, "r");

	if (NULL == fp)
	{
		printf("Nije otvorena datoteka!\n");
		return NULL;
	}

	while (!feof(fp))
	{
		TreeNodePosition node = NULL;
		char data[DATA_SIZE] = { 0 };
		fscanf(fp, "%s", data);

		node = create(data);

		if (NULL == node)
		{
			fclose(fp);
			return NULL;
		}

		if (IsNumber(data))
		{
			pushFront(&head, node);

		}

		else
		{
			node->right = pushFront(&head);

			if (NULL == node->right)
			{
				printf("Postfix writtenf in file %s isn't good!\n", fileName);
				return NULL;
			}
			if (NULL == node->left)
			{
				printf("Postfix writtenf in file %s isn't good!\n", fileName);
				return NULL;
			}

			pushFront(&head, node);
		}
	}

	result = popFront(&head);

	if (NULL == result)
	{
		printf("Postfix writtenf in file %s isn't good!\n", fileName);
	}
	if (popFornt(&head))
}

int IsNumber(char* data)
{
	int number = 0;

	if (sscanf(data, "%d", &number) == 1)
		return 1;

	return 0;
}
