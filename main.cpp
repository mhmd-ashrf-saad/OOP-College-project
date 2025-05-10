#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "TeachingAssistant.h"
#include "Admin.h"
#include "Course.h"

bool loginSystem(std::vector<User *> &users, User *&loggedInUser)
{
    std::string u, p;
    std::cout << "\n--- Login Page ---\n";
    std::cout << "1. Login\n0. Exit\nChoice: ";
    int option;
    std::cin >> option;
    if (option == 0)
        return false;

    std::cout << "Username: ";
    std::cin >> u;
    std::cout << "Password: ";
    std::cin >> p;

    for (auto user : users)
    {
        if (user->login(u, p))
        {
            loggedInUser = user;
            return true;
        }
    }
    std::cout << "Invalid credentials.\n";
    return true;
}

int main()
{
    std::vector<User *> users;
    std::vector<Course> courses;

    Student *s1 = new Student("std1", "123", "Ali");
    Instructor *ins1 = new Instructor("ins1", "123", "Dr. Ahmed");
    TeachingAssistant *ta1 = new TeachingAssistant("ta1", "123", "Mona");
    Admin *admin1 = new Admin("admin", "admin", "Admin");

    users.push_back(s1);
    users.push_back(ins1);
    users.push_back(ta1);
    users.push_back(admin1);

    Course c1("C101", "OOP");
    c1.addLesson("Intro", "OOP Basics");
    c1.addLesson("Inheritance", "How inheritance works");

    Course c2("C102", "Data Structures");
    c2.addLesson("Arrays", "Introduction to arrays");
    c2.addLesson("Linked Lists", "How linked lists work");

    courses.push_back(c1);
    courses.push_back(c2);

    std::cout << "Welcome to the Course Management System\n";

    while (true)
    {
        User *loggedIn = nullptr;
        bool continueLogin = loginSystem(users, loggedIn);
        if (!continueLogin)
            break;

        if (loggedIn == nullptr)
            continue;

        std::cout << "Login successful as " << loggedIn->getRole() << "\n";

        if (loggedIn->getRole() == "Student")
        {
            Student *s = dynamic_cast<Student *>(loggedIn);
            int choice;
            do
            {
                std::cout << "\n1. View Courses\n2. Enroll in Course\n3. View Enrolled Courses\n"
                          << "4. Show My Information\n0. Logout\nChoice: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    for (auto &c : courses)
                        c.displayCourse();
                }
                else if (choice == 2)
                {
                    std::string id;
                    std::cout << "Enter Course ID: ";
                    std::cin >> id;
                    for (auto &c : courses)
                    {
                        if (c.getCourseID() == id)
                        {
                            s->enroll(&c);
                            std::cout << "Enrolled successfully.\n";
                        }
                    }
                }
                else if (choice == 3)
                {
                    s->showCourses();
                }
                else if (choice == 4)
                {
                    s->showInfo();
                }
            } while (choice != 0);
        }
        else if (loggedIn->getRole() == "Instructor")
        {
            Instructor *ins = dynamic_cast<Instructor *>(loggedIn);
            int choice;
            do
            {
                std::cout << "\n1. Add Course\n2. Show All Courses\n"
                          << "3. Show My Information\n0. Logout\nChoice: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    ins->addCourse(courses);
                }
                else if (choice == 2)
                {
                    ins->showCourses(courses);
                }
                else if (choice == 3)
                {
                    ins->showInfo();
                }
            } while (choice != 0);
        }
        else if (loggedIn->getRole() == "Admin")
        {
            Admin *a = dynamic_cast<Admin *>(loggedIn);
            int choice;
            do
            {
                std::cout << "\n1. Add User\n2. Reset Password\n3. Show All Courses\n"
                          << "4. Show My Information\n0. Logout\nChoice: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    a->addUser(users);
                }
                else if (choice == 2)
                {
                    std::string uname;
                    std::cout << "Enter username to reset password: ";
                    std::cin >> uname;
                    for (auto u : users)
                    {
                        if (u->getUsername() == uname)
                        {
                            a->resetPassword(*u, "newpass123");
                        }
                    }
                }
                else if (choice == 3)
                {
                    a->showCourses(courses);
                }
                else if (choice == 4)
                {
                    a->showInfo();
                }
            } while (choice != 0);
        }
        else
        {
            loggedIn->displayProfile();
        }
    }

    std::cout << "Exiting system...\n";

    for (auto u : users)
        delete u;

    return 0;
}
