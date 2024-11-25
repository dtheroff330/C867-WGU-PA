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


