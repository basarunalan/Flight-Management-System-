#include <iostream>
using namespace std;
#include "Menu.h"
void Menu::Title(){
	cout<<"\n \n      WELCOME TO FLIGHT SYSTEM"<<endl;
}
void Menu::MainMenu(){
	cout<<"\n \n";
	cout<<"   1 - Tickets"<<endl;
	cout<<"   2 - Administration"<<endl;
	cout<<"   3 - Exit"<<endl;
	cout<< "\n Enter a number between 1 and 3: ";

}

void Menu::EngineerMenu()
{
	cout << "1 - Display Engineer" <<endl;
    cout << "2 - Add Engineer" <<endl;
    cout << "3 - Add Broken Plane" <<endl;
	cout << "4 - Edit Broken Plane" <<endl;
    cout << "5 - Return back" <<endl;
	cout << "Please enter a number: "<<endl;
}

void Menu::FlightsMenu()
{
	cout << "1 - Add new Flight" << endl;
    cout << "2 - Edit Flights" << endl;
    cout << "3 - View Flights" << endl;
    cout << "4 - Return back" << endl;
    cout << "Please enter a number: ";
}

void Menu::HostessMenu()
{
	cout << "1 - Display Hostess" <<endl;
    cout << "2 - Add Hostess" <<endl;
    cout << "3 - Edit Hostesses" <<endl;
    cout << "4 - Return back" <<endl;
    cout << "Please enter a number: ";
}

void Menu::PilotMenu()
{
	cout << "1 - Add new Pilot" << endl;
    cout << "2 - Edit Pilots" << endl;
    cout << "3 - View Pilots" << endl;
    cout << "4 - Return back" << endl;
    cout <<"Please enter a number "<<endl;
}

void Menu::PlaneMenu()
{
	cout << "1 - Add new Plane" << endl;
    cout << "2 - Edit Planes" << endl;
    cout << "3 - View Planes" << endl;
    cout << "4 - Return back" << endl;
    cout <<"Please enter a number "<<endl;
}

void Menu::AdminMenu()
{
	cout<<"1 - PILOT"<<endl;
    cout<<"2 - HOSTESS"<<endl;
    cout<<"3 - PLANE"<<endl;
    cout<<"4 - FLIGHTS"<<endl;
    cout<<"5 - ENGINEER"<<endl;
    cout<<"6 - RETURN TO MAIN MENU"<<endl;
    cout<<"Please select a department : ";
}
