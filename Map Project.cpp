#include <iostream>
#include <fstream>
#include "schedule.h"

int main() {
    schedule sched;

    // Open the file
    std::ifstream inputFile("STEM - Summer 2022 Schedule of Classes as of 05-02-22.csv");
    if (!inputFile) {
        std::cerr << "Error opening file. Ensure the file is in the same directory and the name is correct.\n";
        return 1;
    }

    // Initialize schedule
    sched.initSchedule(inputFile);
    inputFile.close();

    // Menu
    int choice;
    do {
        std::cout << "\nMenu:\n"
            << "1. Print schedule\n"
            << "2. Find by subject\n"
            << "3. Find by subject and catalog\n"
            << "4. Find by instructor\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            sched.print();
            break;
        case 2: {
            std::string subject;
            std::cout << "Enter subject: ";
            std::cin >> subject;
            sched.findBySubject(subject);
            break;
        }
        case 3: {
            std::string subject, catalog;
            std::cout << "Enter subject: ";
            std::cin >> subject;
            std::cout << "Enter catalog: ";
            std::cin >> catalog;
            sched.findBySubjectCatalog(subject, catalog);
            break;
        }
        case 4: {
            std::string lastName;
            std::cout << "Enter instructor's last name: ";
            std::cin >> lastName;
            sched.findByInstructor(lastName);
            break;
        }
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
