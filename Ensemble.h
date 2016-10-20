/*************************************************************************
Ensemble  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H
//------------------------------------------------------------- Constantes
const int CARD_MAX = 5;
enum crduEstInclus {NON_INCLUSION,INCLUSION_LARGE,INCLUSION_STRICTE};
enum crduAjouter { DEJA_PRESENT,PLEIN,AJOUTE };

class Ensemble
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void Afficher();

	bool EstEgal (const Ensemble & unEnsemble) const;

	crduEstInclus EstInclus(const Ensemble & unEnsemble) const;

	crduAjouter Ajouter(int aAjouter);

	unsigned int Ajuster(int delta);

	bool Retirer(int element);

	//------------------------------------------------- Surcharge d'opérateurs
	Ensemble & operator = ( const Ensemble & unEnsemble );


	//-------------------------------------------- Constructeurs - destructeur
	Ensemble(const Ensemble & unEnsemble);
	//Constructeur de copie


	Ensemble(unsigned int cardMax = CARD_MAX);
	//Constructeur défaut

	Ensemble(int t[], unsigned int nbElements);
	//Constructeur à partir d'un tableau et d'une CardMax


	virtual ~Ensemble();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées
	int* EnleveDoublons(int tab[], int taille);
	void TriBulle(int* t, int current);

	//----------------------------------------------------- Attributs protégés
	unsigned int cardMaxi;
	unsigned int cardCurrent;
	int* table;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // Ensemble

#pragma once
