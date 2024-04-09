#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Masina Masina;
typedef struct Nod Nod;

struct Masina
{
	int marca;
	char* nume;
};
struct Nod
{
	Nod* next;
	Masina InfoUtila;
};

void afisareMasina(Masina masina)
{
	printf("\n Masina cu nume %s are marca %d.", masina.nume, masina.marca);
}

void parcurgereLista(Nod* cap)
{
	while (cap != NULL)
	{
		afisareMasina(cap->InfoUtila);
		cap = cap->next;
	}
}

Masina initializareMasina(const char* nume, int marca)
{
	Masina masina;
	masina.marca = marca;
	masina.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(masina.nume, nume);
	return masina;
}

void inserareMasinaInceput(Masina masina, Nod** cap)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->InfoUtila = masina;
	nou->next = *cap;
	*cap = nou;
}

void inserareMasinaSfarsit(Masina masina, Nod** cap)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->InfoUtila = masina;
	nou->next = NULL;

	if ((*cap) != NULL)
	{
		Nod* copie = nou;
		while (copie->next)
		{
			copie = copie->next;
		}
		copie->next = nou;
	}
	else
	{
		*cap = nou;
	}
}

void dezalocare(Nod** cap)
{
	while ((*cap) != NULL)
	{
		free((*cap)->InfoUtila.nume);
		Nod* copie = *cap;
		*cap = (*cap)->next;
		free(copie);
	}

}

int main()
{
	Nod* cap=NULL;
	inserareMasinaInceput(initializareMasina("BMW", 250), &cap);
	inserareMasinaInceput(initializareMasina("Audi", 251), &cap);
	inserareMasinaInceput(initializareMasina("Skoda", 252), &cap);
	inserareMasinaInceput(initializareMasina("Dacia", 253), &cap);
	inserareMasinaInceput(initializareMasina("Volvo", 254), &cap);
	printf("\nParcurgere lista:");
	parcurgereLista(cap);
	printf("\n");
	inserareMasinaSfarsit(initializareMasina("Tesla", 300), &cap);
	printf("\nParcurgere lista dupa inserare la sfarsit:");
	parcurgereLista(cap);
	printf("\n");
	dezalocare(&cap);
	cap = NULL;
}