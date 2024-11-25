#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <array>

using std::endl;
using std::cout;
using std::string;


Roster::Roster(int classSize)
{
    this->classSize = classSize;
    for (int i = 0; i < classSize; i++)
    {
        this->classRosterArray[i] = new Student;
    }
}

Roster::~Roster()
{
    int i = 0;
    while (i < 5) 
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        i++;
    }
}

void Roster::parse(string studentData)
{
    int start = 0;
    int end = studentData.find(',');

    string studentID = studentData.substr(start, end - start);

    start = end + 1;
    end = studentData.find(',', start);
    string firstName = studentData.substr(start, end - start);

    start = end + 1;
    end = studentData.find(',', start);
    string lastName = studentData.substr(start, end - start);

    start = end + 1;
    end = studentData.find(',', start);
    string emailAddress = studentData.substr(start, end - start);

    start = end + 1;
    end = studentData.find(',', start);
    int age = std::stoi(studentData.substr(start, end - start));

    start = end + 1;
    end = studentData.find(',', start);
    int daysInCourse1 = std::stoi(studentData.substr(start, end - start));

    start = end + 1;
    end = studentData.find(',', start);
    int daysInCourse2 = std::stoi(studentData.substr(start, end - start));

    start = end + 1;
    end = studentData.find(',', start);
    int daysInCourse3 = std::stoi(studentData.substr(start, end - start));

    start = end + 1;
    string degreeProgramString = studentData.substr(start);

    DegreeProgram degreeProgram;
    string degreeProgramString;
    if (degreeProgramString == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    } else if (degreeProgramString == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    } else if (degreeProgramString == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    } else {
        cout << "Not a valid Degree Program" << endl;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    classRosterArray[classSize] = new Student(studentID, firstName, lastName, emailAddress, age, (int[3]){daysInCourse1, daysInCourse2, daysInCourse3}, degreeProgram);
}

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

    cout << "Student " << studentID << (isStudent ? " removed." : " Not Found.") << endl;
}

void Roster::printAll()
{
    cout << "Displaying all students:" << endl;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID)
        {
            int* daysInCourse = classRosterArray[i]->getDaysInCourse();
            cout << "Average days in course for " << studentID << ": "
                      << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3 << endl;

            return;
        }
    }
    cout << "Error: Student with ID " << studentID << " not found." << endl;
}

void printInvalidEmails()
{
    //public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
 

    //Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
}

void printByDegreeProgram(DegreeProgram degreeProgram)
{
    //public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
}


