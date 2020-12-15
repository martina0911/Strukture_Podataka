#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct _stog* Pozicija;
typedef struct _stog
{
	int El;
	Pozicija next;
}Stog;

int CitanjeDatoteke(char*, Pozicija);
int Push(int, Pozicija);
int Pop(Pozicija);
int Ispis(Pozicija);
int Operacije (int, int, int*, char);

int main()
{
	Pozicija S = NULL;
	S = (Pozicija)malloc(sizeof(Stog));
	S->next = NULL;

	char* buffer = NULL;
	buffer = (char*)malloc(1000 * sizeof(char));
	if (buffer == NULL)
	{
		printf("Greska u alokaciji!\n");
		return -1;
	}

	CitanjeDatoteke(&buffer, S);

	printf("\nIspis stoga:\n\n");
	Ispis(S->next);

	return 0;
}
int CitanjeDatoteke(char* buffer, Pozicija S)
{
	int i = 0;
	int x, y;
	int rezultat;
	FILE* fp;
	fp = fopen("Postfix.txt", "r");
	if (fp == NULL)
	{
		printf("Greska u otvaranju datoteke!\n");
		return -1;
	}
	
	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		
		//Provjera je li dani znak broj
		
		if (isdigit(buffer[i]))
		{
			sscanf(buffer, "%d", &x);
				Push(x, S);
				printf(" (%d) ", x);
		}
		//Ako nije operand (broj) nego operator
		else
		{
			y = Pop(S);
			x = Pop(S);
			Operacije(x, y, &rezultat, buffer[i]); //prvo se skida y sa stoga i ide desno, a drugi x!!!
			printf("Rezultat ove operacije je: %d\n", rezultat);
			Push(rezultat, S);
		}
		
		i++;
	}
	
	fclose(fp);
	free(buffer);
	
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
	int x;
	Pozicija tmp = NULL;
	tmp = (Pozicija)malloc(sizeof(Stog));

	tmp = S->next;
	x = tmp->El;
	
	if (tmp == NULL)
	{
		printf("Stog je prazan!!\n\n");
		return -1;
	}

	S->next = tmp->next;
	printf("Brise se broj: %d", tmp->El);
	free(tmp);
	
	}
	return x;
}
int Operacije(int x, int y, int* rezultat, char operator)
{
	switch (operator)
	{
		case '+':
		{
			*rezultat = x + y;
			break;
		}
		case '-':
		{
			*rezultat = x - y;
			break;
		}
		case '*':
		{
			*rezultat = x * y;
			break;
		}
		case '/':
		{
			if (y == 0)
			{
				printf("Dijeljenje nulom!\n");
				return -1;
			}
				*rezultat = x / y;
			break;
		}
		default:
		{
			break;
		}
	}

	return 0;
}
int Ispis(Pozicija S)
{
	while (S != NULL)
	{
		printf("%d\n", S->El);
		S = S->next;
	}

	return 0;
}
