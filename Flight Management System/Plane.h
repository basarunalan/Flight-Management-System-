#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <fstream>
using namespace std;
class Plane{
 public:
 void setPlane();
 void addPlane();
 void editPlane(int choice);
 void viewPlane();
 ofstream PlaneAdd;
 ifstream PlaneView;
 private:
 string serialnumber;
 string capacity;
 string location;
 string baseInfo;
 string type;
 string cargoWeight;
 int choice;
 
};
#endif