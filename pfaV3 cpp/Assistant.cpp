#include "Assistant.h"
#include "SalleDeTraitement.h"
#include <iostream>

// Constructeurs et destructeur
Assistant::Assistant() : Utilisateur(), nom(""), prenom("") {}

Assistant::Assistant(int id, const std::string& username, const std::string& password,
                     const std::string& nom, const std::string& prenom)
    : Utilisateur(id, username, password), nom(nom), prenom(prenom) {}

Assistant::~Assistant() {
    // Libération de la mémoire si nécessaire
}

// Getters et setters
std::string Assistant::getNom() const {
    return nom;
}

void Assistant::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Assistant::getPrenom() const {
    return prenom;
}

void Assistant::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

// Méthodes spécifiques
void Assistant::preparerSalle(SalleDeTraitement* salle) {
    if (salle) {
        std::cout << "Assistant " << nom << " " << prenom << " prépare la salle de traitement." << std::endl;
        salle->preparer();
    } else {
        std::cout << "Salle de traitement non disponible." << std::endl;
    }
}

void Assistant::accueillirPatient() {
    std::cout << "Assistant " << nom << " " << prenom << " accueille un patient." << std::endl;
    // Logique pour accueillir un patient
}

void Assistant::envoyerRappel() {
    std::cout << "Assistant " << nom << " " << prenom << " envoie un rappel de rendez-vous." << std::endl;
    // Logique pour envoyer un rappel
}