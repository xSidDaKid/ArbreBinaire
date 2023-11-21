#include <iostream>
#include <Windows.h>
#include <string>
#include <istream>
#include <fstream>
#include "ArbreBinaire.h"
#include "NoeudBinaire.h"
#include "UtilitairesES.h"

using namespace std;

void afficherMenu();
int determinerChoix();
void jouer(ArbreBinaire& arbre);
string prendreLigneComplet();
void sauvegarde(ArbreBinaire& arbre);

int main() {
	int choix;
	bool quitter = false;
	ArbreBinaire arbre;

	while (!quitter) {
		afficherMenu();
		choix = determinerChoix();
		switch (choix) {
		case 1:
			jouer(arbre);
			break;
		case 2:
			quitter = true;
		}
	}

	system("pause");
	return 0;
}

/*
* Le menu pour jouer ou quitter
*/
void afficherMenu() {
	cout << "\nVeuillez choisir parmis les options suivantes:\n"
		<< "1) Jouer une nouvelle partie\n"
		<< "2) Quitter"
		<< endl;
}

int determinerChoix() {
	int choix = lireEntier("Entrez votre choix(entre 1 et 2)", 1, 2);
	return choix;
}

/*
* Methode pour construire au fur et a mesure que l'on joue au jeu
*/
void jouer(ArbreBinaire& arbre) {
	string reponse;
	string elementRacine;
	string choix;
	string raison;
	string distinguer;

	arbre.setCurseurRacine();
	cout << endl;
	
	//Condition pour savoir si la racine est null
	if (arbre.etatRacine() == false)
	{
		arbre.setCurseurRacine();
		cout << "Je ne sais pas" << endl;
		cout << "Quel est la reponse : ";
		cin >> reponse;
		cout << "Comment puis-je le distinguer ? ";
		string elementRacine = prendreLigneComplet();
		arbre.setCurseurGauche();
		arbre.insererElementRacine(elementRacine);
		arbre.insererElementGauche(reponse);
	}

	//Condition pour remplir notre arbre a gauche
	else
	{
		cout << arbre.getCurseurRacine() << " (O/N) ";
		cin >> choix;
		if (choix == "O")//Question
		{
			arbre.deplacerCurseurGauche();
			cout << "C'est un(e) " << arbre.getPositionCurseur();
			cout << endl;

			cout << "Ais-je raison? (O/N): ";
			cin >> raison;
			if (raison == "O")
			{
				cout << "J'ai trouve!!" << endl;
			}
			else if (raison == "N")
			{
				cout << "J'ai perdu" << endl;
				cout << "Quel est la reponse : ";
				cin >> reponse;

				arbre.setCurseurGauche();
				cout << "Comment puis-je le distinguer ? ";
				string distinguer = prendreLigneComplet();

				arbre.deplacerCurseurGauche();
			}
		}

		else if (choix == "N")
		{
			arbre.setCurseurDroite();
			cout << "Je ne sais pas" << endl;
			cout << "Quel est la reponse : ";
			cin >> reponse;
			cout << "Comment puis-je le distinguer ? ";
			string elementRacine = prendreLigneComplet();
		}
	}
}

/*
* Methode qui sert a prendre une ligne au complet 
* qu'on rentre lorsqu'on demande un question
*/
string prendreLigneComplet() {
	string retourner;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, retourner);
	return retourner;
}

/*
* Methode qui sert a faire la sauvegarde de notre arbre
*/
void sauvegarde(ArbreBinaire& arbre) {
	ofstream ficSortie("copie.txt");
	string chaine;
	int racine = 0;

	ficSortie << racine << endl;

	system("pause");
}