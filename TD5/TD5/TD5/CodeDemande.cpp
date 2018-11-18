////////////////////////////////////////////////////////////////////////////////
/// VOTRE ENTÊTE ICI
////////////////////////////////////////////////////////////////////////////////

#pragma region "Inclusions" //{

#include "CodeFourni.hpp"
#include "CodeDemande.hpp"

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#pragma endregion //}


#pragma region "Globaux" //{

#pragma region "Fonctions" //{

void ajouterCible(ListeCibles& liste, const Cible& element)
{
	// TODO: S'il reste de la place, ajouter l'élément à la fin.
	if (liste.capacite > liste.nbElements) {
		liste.elements[liste.nbElements] = element;
		liste.nbElements++;
	}
}


void retirerCible(ListeCibles& liste, uint32_t id)
{
	// TODO: Rechercher la cible avec le même ID et le retirer de la liste si
	//       présent. ATTENTION! On parle bien de Cible::id, pas de l'index
	//       dans le tableau.

	for (int i = 0; i < liste.nbElements - 1; i++) {
		if (liste.elements[i].id == id) {
			for (int j = i; j < liste.nbElements - 1; j++) {
				liste.elements[j] = liste.elements[j + 1];

			}
			liste.nbElements--;
		}
		else if (liste.elements[liste.nbElements - 1].id == id) {
			liste.nbElements--;
		}
	}
}


void lireCibles(istream& fichier, ListeCibles& cibles)
{
	// TODO: Tant que la fin de fichier n'est pas atteinte :
	// TODO: Lire une 'Cible' à partir du ficher à la position
	//       courante et l'ajouter à la liste.

	Cible cible;
	while (fichier.peek() != EOF) {
		fichier.read((char*)& cible, sizeof(cible));
		ajouterCible(cibles, cible);

	}
}


void ecrireCibles(ostream& fichier, const ListeCibles& cibles)
{
	// TODO: Écrire tous les éléments de la liste dans le fichier à partir de la position courante.

	for (int i = 0; i < cibles.nbElements; i++) {
		fichier.write((char*)& cibles.elements[i], sizeof(cibles.elements[i]));

	}


}



void ecrireJournalDetection(const string& nomFichier, const JournalDetection& journal, bool& ok)
{
	// TODO: Ouvrir un fichier en écriture binaire.
	ofstream fichier;
	fichier.open(nomFichier, ios::binary);

	// TODO: Indiquer la réussite ou l'échec de l'ouverture dans 'ok'.
	if (fichier.fail()) {
		ok = false;
	}
	else {
		ok = true;
		// TODO: Écrire les paramètres de mission dans le fichier.
		fichier.write((char*)& journal.parametres, sizeof(journal.parametres)); ////////////////// est-ce que il a un parametre par element ou 1 pour tous

		// TODO: Écrire les cibles dans le fichier.
		ecrireCibles(fichier, journal.cibles);
	}
	

	
}


void ecrireObservation(const string& nomFichier, size_t index, const string& observation)
{
	// TODO: Ouvrir un fichier en lecture/écriture binaire.

	fstream f_InOut;
	f_InOut.open(nomFichier, ios::binary | ios::in | ios::out);

	// TODO: Se positionner (têtes de lecture et d'écriture) au début de la cible 
	//       à l'index donné. On parle ici de l'index dans le fichier, donc 0 est
	//       la première cible dans le fichier, etc.
	f_InOut.seekg(index*sizeof(Cible)+sizeof(ParametresMission), ios::beg);
	

	// TODO: Lire cette cible.
	//       ATTENTION! Vous ne devez lire que cette cible isolée, pas tout le
	//       tableau.
	Cible cible;
	f_InOut.read((char*)& cible, sizeof(Cible));
	

	// TODO: Copier l'observation donnée en paramètre dans la cible.
	//       Astuce : strcpy()

	char observationC[TAILLE_OBSERVATION];
	strcpy_s(observationC, observation.c_str());
	strcpy(cible.observation, observationC);

	// TODO: Réécrire la cible (et seulement celle-là) dans le fichier.
	f_InOut.seekg(index * sizeof(Cible) + sizeof(ParametresMission), ios::beg);
	f_InOut.write((char*)& cible, sizeof(cible));
}


ListeCibles allouerListe(size_t capacite)
{
	// TODO: Créer une 'ListeDonnee' vide (nbElements = 0) avec la capacité donnée.
	// TODO: Allouer un tableau de 'Cible' de la taille demandée.
	ListeCibles listeDonnee;
	listeDonnee.elements= new Cible[capacite];
	listeDonnee.capacite = capacite;
	listeDonnee.nbElements = 0;
	return listeDonnee;
}


void desallouerListe(ListeCibles& cibles)
{
	// TODO: Désallouer le tableau d'élément.
	// TODO: Remettre les membres à zéro.
	delete[] &cibles.elements;
	cibles.elements = nullptr;
}


JournalDetection lireJournalDetection(const string& nomFichier, bool& ok)
{
	JournalDetection journalDetection;


	// TODO: Ouvrir un fichier en lecture binaire.
	ifstream fichierLire;
	fichierLire.open(nomFichier, ios::binary);
	// TODO: Indiquer la réussite ou l'échec de l'ouverture dans 'ok'.
	if (fichierLire.fail()) { ////////////////////////////////////////////////////// est ce que je devrais mettre tous le reste de la foncrion dans le if
		ok = false;
	}
	else {
		ok = true;
		// TODO: Lire les paramètres de mission
		fichierLire.seekg(0, ios::beg);
		fichierLire.read((char*)& journalDetection.parametres, sizeof(journalDetection.parametres));

		// TODO: Compter le nombre de cibles dans le fichier.
		int nbCibles = (sizeof(fichierLire) - sizeof(journalDetection.parametres)) / sizeof(Cible);

		// TODO: Allouer la liste de cibles avec la bonne capacité.
		journalDetection.cibles = allouerListe(nbCibles);

		// TODO: Lire les cibles.
		fichierLire.seekg(sizeof(journalDetection.parametres), ios::beg);
		lireCibles(fichierLire, journalDetection.cibles);

		return journalDetection;
	}

	
}

#pragma endregion //}

#pragma endregion //}

