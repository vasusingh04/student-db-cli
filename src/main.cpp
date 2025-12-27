#include "StudentDatabase.h"
#include <iostream>

int main() {
    // Initialize the database with persistent storage file
    StudentDatabase db("data/students.txt");

    int choice;

    // Main menu loop
    while (true) {
        // Display menu options
        std::cout << "\n1. Add Student\n"
                  << "2. Delete Student\n"
                  << "3. Search Student\n"
                  << "4. Sort by Marks\n"
                  << "5. Sort by ID\n"
                  << "6. Display All\n"
                  << "0. Exit\n"
                  << "Enter choice: ";

        std::cin >> choice;

        // Exit condition
        if (choice == 0) {
            break;
        }

        // Handle user choice
        switch (choice) {

            case 1:
                // Add a new student
                db.addStudent();
                break;

            case 2: {
                // Delete a student by ID
                int id;
                std::cout << "Enter ID to delete: ";
                std::cin >> id;
                db.deleteStudentById(id);
                break;
            }

            case 3: {
                // Search for a student by ID
                int id;
                std::cout << "Enter ID to search: ";
                std::cin >> id;
                db.searchStudentById(id);
                break;
            }

            case 4:
                // Sort students by marks (descending)
                db.sortByMarks();
                break;

            case 5:
                // Sort students by ID (ascending)
                db.sortById();
                break;

            case 6:
                // Display all students
                db.displayAll();
                break;

            default:
                // Handle invalid menu input
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
