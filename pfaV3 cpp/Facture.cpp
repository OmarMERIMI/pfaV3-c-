#include "Facture.h"
#include "Dentiste.h"
#include "Patient.h"
#include <iostream>

// Constructeurs et destructeur
Facture::Facture() : id(0), dateEmission(""), montant(0.0f), statut("en attente"), dentiste(nullptr), patient(nullptr) {}

Facture::Facture(int id, const std::string& dateEmission, float montant, const std::string& statut)
    : id(id), dateEmission(dateEmission), montant(montant), statut(statut), dentiste(nullptr), patient(nullptr) {}

Facture::~Facture() {
    // Pas de libération de mémoire pour dentiste et patient car ils sont gérés ailleurs
}

// Getters et setters
int Facture::getId() const {
    return id;
}

void Facture::setId(int id) {
    this->id = id;
}

std::string Facture::getDateEmission() const {
    return dateEmission;
}

void Facture::setDateEmission(const std::string& dateEmission) {
    this->dateEmission = dateEmission;
}

float Facture::getMontant() const {
    return montant;
}

void Facture::setMontant(float montant) {
    this->montant = montant;
}

std::string Facture::getStatut() const {
    return statut;
}

void Facture::setStatut(const std::string& statut) {
    this->statut = statut;
}

Dentiste* Facture::getDentiste() const {
    return dentiste;
}

void Facture::setDentiste(Dentiste* dentiste) {
    this->dentiste = dentiste;
}

Patient* Facture::getPatient() const {
    return patient;
}

void Facture::setPatient(Patient* patient) {
    this->patient = patient;
}

// Méthodes spécifiques
float Facture::calculerMontant() {
    // Logique pour calculer le montant (pourrait être plus complexe dans une application réelle)
    std::cout << "Calcul du montant de la facture." << std::endl;
    return montant; // Pour l'exemple, on retourne simplement le montant actuel
}

void Facture::payer() {
    statut = "payée";
    std::cout << "Facture #" << id << " payée. Montant: " << montant << std::endl;
}

void Facture::afficherDetails() const {
    std::cout << "=== Détails de la Facture #" << id << " ===" << std::endl;
    std::cout << "Date d'émission: " << dateEmission << std::endl;
    std::cout << "Montant: " << montant << std::endl;
    std::cout << "Statut: " << statut << std::endl;
    if (dentiste) {
        std::cout << "Dentiste: Dr. " << dentiste->getNom() << std::endl;
    } else {
        std::cout << "Dentiste: Non assigné" << std::endl;
    }
    if (patient) {
        std::cout << "Patient: " << patient->getNom() << " " << patient->getPrenom() << std::endl;
    } else {
        std::cout << "Patient: Non assigné" << std::endl;
    }
}