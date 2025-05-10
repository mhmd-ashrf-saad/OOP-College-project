#include "TeachingAssistant.h"
#include <iostream>

TeachingAssistant::TeachingAssistant(std::string u, std::string p, std::string n)
    : User(u, p, n), Student(u, p, n), Instructor(u, p, n) {}

void TeachingAssistant::displayProfile() override
{
    std::cout << "[Teaching Assistant] ";
    User::displayProfile();
}

std::string TeachingAssistant::getRole() const override
{
    return "TA";
}