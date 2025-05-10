#include "User.h"

User::User(std::string u, std::string p, std::string n) : username(u), password(p), name(n) {}

void User::displayProfile()
{
    std::cout << "Name: " << name << ", Username: " << username << std::endl;
}

bool User::login(std::string u, std::string p)
{
    return username == u && password == p;
}

void User::setPassword(std::string newPass)
{
    password = newPass;
}

std::string User::getUsername() const
{
    return username;
}

void User::showInfo() const
{
    std::cout << "\n--- User Information ---\n";
    std::cout << "Username: " << username << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Role: " << getRole() << std::endl;
    std::cout << "------------------------\n";
}