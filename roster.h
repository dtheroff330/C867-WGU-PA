#pragma once

#include <vector>
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
    int class_Size = 0;
    int search_Index;
public:
    Roster(int class_Size);
    ~Roster();
    void parse(string student_Data);
    void add(string student_ID, string first_Name, string last_Name, string email_Address, int student_Age, int daysC1, int daysC2, int daysC3, DegreeProgram degree_Program);
    void remove(string student_ID);
    void printAll();
    void printAverageDaysInCourse(string student_ID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree_Program);
};