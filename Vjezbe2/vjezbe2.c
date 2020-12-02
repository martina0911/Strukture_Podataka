#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _osoba;
typedef struct _osoba* pozicija;
typedef struct _osoba
{
	char ime[100];
	char prezime[100];
	int god;
	pozicija next;
}Osoba;

int UnosP(pozicija);
pozicija UnosEl(pozicija);
int Ispis(pozicija);
int UnosK(pozicija);
pozicija TraziZadnji(pozicija);
int Brisanje(pozicija, char*);
pozicija TraziElement(pozicija);

int main()
{
	pozicija head = NULL;
	head = (pozicija)malloc(sizeof(Osoba));
	head->next = NULL;

	int i, n;
	char prezime[20];

	printf("Unesite broj zeljenih elemenata u listi:\n\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		UnosP(head);
	}
	printf("Ispis liste koju ste unijeli:\n\n");
	Ispis(head->next);
	printf("Unesite jedan element na kraj liste:\n\n");
	UnosK(head);
	printf("Ispis nove liste:\n");
	Ispis(head->next);
	printf("Unesite prezime koje zelite izbrisati s liste:\n\n");
	scanf("%s", &prezime);
	Brisanje(head->next, &prezime);
	printf("Konacan ispis liste:\n\n");
	Ispis(head->next);

	return 0;
}

int UnosP(pozicija p)
{
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(Osoba));
	if (q == NULL)
	{
		printf("Nema slobodnog mjesta u memoriji!\n");
		return -1;
	}

	UnosEl(q);

	q->next = p->next;
	p->next = q;

	return 0;
}

pozicija UnosEl(pozicija q)
{
	printf("Unesite ime, prezime i godinu rodenja:\n");
	scanf("%s %s %d. \n", q->ime, q->prezime, &q->god);

	return 0;
}
int Ispis(pozicija p)
{
	if (p == NULL)
	{
		printf("Lista je prazna!!!\n");
		return -1;
	}
	else
	{
		while (p != NULL)
		{
			printf("%s %s %d.\n", p->ime, p->prezime, p->god);
			p = p->next;
		}
	}

	return 0;
}

int UnosK(pozicija p)
{
	pozicija zadnji = NULL;
	zadnji = TraziZadnji(p);
	UnosP(zadnji);

	return 0;
}
pozicija TraziZadnji(pozicija p)
{
	while (p->next != NULL)
		p = p->next;

	return p;
}
int Brisanje(pozicija p, char* prezime)
{
	pozicija prev = NULL;
	pozicija curr = NULL;

	prev = TraziElement(p, prezime); //trazimo prethodni element

	if (prev == NULL)
	{
		printf("Ta osoba ne postoji u listi!\n\n");
		return -1;
	}

	curr = prev->next;
	prev->next = prev->next->next;
	free(curr);

	return 0;
}
pozicija TraziElement(pozicija p, char* prezime)
{
	pozicija prev = NULL;
	pozicija curr = NULL;

	prev = p;
	curr = p->next;

	while (curr != NULL && strcmp(curr->prezime, prezime) != NULL)
	{
		prev = curr;
		curr = prev->next;
	}
	if (curr == NULL)
		return NULL;
	else
		return prev;

}
