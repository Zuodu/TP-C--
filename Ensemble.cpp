/*************************************************************************
Ensemble  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "Ensemble.h"

//----------------------------------------------------- Méthodes publiques
void Ensemble::Afficher()
{
	TriBulle(table, cardCurrent);
	cout << cardCurrent << "\r\n";
	cout << cardMaxi << "\r\n";
	if (cardCurrent == 0) {
		cout << "{}" << "\r\n";
	}
	else if (cardCurrent == 1) {
		cout << "{" << table[0] << "}" << "\r\n";
	}
	else {
		cout << "{";
		for (int i = 0; i<cardCurrent - 1; i++) {
			cout << table[i] << ",";
		}
		cout << table[cardCurrent - 1] << "}" << "\r\n";
	}
}

bool Ensemble::EstEgal(const Ensemble & unEnsemble) const
{
	bool egal=true;
	int current = 0;
	if (unEnsemble.cardCurrent == this->cardCurrent) 
	{
		for (int i = 0; i < this->cardCurrent && egal == true ; i++)
		{
			for (int j = 0; j < this->cardCurrent; j++)
			{
				if (this->table[j] == unEnsemble.table[i])
				{
					current++;
				}
			}
			if (current != i+1) 
			{
				egal = false;
			}
		}
	}
	else 
	{
		egal = false;
	}
	return egal;
}

crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const 
{
	crduEstInclus etat;
	if (this->EstEgal(unEnsemble) == 1)
	{
		etat = INCLUSION_LARGE;
	}
	else 
	{
		if (this->cardCurrent >= unEnsemble.cardCurrent)
		{
			etat = NON_INCLUSION;
		}
		else 
		{
			int current = 0;
			bool inclus = true;
			for (int i = 0; i < this->cardCurrent && inclus; i++)
			{
				for (int j = 0; j < unEnsemble.cardCurrent; j++)
				{
					if (this->table[i] == unEnsemble.table[j]) 
					{
						current++;
					}
				}
				if (current != i + 1) 
				{
					inclus = false;
				}
			}
			if (!inclus)
			{
				etat = NON_INCLUSION;
			}
			else 
			{
				etat = INCLUSION_STRICTE;
			}
		}
	}
	return etat;
}

crduAjouter Ensemble::Ajouter(int aAjouter) 
{
	crduAjouter action;
	bool presence = false;
	for (int i = 0; i < cardCurrent; i++) 
	{
		if (table[i] == aAjouter) 
		{
			presence = true;
		}
	}
	if (presence == true) 
	{
		action = DEJA_PRESENT;
	}
	else 
	{
		if (cardCurrent == cardMaxi) 
		{
			action = PLEIN;
		}
		else 
		{
			table[cardCurrent] = aAjouter;
			cardCurrent++;
			action = AJOUTE;
		}
	}
	return action;
}

unsigned int Ensemble::Ajuster(int delta) 
{
	if (delta >= 0) 
	{
		cardMaxi = cardMaxi + delta;
	}
	else {
		if (cardMaxi - cardCurrent <= delta-(2*delta))
		{
			cardMaxi = cardCurrent;
		}
		else
		{
			cardMaxi = cardMaxi + delta;
		}
	}
	return cardMaxi;
}

bool Ensemble::Retirer(int element) 
{
	bool retrait = false;
	for (int i = 0; i < cardCurrent && !retrait; i++)
	{
		if (table[i] == element) 
		{
			table[i] = table[cardCurrent-1];
			cardCurrent = cardCurrent - 1;
			retrait = true;
		}
	}
	cardMaxi = cardCurrent;
	return retrait;
}
//------------------------------------------------- Surcharge d'opérateurs
Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
{
	Ensemble provisoire;
	return provisoire;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble(const Ensemble & unEnsemble)
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Ensemble>" << "\r\n";
#endif
} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble(unsigned int cardMax)
{
#ifdef MAP
	cout << "Appel au constructeur par défaut de <Ensemble>" << "\r\n";
#endif
	cardMaxi = cardMax;
	cardCurrent = 0;
	table = new int[cardMaxi];
}

Ensemble::Ensemble(int t[], unsigned int nbElements)
{

#ifdef MAP
	cout << "Appel au constructeur 2 de <Ensemble>" << "\r\n";
	cout << "tableau " << "\r\n";
#endif
	cardMaxi = nbElements;
	table = new int[cardMaxi];
	int* preTable = EnleveDoublons(t, nbElements);
	cardCurrent = preTable[cardMaxi];
	for (int i = 0; i<cardCurrent; i++) 
	{
		table[i] = preTable[i];
	}
	delete[] preTable;
}

Ensemble::~Ensemble()
{
#ifdef MAP
	cout << "Appel au destructeur de <Ensemble>" << "\r\n";
#endif
	delete table;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int* Ensemble::EnleveDoublons(int tab[], int taille)
{
	int* verifTable = new int[taille + 1];
	bool ecritureAutorisee = true;
	int current = 0;
	bool premierZero = true;
	bool zero = false;
	for (int i = 0; i<taille; i++) {
		for (int j = 0; j <= i; j++) {
			if (tab[i] == verifTable[j]) {
				ecritureAutorisee = false;
			}
			if (tab[i] == 0 && premierZero) {
				premierZero = false;
				zero = true;
			}
		}
		if (ecritureAutorisee || zero) {
			verifTable[current] = tab[i];
			current++;
			zero = false;
		}
		ecritureAutorisee = true;
	}
	verifTable[taille] = current;
	return verifTable;
}

void Ensemble::TriBulle(int *t, int current) {
	int* echange = new int[current];
	for (int i = 0; i<current; i++)
	{
		echange[i] = t[i];
	}
	for (int j = 0; j<current; j++) {
		for (int k = j; k<current; k++) {
			if (t[j]>echange[k]) {
				t[k] = t[j];
				t[j] = echange[k];
				echange[k] = t[k];
				echange[j] = t[j];
			}
		}
	}
	delete[] echange;
}

