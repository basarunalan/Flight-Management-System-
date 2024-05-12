#include "Plane.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int counterPlane = 0;
void Plane::setPlane()
{
    cout << "Enter the serial number" << endl;
    cin >> serialnumber;
    do{
        if(serialnumber.size() < 6 || serialnumber.size() > 6){
        cout << "Serial number must be 6 characters" << endl;
    cin >> serialnumber;
    }
    }while(serialnumber.size() < 6 || serialnumber.size() > 6);
    cout << "Enter the passenger capacity" << endl;
    cin >> capacity;
    cout << "Enter plane current location" << endl;
    cin.ignore();
    getline(cin, location);
    cout << "Enter base information about plane" << endl;
    getline(cin, baseInfo);
    cout << "Enter plane flight type" << endl;
    cin >>type;
    cout<<"Enter the capacity of cargo weight"<<endl;
    cin>>cargoWeight;
    addPlane();
}

void Plane::addPlane()
{
    PlaneAdd.open("PlaneData.txt",ios::app);
    PlaneAdd<<endl<<serialnumber<<setw(7)<<capacity<<setw(10)<<location<<setw(10)<<baseInfo<<setw(15)<<type<<setw(7)<<cargoWeight;
    PlaneAdd.close();
    counterPlane++;
}

void Plane::editPlane(int choice)
{
    string _serialnumber, _capacity, _location, _baseInfo, _type, _cargoWeight;
    int choiceEdit;
    string newValue;
    ofstream tempPlane("TempPlane.txt");
     string line;
            PlaneView.open("PlaneData.txt");
            while(getline(PlaneView , line))
            {
                counterPlane++;
            }
            PlaneView.close();
    do{
        if(choice < 1 || choice > counterPlane){
        cout<<"There is no plane for your choice , please enter again"<<endl;
        viewPlane();
        cin>>choice;
    }
    }while(choice < 1 || choice > counterPlane);
    int currentData = 1;
            string Planeline;
            PlaneView.open("PlaneData.txt");
            while(getline(PlaneView , Planeline))
            {
                if (currentData == choice) {
                istringstream issPlane(Planeline);
                issPlane>>_serialnumber>>_capacity>>_location>>_baseInfo>>_type>>_cargoWeight;
                cout<<Planeline<<endl;
                cout << "Choose one of them which you want to edit" << endl;
                cin >> choiceEdit;
                cout << "Please enter the new information" << endl;
                cin.ignore();
                getline(cin,newValue);
                switch (choiceEdit){
                    case 1:{
                        _serialnumber = newValue;
                    tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_cargoWeight;
                        break;
                    }
                    case 2:{
                        _capacity = newValue;
                        tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_cargoWeight;
                        break;
                    }
                    case 3:{
                         _location = newValue;
                        tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_cargoWeight;
                        break;
                    }
                    case 4:{
                         _baseInfo = newValue;
                        tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_cargoWeight;
                        break;
                    }
                    case 5:{
                         _type = newValue;
                        tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_cargoWeight;
                        break;
                    }
                    case 6:{
                         _cargoWeight = newValue;
                        tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_cargoWeight;
                        break;
                    }
                    
                }
            }
             else{
                    tempPlane<<Planeline<<endl;
                }
            currentData++;
            }
            PlaneView.close();
            tempPlane.close();
            remove("PlaneData.txt");
            rename("TempPlane.txt","PlaneData.txt");

            cout << "Succesfully" << endl;
}

void Plane::viewPlane()
{
    int counter = 1;
           string line;
            PlaneView.open("PlaneData.txt");
            while(getline(PlaneView , line))
            {
                cout<<"Plane "<<counter<<" -> "<<line<<endl;
                counter++;
               
            }
            PlaneView.close();
}
