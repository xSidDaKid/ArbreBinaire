#ifndef NOEUD_BINAIRE_H
#define NOEUD_BINAIRE_H

#include <string>

using namespace std;

class NoeudBinaire {

	friend class ArbreBinaire;

public:
	NoeudBinaire();
	~NoeudBinaire();

	const string getElement() const;
	const NoeudBinaire* getGauche() const;
	NoeudBinaire* getGauche();
	const NoeudBinaire* getDroite() const;
	NoeudBinaire* getDroite();
	void setElement(string element);
	void setGauche(NoeudBinaire* gauche);
	void setDroite(NoeudBinaire* droite);

private:
	NoeudBinaire* gauche;
	NoeudBinaire* droite;
	string element;
};

#endif