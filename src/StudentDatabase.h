#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include <string>
#include <vector>

/*
    Represents a single student record.
    This struct is a pure data container with no logic.
*/
struct Student {
    int id;                 // Unique student identifier
    std::string name;       // Student name
    int marks;              // Student marks/score
};

/*
    StudentDatabase
    ----------------
    Manages a collection of student records with:
    - Persistent file storage
    - Search, deletion, and sorting operations
    - Clean separation between data and logic
*/
class StudentDatabase {
private:
    // In-memory storage of student records
    std::vector<Student> students;

    // File path used for persistent storage
    std::string filename;

public:
    /*
        Constructor
        Initializes the database and loads existing data
        from the provided file (if it exists).
    */
    explicit StudentDatabase(const std::string& file);

    /* File Operations */

    // Load student records from file into memory
    void load();

    // Save current in-memory records to file
    void save() const;

    /* CRUD Operations */

    // Add a new student (ID must be unique)
    void addStudent();

    // Delete a student record by ID
    void deleteStudentById(int id);

    // Search and display a student record by ID
    void searchStudentById(int id) const;

    /* Sorting */

    // Sort students by marks in descending order
    void sortByMarks();

    // Sort students by ID in ascending order
    void sortById();

    /* Display */

    // Display all student records
    void displayAll() const;
};

#endif  // STUDENT_DATABASE_H
