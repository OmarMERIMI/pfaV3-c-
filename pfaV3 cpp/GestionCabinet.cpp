#include "GestionCabinet.h"
#include "Utilisateur.h"
#include "Patient.h"
#include "Dentiste.h"
#include "Assistant.h"
#include "Responsable.h"
#include "RendezVous.h"
#include "DossierPatient.h"
#include "SalleDeTraitement.h"
#include "Facture.h"
#include <iostream>
#include <limits>
#include <algorithm>

// Constructeur et destructeur
GestionCabinet::GestionCabinet() : utilisateurConnecte(nullptr) {
    initialiserDonneesTest();
}

GestionCabinet::~GestionCabinet() {
    // Les shared_ptr se libèrent automatiquement
    utilisateurConnecte = nullptr;
}

// Méthode principale pour démarrer l'application
void GestionCabinet::demarrer() {
    std::cout << "Bienvenue dans le système de gestion du cabinet dentaire!" << std::endl;
    
    bool quitter = false;
    while (!quitter) {
        std::string username, password;
        std::cout << "\n=== Connexion ===" << std::endl;
        std::cout << "Nom d'utilisateur (ou 'q' pour quitter): ";
        std::cin >> username;
        
        if (username == "q") {
            quitter = true;
            continue;
        }
        
        std::cout << "Mot de passe: ";
        std::cin >> password;
        
        if (authentifier(username, password)) {
            std::cout << "Connexion réussie!" << std::endl;
            
            // Déterminer le type d'utilisateur et afficher le menu approprié
            if (dynamic_cast<Patient*>(utilisateurConnecte)) {
                afficherMenuPatient();
            } else if (dynamic_cast<Dentiste*>(utilisateurConnecte)) {
                afficherMenuDentiste();
            } else if (dynamic_cast<Assistant*>(utilisateurConnecte)) {
                afficherMenuAssistant();
            } else if (dynamic_cast<Responsable*>(utilisateurConnecte)) {
                afficherMenuResponsable();
            } else {
                afficherMenuPrincipal();
            }
            
            utilisateurConnecte->seDeconnecter();
            utilisateurConnecte = nullptr;
        } else {
            std::cout << "Échec de la connexion. Nom d'utilisateur ou mot de passe incorrect." << std::endl;
        }
    }
}

// Méthodes d'authentification
bool GestionCabinet::authentifier(const std::string& username, const std::string& password) {
    Utilisateur* utilisateur = trouverUtilisateurParUsername(username);
    if (utilisateur && utilisateur->getPassword() == password) {
        utilisateurConnecte = utilisateur;
        utilisateurConnecte->seConnecter();
        return true;
    }
    return false;
}

// Méthodes d'affichage des menus
void GestionCabinet::afficherMenuPrincipal() {
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Menu Principal ===" << std::endl;
        std::cout << "1. Gérer les patients" << std::endl;
        std::cout << "2. Gérer les dentistes" << std::endl;
        std::cout << "3. Gérer les assistants" << std::endl;
        std::cout << "4. Gérer les responsables" << std::endl;
        std::cout << "5. Gérer les rendez-vous" << std::endl;
        std::cout << "6. Gérer les salles" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1: gererPatients(); break;
            case 2: gererDentistes(); break;
            case 3: gererAssistants(); break;
            case 4: gererResponsables(); break;
            case 5: gererRendezVous(); break;
            case 6: gererSalles(); break;
            case 0: retour = true; break;
            default: std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void GestionCabinet::afficherMenuPatient() {
    Patient* patient = dynamic_cast<Patient*>(utilisateurConnecte);
    if (!patient) return;
    
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Menu Patient ===" << std::endl;
        std::cout << "1. Voir mes informations" << std::endl;
        std::cout << "2. Demander un rendez-vous" << std::endl;
        std::cout << "3. Voir mes rendez-vous" << std::endl;
        std::cout << "4. Consulter mon dossier médical" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                std::cout << "\n=== Mes Informations ===" << std::endl;
                std::cout << "Nom: " << patient->getNom() << std::endl;
                std::cout << "Prénom: " << patient->getPrenom() << std::endl;
                std::cout << "Date de naissance: " << patient->getDateNaissance() << std::endl;
                break;
            case 2:
                patient->demanderRendezVous();
                break;
            case 3:
                std::cout << "\n=== Mes Rendez-vous ===" << std::endl;
                // Afficher les rendez-vous du patient
                break;
            case 4:
                if (patient->getDossier()) {
                    patient->getDossier()->consulterDossier();
                } else {
                    std::cout << "Vous n'avez pas encore de dossier médical." << std::endl;
                }
                break;
            case 0:
                retour = true;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void GestionCabinet::afficherMenuDentiste() {
    Dentiste* dentiste = dynamic_cast<Dentiste*>(utilisateurConnecte);
    if (!dentiste) return;
    
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Menu Dentiste ===" << std::endl;
        std::cout << "1. Voir mes informations" << std::endl;
        std::cout << "2. Consulter les dossiers patients" << std::endl;
        std::cout << "3. Voir mes rendez-vous" << std::endl;
        std::cout << "4. Gérer les traitements" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                std::cout << "\n=== Mes Informations ===" << std::endl;
                std::cout << "Nom: " << dentiste->getNom() << std::endl;
                std::cout << "Spécialité: " << dentiste->getSpecialite() << std::endl;
                break;
            case 2:
                // Logique pour consulter les dossiers patients
                break;
            case 3:
                std::cout << "\n=== Mes Rendez-vous ===" << std::endl;
                // Afficher les rendez-vous du dentiste
                break;
            case 4:
                // Logique pour gérer les traitements
                break;
            case 0:
                retour = true;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void GestionCabinet::afficherMenuAssistant() {
    // Implémentation similaire à afficherMenuDentiste
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Menu Assistant ===" << std::endl;
        std::cout << "1. Gérer les rendez-vous" << std::endl;
        std::cout << "2. Gérer les salles" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1: gererRendezVous(); break;
            case 2: gererSalles(); break;
            case 0: retour = true; break;
            default: std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void GestionCabinet::afficherMenuResponsable() {
    // Implémentation similaire à afficherMenuDentiste
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Menu Responsable ===" << std::endl;
        std::cout << "1. Gérer les patients" << std::endl;
        std::cout << "2. Gérer les dentistes" << std::endl;
        std::cout << "3. Gérer les assistants" << std::endl;
        std::cout << "4. Gérer les rendez-vous" << std::endl;
        std::cout << "5. Gérer les salles" << std::endl;
        std::cout << "0. Se déconnecter" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1: gererPatients(); break;
            case 2: gererDentistes(); break;
            case 3: gererAssistants(); break;
            case 4: gererRendezVous(); break;
            case 5: gererSalles(); break;
            case 0: retour = true; break;
            default: std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

// Méthodes de gestion
void GestionCabinet::gererPatients() {
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Gestion des Patients ===" << std::endl;
        std::cout << "1. Lister tous les patients" << std::endl;
        std::cout << "2. Ajouter un patient" << std::endl;
        std::cout << "3. Modifier un patient" << std::endl;
        std::cout << "4. Supprimer un patient" << std::endl;
        std::cout << "0. Retour" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                std::cout << "\n=== Liste des Patients ===" << std::endl;
                for (const auto& patient : patients) {
                    std::cout << "ID: " << patient->getId()
                              << ", Nom: " << patient->getNom()
                              << ", Prénom: " << patient->getPrenom() << std::endl;
                }
                break;
            case 2:
                // Logique pour ajouter un patient
                {
                    int id;
                    std::string username, password, nom, prenom, dateNaissance, antecedents;
                    std::cout << "ID: "; std::cin >> id;
                    std::cout << "Nom d'utilisateur: "; std::cin >> username;
                    std::cout << "Mot de passe: "; std::cin >> password;
                    std::cout << "Nom: "; std::cin >> nom;
                    std::cout << "Prénom: "; std::cin >> prenom;
                    std::cout << "Date de naissance: "; std::cin >> dateNaissance;
                    std::cout << "Antécédents médicaux: "; std::cin.ignore(); std::getline(std::cin, antecedents);
                    auto patient = std::make_shared<Patient>(id, username, password, nom, prenom, dateNaissance, antecedents);
                    ajouterPatient(patient);
                    std::cout << "Patient ajouté avec succès." << std::endl;
                }
                break;
            case 3:
                // Logique pour modifier un patient
                {
                    int id;
                    std::cout << "ID du patient à modifier: "; std::cin >> id;
                    Patient* patient = trouverPatient(id);
                    if (patient) {
                        std::string nom, prenom, dateNaissance, antecedents;
                        std::cout << "Nouveau nom: "; std::cin >> nom;
                        std::cout << "Nouveau prénom: "; std::cin >> prenom;
                        std::cout << "Nouvelle date de naissance: "; std::cin >> dateNaissance;
                        std::cout << "Nouveaux antécédents médicaux: "; std::cin.ignore(); std::getline(std::cin, antecedents);
                        patient->setNom(nom);
                        patient->setPrenom(prenom);
                        patient->setDateNaissance(dateNaissance);
                        patient->setAntecedents(antecedents);
                        std::cout << "Patient modifié avec succès." << std::endl;
                    } else {
                        std::cout << "Patient introuvable." << std::endl;
                    }
                }
                break;
            case 4:
                // Logique pour supprimer un patient
                {
                    int id;
                    std::cout << "ID du patient à supprimer: "; std::cin >> id;
                    supprimerPatient(id);
                    std::cout << "Patient supprimé avec succès." << std::endl;
                }
                break;
            case 0:
                retour = true;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void GestionCabinet::gererDentistes() {
    // Implémentation similaire à gererPatients
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Gestion des Dentistes ===" << std::endl;
        std::cout << "1. Lister tous les dentistes" << std::endl;
        std::cout << "2. Ajouter un dentiste" << std::endl;
        std::cout << "3. Modifier un dentiste" << std::endl;
        std::cout << "4. Supprimer un dentiste" << std::endl;
        std::cout << "0. Retour" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                std::cout << "\n=== Liste des Dentistes ===" << std::endl;
                for (const auto& dentiste : dentistes) {
                    std::cout << "ID: " << dentiste->getId()
                              << ", Nom: " << dentiste->getNom()
                              << ", Spécialité: " << dentiste->getSpecialite() << std::endl;
                }
                break;
            case 2:
                // Logique pour ajouter un dentiste
                {
                    int id;
                    std::string username, password, nom, specialite;
                    std::cout << "ID: "; std::cin >> id;
                    std::cout << "Nom d'utilisateur: "; std::cin >> username;
                    std::cout << "Mot de passe: "; std::cin >> password;
                    std::cout << "Nom: "; std::cin >> nom;
                    std::cout << "Spécialité: "; std::cin >> specialite;
                    auto dentiste = std::make_shared<Dentiste>(id, username, password, nom, specialite);
                    ajouterUtilisateur(dentiste);
                    dentistes.push_back(dentiste);
                    std::cout << "Dentiste ajouté avec succès." << std::endl;
                }
                break;
            case 3:
                // Logique pour modifier un dentiste
                {
                    int id;
                    std::cout << "ID du dentiste à modifier: "; std::cin >> id;
                    for (auto& d : dentistes) {
                        if (d->getId() == id) {
                            std::string nom, specialite;
                            std::cout << "Nouveau nom: "; std::cin >> nom;
                            std::cout << "Nouvelle spécialité: "; std::cin >> specialite;
                            d->setNom(nom);
                            d->setSpecialite(specialite);
                            std::cout << "Dentiste modifié avec succès." << std::endl;
                            break;
                        }
                    }
                }
                break;
            case 4:
                // Logique pour supprimer un dentiste
                {
                    int id;
                    std::cout << "ID du dentiste à supprimer: "; std::cin >> id;
                    auto it = std::remove_if(dentistes.begin(), dentistes.end(), [id](const std::shared_ptr<Dentiste>& d){ return d->getId() == id; });
                    dentistes.erase(it, dentistes.end());
                    supprimerUtilisateur(id);
                    std::cout << "Dentiste supprimé avec succès." << std::endl;
                }
                break;
            case 0:
                retour = true;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void GestionCabinet::gererAssistants() {
    // Implémentation similaire à gererPatients
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Gestion des Assistants ===" << std::endl;
        std::cout << "1. Lister tous les assistants" << std::endl;
        std::cout << "2. Ajouter un assistant" << std::endl;
        std::cout << "3. Modifier un assistant" << std::endl;
        std::cout << "4. Supprimer un assistant" << std::endl;
        std::cout << "0. Retour" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Implémentation des options du menu
        retour = (choix == 0);
    }
}

void GestionCabinet::gererResponsables() {
    // Implémentation similaire à gererPatients
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Gestion des Responsables ===" << std::endl;
        std::cout << "1. Lister tous les responsables" << std::endl;
        std::cout << "2. Ajouter un responsable" << std::endl;
        std::cout << "3. Modifier un responsable" << std::endl;
        std::cout << "4. Supprimer un responsable" << std::endl;
        std::cout << "0. Retour" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Implémentation des options du menu
        retour = (choix == 0);
    }
}

void GestionCabinet::gererRendezVous() {
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Gestion des Rendez-vous ===" << std::endl;
        std::cout << "1. Lister tous les rendez-vous" << std::endl;
        std::cout << "2. Ajouter un rendez-vous" << std::endl;
        std::cout << "3. Modifier un rendez-vous" << std::endl;
        std::cout << "4. Supprimer un rendez-vous" << std::endl;
        std::cout << "0. Retour" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                std::cout << "\n=== Liste des Rendez-vous ===" << std::endl;
                for (const auto& rdv : rendezVous) {
                    std::cout << "Date: " << rdv->getDate()
                              << ", Heure: " << rdv->getHeure()
                              << ", Statut: " << rdv->getStatut() << std::endl;
                }
                break;
            case 2:
                // Logique pour ajouter un rendez-vous
                {
                    std::string date, heure, statut;
                    int idPatient, idSalle;
                    std::cout << "Date (YYYY-MM-DD): "; std::cin >> date;
                    std::cout << "Heure (HH:MM): "; std::cin >> heure;
                    std::cout << "Statut: "; std::cin >> statut;
                    std::cout << "ID Patient: "; std::cin >> idPatient;
                    std::cout << "ID Salle: "; std::cin >> idSalle;
                    auto rdv = std::make_shared<RendezVous>(date, heure, statut);
                    Patient* patient = trouverPatient(idPatient);
                    SalleDeTraitement* salle = trouverSalle(idSalle);
                    if (patient && salle) {
                        rdv->setPatient(patient);
                        rdv->setSalle(salle);
                        ajouterRendezVous(rdv);
                        std::cout << "Rendez-vous ajouté avec succès." << std::endl;
                    } else {
                        std::cout << "Patient ou salle introuvable." << std::endl;
                    }
                }
                break;
            case 3:
                // Logique pour modifier un rendez-vous
                {
                    std::string date, heure;
                    std::cout << "Date du rendez-vous à modifier (YYYY-MM-DD): "; std::cin >> date;
                    std::cout << "Heure du rendez-vous à modifier (HH:MM): "; std::cin >> heure;
                    RendezVous* rdv = trouverRendezVous(date, heure);
                    if (rdv) {
                        std::string newDate, newHeure, newStatut;
                        int idPatient, idSalle;
                        std::cout << "Nouvelle date: "; std::cin >> newDate;
                        std::cout << "Nouvelle heure: "; std::cin >> newHeure;
                        std::cout << "Nouveau statut: "; std::cin >> newStatut;
                        std::cout << "ID Patient: "; std::cin >> idPatient;
                        std::cout << "ID Salle: "; std::cin >> idSalle;
                        rdv->setDate(newDate);
                        rdv->setHeure(newHeure);
                        rdv->setStatut(newStatut);
                        Patient* patient = trouverPatient(idPatient);
                        SalleDeTraitement* salle = trouverSalle(idSalle);
                        if (patient && salle) {
                            rdv->setPatient(patient);
                            rdv->setSalle(salle);
                            std::cout << "Rendez-vous modifié avec succès." << std::endl;
                        } else {
                            std::cout << "Patient ou salle introuvable." << std::endl;
                        }
                    } else {
                        std::cout << "Rendez-vous introuvable." << std::endl;
                    }
                }
                break;
            case 4:
                // Logique pour supprimer un rendez-vous
                {
                    std::string date, heure;
                    std::cout << "Date du rendez-vous à supprimer (YYYY-MM-DD): "; std::cin >> date;
                    std::cout << "Heure du rendez-vous à supprimer (HH:MM): "; std::cin >> heure;
                    supprimerRendezVous(date, heure);
                    std::cout << "Rendez-vous supprimé avec succès." << std::endl;
                }
                break;
            case 0:
                retour = true;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void GestionCabinet::gererSalles() {
    bool retour = false;
    while (!retour) {
        std::cout << "\n=== Gestion des Salles ===" << std::endl;
        std::cout << "1. Lister toutes les salles" << std::endl;
        std::cout << "2. Ajouter une salle" << std::endl;
        std::cout << "3. Modifier une salle" << std::endl;
        std::cout << "4. Supprimer une salle" << std::endl;
        std::cout << "0. Retour" << std::endl;
        
        int choix;
        std::cout << "Votre choix: ";
        std::cin >> choix;
        
        // Vider le buffer d'entrée
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choix) {
            case 1:
                std::cout << "\n=== Liste des Salles ===" << std::endl;
                for (const auto& salle : salles) {
                    std::cout << "ID: " << salle->getId()
                              << ", Nom: " << salle->getNom()
                              << ", Statut: " << salle->getStatut() << std::endl;
                }
                break;
            case 2:
                // Logique pour ajouter une salle
                {
                    int id;
                    std::string nom, equipement, statut;
                    std::cout << "ID: "; std::cin >> id;
                    std::cout << "Nom: "; std::cin >> nom;
                    std::cout << "Équipement: "; std::cin >> equipement;
                    std::cout << "Statut: "; std::cin >> statut;
                    auto salle = std::make_shared<SalleDeTraitement>(id, nom, equipement, statut);
                    ajouterSalle(salle);
                    std::cout << "Salle ajoutée avec succès." << std::endl;
                }
                break;
            case 3:
                // Logique pour modifier une salle
                {
                    int id;
                    std::cout << "ID de la salle à modifier: "; std::cin >> id;
                    SalleDeTraitement* salle = trouverSalle(id);
                    if (salle) {
                        std::string nom, equipement, statut;
                        std::cout << "Nouveau nom: "; std::cin >> nom;
                        std::cout << "Nouvel équipement: "; std::cin >> equipement;
                        std::cout << "Nouveau statut: "; std::cin >> statut;
                        salle->setNom(nom);
                        salle->setEquipements(equipement);
                        salle->setStatut(statut);
                        std::cout << "Salle modifiée avec succès." << std::endl;
                    } else {
                        std::cout << "Salle introuvable." << std::endl;
                    }
                }
                break;
            case 4:
                // Logique pour supprimer une salle
                {
                    int id;
                    std::cout << "ID de la salle à supprimer: "; std::cin >> id;
                    supprimerSalle(id);
                    std::cout << "Salle supprimée avec succès." << std::endl;
                }
                break;
            case 0:
                retour = true;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

// Méthodes de gestion des utilisateurs
void GestionCabinet::ajouterUtilisateur(std::shared_ptr<Utilisateur> utilisateur) {
    utilisateurs.push_back(utilisateur);
}

void GestionCabinet::supprimerUtilisateur(int id) {
    auto it = std::remove_if(utilisateurs.begin(), utilisateurs.end(),
                            [id](const std::shared_ptr<Utilisateur>& u) { return u->getId() == id; });
    utilisateurs.erase(it, utilisateurs.end());
}

Utilisateur* GestionCabinet::trouverUtilisateur(int id) {
    for (const auto& utilisateur : utilisateurs) {
        if (utilisateur->getId() == id) {
            return utilisateur.get();
        }
    }
    return nullptr;
}

Utilisateur* GestionCabinet::trouverUtilisateurParUsername(const std::string& username) {
    for (const auto& utilisateur : utilisateurs) {
        if (utilisateur->getUsername() == username) {
            return utilisateur.get();
        }
    }
    return nullptr;
}

// Méthodes de gestion des patients
void GestionCabinet::ajouterPatient(std::shared_ptr<Patient> patient) {
    patients.push_back(patient);
    ajouterUtilisateur(patient);
}

void GestionCabinet::supprimerPatient(int id) {
    auto it = std::remove_if(patients.begin(), patients.end(),
                            [id](const std::shared_ptr<Patient>& p) { return p->getId() == id; });
    patients.erase(it, patients.end());
    supprimerUtilisateur(id);
}

Patient* GestionCabinet::trouverPatient(int id) {
    for (const auto& patient : patients) {
        if (patient->getId() == id) {
            return patient.get();
        }
    }
    return nullptr;
}

// Méthodes de gestion des rendez-vous
void GestionCabinet::ajouterRendezVous(std::shared_ptr<RendezVous> rdv) {
    rendezVous.push_back(rdv);
}

void GestionCabinet::supprimerRendezVous(const std::string& date, const std::string& heure) {
    auto it = std::remove_if(rendezVous.begin(), rendezVous.end(),
                            [&date, &heure](const std::shared_ptr<RendezVous>& r) {
                                return r->getDate() == date && r->getHeure() == heure;
                            });
    rendezVous.erase(it, rendezVous.end());
}

RendezVous* GestionCabinet::trouverRendezVous(const std::string& date, const std::string& heure) {
    for (const auto& rdv : rendezVous) {
        if (rdv->getDate() == date && rdv->getHeure() == heure) {
            return rdv.get();
        }
    }
    return nullptr;
}

// Méthodes de gestion des salles
void GestionCabinet::ajouterSalle(std::shared_ptr<SalleDeTraitement> salle) {
    salles.push_back(salle);
}

void GestionCabinet::supprimerSalle(int id) {
    auto it = std::remove_if(salles.begin(), salles.end(),
                            [id](const std::shared_ptr<SalleDeTraitement>& s) { return s->getId() == id; });
    salles.erase(it, salles.end());
}

SalleDeTraitement* GestionCabinet::trouverSalle(int id) {
    for (const auto& salle : salles) {
        if (salle->getId() == id) {
            return salle.get();
        }
    }
    return nullptr;
}

// Initialisation des données de test
void GestionCabinet::initialiserDonneesTest() {
    // Création de quelques utilisateurs de test
    
    // Patients
    auto patient1 = std::make_shared<Patient>(1, "omarpa", "omarpa123", "Dupont", "Jean", "01/01/1980", "Aucun antécédent particulier");
    auto patient2 = std::make_shared<Patient>(2, "patient2", "pass123", "Martin", "Sophie", "15/05/1992", "Allergie à la pénicilline");
    
    // Dentistes
    auto dentiste1 = std::make_shared<Dentiste>(3, "dentiste1", "pass123", "Lefebvre", "Orthodontie");
    auto dentiste2 = std::make_shared<Dentiste>(4, "dentiste2", "pass123", "Moreau", "Chirurgie dentaire");
    
    // Assistants
    auto assistant1 = std::make_shared<Assistant>(5, "assistant1", "pass123", "Petit", "Marie");
    
    // Responsables
    auto responsable1 = std::make_shared<Responsable>(6, "admin", "admin", "Dubois", "Pierre");
    
    // Ajout des utilisateurs
    ajouterPatient(patient1);
    ajouterPatient(patient2);
    
    ajouterUtilisateur(dentiste1);
    dentistes.push_back(dentiste1);
    
    ajouterUtilisateur(dentiste2);
    dentistes.push_back(dentiste2);
    
    ajouterUtilisateur(assistant1);
    assistants.push_back(assistant1);
    
    ajouterUtilisateur(responsable1);
    responsables.push_back(responsable1);
    
    // Création de dossiers patients
    auto dossier1 = std::make_shared<DossierPatient>(1, "Dossier médical standard");
    dossier1->setPatient(patient1.get());
    patient1->setDossier(dossier1.get());
    dossiers.push_back(dossier1);
    
    auto dossier2 = std::make_shared<DossierPatient>(2, "Traitement orthodontique en cours");
    dossier2->setPatient(patient2.get());
    patient2->setDossier(dossier2.get());
    dossiers.push_back(dossier2);
    
    // Création de salles
    auto salle1 = std::make_shared<SalleDeTraitement>(1, "Salle A", "Équipement standard", "disponible");
    auto salle2 = std::make_shared<SalleDeTraitement>(2, "Salle B", "Équipement chirurgical", "disponible");
    salles.push_back(salle1);
    salles.push_back(salle2);
    
    // Création de rendez-vous
    auto rdv1 = std::make_shared<RendezVous>("2023-06-15", "10:00", "confirmé");
    rdv1->setPatient(patient1.get());
    rdv1->setSalle(salle1.get());
    rendezVous.push_back(rdv1);
    
    auto rdv2 = std::make_shared<RendezVous>("2023-06-16", "14:30", "en attente");
    rdv2->setPatient(patient2.get());
    rdv2->setSalle(salle2.get());
    rendezVous.push_back(rdv2);
    
    std::cout << "Données de test initialisées." << std::endl;
}