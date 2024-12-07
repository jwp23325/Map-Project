#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "scheduleItem.h"

class schedule {
private:
    std::map<std::string, scheduleItem> scheduleMap;

public:
    // Initialize the schedule from a file
    void initSchedule(std::ifstream& file) {
        std::string line;

        // Skip the header line
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string subject, catalog, section, component, session, instructor;
            int units, totEnrl, capEnrl;

            // Read fields from the line
            std::getline(ss, subject, ',');
            std::getline(ss, catalog, ',');
            std::getline(ss, section, ',');
            std::getline(ss, component, ',');
            std::getline(ss, session, ',');
            ss >> units;
            ss.ignore(1, ','); // Skip comma
            ss >> totEnrl;
            ss.ignore(1, ','); // Skip comma
            ss >> capEnrl;
            ss.ignore(1, ','); // Skip comma
            std::getline(ss, instructor, ',');

            // Create and add a scheduleItem
            scheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
            addEntry(item);
        }
    }

    // Add an entry to the map
    void addEntry(const scheduleItem& item) {
        scheduleMap[item.getKey()] = item;
    }

    // Print all entries
    void print() const {
        std::cout << "Subject  Catalog  Section  Component  Session  Units  TotEnrl  CapEnrl  Instructor\n";
        for (const auto& [key, item] : scheduleMap) {
            item.print();
        }
    }

    // Find by subject
    void findBySubject(const std::string& subject) const {
        for (const auto& [key, item] : scheduleMap) {
            if (item.getSubject() == subject) {
                item.print();
            }
        }
    }

    // Find by subject and catalog
    void findBySubjectCatalog(const std::string& subject, const std::string& catalog) const {
        for (const auto& [key, item] : scheduleMap) {
            if (item.getSubject() == subject && item.getCatalog() == catalog) {
                item.print();
            }
        }
    }

    // Find by instructor's last name
    void findByInstructor(const std::string& lastName) const {
        for (const auto& [key, item] : scheduleMap) {
            if (item.getInstructor().find(lastName) != std::string::npos) {
                item.print();
            }
        }
    }
};
