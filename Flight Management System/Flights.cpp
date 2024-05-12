#include "Flights.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Hostess.h"
#include "Hostess.cpp"
#include "Plane.h"
#include "Plane.cpp"
#include "Pilot.h"
#include "Pilot.cpp"
#include "Route.h"
#include "Route.cpp"
#include "Engineer.h"
using namespace std;
int counterFlight = 1;
Hostess Defne;
Plane Plane1;
Pilot Pilot1;
Engineer Eng1;
void Flights::setFlight()
{ 
    string _name, _surname,_age, _location, _baseInfo, _type;
    string _serialnumber, _capacity, _cargoWeight;
    string _planeID,_experience;
    int tempGrapgh[7];
    int unAvailable;
    int choicePilot,choicePlane,choiceHostess;
    int checkNumber,flightType,landingChoice,departureChoice;
    cout << "\nEnter the details for the new Flight." << endl;
    cout<<"Enter the passenger number"<<endl;
	cin>>passengerNumber;
    checkNumber = stoi(passengerNumber);
    if(checkNumber < 1 ){
        cout<<"Number can not be negative"<<endl;
        cout<<"Enter the passenger number"<<endl;
	    cin>>passengerNumber;
    }
    cout<<"Enter the total cargo weight"<<endl;
	cin>>cargoWeight;
    cout<<"Please choose your flight type "<<endl,
    cout<<"1 - International \n2 - Domestic"<<endl;
    cin>>flightType;
    if(flightType == 1){
        departure = "Istanbul";
        cout<<"1 - Munich \n2 - London \n3 - Washington \n4 - Delhi  \n5 - Beijing \n6 - Tokyo "<<endl;
        cout<<"Is a airplane unavailable ? (0 for NO)"<<endl;
        cin>>unAvailable;
        cout<<"Please choose the landing airplane location "<<endl;
         cout<<"1 - Munich \n2 - London \n3 - Washington \n4 - Delhi  \n5 - Beijing \n6 - Tokyo "<<endl;
        cin>>landingChoice;
        if(landingChoice == unAvailable){
            cout<<"You can not choose this location , because airPlane is not available"<<endl;
            cout<<"1 - Munich \n2 - London \n3 - Washington \n4 - Delhi  \n5 - Beijing \n6 - Tokyo "<<endl;
            cin>>landingChoice;
        }
        else if (unAvailable != 0){
           switch (landingChoice){
            case 1:{
                landing = "Munich";
                break;
            }
            case 2:{
                landing = "London";
                break;
            }
            case 3:{
                landing = "Washington";
                break;
            }
            case 4:{
                landing = "Delhi";
                break;
            }
            case 5:{
                landing = "Beijing";
                break;
            }
            case 6:{
                landing = "Tokyo";
                break;
            }
        }
       Route R1;
       for(int i = 0;i < 7;i++){
         tempGrapgh[i] = graph[unAvailable][i];
       }
       for(int j = 0;j < 7;j++){
        graph[unAvailable][j] = 0;
       }
       R1.Dijkstra(0,landingChoice);
        for(int k = 0;k < 7;k++){
        graph[unAvailable][k] = tempGrapgh[k];
       }
        }
        else{
            switch (landingChoice){
            case 1:{
                landing = "Munich";
                break;
            }
            case 2:{
                landing = "London";
                break;
            }
            case 3:{
                landing = "Washington";
                break;
            }
            case 4:{
                landing = "Delhi";
                break;
            }
            case 5:{
                landing = "Beijing";
                break;
            }
            case 6:{
                landing = "Tokyo";
                break;
            }
        }
       Route R1;
       R1.Dijkstra(0,landingChoice);
        }
    cout<<"Enter the departure hour"<<endl;
	cin>>hour;
int counter = 1;
string Pilotline;
Pilot1.Pilotview.open("PilotData.txt");
while (getline(Pilot1.Pilotview, Pilotline))
{
    istringstream issPilot(Pilotline);
    issPilot >> _name >> _surname >> _age >> _location >> _baseInfo >> _type;
    if (_type == "International" && _location == departure) {
        cout << "Pilot " << counter << " -> " << Pilotline << endl;
        counterPilot++;
    }
    counter++;
}
Pilot1.Pilotview.close();
    do{
     cout<<"Choose the pilot "<<endl;
    cin>>choicePilot;
    if(choicePilot < 1 || choicePilot > counter){
        cout<<"Please enter again"<<endl;
        cin>>choicePilot;
    }
    }while(choicePilot < 1 || choicePilot > counter);

    counter = 1;
    string Planeline;
    string Engineerline;
Plane1.PlaneView.open("PlaneData.txt");
Eng1.EngineerView.open("EngineerData.txt");
while (getline(Plane1.PlaneView, Planeline))
{
    istringstream issPlane(Planeline);
    issPlane >> _serialnumber >> _capacity >> _location >> _baseInfo >> _type >> _cargoWeight;

    if (_type == "International" && _location == departure) {
        int counterCheck = 0;
        Eng1.EngineerView.clear(); 

        while (getline(Eng1.EngineerView, Engineerline)) {
            istringstream issEngineer(Engineerline);
            issEngineer >> _name >> _surname >> _age >> _planeID >> _experience;

            if (_serialnumber == _planeID) {
                counterCheck++;
                break; 
            }
        }

        if (counterCheck == 0) {
            cout << "Plane " << counter << " -> " << Planeline << endl;
        }
    }
    counter++;
}
Eng1.EngineerView.close();
Plane1.PlaneView.close();
   do{
    cout<<"Choose the plane "<<endl;
    cin>>choicePlane;
    if(choicePlane < 1 || choicePlane > counter){
        cout<<"Please enter again"<<endl;
        cin>>choicePlane;
    }
    }while(choicePlane < 1 || choicePlane > counter);
    Defne.displayInfo();
    cout<<"Choose a Hostess"<<endl;
    cin>>choiceHostess;
    checkOver = "No";
    addFlight(choicePilot,choicePlane,choiceHostess);
        
    }
    else if(flightType == 2){
        do {
        cout<<"Please choose the departure airplane location "<<endl;
    cout<<"1 - Istanbul \n2 - Ankara \n3 - Izmir"<<endl;
    cin>>departureChoice;
    if(departureChoice < 1 || departureChoice > 3){
        cout<<"Please enter a number between 1 - 3 !"<<endl;
    }
    } while (departureChoice < 1 || departureChoice > 3);
    switch (departureChoice){
            case 1:{
                departure = "Istanbul";
                break;
            }
            case 2:{
                departure = "Ankara";
                break;
            }
            case 3:{
                departure = "Izmir";
                break;
            }
        }
    cin.ignore();
	cout<<"Enter the landing location"<<endl;
	getline(cin,landing);
    cout<<"Enter the departure hour"<<endl;
	cin>>hour;

int counter = 1;
string Pilotline;
Pilot1.Pilotview.open("PilotData.txt");
while (getline(Pilot1.Pilotview, Pilotline))
{
    istringstream issPilot(Pilotline);
    issPilot >> _name >> _surname >> _age >> _location >> _baseInfo >> _type;
    if (_type != "International" && _location == departure) {
        cout << "Pilot " << counter << " -> " << Pilotline << endl;
    }
    counter++;
}
Pilot1.Pilotview.close();
    do{
     cout<<"Choose the pilot "<<endl;
    cin>>choicePilot;
    if(choicePilot < 1 || choicePilot > counter){
        cout<<"Please enter again"<<endl;
        cin>>choicePilot;
    }
    }while(choicePilot < 1 || choicePilot > counter);
    counter = 1;
    string Planeline;
    string Engineerline;
Plane1.PlaneView.open("PlaneData.txt");
Eng1.EngineerView.open("EngineerData.txt");
while (getline(Plane1.PlaneView, Planeline))
{
    istringstream issPlane(Planeline);
    issPlane >> _serialnumber >> _capacity >> _location >> _baseInfo >> _type >> _cargoWeight;

    if (_type != "International" && _location == departure) {
        int counterCheck = 0;
        Eng1.EngineerView.clear(); 

        while (getline(Eng1.EngineerView, Engineerline)) {
            istringstream issEngineer(Engineerline);
            issEngineer >> _name >> _surname >> _age >> _planeID >> _experience;

            if (_serialnumber == _planeID) {
                counterCheck++;
                break; 
            }
        }

        if (counterCheck == 0) {
            cout << "Plane " << counter << " -> " << Planeline << endl;
        }
    }
    counter++;
}
Eng1.EngineerView.close();
Plane1.PlaneView.close();
   do{
    cout<<"Choose the plane "<<endl;
    cin>>choicePlane;
    if(choicePlane < 1 || choicePlane > counter){
        cout<<"Please enter again"<<endl;
        cin>>choicePlane;
    }
    }while(choicePlane < 1 || choicePlane > counter);
    Defne.displayInfo();
    cout<<"Choose a Hostess"<<endl;
    cin>>choiceHostess;
    checkOver = "No";
    addFlight(choicePilot,choicePlane,choiceHostess);
    }

}
void Flights::addFlight(int _choicePilot,int _choicePlane,int _choiceHostess) {
     string _name, _surname,_age, _location, _baseInfo, _type;
     string _serialnumber, _capacity, _cargoWeight;
     string _id, _role,_gender, _experience, _year;
            int currentPilotData = 1;
            int currentPlaneData = 1;
            int currentHostessData = 1;
            string Pilotline;
            Pilot1.Pilotview.open("PilotData.txt");
            while(getline(Pilot1.Pilotview , Pilotline))
            {
                if (currentPilotData == _choicePilot) {
                istringstream issPilot(Pilotline);
                issPilot>>_name>>_surname>>_age>>_location>>_baseInfo>>_type;
                pilotName = _name;
                pilotSurname = _surname;
                }
                currentPilotData++;
                }
                Pilot1.Pilotview.close();
                 string Planeline;
            Plane1.PlaneView.open("PlaneData.txt");
            
            while(getline(Plane1.PlaneView , Planeline))
            {
                if (currentPlaneData == _choicePlane) {
                istringstream issPlane(Planeline);
                issPlane>>_serialnumber>>_capacity>>_location>>_baseInfo>>_type>>_cargoWeight;
                planeNumber = _serialnumber;
                }
                currentPlaneData++;
                }
                Plane1.PlaneView.close();
                string HostessLine;
            Defne.HostessView.open("HostessData.txt");
            
    while(getline(Defne.HostessView , HostessLine))
            {
                if (currentHostessData == _choiceHostess) {
                istringstream issHostess(HostessLine);
                issHostess>>_name>>_surname>>_id>>_role>>_age>>_gender>>_experience>>_year;
                hostessName = _name;
                hostessSurname = _surname;
                }
                currentHostessData++;
                }
                Defne.HostessView.close();

    FlightAdd.open("FlightData.txt",ios::app);
    FlightAdd<<endl<<passengerNumber<<setw(10)<<cargoWeight<<setw(10)<<departure<<setw(15)<<landing<<setw(10)<<hour<<setw(7)<<checkOver
    <<setw(10)<<pilotName<<setw(12)<<pilotSurname<<setw(10)<<planeNumber<<setw(10)<<hostessName<<setw(12)<<hostessSurname;
    FlightAdd.close();
    counterFlight++;
}
void Flights::editFlight(int choice) {
    string _cargoWeight,_passengerNumber,_departure,_landing,_hour,_checkOver,_pilotName,_pilotSurname,_hostessName,_hostessSurname,_planeNumber;
    int choiceEdit;
    int editPilot,editPlane,editHostess;
    string newValue;
    ofstream tempFlight("TempFlight.txt");
    int currentData = 1;
     string FlightLine;
     Flightview.open("FlightData.txt");
     while(getline(Flightview,FlightLine)){
        if(currentData == choice){
            istringstream issFlight(FlightLine);
            issFlight>>_passengerNumber>>_cargoWeight>>_departure>>_landing>>_hour>>_checkOver>>_pilotName
            >>_pilotSurname>>_planeNumber>>_hostessName>>_hostessSurname;
            cout<<FlightLine<<endl;
            cout<<"Choose one of them which you want to edit"<<endl;
        cin>>choiceEdit;
        if(choiceEdit < 7){
         switch (choiceEdit){
                    case 1:{
                        cout<<"Please enter the new information"<<endl;
                        cin.ignore();
                         getline(cin,newValue);
                        _passengerNumber = newValue;
                         tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                     break;
                    }
                    case 2:{
                        cout<<"Please enter the new information"<<endl;
                        cin.ignore();
                        getline(cin,newValue);
                        _cargoWeight = newValue;
                        tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                     break;
                    }
                    case 3:{
                        cout<<"Please enter the new information"<<endl;
                        cin.ignore();
                        getline(cin,newValue);
                         _departure = newValue;
                        tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
    
                       break;
                    }
                    case 4:{
                        cout<<"Please enter the new information"<<endl;
                        cin.ignore();
                        getline(cin,newValue);
                         _landing = newValue;
                       tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
    
                       break;
                    }
                    case 5:{
                        cout<<"Please enter the new information"<<endl;
                        cin.ignore();
                        getline(cin,newValue);
                       tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                       break;
                    }
                    case 6:{
                        int answer;
                        cout<<"Is flight over? (1 for Yes / 0 for No)"<<endl;
                        cin>>answer;
                        if(answer == 1){
                           string returnBase;
                           string _name,_surname,_age,_location,_baseInfo,_type;
                           string _serialnumber, _capacity,_PlaneCargo;
                           string Pilotline;
                           string Planeline;
                           int counter = 1;
                           Pilot1.Pilotview.open("PilotData.txt");
                          while (getline(Pilot1.Pilotview, Pilotline))
                         {
                         istringstream issPilot(Pilotline);
                        issPilot >> _name >> _surname >> _age >> _location >> _baseInfo >> _type;
                        if (_pilotName == _name && _pilotSurname == _surname) {
                            returnBase = _baseInfo;
                         }
                           counter++;
                            }
                           Pilot1.Pilotview.close();
                            if(_landing != returnBase){
                                 Pilot1.Pilotview.open("PilotData.txt");
                                 ofstream tempPilot("TempPilot.txt");
                                cout<<"Flight is over , new flight to return base is added"<<endl;
                                tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(12)<<_landing<<setw(13)<<_departure<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                            while (getline(Pilot1.Pilotview, Pilotline))
                         {
                        istringstream issPilot(Pilotline);
                        issPilot >> _name >> _surname >> _age >> _location >> _baseInfo >> _type;
                        if (_pilotName == _name && _pilotSurname == _surname) {
                            _location = _landing;
                            tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(12)<<_location<<setw(10)<<_baseInfo<<setw(16)<<_type<<endl;
                         }
                         else{
                            tempPilot<<Pilotline<<endl;
                         }
                           counter++;
                            }
                            Pilot1.Pilotview.close();
                            tempPilot.close();
                            remove("PilotData.txt");
                            rename("TempPilot.txt","PilotData.txt");
                            counter = 1;
                            Plane1.PlaneView.open("PlaneData.txt");
                            ofstream tempPlane("TempPlane.txt");
                            while (getline(Plane1.PlaneView,Planeline))
                         {
                        istringstream issPlane(Planeline);
                        issPlane >> _serialnumber >> _capacity >> _location >> _baseInfo >> _type >> _PlaneCargo;
                        if (_serialnumber == _planeNumber) {
                            _location = _landing;
                             tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_PlaneCargo<<endl;
                         }
                         else{
                            tempPlane<<Planeline<<endl;
                         }
                           counter++;
                            }
                            Plane1.PlaneView.close();
                            tempPlane.close();
                            remove("PlaneData.txt");
                            rename("TempPlane.txt","PlaneData.txt");
                            }
                            else if(_landing == returnBase){
                                 Pilot1.Pilotview.open("PilotData.txt");
                                 ofstream tempPilot("TempPilot.txt");
                                while (getline(Pilot1.Pilotview, Pilotline))
                         {
                         istringstream issPilot(Pilotline);
                        issPilot >> _name >> _surname >> _age >> _location >> _baseInfo >> _type;
                        if (_pilotName == _name && _pilotSurname == _surname) {
                            _location = _landing;
                            tempPilot<<_name<<setw(10)<<_surname<<setw(5)<<_age<<setw(12)<<_location<<setw(10)<<_baseInfo<<setw(16)<<_type<<endl;
                         }
                         else{
                            tempPilot<<Pilotline<<endl;
                         }
                           counter++;
                            }
                            Pilot1.Pilotview.close();
                            tempPilot.close();
                            remove("PilotData.txt");
                            rename("TempPilot.txt","PilotData.txt");
                            counter = 1;
                            Plane1.PlaneView.open("PlaneData.txt");
                            ofstream tempPlane("TempPlane.txt");
                            while (getline(Plane1.PlaneView,Planeline))
                         {
                        istringstream issPlane(Planeline);
                        issPlane >> _serialnumber >> _capacity >> _location >> _baseInfo >> _type >> _PlaneCargo;
                        if (_serialnumber == _planeNumber) {
                            _location = _landing;
                             tempPlane<<_serialnumber<<setw(7)<<_capacity<<setw(10)<<_location<<setw(10)<<_baseInfo<<setw(15)<<_type<<setw(7)<<_PlaneCargo<<endl;
                         }
                         else{
                            tempPlane<<Planeline<<endl;
                         }
                           counter++;
                            }
                            Plane1.PlaneView.close();
                            tempPlane.close();
                            remove("PlaneData.txt");
                            rename("TempPlane.txt","PlaneData.txt");
                        
                                cout<<"Flight is over , pilot returned to base"<<endl;
                                tempFlight;
                            }
                            }
                        else if(answer == 0){
                          tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                        }
                       break;
                    }
             
                    }
        }
        else if(choiceEdit == 7 || choiceEdit == 8){
            string _name,_surname,_age,_location,_baseInfo,_type;
             string Pilotline;
             int counter = 1;
            Pilot1.Pilotview.open("PilotData.txt");
        while (getline(Pilot1.Pilotview, Pilotline))
       {
       istringstream issPilot(Pilotline);
       issPilot >> _name >> _surname >> _age >> _location >> _baseInfo >> _type;
       if (_location == _departure && _type == "International" && (_landing == "Munich"  || _landing == "London" || _landing == "Washington" || _landing == "Delhi" || _landing == "Beijing" || _landing == "Tokyo")) {
        cout << "Pilot " << counter << " -> " << Pilotline << endl;
       }
       counter++;
       }
       Pilot1.Pilotview.close();
       Pilot1.Pilotview.open("PilotData.txt");
       counter = 1;
       while (getline(Pilot1.Pilotview, Pilotline))
       {
       istringstream issPilot(Pilotline);
       issPilot >> _name >> _surname >> _age >> _location >> _baseInfo >> _type;
       if (_location == _departure && _type != "International" && (_landing != "Munich"  && _landing != "London" && _landing != "Washington" && _landing != "Delhi" && _landing != "Beijing" && _landing != "Tokyo")) {
        cout << "Pilot " << counter << " -> " << Pilotline << endl;
       }
       counter++;
       }
            
            Pilot1.Pilotview.close();
            Pilot1.Pilotview.open("PilotData.txt");
            cout<<"Choose the pilot "<<endl;
            cin>>editPilot;
            counter = 1;
           while(getline(Pilot1.Pilotview , Pilotline))
            {
               if(counter == editPilot){
                istringstream issPilot(Pilotline);
                 issPilot>>_pilotName>>_pilotSurname;
                 tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
               }
               counter++;
            }
        }
        else if(choiceEdit == 9){
            string _name,_surname,_age,_planeID,_experience;
            string _serialNumber,_capacity,_location,_baseInfo,_type,_cargoWeight;
            string PlaneLine;
            string Engineerline;
          int counter = 1;
             Eng1.EngineerView.open("EngineerData.txt");
             Plane1.PlaneView.open("PlaneData.txt");
        while (getline(Plane1.PlaneView, PlaneLine))
       {
       istringstream issPlane(PlaneLine);
       issPlane >> _serialNumber >> _capacity >> _location >> _baseInfo >> _type >> _cargoWeight;
       if (_location == _departure &&_type == "International" && (_landing == "Munich"  || _landing == "London" || _landing == "Washington" || _landing == "Delhi" || _landing == "Beijing" || _landing == "Tokyo")) {
          int counterCheck = 0;
        Eng1.EngineerView.clear(); 

        while (getline(Eng1.EngineerView, Engineerline)) {
            istringstream issEngineer(Engineerline);
            issEngineer >> _name >> _surname >> _age >> _planeID >> _experience;

            if (_serialNumber == _planeID) {
                counterCheck++;
                break; 
            }
        }

        if (counterCheck == 0) {
            cout << "Plane " << counter << " -> " << PlaneLine << endl;
        }
       }
       counter++;
       }
       Plane1.PlaneView.close();
       Eng1.EngineerView.close();
       counter = 1;
            Plane1.PlaneView.open("PlaneData.txt");
            Eng1.EngineerView.open("EngineerData.txt");
            while (getline(Plane1.PlaneView, PlaneLine))
       {
       istringstream issPlane(PlaneLine);
       issPlane >> _serialNumber >> _capacity >> _location >> _baseInfo >> _type >> _cargoWeight;
       if (_location == _departure && _type != "International" && (_landing != "Munich"  && _landing != "London" && _landing != "Washington" && _landing != "Delhi" && _landing != "Beijing" && _landing != "Tokyo")) {
        int counterCheck = 0;
        Eng1.EngineerView.clear(); 

        while (getline(Eng1.EngineerView, Engineerline)) {
            istringstream issEngineer(Engineerline);
            issEngineer >> _name >> _surname >> _age >> _planeID >> _experience;

            if (_serialNumber == _planeID) {
                counterCheck++;
                break; 
            }
        }

        if (counterCheck == 0) {
            cout << "Plane " << counter << " -> " << PlaneLine << endl;
        }
       }
       counter++;
       }
       Plane1.PlaneView.close();
       Eng1.EngineerView.close();
       counter = 1;
       Plane1.PlaneView.open("PlaneData.txt");
            cout<<"Choose the plane "<<endl;
            cin>>editPlane;
           while(getline(Plane1.PlaneView , PlaneLine))
            {
               if(counter == editPlane){
                istringstream issPlane(PlaneLine);
                 issPlane>>_planeNumber;
                  tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
               }
               counter++;
            }
        }
        else if(choiceEdit == 10 || choiceEdit == 11){
            int counter = 1;
            Defne.displayInfo();
            Defne.HostessView.open("HostessData.txt");
            cout<<"Choose the hostess "<<endl;
            cin>>editHostess;
            string HostessLine;
           while(getline(Defne.HostessView , HostessLine))
            {
               if(counter == editHostess){
                istringstream issHostess(HostessLine);
                 issHostess>>_hostessName>>_hostessSurname;
             tempFlight<<_passengerNumber<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
    <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
               }
               counter++;
            }
        }
                }
        else{
                    tempFlight<<FlightLine<<endl;
                }
            currentData++;
     }
    Defne.HostessView.close();
    Plane1.PlaneView.close();
    Pilot1.Pilotview.close();
    Flightview.close();
    tempFlight.close();
            remove("FlightData.txt");
            rename("tempFlight.txt","FlightData.txt");
        cout << "Flight edited successfully." << endl;
}

void Flights::viewFlights() {
    int counter = 1;
           string line;
            Flightview.open("FlightData.txt");
            while(getline(Flightview , line))
            {
                cout<<"Flight "<<counter<<" -> "<<line<<endl;
                counter++;
               
            }
            Flightview.close();
}

void Flights::FlightsTicketView()
{
    static int counter = 1;
    string line;
    string _passenger,_cargo,_departure,_landing,_hour;
    Flightview.open("FlightData.txt");
    cout << " \n ---- Flights ----" << endl;
    while(getline(Flightview , line))
            {
                istringstream issFlight(line);
                issFlight>>_passenger>>_cargo>>_departure>>_landing>>_hour;
                cout<<"Flight "<<counter<<" -> "<<_departure<<" "<<_landing<<" | "<<_hour<<"\n\n";
                counter++;
                }
                Flightview.close();
                counter = 1;
}

void Flights::PassengerChange(int _newPassenger, int _choiceType)
{
    string _passengerNumber,_cargoWeight,_departure,_landing,_hour,_checkOver,_pilotName,_pilotSurname,_planeNumber,_hostessName,_hostessSurname;
    string newPassenger;
    ofstream tempFlight("tempFlight.txt");
    static int currentData = 1;
    string line;
            Flightview.open("FlightData.txt");
    while(getline(Flightview , line))
            {
                if (currentData == _choiceType) {
                istringstream issFlight(line);
                issFlight>>_passengerNumber>>_cargoWeight>>_departure>>_landing>>_hour>>_checkOver>>_pilotName>>_pilotSurname>>_planeNumber>>_hostessName>>_hostessSurname;
                int passenger = stoi(_passengerNumber);
                passenger += _newPassenger;
                newPassenger = to_string(passenger);
                tempFlight<<newPassenger<<setw(10)<<_cargoWeight<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
                <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                }
                else{
                    tempFlight<<line<<endl;
                }
                currentData++;
                }
                Flightview.close();
                tempFlight.close();
                remove("FlightData.txt");
                rename("tempFlight.txt","FlightData.txt");
                currentData = 1;
}

void Flights::CargoChange(int _weight, int _choiceType)
{
    string _passengerNumber,_cargoWeight,_departure,_landing,_hour,_checkOver,_pilotName,_pilotSurname,_planeNumber,_hostessName,_hostessSurname;
    string newCargo;
    ofstream tempFlight("tempFlight.txt");
    static int currentData = 1;
    string line;
            Flightview.open("FlightData.txt");
    while(getline(Flightview , line))
            {
                if (currentData == _choiceType) {
                istringstream issFlight(line);
                issFlight>>_passengerNumber>>_cargoWeight>>_departure>>_landing>>_hour>>_checkOver>>_pilotName>>_pilotSurname>>_planeNumber>>_hostessName>>_hostessSurname;
                int cargo = stoi(_cargoWeight);
                cargo += _weight;
                newCargo = to_string(cargo);
                tempFlight<<_passengerNumber<<setw(10)<<newCargo<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
                <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                }
                else{
                    tempFlight<<line<<endl;
                }
                currentData++;
                }
                Flightview.close();
                tempFlight.close();
                remove("FlightData.txt");
                rename("tempFlight.txt","FlightData.txt");
                currentData = 1;
}

void Flights::CargoChange(double _weight, int _choiceType)
{
    string _passengerNumber,_cargoWeight,_departure,_landing,_hour,_checkOver,_pilotName,_pilotSurname,_planeNumber,_hostessName,_hostessSurname;
    string newCargo;
    ofstream tempFlight("tempFlight.txt");
    static int currentData = 1;
    string line;
            Flightview.open("FlightData.txt");
    while(getline(Flightview , line))
            {
                if (currentData == _choiceType) {
                istringstream issFlight(line);
                issFlight>>_passengerNumber>>_cargoWeight>>_departure>>_landing>>_hour>>_checkOver>>_pilotName>>_pilotSurname>>_planeNumber>>_hostessName>>_hostessSurname;
                double cargo = stod(_cargoWeight);
                cargo += _weight;
                newCargo = to_string(cargo).substr(0,5);
                tempFlight<<_passengerNumber<<setw(10)<<newCargo<<setw(10)<<_departure<<setw(15)<<_landing<<setw(10)<<_hour<<setw(7)<<_checkOver
                <<setw(10)<<_pilotName<<setw(12)<<_pilotSurname<<setw(10)<<_planeNumber<<setw(10)<<_hostessName<<setw(12)<<_hostessSurname<<endl;
                }
                else{
                    tempFlight<<line<<endl;
                }
                currentData++;
                }
                Flightview.close();
                tempFlight.close();
                remove("FlightData.txt");
                rename("tempFlight.txt","FlightData.txt");
                currentData = 1;
}
