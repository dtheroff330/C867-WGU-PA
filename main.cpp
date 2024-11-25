#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Course Title: C867 - Scripting and Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 011949764" << endl;
    cout << "Student Name: Daniel Theroff" << endl << endl;

    const string studentData[] =
        {
            "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Daniel,Theroff,dtherof@wgu.edu,22,40,50,70,SOFTWARE"
        };

    Roster *classRoster = new Roster(5);
    for (int i = 0; i < 5; i++)
    {
        classRoster->parse(studentData[i]);
    };

    classRoster->printAll();

    classRoster->printInvalidEmails();

    string studentIds[] = {"A1", "A2", "A3", "A4", "A5"};
    int numStudents = sizeof(studentIds) / sizeof(studentIds[0]);

    for (int i = 0; i < numStudents; i++)
    {
        classRoster->printAverageDaysInCourse(studentIds[i]);
    }

    classRoster->printByDegreeProgram(SOFTWARE);

    classRoster->remove("A3");

    classRoster->printAll();

    classRoster->remove("A3");

    delete classRoster;

    return 0;
}