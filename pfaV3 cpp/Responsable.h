#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include "Utilisateur.h"
#include <string>
#include <vector>

class Rapport;

class Responsable : public Utilisateur {
private:
    std::string nom;
    std::string prenom;
    std::vector<Rapport*> rapports;

public:
    // Constructeurs et destructeur
    Responsable();
    Responsable(int id, const std::string& username, const std::string& password,
                const std::string& nom, const std::string& prenom);
    ~Responsable() override;

    // Getters et setters
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getPrenom() const;
    void setPrenom(const std::string& prenom);

    // Méthodes spécifiques
    void gererUtilisateurs();
    void genererRapports();
};

#endif // RESPONSABLE_H