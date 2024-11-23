#include "student.h"
#include "degree.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/*
Student::Student()
{
    //add paramters for default constructor
}
Student::Student()
{
    //add paramters for full constructor
}

*/

string Student::getStudentID()
{
    return student_ID;
}
string Student::getFirstName()
{
    return first_Name;
}
string Student::getLastName()
{
    return last_Name;
}
string Student::getEmailAddress()
{
    return email_Address;
}
int Student::getStudentAge()
{
    return student_Age;
}
int* Student::getDaysCompletion()
{
    return days_Completion;
}
DegreeProgram Student::getDegreeProgram()
{
    return degree_Program;
}