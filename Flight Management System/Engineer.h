#ifndef ENGINEER_H
#define ENGINEER_H
#include <iostream>
using namespace std;
#include"Employee.h"
#include <fstream>
#include "Plane.h"
class Engineer : public Employee{
    public:
    Engineer(string _name = "Ahmet",string _surname = "Ak",string _age = "30",string _PlaneID = "Null",string _experience = "Seniour");
    void DisplayEngineers();
    void addEngineer();
    void addBrokenPlane();
    void EditBrokenPlane();
    ofstream EngineerAdd;
    ifstream EngineerView;
    private:
    string experience;
    string planeID;
    Plane brokenPlane;
    string checkBroken;


};


#endif