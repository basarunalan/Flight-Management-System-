#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee {
public:
    explicit Employee(string _name, string _surname,string _age);
    ~Employee();
    void setName(string _name);
    void setSurname(string _surname);
    void setAge(string _age);
    string getName();
    string getSurname();
    string getAge();
    protected:
    string name;
    string surname;
    string age;
};

#endif