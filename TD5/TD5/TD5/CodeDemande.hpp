////////////////////////////////////////////////////////////////////////////////
/// \file    CodeDemande.hpp
/// \author  Félix Dumont et Mark Weber-Sadler
/// \version 2018-11-18
///
/// Déclarations de fonction à écrire 
////////////////////////////////////////////////////////////////////////////////

#pragma once

#pragma region "Inclusions" //{

#include "CodeFourni.hpp"

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <ctime>
#include <fstream>
#include <string>

using namespace std;

#pragma endregion //}


#pragma region "Déclarations" //{

#pragma region "Globaux" //{

void ajouterCible(ListeCibles&, const Cible&);

void retirerCible(ListeCibles&, uint32_t);

void lireCibles(istream&, ListeCibles&);

void ecrireCibles(ostream&, const ListeCibles&);

void ecrireJournalDetection(const string&, const JournalDetection&, bool&);

void ecrireObservation(const string&, size_t, const string&);

ListeCibles allouerListe(size_t);

void desallouerListe(ListeCibles&);

JournalDetection lireJournalDetection(const string&, bool&);

#pragma endregion //}

#pragma endregion //}

