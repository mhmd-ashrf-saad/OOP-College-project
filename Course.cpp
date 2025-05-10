#include "Course.h"
#include <iostream>

Course::Course(std::string id, std::string t) : courseID(id), title(t) {}

void Course::addLesson(std::string title, std::string content)
{
    lessons.push_back(Lesson(title, content));
}

void Course::displayCourse() const
{
    std::cout << "\nCourse ID: " << courseID << ", Title: " << title << std::endl;
    for (const auto &lesson : lessons)
    {
        lesson.displayLesson();
    }
    std::cout << "\n------------------------\n\n";
}

std::string Course::getCourseID() const
{
    return courseID;
}