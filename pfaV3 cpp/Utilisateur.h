#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>

class Utilisateur {
protected:
    int id;
    std::string username;
    std::string password;

public:
    // Constructeurs et destructeur
    Utilisateur();
    Utilisateur(int id, const std::string& username, const std::string& password);
    virtual ~Utilisateur();

    // Getters et setters
    int getId() const;
    void setId(int id);
    std::string getUsername() const;
    void setUsername(const std::string& username);
    std::string getPassword() const;
    void setPassword(const std::string& password);

    // Méthodes de la classe
    virtual void seConnecter();
    virtual void seDeconnecter();
};

#endif // UTILISATEUR_H