#ifndef FACTURE_H
#define FACTURE_H

#include <string>

class Dentiste;
class Patient;

class Facture {
private:
    int id;
    std::string dateEmission;
    float montant;
    std::string statut; // ex: "payée", "en attente", "annulée"
    Dentiste* dentiste;
    Patient* patient;

public:
    // Constructeurs et destructeur
    Facture();
    Facture(int id, const std::string& dateEmission, float montant, const std::string& statut);
    ~Facture();

    // Getters et setters
    int getId() const;
    void setId(int id);
    std::string getDateEmission() const;
    void setDateEmission(const std::string& dateEmission);
    float getMontant() const;
    void setMontant(float montant);
    std::string getStatut() const;
    void setStatut(const std::string& statut);
    Dentiste* getDentiste() const;
    void setDentiste(Dentiste* dentiste);
    Patient* getPatient() const;
    void setPatient(Patient* patient);

    // Méthodes spécifiques
    float calculerMontant();
    void payer();
    void afficherDetails() const;
};

#endif // FACTURE_H