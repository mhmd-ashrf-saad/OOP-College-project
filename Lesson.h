#ifndef LESSON_H
#define LESSON_H

#include <string>
#include <iostream>

class Lesson
{
private:
    std::string lessonTitle;
    std::string content;

public:
    Lesson(std::string title = "", std::string cont = "");
    void displayLesson() const;
};

#endif