#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "User.h"
#include "Course.h"
#include <vector>

class Instructor : virtual public User
{
public:
    Instructor(std::string u, std::string p, std::string n);
    void displayProfile() override;
    std::string getRole() const override;
    void addCourse(std::vector<Course> &courses);
    void showCourses(const std::vector<Course> &courses);
};

#endif