#include "Lesson.h"

Lesson::Lesson(std::string title, std::string cont) : lessonTitle(title), content(cont) {}

void Lesson::displayLesson() const
{
    std::cout << "Lesson: " << lessonTitle << "\nContent: " << content << std::endl;
}