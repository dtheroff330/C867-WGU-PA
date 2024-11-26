
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <array>
#include <sstream>

// Uses std namespace for specific things to avoid repetitive typing
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::stringstream;
using std::getline;

// Full constructor for roster class
Roster::Roster(int classSize)
{
    this->classSize = classSize;
    for (int i = 0; i < classSize; i++)
    {
        this->classRosterArray[i] = new Student;
    }
}

// Full destructor for the roster class
Roster::~Roster()
{
    int i = 0;
    while (i < 5)
    {
        if (classRosterArray[i] != nullptr)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
        i++;
    }
}

/* 
Uses stringstream to avoid extremely repetitive calls to .find and .substr
Prior method of using an index was difficult to read due to length
*/

// Function definition for parse function, Task E2
void Roster::parse(string studentData)
{

    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    string degreeProgramString;

    int age;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;


    stringstream ss(studentData);

    getline(ss, studentID, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');  
    getline(ss, emailAddress, ',');


    string tempString;
    getline(ss, tempString, ',');
    age = stoi(tempString);

    getline(ss, tempString, ',');
    daysInCourse1 = stoi(tempString);

    getline(ss, tempString, ',');
    daysInCourse2 = stoi(tempString);

    getline(ss, tempString, ',');
    daysInCourse3 = stoi(tempString);


    getline(ss, degreeProgramString); 
    DegreeProgram degreeProgram;
    if (degreeProgramString == "SECURITY")
    {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (degreeProgramString == "NETWORK")
    {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (degreeProgramString == "SOFTWARE")
    {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    else
    {
        cout << "Not a valid Degree Program: " << degreeProgramString << endl;
        return;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}


// Adds a student to the roster, Task E2
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    if (searchIndex < 5) // Array size as per given student data
    {
        int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
        classRosterArray[searchIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
        searchIndex++;
    }
    // Array size would need to manually be edited in roster.h to avoid this limit, as well as the search index above
    else
    {
        cout << "Roster is full. Cannot add more students at this time." << endl;
    }
}

// Removes a student from the created roster, Task E2
void Roster::remove(string studentID)
{
    bool isStudent = false;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr && studentID == classRosterArray[i]->getStudentID())
        {
            classRosterArray[i] = nullptr;
            isStudent = true;
            break;
        }
    }

    cout << "Student " << studentID << (isStudent ? " removed." : " Not Found.") << endl << endl;
}

// Prints out all students from the created roster, Task E2
void Roster::printAll()
{
    cout << "Showing all students:" << endl;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

// Prints average days in 3 courses for an individual student, Task E2
void Roster::printAverageDaysInCourse(string studentID)
{
    if (studentID.empty())
    {
        cout << "Average days in course for all students:" << endl;
        for (int i = 0; i < classSize; i++)
        {
            if (classRosterArray[i] != nullptr)
            {
                string studentID = classRosterArray[i]->getStudentID();
                int *daysInCourse = classRosterArray[i]->getDaysInCourse();
                int averageTime = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
                cout << "ID: " << studentID << ", Average Days for Student: " << averageTime << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < classSize; i++)
        {
            if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID)
            {
                int *daysInCourse = classRosterArray[i]->getDaysInCourse();
                int averageTime = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
                cout << "ID: " << studentID << ", Average Days for Student: " << averageTime << endl;
                return;
            }
        }
        cout << studentID << " could not be located in roster." << endl;
    }
}

// Prints students with emails that don't follow good conventions, Task E2
void Roster::printInvalidEmails()
{
    cout << "Showing students with invalid email addresses:" << endl << endl;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            string eAddress = classRosterArray[i]->getEmailAddress();
            if (eAddress.find(' ') != string::npos || eAddress.find('@') == string::npos || eAddress.find('.') == string::npos)
            {
                cout << eAddress << " is invalid!" << endl << endl;
            }
        }
    }
}

// Prints students dependent on the chosen degree program, Task E2
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    cout << endl;
    cout << "Students in the " << degreeProgramStrings[degreeProgram] << " program:" << endl;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

