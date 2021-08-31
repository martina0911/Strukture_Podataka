#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista* pozicija;
typedef struct lista
{
	int El;
	pozicija next;
}Lista;

int UnosP(pozicija);
int SortUnos(pozicija);
int Ispis(pozicija);
int Unija(pozicija, pozicija, pozicija);
int Presjek(pozicija, pozicija, pozicija);
int Ispis(pozicija);

int main()
{
	int m,n,i;

	pozicija L1 = NULL;
	pozicija L2 = NULL;
	pozicija U = NULL;
	pozicija P = NULL;

	L1 = (pozicija)malloc(sizeof(Lista));
	L2 = (pozicija)malloc(sizeof(Lista));
	U = (pozicija)malloc(sizeof(Lista));
	P = (pozicija)malloc(sizeof(Lista));

	L1->next = NULL;
	L2->next = NULL;
	U->next = NULL;
	P->next = NULL;

	printf("Koliko elemenata zelite u prvoj listi?\n");
	scanf("%d", &m);

	printf("Unesite prvu listu:\n\n");
	for (i = 0; i < m; i++)
	{
		UnosP(L1);
	}
	printf("Koliko elemenata zelite u drugoj listi?\n");
	scanf("%d", &n);
	printf("Unesite drugu listu:\n\n");
	for (i = 0; i < n; i++)
	{
		UnosP(L2);
	}

	//Ispis listi

	printf("Ispis prve liste:\n\n");
	Ispis(L1->next);
	printf("Ispis druge liste:\n\n");
	Ispis(L2->next);

	//Trazenje presjeka i unije

	Unija(L1, L2, U);
	Presjek(L1, L2, P);

	//Ispis unije i presjeka

	printf("Ispis unije:\n\n");
	Ispis(U->next);
	printf("Ispis presjeka:\n\n");
	Ispis(P->next);

	return 0;
}
int UnosP(pozicija p)
{
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(Lista));
	if (q == NULL)
	{
		printf("Greska u alokaciji!!\n");
		return -1;
	}
	SortUnos(p, q);

	return 0;
}
int SortUnos(pozicija p, pozicija q)
{
	scanf(" %d", &q->El);
	while (p->next != NULL && q->El > p->next->El)
		p = p->next;

	q->next = p->next;
	p->next = q;

	return 0;
}
int Ispis(pozicija p)
{
	while (p != NULL)
	{
		printf(" %d", p->El);
		p = p->next;
	}
	printf("\n");
	return 0;
}
int Unija(pozicija L1, pozicija L2, pozicija U)
{
	pozicija q = NULL;
	pozicija pom = NULL;

	while (L1 != NULL && L2 != NULL)
	{
		q = (pozicija)malloc(sizeof(Lista));
		if (q == NULL)
		{
			printf("Greska u alokaciji!\n");
			return -1;
		}
		if (L1->El == L2->El)
		{
			q->El = L1->El;

			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->El > L2->El)
		{
			q->El = L2->El;
			L2 = L2->next;
		}
		else 
		{
			q->El = L1->El;
			L1 = L1->next;
		}

		if (U->El == q->El)
			free(q);

		else
		{
			q->next = U->next;
			U->next = q;
			U = q;
		}

		if (L1 == NULL)
			pom = L2;
		else pom = L1;

		while (pom != NULL)
		{
			q = (pozicija)malloc(sizeof(Lista));
			if (q == NULL)
			{
				printf("Greska u alokaciji!\n\n");
				return -1;
			}
			else
			{
				q->El = pom->El;

				if (pom->El == q->El)
					free(q);
				else
				{
					q->next = U->next;
					U->next = q;
					U = q;
				}
				pom = pom->next;
			}
		}
	}

	return 0;
}
int Presjek(pozicija L1, pozicija L2, pozicija P)
{
	pozicija q = NULL;

	while (L1 != NULL && L2 != NULL)
	{
		q = (pozicija)malloc(sizeof(Lista));
		if (q == NULL)
		{
			printf("Greska u alokaciji!\n\n");
			return -1;
		}
		if (L1->El == L2->El)
		{
			q->El = L1->El;

			q->next = P->next;
			P->next = q;

			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->El > L2->El)
			L2 = L2->next;
		else
			L1 = L1->next;
	}

	return 0;
}
