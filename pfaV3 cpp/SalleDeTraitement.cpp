#include "SalleDeTraitement.h"
#include "RendezVous.h"
#include "Assistant.h"
#include <iostream>

// Constructeurs et destructeur
SalleDeTraitement::SalleDeTraitement() : id(0), nom(""), equipements(""), statut("disponible"), assistant(nullptr) {}

SalleDeTraitement::SalleDeTraitement(int id, const std::string& nom, const std::string& equipements, const std::string& statut)
    : id(id), nom(nom), equipements(equipements), statut(statut), assistant(nullptr) {}

SalleDeTraitement::~SalleDeTraitement() {
    // Pas de libération de mémoire pour les rendez-vous et l'assistant car ils sont gérés ailleurs
}

// Getters et setters
int SalleDeTraitement::getId() const {
    return id;
}

void SalleDeTraitement::setId(int id) {
    this->id = id;
}

std::string SalleDeTraitement::getNom() const {
    return nom;
}

void SalleDeTraitement::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string SalleDeTraitement::getEquipements() const {
    return equipements;
}

void SalleDeTraitement::setEquipements(const std::string& equipements) {
    this->equipements = equipements;
}

std::string SalleDeTraitement::getStatut() const {
    return statut;
}

void SalleDeTraitement::setStatut(const std::string& statut) {
    this->statut = statut;
}

Assistant* SalleDeTraitement::getAssistant() const {
    return assistant;
}

void SalleDeTraitement::setAssistant(Assistant* assistant) {
    this->assistant = assistant;
}

// Méthodes spécifiques
void SalleDeTraitement::preparer() {
    statut = "en préparation";
    std::cout << "Salle " << nom << " en cours de préparation." << std::endl;
    // Logique pour préparer la salle
    if (verifierEquipement()) {
        statut = "disponible";
        std::cout << "Salle " << nom << " prête et disponible." << std::endl;
    } else {
        statut = "en maintenance";
        std::cout << "Salle " << nom << " nécessite une maintenance." << std::endl;
    }
}

bool SalleDeTraitement::verifierEquipement() {
    std::cout << "Vérification des équipements de la salle " << nom << std::endl;
    // Logique pour vérifier les équipements
    // Pour l'exemple, on retourne toujours true
    return true;
}

void SalleDeTraitement::ajouterRendezVous(RendezVous* rdv) {
    rendezVous.push_back(rdv);
    rdv->setSalle(this);
    std::cout << "Rendez-vous ajouté à la salle " << nom << std::endl;
}

void SalleDeTraitement::afficherDetails() const {
    std::cout << "=== Détails de la Salle #" << id << " ===" << std::endl;
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Équipements: " << equipements << std::endl;
    std::cout << "Statut: " << statut << std::endl;
    if (assistant) {
        std::cout << "Assistant assigné: " << assistant->getNom() << " " << assistant->getPrenom() << std::endl;
    } else {
        std::cout << "Assistant: Non assigné" << std::endl;
    }
    std::cout << "Nombre de rendez-vous programmés: " << rendezVous.size() << std::endl;
}