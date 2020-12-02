#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Studenti
{
	char ime[20];
	char prezime[20];
	int apsbr;
	float relbr;
}Student;

int brojanjeredaka(char niz[]);
void citanje(char niz[], int a, Student* popis);
void ispisStudenata(int n, Student* popis);

int main()
{
	Student* popis;
	int br;
	char niz[100] = { 0 };
	br = brojanjeredaka(niz);

	printf("Broj redaka je: %d\n", br);

	popis = (Student*)malloc(br * sizeof(Student));

	citanje(niz, br, popis);
	ispisStudenata(br, popis);
	return 0;
}
int brojanjeredaka(char niz[])
{
	FILE* fp;

	fp = fopen("Studenti.txt", "r");

	int brojac = 0;
	int i;

	if (fp == NULL)
	{
		printf("Greska u otvaranju datoteke!\n");
	}

	while (!feof(fp))
	{
		fgets(niz, 100, fp);
		if (strlen(niz) > 1)
		{
			brojac++;
		}

	}
	fclose(fp);
	return brojac;
}

void citanje(char niz[], int a, Student* popis)
{
	int i = 0;
	int max = 0;
	FILE* fp;

	fp = fopen("studenti.txt", "r");

	if (fp == NULL)
	{
		printf("Greska u otvaranju datoteke!\n");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s %s %d", popis[i].ime, popis[i].prezime, &popis[i].apsbr);
			if (popis[i].apsbr > max)
				max = popis[i].apsbr;
			i++;
		}
	}
	fclose(fp);
	for (i = 0; i < a; i++)
	{
		popis[i].relbr = popis[i].apsbr / (float) max * 100;
	}
}
void ispisStudenata(int a, Student* popis)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
		printf("%s %s %d %f", popis[i].ime, popis[i].prezime, popis[i].apsbr, popis[i].relbr);
		printf("\n");
	}
}
