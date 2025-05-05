#include "Utilisateur.h"
#include <iostream>

// Constructeurs et destructeur
Utilisateur::Utilisateur() : id(0), username(""), password("") {}

Utilisateur::Utilisateur(int id, const std::string& username, const std::string& password)
    : id(id), username(username), password(password) {}

Utilisateur::~Utilisateur() {}

// Getters et setters
int Utilisateur::getId() const {
    return id;
}

void Utilisateur::setId(int id) {
    this->id = id;
}

std::string Utilisateur::getUsername() const {
    return username;
}

void Utilisateur::setUsername(const std::string& username) {
    this->username = username;
}

std::string Utilisateur::getPassword() const {
    return password;
}

void Utilisateur::setPassword(const std::string& password) {
    this->password = password;
}

// Méthodes de la classe
void Utilisateur::seConnecter() {
    std::cout << "Utilisateur " << username << " connecté." << std::endl;
}

void Utilisateur::seDeconnecter() {
    std::cout << "Utilisateur " << username << " déconnecté." << std::endl;
}