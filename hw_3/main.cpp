/*
    Nolan Hughes
    HW3
    Due 3/24/2025
*/

#include <iostream>
#include <string>
#include "Person.h"
#include "Polygon.h"

using namespace std;

class Student : public Person
{
    public:
        Student();
        Student(std::string first, std::string last, int day, int month, int year);

        int getCreditHours();
        void addCreditHours(int val);

    protected:
        int creditHours;
};

Student::Student() : Person()
{
}

Student::Student(std::string first, std::string last, int day, int month, int year) : Person(first, last, day, month, year)
{
    creditHours = 0;
}

int Student::getCreditHours()
{
    return this->creditHours;
}

void Student::addCreditHours(int hours)
{
    this->creditHours += hours;
}

class GradStudent : public Student
{
    public:
        GradStudent();
        GradStudent(std::string first, std::string last, int day, int month, int year, int requiredCreditHours);

        int getRequiredCreditHours();
        void setRequiredCreditHours(int hours);

        bool canGraduate();

    private:
        int requiredCreditHours;
};

GradStudent::GradStudent() : Student()
{
    this->requiredCreditHours = 20;
}

GradStudent::GradStudent(std::string first, std::string last, int day, int month, int year, int requiredCreditHours) : Student(first, last, day, month, year)
{
    this->requiredCreditHours = requiredCreditHours;
}

int GradStudent::getRequiredCreditHours()
{
    return this->requiredCreditHours;
}

void GradStudent::setRequiredCreditHours(int hours)
{
    this->requiredCreditHours = hours;
}

bool GradStudent::canGraduate()
{
    return this->creditHours >= this->requiredCreditHours;
}

class Rectangle : public Polygon
{
    public:
        Rectangle();
        Rectangle(int width, int height);

        int getArea();
        void draw();
};

Rectangle::Rectangle() : Polygon()
{
}

Rectangle::Rectangle(int width, int height) : Polygon(width, height)
{
}

int Rectangle::getArea()
{
    return this->width * this->height;
}

void Rectangle::draw()
{
    for (int y = 0; y < this->height; ++y)
    {
        for (int x = 0; x < this->width; ++x)
        {
            cout << "*";
        }

        cout << "\n";
    }
}

class Triangle : public Polygon
{
    public:
        Triangle();
        Triangle(int width, int height);

        int getArea();
        void draw();
};

Triangle::Triangle() : Polygon()
{
}

Triangle::Triangle(int width, int height) : Polygon(width, height)
{
}

int Triangle::getArea()
{
    return width * height / 2;
}

void Triangle::draw()
{
    for (int y = 0; y < this->height; ++y)
    {
        for (int i = 0; i < this->height - y - 1; ++i)
        {
            cout << " ";
        }

        for (int i = 0; i <= y * 2; ++i)
        {
            cout << "*";
        }

        cout << "\n";
    }
}

int main()
{
    Person p1("Tony", "Stark", 1, 21, 1950);
    cout << p1.getName() << " born on: " << p1.getBirthdate() << endl;

    GradStudent gradStudent("Nolan", "Hughes", 6, 9, 2005, 30);
    gradStudent.addCreditHours(4);
    gradStudent.addCreditHours(3);
    
    cout << gradStudent.getName() << " has " << gradStudent.getCreditHours() << "/" << gradStudent.getRequiredCreditHours() << " credits\n";

    if (gradStudent.canGraduate())
    {
        cout << gradStudent.getName() << "can graduate\n";
    }
    else
    {
        cout << gradStudent.getName() << " can not graduate yet\n";
    }

    cout << "\n";

    Rectangle rectangle(4, 2);
    rectangle.draw();
    cout << "Area: " << rectangle.getArea() << "\n\n";

    rectangle.setWidth(8);
    rectangle.setHeight(4);
    rectangle.draw();
    cout << "New area: " << rectangle.getArea() << "\n\n";

    Triangle triangle(5, 3);
    triangle.draw();
    cout << "Area: " << triangle.getArea() << "\n\n";

    triangle.setWidth(10);
    triangle.setHeight(6);
    triangle.draw();
    cout << "New area: " << triangle.getArea() << "\n\n";

    /*
    
    Question 1:

    Polygon polygon(3, 3);

    The above line causes a compilation failure due to declaration of an abstract type.
    The Polygon class is abstract because it contains a pure virtual function.
    

    Question 2:

    Even after removing the pure virtual functions in the Polygon class, a compilation error still occurs.
    This is because the functions are still not defined in the Polygon class.
    The error mentions an undefined reference to vtable for Polygon.

    */

    return 0;
}
