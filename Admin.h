#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Course.h"
#include <vector>

class Admin : public User
{
public:
    Admin(std::string u, std::string p, std::string n);
    void displayProfile() override;
    std::string getRole() const override;
    void resetPassword(User &u, std::string newPass);
    void addUser(std::vector<User *> &users);
    void showCourses(const std::vector<Course> &courses);
};

#endif