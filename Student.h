#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include <vector>

class Student : virtual public User
{
private:
    std::vector<Course *> enrolledCourses;

public:
    Student(std::string u, std::string p, std::string n);
    void enroll(Course *course);
    void viewEnrolledCourses();
    void showCourses() const;
    void displayProfile() override;
    std::string getRole() const override;
};

#endif