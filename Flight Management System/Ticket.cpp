#include <iostream>
using namespace std;
#include "Ticket.h"
#include "Flights.h"
ostream &operator<<(ostream &output,Ticket &T1){
	output<<" Your flight is : "<<T1.flightChoice<<" \n Your ticket type is : "<<T1.TicketType<<" \n You are  "<<T1.numberPeople<<" people"
	<<"\n Your cargo weight is : "<<T1.weight<<"\n your total ticket price is : "<<T1.price*T1.numberPeople;
	return output;
	
}
istream &operator>>(istream &input,Ticket &T1){
	input>>T1.flightChoice;
	do {
        input>> T1.choice;
        if (T1.choice < 1 || T1.choice > 3) {
            cout << "\n Please enter a number between 1 and 3!" <<endl;
        }
    } while (T1.choice < 1 || T1.choice > 3);

	
	switch(T1.choice){
		case 1:{
			T1.TicketType = "Economic";
		T1.price = 500;
			break;
		}
		case 2:{
			T1.TicketType = "Business";
		T1.price = 1000;
			break;
		}
		case 3:{
			T1.TicketType = "VIP";
		T1.price = 2000;
			break;
		}
	}
	input>>T1.numberPeople;
	input>>T1.weight;
	Flights F1;
	F1.CargoChange(T1.weight,T1.flightChoice);
	F1.PassengerChange(T1.numberPeople,T1.flightChoice);
	return input;
}
void Ticket::TicketMenu(){
	allFlights.FlightsTicketView();
	cout<<"\n\n Ticket Prices"<<endl<<endl;
	cout<<"   1 - Economic (500)"<<endl;
	cout<<"   2 - Business (1000)"<<endl;
	cout<<"   3 - VIP (2000)"<<endl;
}
 
 
