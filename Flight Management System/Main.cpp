#include <iostream>
using namespace std;
#include "Menu.h"
#include "Menu.cpp"
#include "Ticket.h"
#include "Ticket.cpp"
#include "Admin.h"
#include "Admin.cpp"
#include "Pilot.h"
#include "hostess.h"
#include "Plane.h"
#include "Flights.h"
#include "Flights.cpp"
#include "Engineer.h"
#include "Engineer.cpp"
int main(){
	int choiceMain;
	Menu mainMenu;
	Menu subMenu;
	mainMenu.Title();
	mainMenu.MainMenu();
	do {
        cin>> choiceMain;
        if (choiceMain < 1 || choiceMain > 3) {
            cout<< "\n Please enter a number between 1 and 3!" <<endl;
        }
    } while (choiceMain < 1 || choiceMain > 3);

	while (choiceMain != 3){
		switch(choiceMain){
	 	case 1:{
	 		Ticket T1;
	 		T1.TicketMenu();
	 		cout<<"Please choose your flight"<<" | choose your ticket type"<<" | Enter how many people you are and your cargo weight \n ";
	 		cin>>T1;
	 		cout<<T1<<endl;
			cin.ignore();
			mainMenu.MainMenu();
				do {
        cin>> choiceMain;
        if (choiceMain < 1 || choiceMain > 3) {
            cout << "\n Please enter a number between 1 and 3!" <<endl;
        }
    } while (choiceMain < 1 || choiceMain > 3);
			break;
		 } 
				
		 case 2:{
			string username,password;
			int choiceAdmin;
			Admin A1;
			while(A1.UserLogin(username,password) == 0){
			
            cout<<"Please enter username "<<endl;
			cin>>username;
			cout<<"Please enter your password"<<endl;
			cin>>password;
			A1.UserLogin(username,password);
			if(A1.UserLogin(username,password) == 0){
              cout<<"Wrong username or password"<<endl;
			}
			}
			subMenu.AdminMenu();
			do {
			cin>>choiceAdmin;
        if (choiceAdmin < 1 || choiceAdmin > 6) {
            cout << "\n Please enter a number between 1 and 6!" <<endl;
        }
    } while (choiceAdmin < 1 || choiceAdmin > 6);
			while(choiceAdmin != 0){
				if(choiceAdmin == 1){
				int choicePilot = 0; 
                Pilot P1;
				subMenu.PilotMenu();
				cin>>choicePilot;
				while(choicePilot != 4){
                     switch(choicePilot){
					case 1:{
						P1.setPilot();
						choicePilot = 0;
						break;
					}
					case 2:{
                       P1.viewPilot();
					   cout<<"Choose a pilot that you want to edit : ";
					   cin>>choicePilot;
						P1.editPilot(choicePilot);
						choicePilot = 0;
						break;

					}
					case 3:{
						P1.viewPilot();
						break;
					}
					case 4:{
						break;

					}
				}
				subMenu.PilotMenu();
				    cin>>choicePilot;
				}
				choiceAdmin = 0;
				subMenu.AdminMenu();
				cin>>choiceAdmin;
 			}
			else if(choiceAdmin == 2){
				int hostessChoice;
    subMenu.HostessMenu();
    cin >> hostessChoice;

    Hostess fatma; 
while(hostessChoice != 4){
	switch (hostessChoice) {
        case 1:
            fatma.displayInfo();
            break;
        case 2: {
            fatma.setHostess();
            break;
        }
        case 3:
            fatma.displayInfo();
			cout<<"Choose a hostess "<<endl;
			cin>>hostessChoice;
			fatma.editInfo(hostessChoice);
			hostessChoice = 0;
            break;
        default:
            cout << "Invalid choice.\n";
			break;
}
    subMenu.HostessMenu();
    cin >> hostessChoice;
}
choiceAdmin = 0;
				subMenu.AdminMenu();
				cin>>choiceAdmin;
    }
	else if(choiceAdmin == 3){
		int choicePlane = 0; 
                Plane Pegasus;
				subMenu.PlaneMenu();
				cin>>choicePlane;
				while(choicePlane != 4){
                     switch(choicePlane){
					case 1:{
						Pegasus.setPlane();
						choicePlane = 0;
						break;
					}
					case 2:{
                       Pegasus.viewPlane();
					   cout<<"Choose a plane that you want to edit : ";
					   cin>>choicePlane;
						Pegasus.editPlane(choicePlane);
						choicePlane = 0;
						break;

					}
					case 3:{
						Pegasus.viewPlane();
						break;
					}
					case 4:{
						break;

					}
				}
				subMenu.PlaneMenu();
				    cin>>choicePlane;
				}
				choiceAdmin = 0;
				subMenu.AdminMenu();
				cin>>choiceAdmin;
	}
	else if(choiceAdmin == 4){
		int choiceFlight = 0; 
                Flights Flight1;
				subMenu.FlightsMenu();
				cin>>choiceFlight;
				while(choiceFlight != 4){
                     switch(choiceFlight){
					case 1:{
						Flight1.setFlight();
						choiceFlight = 0;
						break;
					}
					case 2:{
                       Flight1.viewFlights();
					   cout<<"Choose a flight that you want to edit : ";
					   cin>>choiceFlight;
						Flight1.editFlight(choiceFlight);
						choiceFlight = 0;
						break;

					}
					case 3:{
						Flight1.viewFlights();
						break;
					}
					case 4:{
						break;

					}
				}
				subMenu.FlightsMenu();
				    cin>>choiceFlight;
				}
				choiceAdmin = 0;
				subMenu.AdminMenu();
				cin>>choiceAdmin;
	}
	else if(choiceAdmin == 5){
		Engineer Eng1;
    int choiceEngineer;
    do {
        subMenu.EngineerMenu();
        cin >> choiceEngineer;

        switch (choiceEngineer) {
            case 1:
                Eng1.DisplayEngineers();
                break;
            case 2:
                Eng1.addEngineer();
                break;
            case 3:
                Eng1.addBrokenPlane();
                break;
			case 4:
                Eng1.EditBrokenPlane();
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choiceEngineer != 5);

    choiceAdmin = 0;
    subMenu.AdminMenu();
    cin >> choiceAdmin;
	}
    else if(choiceAdmin == 6){
		       cin.ignore();
			mainMenu.MainMenu();
				do {
        cin>> choiceMain;
        if (choiceMain < 1 || choiceMain > 3) {
            cout << "\n Please enter a number between 1 and 3!" <<endl;
        }
    } while (choiceMain < 1 || choiceMain > 3);
				break;
			}
			}
		 }
		 
	 }
	}
			cout<<"System is closing..."<<endl;
			return 0;
}