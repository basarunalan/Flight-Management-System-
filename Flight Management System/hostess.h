#ifndef HOSTESS_H
#define HOSTESS_H
#include <iostream>
#include <fstream>
#include "Employee.h"
#include "Employee.cpp"
using namespace std;
class Hostess  : public Employee{
public:
    Hostess(string _name = "Fatma",string _surname = "Yilmaz",string _id = "0000",string _role = "Cabin Crew",string _age = "25",
    string _gender = "Female",string _experience ="Beginner" ,string _year = "6");
    void setHostess();
    void addHostess();
    void editInfo(int choice);
    void displayInfo();
    ofstream HostessAdd;
    ifstream HostessView;

private:
  
    string id;
    string role;
    string gender;
    string experience;
    string year;
   
    
};

#endif