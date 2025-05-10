#include "Instructor.h"
#include <iostream>

Instructor::Instructor(std::string u, std::string p, std::string n) : User(u, p, n) {}

void Instructor::displayProfile() override
{
    std::cout << "[Instructor] ";
    User::displayProfile();
}

std::string Instructor::getRole() const override
{
    return "Instructor";
}

void Instructor::addCourse(std::vector<Course> &courses)
{
    std::string id, title;
    std::cout << "Enter Course ID: ";
    std::cin >> id;
    std::cout << "Enter Course Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    Course newCourse(id, title);

    int lessonCount;
    std::cout << "How many lessons? ";
    std::cin >> lessonCount;
    std::cin.ignore();
    for (int i = 0; i < lessonCount; i++)
    {
        std::string lt, lc;
        std::cout << "Enter Lesson Title: ";
        std::getline(std::cin, lt);
        std::cout << "Enter Lesson Content: ";
        std::getline(std::cin, lc);
        newCourse.addLesson(lt, lc);
    }

    courses.push_back(newCourse);
    std::cout << "Course added successfully.\n";
}

void Instructor::showCourses(const std::vector<Course> &courses)
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
        std::cout << "\n------------------------\n";
    }
}