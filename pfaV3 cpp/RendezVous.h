#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <string>

class Patient;
class SalleDeTraitement;

class RendezVous {
private:
    std::string date;
    std::string heure;
    std::string statut; // ex: "confirmé", "annulé", "en attente"
    Patient* patient;
    SalleDeTraitement* salle;

public:
    // Constructeurs et destructeur
    RendezVous();
    RendezVous(const std::string& date, const std::string& heure, const std::string& statut);
    ~RendezVous();

    // Getters et setters
    std::string getDate() const;
    void setDate(const std::string& date);
    std::string getHeure() const;
    void setHeure(const std::string& heure);
    std::string getStatut() const;
    void setStatut(const std::string& statut);
    Patient* getPatient() const;
    void setPatient(Patient* patient);
    SalleDeTraitement* getSalle() const;
    void setSalle(SalleDeTraitement* salle);

    // Méthodes spécifiques
    void ajouterRappel();
    void confirmer();
    void afficherDetails() const;
};

#endif // RENDEZVOUS_H