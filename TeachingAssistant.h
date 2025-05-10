#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "Student.h"
#include "Instructor.h"

class TeachingAssistant : public Student, public Instructor
{
public:
    TeachingAssistant(std::string u, std::string p, std::string n);
    void displayProfile() override;
    std::string getRole() const override;
};

#endif