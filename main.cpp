
#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"

// Uses std namespace for specific things to avoid repetitive typing
using std::cout;
using std::endl;
using std::string;

//Main function for rubric's task F
int main()
{
    cout << endl;
    cout << "Course Title: C867 - Scripting and Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 011949764" << endl;
    cout << "Student Name: Daniel Theroff" << endl << endl;

    // Student Data edited to include personal Data on A5, Task A
    const string studentData[] =
        {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Daniel,Theroff,dtherof@wgu.edu,22,40,50,70,SOFTWARE"
        };

    // Creates a new roster and parses the above student data, Task F2/F3
    Roster *classRoster = new Roster(5);
    for (int i = 0; i < 5; ++i)
    {
        string currentData = studentData[i];
        classRoster->parse(currentData);
    }

    // Calls printAll function, Task F4
    classRoster->printAll();

    // Calls printInvalidEmails function, Task F4
    classRoster->printInvalidEmails();

    // Calls searchStudentID in order to grab student ID's for printAverageDaysInCourse function, Task F4
    for (int i = 0; i < 5; ++i)
    {
        string studentID = classRoster->searchStudentID(i);
        classRoster->printAverageDaysInCourse(studentID);
    }

    // Calls printByDegreeProgram function, specifically to print students in the software program, Task F4
    classRoster->printByDegreeProgram(SOFTWARE);

    // Calls remove function to remove A3 (Jack Napoli), then calls printAll function to reprint the table, Task F4
    classRoster->remove("A3");
    classRoster->printAll();

    // Calls remove function again on the same student, which leads to an intended error message of not finding the student
    classRoster->remove("A3");

    // Uses destructor to clean up memory
    delete classRoster;

    return 0;
}
