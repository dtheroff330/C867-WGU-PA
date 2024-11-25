#pragma once

#include <string>
#include <iostream>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

//Task D1 and D2
class Student 
{

private:

    string studentID;
    string firstName;
    string lastName;
    string emailAddress;

    int age;
    int daysInCourse[3];

    DegreeProgram degreeProgram;

public:

    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram);
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);
    void print();

};