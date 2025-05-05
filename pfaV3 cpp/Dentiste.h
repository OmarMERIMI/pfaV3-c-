#ifndef DENTISTE_H
#define DENTISTE_H

#include "Utilisateur.h"
#include <string>
#include <vector>

class DossierPatient;
class Facture;

class Dentiste : public Utilisateur {
private:
    std::string nom;
    std::string specialite;
    std::vector<Facture*> factures;

public:
    // Constructeurs et destructeur
    Dentiste();
    Dentiste(int id, const std::string& username, const std::string& password,
             const std::string& nom, const std::string& specialite);
    ~Dentiste() override;

    // Getters et setters
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getSpecialite() const;
    void setSpecialite(const std::string& specialite);

    // Méthodes spécifiques
    void consulterDossierPatient(DossierPatient* dossier);
    void ajouterNotes(DossierPatient* dossier, const std::string& notes);
    void gererTraitement(DossierPatient* dossier);
};

#endif // DENTISTE_H