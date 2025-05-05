#include "RendezVous.h"
#include "Patient.h"
#include "SalleDeTraitement.h"
#include <iostream>

// Constructeurs et destructeur
RendezVous::RendezVous() : date(""), heure(""), statut("en attente"), patient(nullptr), salle(nullptr) {}

RendezVous::RendezVous(const std::string& date, const std::string& heure, const std::string& statut)
    : date(date), heure(heure), statut(statut), patient(nullptr), salle(nullptr) {}

RendezVous::~RendezVous() {
    // Pas de libération de mémoire pour patient et salle car ils sont gérés ailleurs
}

// Getters et setters
std::string RendezVous::getDate() const {
    return date;
}

void RendezVous::setDate(const std::string& date) {
    this->date = date;
}

std::string RendezVous::getHeure() const {
    return heure;
}

void RendezVous::setHeure(const std::string& heure) {
    this->heure = heure;
}

std::string RendezVous::getStatut() const {
    return statut;
}

void RendezVous::setStatut(const std::string& statut) {
    this->statut = statut;
}

Patient* RendezVous::getPatient() const {
    return patient;
}

void RendezVous::setPatient(Patient* patient) {
    this->patient = patient;
}

SalleDeTraitement* RendezVous::getSalle() const {
    return salle;
}

void RendezVous::setSalle(SalleDeTraitement* salle) {
    this->salle = salle;
}

// Méthodes spécifiques
void RendezVous::ajouterRappel() {
    std::cout << "Rappel ajouté pour le rendez-vous du " << date << " à " << heure << std::endl;
    // Logique pour ajouter un rappel
}

void RendezVous::confirmer() {
    statut = "confirmé";
    std::cout << "Rendez-vous du " << date << " à " << heure << " confirmé." << std::endl;
}

void RendezVous::afficherDetails() const {
    std::cout << "=== Détails du Rendez-vous ===" << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Heure: " << heure << std::endl;
    std::cout << "Statut: " << statut << std::endl;
    if (patient) {
        std::cout << "Patient: " << patient->getNom() << " " << patient->getPrenom() << std::endl;
    } else {
        std::cout << "Patient: Non assigné" << std::endl;
    }
    if (salle) {
        std::cout << "Salle: " << salle->getNom() << std::endl;
    } else {
        std::cout << "Salle: Non assignée" << std::endl;
    }
}