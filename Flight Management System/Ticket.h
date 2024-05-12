#ifndef TICKET_H
#define TICKET_H
#include <iostream>
using namespace std;
#include "Flights.h"
class Ticket{
	friend ostream &operator<<(ostream &output,Ticket &T1);
	friend istream &operator>>(istream &input,Ticket &T1);
	public:
		void TicketMenu();
	private:
        int flightChoice;
		string TicketType;
		int numberPeople;
		double weight;
		int price;
		int choice;
		Flights allFlights;
		
	
};
#endif
