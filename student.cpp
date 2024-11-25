#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

//Task D1 and D2
Student::Student() 
{
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
    degreeProgram = SOFTWARE;

    for (int i = 0; i < 3; ++i) {
        daysInCourse[i] = 0;
    }
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->degreeProgram = degreeProgram;

    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}



string Student::getStudentID()
{
    return studentID;
}
string Student::getFirstName()
{
    return firstName;
}
string Student::getLastName()
{
    return lastName;
}
string Student::getEmailAddress()
{
    return emailAddress;
}
int Student::getStudentAge()
{
    return age;
}
int* Student::getDaysInCourse()
{
    return daysInCourse;
}
DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

void Student::setStudentID(string studentID) 
{ 
    this->studentID = studentID; 
}
void Student::setFirstName(string firstName) 
{ 
    this->firstName = firstName; 
}
void Student::setLastName(string lastName) 
{ 
    this->lastName = lastName; 
}
void Student::setEmailAddress(string emailAddress)
{ 
    this->emailAddress = emailAddress; 
}
void Student::setAge(int age)
{ 
    this->age = age; 
}
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) 
{ 
    this->degreeProgram = degreeProgram; 
}

void Student::print()
{
    cout << "ID: " << studentID << "  " << "First Name: " << firstName << "  " << "Last Name: " << lastName << "  "
            << "Email: " << emailAddress << "  " << "Age: " << age << "  "
            << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}  "
            << "Degree Program: " << degreeProgramStrings[degreeProgram]
            << endl;
}