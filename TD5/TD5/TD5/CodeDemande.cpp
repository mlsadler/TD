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
	
	// TODO: Indiquer la réussite ou l'échec de l'ouverture dans 'ok'.
	
	// TODO: Écrire les paramètres de mission dans le fichier.
	
	// TODO: Écrire les cibles dans le fichier.
}


void ecrireObservation(const string& nomFichier, size_t index, const string& observation)
{
	// TODO: Ouvrir un fichier en lecture/écriture binaire.

	fstream f_InOut;
	f_InOut.open(nomFichier, ios::binary | ios::in | ios::out);

	// TODO: Se positionner (têtes de lecture et d'écriture) au début de la cible 
	//       à l'index donné. On parle ici de l'index dans le fichier, donc 0 est
	//       la première cible dans le fichier, etc.
	f_InOut.seekg(index, ios::beg);


	// TODO: Lire cette cible.
	//       ATTENTION! Vous ne devez lire que cette cible isolée, pas tout le
	//       tableau.
	Cible cible;
	f_InOut.read((char*)& cible, sizeof(cible));

	// TODO: Copier l'observation donnée en paramètre dans la cible.
	//       Astuce : strcpy()

	strcpy(cible, observation);

	// TODO: Réécrire la cible (et seulement celle-là) dans le fichier.
	f_InOut.seekp(index, ios::beg);
}


ListeCibles allouerListe(size_t capacite)
{
	// TODO: Créer une 'ListeDonnee' vide (nbElements = 0) avec la capacité donnée.
	
	// TODO: Allouer un tableau de 'Cible' de la taille demandée.
	return {};
}


void desallouerListe(ListeCibles& cibles)
{
	// TODO: Désallouer le tableau d'élément.
	// TODO: Remettre les membres à zéro.
}


JournalDetection lireJournalDetection(const string& nomFichier, bool& ok)
{
	// TODO: Ouvrir un fichier en lecture binaire.
	
	// TODO: Indiquer la réussite ou l'échec de l'ouverture dans 'ok'.
	
	// TODO: Lire les paramètres de mission
	
	// TODO: Compter le nombre de cibles dans le fichier.
	
	// TODO: Allouer la liste de cibles avec la bonne capacité.
	
	// TODO: Lire les cibles.
	return {};
}

#pragma endregion //}

#pragma endregion //}

