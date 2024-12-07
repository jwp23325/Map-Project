#pragma once
#include <string>
#include <iostream>

class scheduleItem {
private:
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totEnrl;
    int capEnrl;
    std::string instructor;

public:
    // Constructor with default parameters
    scheduleItem(std::string subj = "", std::string cat = "", std::string sec = "",
        std::string comp = "", std::string sess = "", int u = 0,
        int tot = 0, int cap = 0, std::string instr = "")
        : subject(subj), catalog(cat), section(sec), component(comp), session(sess),
        units(u), totEnrl(tot), capEnrl(cap), instructor(instr) {}

    // Getters
    std::string getSubject() const { return subject; }
    std::string getCatalog() const { return catalog; }
    std::string getSection() const { return section; }
    std::string getComponent() const { return component; }
    std::string getSession() const { return session; }
    int getUnits() const { return units; }
    int getTotEnrl() const { return totEnrl; }
    int getCapEnrl() const { return capEnrl; }
    std::string getInstructor() const { return instructor; }

    // Key generator
    std::string getKey() const {
        return subject + "_" + catalog + "_" + section;
    }

    // Overloaded operators
    bool operator==(const scheduleItem& other) const {
        return getKey() == other.getKey();
    }
    bool operator!=(const scheduleItem& other) const {
        return getKey() != other.getKey();
    }
    bool operator>=(const scheduleItem& other) const {
        return getKey() >= other.getKey();
    }

    // Print function
    void print() const {
        std::cout << subject << "  " << catalog << "  " << section << "  "
            << component << "  " << session << "  " << units << "  "
            << totEnrl << "  " << capEnrl << "  " << instructor << "\n";
    }
};
