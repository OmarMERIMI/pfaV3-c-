#include "Dentiste.h"
#include "DossierPatient.h"
#include "Facture.h"
#include <iostream>

// Constructeurs et destructeur
Dentiste::Dentiste() : Utilisateur(), nom(""), specialite("") {}

Dentiste::Dentiste(int id, const std::string& username, const std::string& password,
                   const std::string& nom, const std::string& specialite)
    : Utilisateur(id, username, password), nom(nom), specialite(specialite) {}

Dentiste::~Dentiste() {
    // Libération de la mémoire si nécessaire
}

// Getters et setters
std::string Dentiste::getNom() const {
    return nom;
}

void Dentiste::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Dentiste::getSpecialite() const {
    return specialite;
}

void Dentiste::setSpecialite(const std::string& specialite) {
    this->specialite = specialite;
}

// Méthodes spécifiques
void Dentiste::consulterDossierPatient(DossierPatient* dossier) {
    if (dossier) {
        std::cout << "Dr. " << nom << " consulte le dossier du patient." << std::endl;
        // Logique pour consulter le dossier
    } else {
        std::cout << "Dossier patient non disponible." << std::endl;
    }
}

void Dentiste::ajouterNotes(DossierPatient* dossier, const std::string& notes) {
    if (dossier) {
        std::cout << "Dr. " << nom << " ajoute des notes au dossier du patient." << std::endl;
        dossier->ajouterNotes(notes);
    } else {
        std::cout << "Dossier patient non disponible." << std::endl;
    }
}

void Dentiste::gererTraitement(DossierPatient* dossier) {
    if (dossier) {
        std::cout << "Dr. " << nom << " gère le traitement du patient." << std::endl;
        // Logique pour gérer le traitement
    } else {
        std::cout << "Dossier patient non disponible." << std::endl;
    }
}