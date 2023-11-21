#pragma once
#include <string>
#include "NoeudBinaire.h"

using namespace std;

class ArbreBinaire {

public:
	ArbreBinaire();
	ArbreBinaire(const ArbreBinaire& abf);
	~ArbreBinaire();

	//INSERTION
	bool etatRacine();
	void insererElementRacine(string reponse);
	void insererElementGauche(string entree);
	void insererElementDroite(string entree);

	//CURSEUR
	void deplacerCurseurGauche();
	void deplacerCurseurDroite();	
	string getCurseur();
	void setCurseurRacine();
	string getCurseurRacine();
	void setCurseurGauche();
	string getCurseurGauche();
	void setCurseurDroite();
	string getCurseurDroite();
	
	void insererReponse(ArbreBinaire& arbre, string question, string reponse);
	int calculerHauteur() const;
	string getPositionCurseur();

private:
	NoeudBinaire* racine;
	int calculerHauteurRecursif(const NoeudBinaire* n) const;
	NoeudBinaire* construireRecursif(NoeudBinaire *n);
	mutable NoeudBinaire* curseur;
};