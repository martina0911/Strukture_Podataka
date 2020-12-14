/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	MENI OVO NE RADI I TRENUTNO NE ZNAM BOLJE, ALI POSTAVILA SAM DA VIDITE DA SAM U 
	PROCESU I KAD BUDEM MALO PAMETNIJA, ISPRAVIT CU KOD! 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _stog* Pozicija;
typedef struct _stog
{
	int El;
	Pozicija next;
}Stog;

int CitanjeDatoteke(char*);
int Push(int, Pozicija);
int Pop(Pozicija);
int Ispis(Pozicija);
int Zbroj(Pozicija);
int Razlika(Pozicija);
int Produkt(Pozicija);
int Kolicnik(Pozicija);

int main()
{
	Pozicija S = NULL;
	S = (Pozicija)malloc(sizeof(Stog));
	S->next = NULL;

	char* buffer = NULL;
	buffer = (char*)malloc(sizeof(char));
	if (buffer == NULL)
	{
		printf("Greska u alokaciji!\n");
		return -1;
	}

	CitanjeDatoteke(&buffer);

	int i = 0;

	while (buffer[i] != NULL)
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
			Push(buffer[i], S);

		else if (buffer[i] == '+')
			Zbroj(S);

		else if (buffer[i] == '-')
			Razlika(S);

		else if (buffer[i] = '*')
			Produkt(S);

		else if (buffer[i] = '/')
			Kolicnik(S);

		else if (buffer[i] == '(')
			Pop(S);

		i++;
	}

	printf("\nIspis stoga:\n\n");
	Ispis(S->next);

	return 0;
}
int CitanjeDatoteke(char* brojac)
{
	FILE* fp;
	fp = fopen("Postfix.txt", "r");
	if (fp == NULL)
	{
		printf("Greska u otvaranju datoteke!\n");
		return -1;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s", *brojac);
	}

	return 0;
}
int Push(int x, Pozicija S) //unos na pocetak
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(Stog));
	if (q == NULL)
	{
		printf("Greska u alokaciji!\n");
		return -1;
	}

	q->El = x;
	q->next = S->next;
	S->next = q;

	printf("Upisan je broj %d.\n", q->El);

	return 0;
}
int Pop(Pozicija S)
{
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
	}
		return 0;
}
int Zbroj(Pozicija S)
{
	while (S->next->next != NULL)
		S = S->next;

	S->El = S->El + S->next->El;
	S->next = NULL;

	Push(S->El, S);

	return 0;
}
int Razlika(Pozicija S)
{
	while (S->next->next != NULL)
		S = S->next;

	S->El = S->El - S->next->El;
	S->next = NULL;

	Push(S->El, S);

	return 0;
}
int Produkt(Pozicija S)
{
	while (S->next->next != NULL)
		S = S->next;

	S->El = S->El * S->next->El;
	S->next = NULL;

	Push(S->El, S);

	return 0;
}
int Kolicnik(Pozicija S)
{
	while (S->next->next != NULL)
		S = S->next;

	S->El = S->El / S->next->El;
	S->next = NULL;

	Push(S->El, S);

	return 0;
}
int Ispis(Pozicija S)
{
	if (S == NULL)
	{
		printf("Stog je prazan!\n");
		return -1;
	}
	while (S != NULL)
	{
		printf("%d\n", S->El);
		S = S->next;
	}

	return 0;
}
