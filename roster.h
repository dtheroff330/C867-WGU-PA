#pragma once

#include <array>
#include <iostream>
#include "student.h"
#include "degree.h"

using std::cout;
using std::endl;
using std::string;

class Roster
{
private:
    Student* classRosterArray[5];
    int classSize = 0;
    int searchIndex;
public:
    Roster(int classSize);
    ~Roster();
    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};