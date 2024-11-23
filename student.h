#pragma once

#include <string>
#include <iostream>
#include "degree.h"

using std::string;


class Student {
private:
    string student_ID;
    string first_Name;
    string last_Name;
    string email_Address;

    int student_Age;
    int days_Completion[3];

    DegreeProgram degree_Program;
public:
    Student();
    Student(string student_ID, string first_Name, string last_Name, string email_Address, int student_Age, int days_Completion[3], DegreeProgram degree_Program);
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge();
    int getCourseCompletionDays();
    DegreeProgram getDegreeProgram();
    void setStudentID(string student_ID);
    void setFirstName(string first_Name);
    void setLastName(string last_Name);
    void setEmailAddress(string email_Address);
    void setAge(int student_Age);
    void setCourseCompletionDays(int days1, int days2, int days3);
    void setDegreeProgram(DegreeProgram degree_Program);
    void print();

};