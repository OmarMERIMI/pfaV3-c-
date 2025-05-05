#ifndef GESTIONCABINET_H
#define GESTIONCABINET_H

#include <vector>
#include <memory>
#include <string>

class Utilisateur;
class Patient;
class Dentiste;
class Assistant;
class Responsable;
class RendezVous;
class DossierPatient;
class SalleDeTraitement;

class GestionCabinet {
private:
    std::vector<std::shared_ptr<Utilisateur>> utilisateurs;
    std::vector<std::shared_ptr<Patient>> patients;
    std::vector<std::shared_ptr<Dentiste>> dentistes;
    std::vector<std::shared_ptr<Assistant>> assistants;
    std::vector<std::shared_ptr<Responsable>> responsables;
    std::vector<std::shared_ptr<RendezVous>> rendezVous;
    std::vector<std::shared_ptr<DossierPatient>> dossiers;
    std::vector<std::shared_ptr<SalleDeTraitement>> salles;
    
    // Utilisateur actuellement connecté
    Utilisateur* utilisateurConnecte;
    
    // Méthodes privées
    void afficherMenuPrincipal();
    void afficherMenuPatient();
    void afficherMenuDentiste();
    void afficherMenuAssistant();
    void afficherMenuResponsable();
    
    // Méthodes d'authentification
    bool authentifier(const std::string& username, const std::string& password);
    
    // Méthodes de gestion
    void gererPatients();
    void gererDentistes();
    void gererAssistants();
    void gererResponsables();
    void gererRendezVous();
    void gererSalles();
    
    // Initialisation des données de test
    void initialiserDonneesTest();

public:
    // Constructeur et destructeur
    GestionCabinet();
    ~GestionCabinet();
    
    // Méthode principale pour démarrer l'application
    void demarrer();
    
    // Méthodes de gestion des utilisateurs
    void ajouterUtilisateur(std::shared_ptr<Utilisateur> utilisateur);
    void supprimerUtilisateur(int id);
    Utilisateur* trouverUtilisateur(int id);
    Utilisateur* trouverUtilisateurParUsername(const std::string& username);
    
    // Méthodes de gestion des patients
    void ajouterPatient(std::shared_ptr<Patient> patient);
    void supprimerPatient(int id);
    Patient* trouverPatient(int id);
    
    // Méthodes de gestion des rendez-vous
    void ajouterRendezVous(std::shared_ptr<RendezVous> rdv);
    void supprimerRendezVous(const std::string& date, const std::string& heure);
    RendezVous* trouverRendezVous(const std::string& date, const std::string& heure);
    
    // Méthodes de gestion des salles
    void ajouterSalle(std::shared_ptr<SalleDeTraitement> salle);
    void supprimerSalle(int id);
    SalleDeTraitement* trouverSalle(int id);
};

#endif // GESTIONCABINET_H