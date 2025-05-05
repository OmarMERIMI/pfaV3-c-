#include "Responsable.h"
#include "Rapport.h"
#include <iostream>

// Constructeurs et destructeur
Responsable::Responsable() : Utilisateur(), nom(""), prenom("") {}

Responsable::Responsable(int id, const std::string& username, const std::string& password,
                       const std::string& nom, const std::string& prenom)
    : Utilisateur(id, username, password), nom(nom), prenom(prenom) {}

Responsable::~Responsable() {
    // Libération de la mémoire pour les rapports si nécessaire
    for (auto rapport : rapports) {
        delete rapport;
    }
    rapports.clear();
}

// Getters et setters
std::string Responsable::getNom() const {
    return nom;
}

void Responsable::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Responsable::getPrenom() const {
    return prenom;
}

void Responsable::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

// Méthodes spécifiques
void Responsable::gererUtilisateurs() {
    std::cout << "Responsable " << nom << " " << prenom << " gère les utilisateurs." << std::endl;
    // Logique pour gérer les utilisateurs
}

void Responsable::genererRapports() {
    std::cout << "Responsable " << nom << " " << prenom << " génère des rapports." << std::endl;
    // Logique pour générer des rapports
}