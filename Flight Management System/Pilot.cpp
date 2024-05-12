#include <iostream>
using namespace std;
#include "Pilot.h"
#include <iomanip>
#include <fstream>
#include <sstream>
int counterPilot = 0;
Pilot::Pilot(string _name, string _surname, string _age, string _location, string _baseInfo, string _type):Employee(_name,_surname,_age)
{
    location = _location;
    baseInfo = _baseInfo;
    type = _type;
}
void Pilot::setPilot()
{
    cout<<"Enter the pilot name"<<endl;
	cin>>name;
	cout<<"Enter the surname"<<endl;
	cin>>surname;
	cout<<"Enter pilot age"<<endl;
	cin>>age;
	cout<<"Enter pilot current location"<<endl;
	cin.ignore();
	getline(cin,location);
	cout<<"Enter base information about pilot"<<endl;
	getline(cin,baseInfo);
    cout<<"Enter the type of pilot "<<endl;
    cin>>type;
    addPilot();
}
void Pilot::addPilot()
{
    counterPilot++;
    PilotAdd.open("PilotData.txt",ios::app);
    PilotAdd<<endl<<name<<setw(10)<<surname<<setw(5)<<age<<setw(10)<<location<<setw(10)<<baseInfo<<setw(14)<<type;
    PilotAdd.close(); 

}

void Pilot::editPilot(int choice)
{
    string _name, _surname,_age, _location, _baseInfo, _type;
    int choiceEdit;
    string newValue;
    ofstream tempPilot("TempPilot.txt");
    string line;
            Pilotview.open("PilotData.txt");
            while(getline(Pilotview , line))
            {
                counterPilot++;
            }
            Pilotview.close();
     do{
        if(choice < 1 || choice > counterPilot){
        cout<<"There is no pilot for your choice , please enter again"<<endl;
        viewPilot();
        cin>>choice;
    }
    }while(choice < 1 || choice > counterPilot);
        int currentData = 1;
            string Pilotline;
            Pilotview.open("PilotData.txt");
            while(getline(Pilotview , Pilotline))
            {
                if (currentData == choice) {
                istringstream issPilot(Pilotline);
                issPilot>>_name>>_surname>>_age>>_location>>_baseInfo>>_type;
                cout<<Pilotline<<endl;
                cout << "Choose one of them which you want to edit" << endl;
                cin >> choiceEdit;
                cout << "Please enter the new information" << endl;
                cin.ignore();
                getline(cin,newValue);
                switch (choiceEdit){
                    case 1:{
                        _name = newValue;
                    tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(10)<<_type<<endl;
                        break;
                    }
                    case 2:{
                        _surname = newValue;
                        tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(10)<<_type<<endl;
                        break;
                    }
                    case 3:{
                         _age = newValue;
                        tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(10)<<_type<<endl;
                        break;
                    }
                    case 4:{
                         _location = newValue;
                        tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(10)<<_type<<endl;
                        break;
                    }
                    case 5:{
                         _baseInfo = newValue;
                        tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(10)<<_type<<endl;
                        break;
                    }
                    case 6:{
                         _type = newValue;
                       tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(10)<<_type<<endl;
                        break;
                    }
                    
                }
            }
             else{
                    tempPilot<<Pilotline<<endl;
                }
            currentData++;
            }
            Pilotview.close();
            tempPilot.close();
            remove("PilotData.txt");
            rename("TempPilot.txt","PilotData.txt");

        cout<<"Succesfully"<<endl;
}

void Pilot::viewPilot()
{
    int counter = 1;
           string Pilotline;
            Pilotview.open("PilotData.txt");
            while(getline(Pilotview , Pilotline))
            {
                cout<<"Pilot "<<counter<<" -> "<<Pilotline<<endl;
                counter++;
               
            }
            Pilotview.close();
        
}


