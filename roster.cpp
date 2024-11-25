#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::endl;
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
        if (classRosterArray[i] != nullptr)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
        i++;
    }
}

// Task E2
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
        cout << "Not a valid Degree Program" << endl;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// Task E3
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    if (searchIndex < 5)
    {
        int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
        classRosterArray[searchIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
        searchIndex++;
    }
    else
    {
        cout << "Error: Cannot add more students. Roster is full." << endl;
    }
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

    cout << "Student " << studentID << (isStudent ? " removed." : " Not Found.") << endl << endl;
}

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

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID)
        {
            int *daysInCourse = classRosterArray[i]->getDaysInCourse();
            cout << "Average days in course for " << studentID << ": "
                 << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3 << endl;

            return;
        }
    }
    cout << "Error: Student with ID " << studentID << " not found." << endl << endl;
}

void Roster::printInvalidEmails()
{
    cout << "Showing students with invalid email addresses:" << endl;
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            string eAddress = classRosterArray[i]->getEmailAddress();
            if (eAddress.find(' ') != string::npos || eAddress.find('@') == string::npos || eAddress.find('.') == string::npos)
            {
                cout << eAddress << " (is Invalid)" << endl;
            }
        }
    }
}
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

string Roster::searchStudentID(int searchIndex)
{
    return classRosterArray[searchIndex]->getStudentID();
}