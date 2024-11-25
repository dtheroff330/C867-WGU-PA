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
    //public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
}

void Roster::printAll()
{
    //public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
}

void printAverageDaysinCourse(string studentID)
{
    //public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
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


