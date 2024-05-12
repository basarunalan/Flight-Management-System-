#ifndef PILOT_H
#define PILOT_H
#include <iostream>
#include <fstream>
#include"Employee.h"
using namespace std;
class Pilot : Employee {
    public:
    explicit Pilot(string _name = "Alp",string _surname = "Sultan",string _age = "22",string _location = "Istanbul",string _baseInfo = "Istanbul",string _type = "Domestic");
    void setPilot();
    void addPilot();
    void editPilot(int choice);
    void viewPilot();
    ofstream PilotAdd;
    ifstream Pilotview;
    private:
    string location;
    string baseInfo;
    string type;
    int choice;
   
};



#endif