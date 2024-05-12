#include "Employee.h"
#include <iostream>
using namespace std;
Employee::Employee(string _name, string _surname, string _age)
{
    setName(_name);
    setSurname(_surname);
    setAge(_age);
}

Employee::~Employee()
{
    cout<<"Your employee objects are deleted"<<endl;
}

void Employee::setName(string _name)
{
    name = _name;
}

void Employee::setSurname(string _surname)
{
    surname = _surname;
}

void Employee::setAge(string _age)
{
    age = _age;
}

string Employee::getName()
{
    return name;
}

string Employee::getSurname()
{
    return surname;
}

string Employee::getAge()
{
    return age;
}
