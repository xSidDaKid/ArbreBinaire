#include "NoeudBinaire.h"
#include <string>

using namespace std;

NoeudBinaire::NoeudBinaire() :
	gauche(0),
	droite(0)
{

}

NoeudBinaire::~NoeudBinaire() {

}

const string NoeudBinaire::getElement() const {
	return element;
}

const NoeudBinaire* NoeudBinaire::getGauche() const {
	return gauche;
}

NoeudBinaire* NoeudBinaire::getGauche() {
	if (this == nullptr) {
		return this;
	}
	else {
		return gauche;
	}
}

const NoeudBinaire* NoeudBinaire::getDroite() const {
	return droite;
}

NoeudBinaire* NoeudBinaire::getDroite() {
	if (this == nullptr)
	{
		return this;
	}
	else
	{
		return droite;
	}
	
}

void NoeudBinaire::setElement(string element) {
	this->element = element;
}

void NoeudBinaire::setGauche(NoeudBinaire* gauche) {
	this->gauche = gauche;
}

void NoeudBinaire::setDroite(NoeudBinaire* droite) {
	this->droite = droite;
}
