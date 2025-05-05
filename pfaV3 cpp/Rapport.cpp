#include "Rapport.h"
#include "Responsable.h"
#include <iostream>

// Constructeurs et destructeur
Rapport::Rapport() : id(0), type(""), date(""), contenu(""), responsable(nullptr) {}

Rapport::Rapport(int id, const std::string& type, const std::string& date, const std::string& contenu)
    : id(id), type(type), date(date), contenu(contenu), responsable(nullptr) {}

Rapport::~Rapport() {
    // Pas de libération de mémoire pour responsable car il est géré ailleurs
}

// Getters et setters
int Rapport::getId() const {
    return id;
}

void Rapport::setId(int id) {
    this->id = id;
}

std::string Rapport::getType() const {
    return type;
}

void Rapport::setType(const std::string& type) {
    this->type = type;
}

std::string Rapport::getDate() const {
    return date;
}

void Rapport::setDate(const std::string& date) {
    this->date = date;
}

std::string Rapport::getContenu() const {
    return contenu;
}

void Rapport::setContenu(const std::string& contenu) {
    this->contenu = contenu;
}

Responsable* Rapport::getResponsable() const {
    return responsable;
}

void Rapport::setResponsable(Responsable* responsable) {
    this->responsable = responsable;
}

// Méthodes spécifiques
void Rapport::genererRapport() {
    std::cout << "Génération du rapport #" << id << " de type " << type << std::endl;
    // Logique pour générer le contenu du rapport
    if (responsable) {
        std::cout << "Rapport généré par: " << responsable->getNom() << " " << responsable->getPrenom() << std::endl;
    }
}

void Rapport::afficherRapport() const {
    std::cout << "=== Rapport #" << id << " ===" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Contenu:\n" << contenu << std::endl;
    if (responsable) {
        std::cout << "Généré par: " << responsable->getNom() << " " << responsable->getPrenom() << std::endl;
    } else {
        std::cout << "Responsable: Non assigné" << std::endl;
    }
}