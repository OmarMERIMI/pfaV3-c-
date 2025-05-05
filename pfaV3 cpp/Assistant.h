#ifndef ASSISTANT_H
#define ASSISTANT_H

#include "Utilisateur.h"
#include <string>

class SalleDeTraitement;

class Assistant : public Utilisateur {
private:
    std::string nom;
    std::string prenom;

public:
    // Constructeurs et destructeur
    Assistant();
    Assistant(int id, const std::string& username, const std::string& password,
              const std::string& nom, const std::string& prenom);
    ~Assistant() override;

    // Getters et setters
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getPrenom() const;
    void setPrenom(const std::string& prenom);

    // Méthodes spécifiques
    void preparerSalle(SalleDeTraitement* salle);
    void accueillirPatient();
    void envoyerRappel();
};

#endif // ASSISTANT_H