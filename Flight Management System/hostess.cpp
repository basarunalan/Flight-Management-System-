#include <iostream>
#include "Hostess.h"
#include <fstream>
#include <iomanip>
using namespace std;
int counterHostess = 0;

Hostess::Hostess(string _name, string _surname, string _id, string _role, string _age, string _gender, string _experience, string _year):Employee(_name,_surname,_age)
{
    id = _id;
    role = _role;
    gender = _gender;
    experience = _experience;
    year = _year;
}
void Hostess::setHostess() {
    cout << "Enter the hostess name: ";
    cin >> name;
    cout << "Enter the surname: ";
    cin >> surname;
    cout << "Enter the hostess ID: ";
    cin >> id;
    cout << "Enter the hostess role: ";
    cin.ignore();
    getline(cin,role);
    cout << "Enter the hostess age: ";
    cin >> age;
    cout << "Enter the hostess gender: ";
    cin >> gender;
    cout << "Enter the hostess experience: ";
    cin >> experience;
    cout << "Enter the hostess joining year: ";
    cin >> year;

    addHostess();
}
void Hostess::addHostess() {
    HostessAdd.open("HostessData.txt",ios::app);
    HostessAdd<<endl<<name<<setw(10)<<surname<<setw(5)<<id<<setw(12)<<role<<setw(5)<<age<<setw(10)<<gender<<setw(10)<<experience<<setw(5)<<year;
    HostessAdd.close();
}

void Hostess::editInfo(int choice) {
    int choiceEdit;
    string _name, _surname, _id, _role, _age, _gender, _experience, _year;
    string newValue;
    ofstream tempHostess("tempHostess.txt");
           string line;
            HostessView.open("HostessData.txt");
            while(getline(HostessView , line))
            {
                counterHostess++;
            }
            HostessView.close();
   
    do{
        if(choice < 1 || choice > counterHostess){
        cout<<"There is no hostess for your choice , please enter again"<<endl;
        displayInfo();
        cin>>choice;
    }
    }while(choice < 1 || choice > counterHostess);
    int currentData = 1;
    string HostessLine;
            HostessView.open("HostessData.txt");
    while(getline(HostessView , HostessLine))
            {
                if (currentData == choice) {
                istringstream issHostess(HostessLine);
                issHostess>>_name>>_surname>>_id>>_role>>_age>>_gender>>_experience>>_year;
                cout<<HostessLine<<endl;
                cout << "Choose one of them which you want to edit" << endl;
                cin >> choiceEdit;
                cout << "Please enter the new information" << endl;
                cin.ignore();
                getline(cin,newValue);
                switch (choiceEdit){
                    case 1:{
                        _name = newValue;
                    tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                    <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                    break;
                    }
                    case 2:{
                        _surname = newValue;
                         tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                         <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                        break;
                    }
                    case 3:{
                         _id = newValue;
                        tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                         <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                         break;
                    }
                    case 4:{
                         _role = newValue;
                        tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                         <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                        break;
                    }
                    case 5:{
                         _age = newValue;
                       tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                         <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                       break;
                    }
                    case 6:{
                         _gender = newValue;
                       tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                         <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                       break;
                    }
                    case 7:{
                      _experience = newValue;
                      tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                         <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                         break;
                    }
                    case 8:{
                        _year = newValue;
                        tempHostess<<_name<<setw(10)<<_surname<<setw(5)<<_id<<setw(12)<<_role
                         <<setw(5)<<_age<<setw(10)<<_gender<<setw(10)<<_experience<<setw(5)<<_year<<endl;
                        break;
                    }
                    
                }
            }
             else{
                    tempHostess<<HostessLine<<endl;
                }
            currentData++;
            }
            HostessView.close();
            tempHostess.close();
            remove("HostessData.txt");
            rename("tempHostess.txt","HostessData.txt");

            cout << "Succesfully" << endl;
}

void Hostess::displayInfo() {
    int counter = 1;
           string line;
            HostessView.open("HostessData.txt");
            while(getline(HostessView , line))
            {
                cout<<"Hostess "<<counter<<" -> "<<line<<endl;
                counter++;
               
            }
            HostessView.close();

}