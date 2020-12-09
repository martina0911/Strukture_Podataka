#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

typedef struct _red* Pozicija;
typedef struct _red
{
	int El;
	Pozicija next;
}Red;

int Push(int, Pozicija);
int Pop(Pozicija);
int SlucajniBroj(int, int);
int Ispis(Pozicija);

int main()
{
	int odabir = 1;

	srand((unsigned)time(NULL));

	Pozicija R = NULL;
	R = (Pozicija)malloc(sizeof(Red));
	R->next = NULL;

	printf("Izaberite broj:\n\n");
	printf("1 - Push\n2 - Pop\n\n");
	scanf("%d", &odabir);


	while (odabir)
	{
		printf("Izaberite broj:\n");
		printf("0 - KRAJ\n 1 - PUSH\n 2- POP\n\n");
		scanf("%d", &odabir);

		if (strcmp(odabir, '1') == 0)
		{
			printf("Izabrali ste funkciju PUSH!\n\n");
			Push(SlucajniBroj(10, 100), R);
		}

		else if (strcmp(odabir, '2') == 0)
		{
			printf("Izabrali ste funkciju POP!\n\n");
			Pop(R);
		}
		else if (strcmp(odabir, '0') == 0)
			printf("Izlazak iz petlje!\n\n");

	}

	printf("Konacan ispis liste:\n\n");
	Ispis(R->next);


	return 0;
}
int SlucajniBroj(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}
int Push(int x, Pozicija R) //unos na kraj
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(Red));
	if (q == NULL)
	{
		printf("Greska u alokaciji!!\n");
		return -1;
	}

	while (R->next != NULL) {
		R = R->next;
	}

	q->El = x;
	q->next = R->next;
	R->next = q;

	printf("Upisan je broj %d.\n", q->El);

	return 0;
}
int Pop(Pozicija R) 
{
	Pozicija tmp = NULL;
	tmp = (Pozicija)malloc(sizeof(Red));

	tmp = R->next;

	if (tmp == NULL)
	{
		printf("Red je prazan!!\n\n");
		return -1;
	}

	R->next = tmp->next;
	printf("Brise se broj: %d", tmp->El);
	free(tmp);

	return 0;
}
int Ispis(Pozicija R)
{
	if (R == NULL)
	{
		printf("Red je prazan!\n");
		return -1;
	}
	else
	{
		while (R != NULL)
		{
			printf("%d\t", R->El);
			R = R->next;
		}
	}

	return 0;
}
