#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


Student::Student()
{

    this->student_ID = "";
    this->first_Name = "";
    this->last_Name = "";
    this->email_Address = "";
    this->student_Age = 0;
    this->days_Completion[0] = 0;
    this->days_Completion[1] = 0;
    this->days_Completion[2] = 0;
    this->degree_Program = SOFTWARE;

}
Student::Student(string student_ID, string first_Name, string last_Name, string email_Address, int student_Age, int days_Completion[], DegreeProgram degree_Program)
{

	this->student_ID = student_ID;
	this->first_Name = first_Name;
	this->last_Name = last_Name;
	this->email_Address = email_Address;
	this->student_Age = student_Age;
	this->days_Completion[0] = days_Completion[0];
	this->days_Completion[1] = days_Completion[1];
	this->days_Completion[2] = days_Completion[2];
	this->degree_Program = degree_Program;
    
}



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

void Student::setStudentID(string student_ID) 
{ 
    this->student_ID = student_ID; 
}
void Student::setFirstName(string first_Name) 
{ 
    this->first_Name = first_Name; 
}
void Student::setLastName(string last_Name) 
{ 
    this->last_Name = last_Name; 
}
void Student::setEmailAddress(string email_Address)
{ 
    this->email_Address = email_Address; 
}
void Student::setAge(int student_Age)
{ 
    this->student_Age = student_Age; 
}
void Student::setDaysCompletion(int daysC1, int daysC2, int daysC3)
{
    days_Completion[0] = daysC1;
    days_Completion[1] = daysC2;
    days_Completion[2] = daysC3;
}
void Student::setDegreeProgram(DegreeProgram degree_Program) 
{ 
    this->degree_Program = degree_Program; 
}

void Student::print()
{
        cout << "ID: " << student_ID << "  "
             << "First Name: " << first_Name << "  "
             << "Last Name: " << last_Name << "  "
             << "Email: " << email_Address << "  "
             << "Age: " << student_Age << "  "
             << "Days in Course: {" << days_Completion[0] << ", "
             << days_Completion[1] << ", " << days_Completion[2] << "}  "
             << "Degree Program: " << degreeProgramStrings[degree_Program]
             << endl;
}