#include "Student.h"
#include <iostream>

Student::Student(std::string u, std::string p, std::string n) : User(u, p, n) {}

void Student::enroll(Course *course)
{
    enrolledCourses.push_back(course);
}

void Student::viewEnrolledCourses()
{
    std::cout << "--- Enrolled Courses for " << name << " ---\n";
    for (auto c : enrolledCourses)
        c->displayCourse();
}

void Student::showCourses() const
{
    std::cout << "\n--- Enrolled Courses for " << name << " ---\n";
    if (enrolledCourses.empty())
    {
        std::cout << "No courses enrolled.\n";
        return;
    }

    for (const auto &course : enrolledCourses)
    {
        course->displayCourse();
        std::cout << "------------------------\n";
    }
}

void Student::displayProfile() override
{
    std::cout << "[Student] ";
    User::displayProfile();
}

std::string Student::getRole() const override
{
    return "Student";
}