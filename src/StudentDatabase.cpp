#include "StudentDatabase.h"

#include <algorithm>    
#include <fstream>     
#include <iostream>    
#include <sstream>     


/*
   Constructor
 */
StudentDatabase::StudentDatabase(const std::string& file)
    : filename(file) {
    // Load existing data (if any) when database is created
    load();
}


/*
   File I/O
 */

// Load student records from file into memory
void StudentDatabase::load() {
    std::ifstream fin(filename);

    // File may not exist on first run — not an error
    if (!fin) {
        return;
    }

    students.clear();
    std::string line;

    // Read file line by line
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        Student s;

        // Expected format: ID Name Marks
        if (ss >> s.id >> s.name >> s.marks) {
            students.push_back(s);
        }
        // Malformed lines are ignored safely
    }
}

// Save current in-memory records to file
void StudentDatabase::save() const {
    std::ofstream fout(filename);

    for (const auto& s : students) {
        fout << s.id << " "
             << s.name << " "
             << s.marks << "\n";
    }
}


/*
   CRUD Operations
 */

// Add a new student to the database
void StudentDatabase::addStudent() {
    Student s;

    std::cout << "Enter ID: ";
    std::cin >> s.id;

    // Enforce unique student ID
    for (const auto& existing : students) {
        if (existing.id == s.id) {
            std::cout << "Error: ID already exists.\n";
            return;
        }
    }

    std::cout << "Enter Name: ";
    std::cin >> s.name;

    std::cout << "Enter Marks: ";
    std::cin >> s.marks;

    students.push_back(s);
    save();

    std::cout << "Student added successfully.\n";
}

// Delete a student by ID
void StudentDatabase::deleteStudentById(int id) {
    // Move matching students to the end
    auto it = std::remove_if(
        students.begin(),
        students.end(),
        [id](const Student& s) {
            return s.id == id;
        }
    );

    // If nothing was removed
    if (it == students.end()) {
        std::cout << "Student with ID " << id << " not found.\n";
        return;
    }

    // Erase the removed range
    students.erase(it, students.end());
    save();

    std::cout << "Student deleted successfully.\n";
}

// Search for a student by ID
void StudentDatabase::searchStudentById(int id) const {
    for (const auto& s : students) {
        if (s.id == id) {
            std::cout << "Student found:\n";
            std::cout << "ID: " << s.id
                      << ", Name: " << s.name
                      << ", Marks: " << s.marks << "\n";
            return;
        }
    }

    std::cout << "Student with ID " << id << " not found.\n";
}


/*
   Sorting
 */

// Sort students by marks (descending)
void StudentDatabase::sortByMarks() {
    std::sort(
        students.begin(),
        students.end(),
        [](const Student& a, const Student& b) {
            return a.marks > b.marks;
        }
    );

    save();
    std::cout << "Students sorted by marks (descending).\n";
}

// Sort students by ID (ascending)
void StudentDatabase::sortById() {
    std::sort(
        students.begin(),
        students.end(),
        [](const Student& a, const Student& b) {
            return a.id < b.id;
        }
    );

    save();
    std::cout << "Students sorted by ID (ascending).\n";
}


/*
   Display
 */

// Display all student records
void StudentDatabase::displayAll() const {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }

    for (const auto& s : students) {
        std::cout << "ID: " << s.id
                  << ", Name: " << s.name
                  << ", Marks: " << s.marks << "\n";
    }
}
