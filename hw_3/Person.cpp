#include "Person.h"
#include <sstream>
using namespace std;

Person::Person()
{
    Fname = "";
    Lname = "";
    birthDay = 1;
    birthMonth = 1;
    birthYear = 1;
}

Person::Person(string first, string last, int day, int month, int year){
    Fname = first;
    Lname = last;
    birthDay = day;
    birthMonth = month;
    birthYear = year;
}

string Person::getName(){
    return Fname + " " + Lname;
}

string Person::getBirthdate(){
    ostringstream bday;
    bday << birthDay << "/" << birthMonth << "/" << birthYear;
    return bday.str();
}
