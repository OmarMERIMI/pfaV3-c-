#include "DossierPatient.h"
#include "Patient.h"
#include <iostream>

// Constructeurs et destructeur
DossierPatient::DossierPatient() : idPatient(0), dossierMedical(""), notes(""), patient(nullptr) {}

DossierPatient::DossierPatient(int idPatient, const std::string& dossierMedical)
    : idPatient(idPatient), dossierMedical(dossierMedical), notes(""), patient(nullptr) {}

DossierPatient::~DossierPatient() {
    // Pas de libération de mémoire pour patient car il est géré ailleurs
}

// Getters et setters
int DossierPatient::getIdPatient() const {
    return idPatient;
}

void DossierPatient::setIdPatient(int idPatient) {
    this->idPatient = idPatient;
}

std::string DossierPatient::getDossierMedical() const {
    return dossierMedical;
}

void DossierPatient::setDossierMedical(const std::string& dossierMedical) {
    this->dossierMedical = dossierMedical;
}

std::string DossierPatient::getNotes() const {
    return notes;
}

void DossierPatient::setNotes(const std::string& notes) {
    this->notes = notes;
}

Patient* DossierPatient::getPatient() const {
    return patient;
}

void DossierPatient::setPatient(Patient* patient) {
    this->patient = patient;
}

// Méthodes spécifiques
void DossierPatient::ajouterNotes(const std::string& nouvelleNote) {
    if (!notes.empty()) {
        notes += "\n";
    }
    notes += nouvelleNote;
    std::cout << "Note ajoutée au dossier du patient." << std::endl;
}

void DossierPatient::consulterDossier() const {
    std::cout << "=== Dossier Patient ID: " << idPatient << " ===" << std::endl;
    if (patient) {
        std::cout << "Patient: " << patient->getNom() << " " << patient->getPrenom() << std::endl;
    }
    std::cout << "Dossier médical: " << dossierMedical << std::endl;
    std::cout << "Notes: " << notes << std::endl;
}