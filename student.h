
#pragma once

#include <string>
#include <iostream>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

// A class that represents each student, Task D1
class Student 
{

private:
    // The variables for student class, Task D1
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // Both empty and full constructors for student, Task D2
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram);

    // Accessor methods for each variable, Task D2
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

    // Mutator functiosn for each variable, Task D2
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    // Print function to print student data, Task D2
    void print();
};
