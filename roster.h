
#pragma once

#include <array>
#include <iostream>
#include "student.h"
#include "degree.h"

using std::cout;
using std::endl;
using std::string;

// Task E's Roster class
class Roster
{
private:
    // Array that holds the data shown in the student data table from main.cpp, Task E1
    Student* classRosterArray[5] = {}; //Set to 5 by default, but could be edited if you wanted to have more than the default 5 students on a roster
    int classSize = 0;  
    int searchIndex = 0;

public:
    // Both constructor and destructor for roster class
    Roster(int classSize);
    ~Roster();
    
    // Function declaration for parse, Task E2
    void parse(string studentData);

    // Adds a student to the roster, Task E2
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Removes a student from the created roster, Task E2
    void remove(string studentID);

    // Prints out all students from the created roster, Task E2
    void printAll();

    // Prints average days in 3 courses for an individual student, Task E2
    void printAverageDaysInCourse(string studentID = "");

    // Prints students with emails that don't follow good conventions, Task E2
    void printInvalidEmails();

    // Prints students dependent on the chosen degree program, Task E2
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
