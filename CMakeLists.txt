cmake_minimum_required(VERSION 3.10)
project(CourseManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cms
    main.cpp
    Lesson.cpp
    Course.cpp
    User.cpp
    Student.cpp
    Instructor.cpp
    TeachingAssistant.cpp
    Admin.cpp
) 