#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Lesson.h"

class Student; // Forward declaration

class Course
{
private:
    std::string courseID, title;
    std::vector<Lesson> lessons;

public:
    Course(std::string id = "", std::string t = "");
    void addLesson(std::string title, std::string content);
    void displayCourse() const;
    std::string getCourseID() const;

    friend class Student;
};

#endif