#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Utilisateur.h"
#include "Patient.h"
#include "Dentiste.h"
#include "Assistant.h"
#include "Responsable.h"
#include "RendezVous.h"
#include "DossierPatient.h"
#include "Facture.h"
#include "SalleDeTraitement.h"
#include "Rapport.h"
#include "GestionCabinet.h"

int main() {
    std::cout << "=== Application de Gestion de Cabinet Dentaire ===" << std::endl;
    
    // Création d'une instance de gestion de cabinet
    GestionCabinet cabinet;
    
    // Démarrage de l'application
    cabinet.demarrer();
    
    std::cout << "Fermeture de l'application..." << std::endl;
    return 0;
}