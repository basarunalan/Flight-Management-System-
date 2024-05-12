#include "Engineer.h"
#include <iostream>
#include <fstream>
#include "Plane.h"
using namespace std;
Engineer::Engineer(string _name, string _surname, string _age, string _PlaneID, string _experience):Employee(_name,_surname,_age)
{
    planeID = _PlaneID;
    experience = _experience;
}

void Engineer::DisplayEngineers()
{
  int counter = 1;
           string line;
            EngineerView.open("EngineerData.txt");
            while(getline(EngineerView , line))
            {
                cout<<"Engineer "<<counter<<" -> "<<line<<endl;
                counter++;
               
            }
            EngineerView.close();
}

void Engineer::addEngineer()
{
    cout << "Enter the engineer name: ";
    cin >> name;
    cout << "Enter the surname: ";
    cin >> surname;
    cout << "Enter the engineer age: ";
    cin >> age;
    planeID = "Null";
    cout << "Enter the engineer experience: ";
    cin >> experience;
    EngineerAdd.open("EngineerData.txt",ios::app);
    EngineerAdd<<endl<<name<<setw(10)<<surname<<setw(5)<<age<<setw(10)<<planeID<<setw(15)<<experience;
    EngineerAdd.close();
}

void Engineer::addBrokenPlane()
{
    
    ofstream tempEngineer("tempEngineer.txt");
    string _name,_surname,_age,_PlaneID, _experience;
    int counter = 1,choiceEngineer;
    string _serialnumber;
    int chooseBroken;
    cout<<"Please choose a plane"<<endl;
    brokenPlane.viewPlane();
    cin>>chooseBroken;
    string Planeline;
brokenPlane.PlaneView.open("PlaneData.txt");
while (getline(brokenPlane.PlaneView, Planeline))
{
    if (chooseBroken == counter) {
    istringstream issPlane(Planeline);
    issPlane>>_serialnumber;
    planeID = _serialnumber;
    }
    counter++;
}
brokenPlane.PlaneView.close();
counter = 1;
 string line;
            EngineerView.open("EngineerData.txt");
            while(getline(EngineerView , line))
            {
                cout<<"Engineer "<<counter<<" -> "<<line<<endl;
                counter++;
               
            }
            EngineerView.close();
            cout<<"Choose a engineer for broken plane"<<endl;
            cin>>choiceEngineer;
            EngineerView.close();
counter = 1;
            string Engineerline;
EngineerView.open("EngineerData.txt");
while (getline(EngineerView, Engineerline))
{
   if(choiceEngineer == counter){
    istringstream issEngineer(Engineerline);
    issEngineer>>_name>>_surname>>_age>>_PlaneID>>_experience;
    _PlaneID = planeID;
    tempEngineer<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_PlaneID<<setw(15)<<_experience<<endl;
   }
   else {
    tempEngineer<<Engineerline<<endl;
   }
    counter++;
}
EngineerView.close();
tempEngineer.close();
            remove("EngineerData.txt");
            rename("tempEngineer.txt","EngineerData.txt");


}

void Engineer::EditBrokenPlane()
{
    ofstream tempEngineer("tempEngineer.txt");
    string _name,_surname,_age,_PlaneID, _experience;
    int counter = 1;
    int choiceEngineer;
    DisplayEngineers();
    cout<<"Please choose an engineer who fixed the plane"<<endl;
    cin>>choiceEngineer;
     string Engineerline;
EngineerView.open("EngineerData.txt");
while (getline(EngineerView, Engineerline))
{
   if(choiceEngineer == counter){
    istringstream issEngineer(Engineerline);
    issEngineer>>_name>>_surname>>_age>>_PlaneID>>_experience;
    _PlaneID = "Null";
    tempEngineer<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_PlaneID<<setw(15)<<_experience<<endl;
   }
   else {
    tempEngineer<<Engineerline<<endl;
   }
    counter++;
}
EngineerView.close();
tempEngineer.close();
            remove("EngineerData.txt");
            rename("tempEngineer.txt","EngineerData.txt");



}
