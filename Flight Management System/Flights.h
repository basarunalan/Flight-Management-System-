#ifndef FLIGHTS_H
#define FLIGHTS_H
#include <iostream>
using namespace std;
#include "Pilot.h"
#include "Plane.h"
#include "Hostess.h"
#include <fstream>
class Flights{
public:
    void addFlight(int _choicePilot,int _choicePlane,int _choiceHostess);
    void setFlight();
    void viewFlights();
    void editFlight(int choice);
    void FlightsTicketView();
    void PassengerChange(int _newPassenger,int _choiceType);
    void CargoChange(int _weight,int _choiceType);
    void CargoChange(double _weight,int _choiceType);
    private:
    string cargoWeight;
    string passengerNumber;
    string departure;
    string landing;
    string hour;
    string checkOver;
    string pilotName,pilotSurname,hostessName,hostessSurname,planeNumber;
    ofstream FlightAdd;
    ifstream Flightview;

};

#endif