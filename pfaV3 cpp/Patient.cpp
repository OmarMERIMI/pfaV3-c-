#include "Patient.h"
#include "DossierPatient.h"
#include "RendezVous.h"
#include <iostream>

// Constructeurs et destructeur
Patient::Patient() : Utilisateur(), nom(""), prenom(""), dateNaissance(""), historiqueMedial(""), dossier(nullptr) {}

Patient::Patient(int id, const std::string& username, const std::string& password,
                 const std::string& nom, const std::string& prenom, 
                 const std::string& dateNaissance, const std::string& historiqueMedial)
    : Utilisateur(id, username, password), nom(nom), prenom(prenom), 
      dateNaissance(dateNaissance), historiqueMedial(historiqueMedial), dossier(nullptr) {}

Patient::~Patient() {
    // Libération de la mémoire pour le dossier patient si nécessaire
    // Note: Dans une application réelle, il faudrait gérer correctement la propriété des objets
}

// Getters et setters
std::string Patient::getNom() const {
    return nom;
}

void Patient::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Patient::getPrenom() const {
    return prenom;
}

void Patient::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

std::string Patient::getDateNaissance() const {
    return dateNaissance;
}

void Patient::setDateNaissance(const std::string& dateNaissance) {
    this->dateNaissance = dateNaissance;
}

std::string Patient::getHistoriqueMedial() const {
    return historiqueMedial;
}

void Patient::setHistoriqueMedial(const std::string& historiqueMedial) {
    this->historiqueMedial = historiqueMedial;
}

DossierPatient* Patient::getDossier() const {
    return dossier;
}

void Patient::setDossier(DossierPatient* dossier) {
    this->dossier = dossier;
}
void Patient::setAntecedents(const std::string& antecedents) {
    this->historiqueMedial = antecedents;
}

// Méthodes spécifiques
void Patient::demanderRendezVous() {
    std::cout << "Patient " << nom << " " << prenom << " demande un rendez-vous." << std::endl;
    // Logique pour demander un rendez-vous
}

void Patient::confirmerRendezVous() {
    std::cout << "Patient " << nom << " " << prenom << " confirme un rendez-vous." << std::endl;
    // Logique pour confirmer un rendez-vous
}

void Patient::payerFacture() {
    std::cout << "Patient " << nom << " " << prenom << " paie une facture." << std::endl;
    // Logique pour payer une facture
}

void Patient::ajouterRendezVous(RendezVous* rdv) {
    rendezVous.push_back(rdv);
    std::cout << "Rendez-vous ajouté pour le patient " << nom << " " << prenom << std::endl;
}