#ifndef PATIENT_H
#define PATIENT_H

#include "Utilisateur.h"
#include <string>
#include <vector>

class DossierPatient;
class RendezVous;

class Patient : public Utilisateur {
private:
    std::string nom;
    std::string prenom;
    std::string dateNaissance; // Simplifié en string pour l'instant
    std::string historiqueMedial;
    std::vector<RendezVous*> rendezVous;
    DossierPatient* dossier;

public:
    // Constructeurs et destructeur
    Patient();
    Patient(int id, const std::string& username, const std::string& password,
            const std::string& nom, const std::string& prenom, 
            const std::string& dateNaissance, const std::string& historiqueMedial);
    ~Patient() override;

    // Getters et setters
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getPrenom() const;
    void setPrenom(const std::string& prenom);
    std::string getDateNaissance() const;
    void setDateNaissance(const std::string& dateNaissance);
    std::string getHistoriqueMedial() const;
    void setHistoriqueMedial(const std::string& historiqueMedial);
    DossierPatient* getDossier() const;
    void setDossier(DossierPatient* dossier);
    void setAntecedents(const std::string& antecedents);

    // Méthodes spécifiques
    void demanderRendezVous();
    void confirmerRendezVous();
    void payerFacture();
    void ajouterRendezVous(RendezVous* rdv);
};

#endif // PATIENT_H