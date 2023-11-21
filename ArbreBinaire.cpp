#include "ArbreBinaire.h"
#include <string>

ArbreBinaire::ArbreBinaire():
	racine(nullptr)
{

}

ArbreBinaire::ArbreBinaire(const ArbreBinaire & abf)
{
	racine = construireRecursif(abf.racine);
}

ArbreBinaire::~ArbreBinaire()
{
}

//INSERTION
bool ArbreBinaire::etatRacine()
{
	if (racine == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ArbreBinaire::insererElementRacine(string reponse)
{
	if (racine == nullptr)
	{
		NoeudBinaire *newRacine = new NoeudBinaire();
		newRacine->setElement(reponse);
		racine = newRacine;
		curseur = racine;
	}
}

void ArbreBinaire::insererElementGauche(string entree)
{
	if (curseur->getGauche() == nullptr)
	{
		NoeudBinaire* curseurG = new NoeudBinaire();;
		curseurG->setElement(entree);
		curseur->setGauche(curseurG);
	}
}

void ArbreBinaire::insererElementDroite(string entree)
{
	if (curseur->getDroite() != nullptr)
	{
		NoeudBinaire* curseurD = new NoeudBinaire();;
		curseurD->setElement(entree);
		curseur->setGauche(curseurD);
	}
}

//CURSEUR
void ArbreBinaire::deplacerCurseurGauche() 
{
	this->curseur = curseur->getGauche();
}

void ArbreBinaire::deplacerCurseurDroite()
{
	this->curseur = curseur->getDroite();
}

string ArbreBinaire::getCurseur()
{
	return curseur->element;
}

void ArbreBinaire::setCurseurRacine()
{
	curseur = racine;
}

string ArbreBinaire::getCurseurRacine()
{
	return curseur->getElement();
}

void ArbreBinaire::setCurseurGauche()
{	
	if (curseur == nullptr)
	{
		NoeudBinaire *curseurGauche = new NoeudBinaire();
		curseurGauche->setGauche(curseurGauche);
	}
	else
	{
		curseur = curseur->gauche;
	}
}

//Methode pour deplacer le curseur a gauche
string ArbreBinaire::getPositionCurseur()
{
	return curseur->element;
}

string ArbreBinaire::getCurseurGauche()
{
	if (curseur == nullptr)
	{
		curseur = new NoeudBinaire();
		this->curseur = curseur->getGauche();
		return curseur->getElement();
	}
	else
	{
		return curseur->getElement();
	}
}

void ArbreBinaire::setCurseurDroite()
{
	if (curseur == nullptr)
	{
		NoeudBinaire *curseurDroite = new NoeudBinaire();
		curseurDroite->setGauche(curseurDroite);
	}
	else
	{
		curseur = curseur->droite;
	}
}

//Methode pour deplacer le curseur a droite
string ArbreBinaire::getCurseurDroite()
{
	this->curseur = curseur->getGauche();
	return curseur->getElement();
}

void ArbreBinaire::insererReponse(ArbreBinaire & arbre, string question, string reponse)
{
	NoeudBinaire* noeudGauche = new NoeudBinaire();
	NoeudBinaire* noeudDroite = new NoeudBinaire();
	string reponseMemoire = arbre.getCurseur();

	noeudDroite->setElement(reponse);
	noeudGauche->setElement(question);

	curseur->setDroite(noeudDroite);
	curseur->setGauche(noeudGauche);

}

int ArbreBinaire::calculerHauteur() const
{
	return calculerHauteurRecursif(racine);
}

int ArbreBinaire::calculerHauteurRecursif(const NoeudBinaire * n) const
{
	if (n != nullptr) {
		int hauteurGauche = calculerHauteurRecursif(n->getGauche());
		int hauteurDroite = calculerHauteurRecursif(n->getDroite());
		return (hauteurDroite > hauteurGauche ? hauteurDroite + 1 : hauteurGauche + 1);
	}
	else {
		return 0;
	}
}

NoeudBinaire* ArbreBinaire::construireRecursif(NoeudBinaire * n)
{
	NoeudBinaire* nouveau = nullptr;
	if (n != nullptr) {
		nouveau = new NoeudBinaire();
		nouveau->element = n->element;
		nouveau->gauche = construireRecursif(n->gauche);
		nouveau->droite = construireRecursif(n->droite);
	}
	return nouveau;
}