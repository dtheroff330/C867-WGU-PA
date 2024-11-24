#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <array>

using std::endl;
using std::cout;
using std::string;


Roster::Roster(int class_Size)
{
    this->class_Size = class_Size;
    for (int i = 0; i < class_Size; i++)
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

void Roster::parse(string student_Data)
{
    int start = 0;
    int end = student_Data.find(',');

    string student_ID = student_Data.substr(start, end - start);

    start = end + 1;
    end = student_Data.find(',', start);
    string first_Name = student_Data.substr(start, end - start);

    start = end + 1;
    end = student_Data.find(',', start);
    string last_Name = student_Data.substr(start, end - start);

    start = end + 1;
    end = student_Data.find(',', start);
    string email_Address = student_Data.substr(start, end - start);

    start = end + 1;
    end = student_Data.find(',', start);
    int student_Age = std::stoi(student_Data.substr(start, end - start));

    start = end + 1;
    end = student_Data.find(',', start);
    int daysC1 = std::stoi(student_Data.substr(start, end - start));

    start = end + 1;
    end = student_Data.find(',', start);
    int daysC2 = std::stoi(student_Data.substr(start, end - start));

    start = end + 1;
    end = student_Data.find(',', start);
    int daysC3 = std::stoi(student_Data.substr(start, end - start));

    start = end + 1;
    std::string degree_program_str = student_Data.substr(start);

    DegreeProgram degree_Program;
    string degree_Program_String;
    if (degree_Program_String == "SECURITY") {
        degree_Program = DegreeProgram::SECURITY;
    } else if (degree_Program_String == "NETWORK") {
        degree_Program = DegreeProgram::NETWORK;
    } else if (degree_Program_String == "SOFTWARE") {
        degree_Program = DegreeProgram::SOFTWARE;
    } else {
        cout << "Not a valid Degree Program" << endl;
    }

    add(student_ID, first_Name, last_Name, email_Address, student_Age, daysC1, daysC2, daysC3, degree_Program);
}

