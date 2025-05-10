#include "Admin.h"
#include "Student.h"
#include "Instructor.h"
#include "TeachingAssistant.h"
#include <iostream>

Admin::Admin(std::string u, std::string p, std::string n) : User(u, p, n) {}

void Admin::displayProfile() override
{
    std::cout << "[Admin] ";
    User::displayProfile();
}

std::string Admin::getRole() const override
{
    return "Admin";
}

void Admin::resetPassword(User &u, std::string newPass)
{
    u.setPassword(newPass);
    std::cout << "Password changed for " << u.getUsername() << std::endl;
}

void Admin::addUser(std::vector<User *> &users)
{
    int type;
    std::string u, p, n;
    std::cout << "Enter username: ";
    std::cin >> u;
    std::cout << "Enter password: ";
    std::cin >> p;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, n);
    std::cout << "User type (1-Student, 2-Instructor, 3-TA, 4-Admin): ";
    std::cin >> type;

    switch (type)
    {
    case 1:
        users.push_back(new Student(u, p, n));
        break;
    case 2:
        users.push_back(new Instructor(u, p, n));
        break;
    case 3:
        users.push_back(new TeachingAssistant(u, p, n));
        break;
    case 4:
        users.push_back(new Admin(u, p, n));
        break;
    default:
        std::cout << "Invalid type.\n";
    }

    std::cout << "User added.\n";
}

void Admin::showCourses(const std::vector<Course> &courses)
{
    std::cout << "\n--- All Courses ---\n";
    if (courses.empty())
    {
        std::cout << "No courses available.\n";
        return;
    }

    for (const auto &course : courses)
    {
        course.displayCourse();
        std::cout << "------------------------\n";
    }
}