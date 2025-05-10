#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
protected:
    std::string username, password, name;

public:
    User(std::string u = "", std::string p = "", std::string n = "");
    virtual void displayProfile();
    bool login(std::string u, std::string p);
    void setPassword(std::string newPass);
    std::string getUsername() const;
    virtual std::string getRole() const = 0;
    void showInfo() const;
    virtual ~User() = default;
};

#endif