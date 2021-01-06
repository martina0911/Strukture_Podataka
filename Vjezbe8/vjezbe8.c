#define _CRT_SECURE_NO_WARNINGS
#define MAX (256)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct _direktorij;
typedef struct _direktorij* Cvor;
typedef struct _direktorij
{
	char name [MAX];
	Cvor Child;
	Cvor next;

}Dir;

struct _stog;
typedef struct _stog* Pozicija;
typedef struct _stog
{
	Cvor El;
	Pozicija next;
}Stog;

Cvor NapraviCvor(int);
Pozicija NapraviStog(int);
int MakeDir(Cvor, char*);
int FindDir(Cvor, char*);
int EnterDir(Cvor, char*, Pozicija);
int ExitDir(Cvor, char*, char*, Pozicija);
int Ispis(Cvor, char*);
int Push(Cvor, Pozicija);
int Pop(Pozicija);

int main()
{	
	Cvor root = NULL;
	root = NapraviCvor(1);
	
	Pozicija stog = NULL;
	stog = NapraviStog(1);

	printf("Unesite ime root direktorija:\n");
	scanf("%s", root->name);


	return 0;
}
Cvor NapraviCvor(int n)
{
	Cvor q = NULL;
	q = (Cvor)malloc(n * sizeof(Dir));
	if (q == NULL)
	{
		printf("Greska u alokaciji!");
		return -1;
	}
	q->Child = NULL;
	q->next = NULL;

	return q;
}
Pozicija NapraviStog(int n)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(n * sizeof(Stog));
	if (q == NULL)
	{
		printf("Greska u alokaciji!\n");
		return -1;
	}

	q->El = NULL;
	q->next = NULL;

	return q;
}
int MakeDir(Cvor S, char* ime)
{
	Cvor q = NULL;

}
int Push(Cvor, Pozicija)
{
	return 0;
}
