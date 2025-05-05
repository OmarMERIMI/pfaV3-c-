#ifndef SALLEDETRAITEMENT_H
#define SALLEDETRAITEMENT_H

#include <string>
#include <vector>

class RendezVous;
class Assistant;

class SalleDeTraitement {
private:
    int id;
    std::string nom;
    std::string equipements;
    std::string statut; // ex: "disponible", "occupée", "en maintenance"
    std::vector<RendezVous*> rendezVous;
    Assistant* assistant;

public:
    // Constructeurs et destructeur
    SalleDeTraitement();
    SalleDeTraitement(int id, const std::string& nom, const std::string& equipements, const std::string& statut);
    ~SalleDeTraitement();

    // Getters et setters
    int getId() const;
    void setId(int id);
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getEquipements() const;
    void setEquipements(const std::string& equipements);
    std::string getStatut() const;
    void setStatut(const std::string& statut);
    Assistant* getAssistant() const;
    void setAssistant(Assistant* assistant);

    // Méthodes spécifiques
    void preparer();
    bool verifierEquipement();
    void ajouterRendezVous(RendezVous* rdv);
    void afficherDetails() const;
};

#endif // SALLEDETRAITEMENT_H