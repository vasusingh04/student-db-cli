# Student Database CLI (C++)

A C++ command-line application for managing student records with persistent storage.  
The project demonstrates clean object-oriented design, structured file handling, and effective use of the C++ Standard Library.

## Features:
- Add students with ID, name, and marks
- Delete students by ID
- Search students by ID
- Sort records by marks (descending)
- Sort records by ID (ascending)
- Display all stored students
- Persistent storage using file I/O so data survives program restarts

## Concepts Used:
- Object-Oriented Programming (classes, encapsulation)
- STL containers (std::vector)
- File handling with ifstream and ofstream
- Sorting with custom comparators using std::sort
- Lambda expressions
- Clear separation of interface (.h) and implementation (.cpp)

## Project Structure
src/        -> Core source files  
data/       -> Persistent student records  
README.md   -> Project documentation  


## Build Instructions:
Compile the project using:
    g++ src/*.cpp -o student_db

Run the executable using:
    ./student_db

## Design Goals:
- Simple and readable command-line interface
- Clear separation of responsibilities
- Reliable and consistent data persistence
- Maintainable and extensible C++ codebase
  

## Author:
Vasu Singh
