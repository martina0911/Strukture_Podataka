#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

typedef struct _stog* Pozicija;
typedef struct _stog
{
	int El;
	Pozicija next;
}Stog;

int Push(int, Pozicija);
int Pop(Pozicija);
int SlucajniBroj(int, int);
int Ispis(Pozicija);

int main()
{
	int odabir = 1;

	srand((unsigned)time(NULL));

	Pozicija S = NULL;
	S = (Pozicija)malloc(sizeof(Stog));
	S->next = NULL;

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
			Push(SlucajniBroj(10, 100), S);
		}

		else if (strcmp(odabir, '2') == 0)
		{
			printf("Izabrali ste funkciju POP!\n\n");
			Pop(S);
		}
		else if (strcmp(odabir, '0') == 0)
			printf("Izlazak iz petlje!\n\n");

	}
	
	printf("Konacan ispis liste:\n\n");
	Ispis(S->next);


	return 0;
}
int SlucajniBroj(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}
int Push(int x, Pozicija S) //unos na pocetak
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(Stog));
	if (q == NULL)
	{
		printf("Greska u alokaciji!!\n");
		return -1;
	}

	q->El = x;
	q->next = S->next;
	S->next = q;

	printf("Upisan je broj %d!\n", q->El);

	return 0;
}
int Pop(Pozicija S) //brisanje s pocetka
{
	Pozicija tmp = NULL;
	tmp = (Pozicija)malloc(sizeof(Stog));

	tmp = S->next;

	if (tmp == NULL)
	{
		printf("Stog je prazan!!\n\n");
		return -1;
	}

	S->next = tmp->next;
	printf("Brise se broj: %d", tmp->El);
	free(tmp);

	return 0;
}
int Ispis(Pozicija S)
{
	if (S == NULL)
	{
		printf("Stog je prazan!\n");
			return -1;
	}
	else
	{
		while (S != NULL)
		{
			printf("%d\t", S->El);
			S = S->next;
		}
	}

	return 0;
}
