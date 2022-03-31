#include "ABC.h"
#include "node.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
/*This is my .cpp file for my ABC .h file where I implement all of the functions and prototypes defined there. In this file is the constructors, destrcutors, virtual functions, and helper functions for each of the derived classes and base class respectively.
*/
ABC::ABC()
{
	destination = NULL;//destination of hiking, dinner, or zoo name
	length = NULL; //the amount of time the user will spend there
	priority_level = 0; 
	time = NULL;
	guest = NULL;

}
ABC::~ABC()
{
	//deallocating all dynamic memory for this classes data members, destination, length, time, guest
	delete [] destination; 
	delete [] length;
	delete [] time;
	delete [] guest;
}
ABC::ABC(const ABC & source) //this is a copy constructor for the Abstract Base Class
{
	if(source.destination)
	{
		this->destination = new char[strlen(source.destination) + 1];
		strcpy(this->destination, source.destination);
	}
	else	
		destination = NULL;
	if(source.length)
	{
		this->length = new char[strlen(source.length) + 1];
		strcpy(this->length, source.length);
	}
	else
		length = NULL;
	if(source.priority_level)
	{
		priority_level = source.priority_level;
	}
	else
		priority_level = 0;
	
	if(source.time)
	{
		this->time = new char[strlen(source.length) + 1];
		strcpy(this->time, source.length);
	}
	else
		time = NULL;
	
	if(source.guest)
	{
		this->guest = new char[strlen(source.guest) + 1];
		strcpy(this->guest, source.guest);
	}
	else
		guest = NULL;

}
ABC::ABC(char * destination_source, char * length_source, char * time_source, char * guest_source,int priority_level_source) //constructor with arguments performing a deep copy on the data members 
{

		this->destination = new char[strlen(destination_source) + 1];
		strcpy(this->destination, destination_source);

		this->length = new char[strlen(length_source) + 1];
		strcpy(this->length, length_source);
		
		this->time = new char[strlen(time_source)+1];
		strcpy(this->time, time_source);

		this->guest = new char[strlen(guest_source) + 1];
		strcpy(this->guest, guest_source);

		this->priority_level = priority_level_source;
}
int ABC::compare_info(char * key)
{
	if(!destination) return 1;
	return strcmp(key,destination);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dining::Dining(): food_type(0)//initialization list
{}
Dining::~Dining() //destructor
{
	delete [] food_type;
}
Dining::Dining(const Dining & source): ABC(source) //copy construcotr
{
			
		this->food_type = new char[strlen(source.food_type) + 1];
		strcpy(this->food_type, source.food_type);
}

Dining::Dining(char * destination_source, char * length_source, char * time_source, char * guest_source,int priority_level_source, char * food_type_source): ABC(destination_source, length_source, time_source, guest_source, priority_level_source) //constructor with arguments and initialization list to kickstart the copy constructors
{
		this->food_type = new char[strlen(food_type_source) + 1];
		strcpy(this->food_type, food_type_source);
	
}

int Dining::display(char * key)//helper display function
{
	
		cout << "Destination: " << destination << endl;
		cout << "Priority level: " << priority_level << endl;
		cout << "How long you plan to do this activity: " << length << endl;		
		cout << "Time and date to start this activity: " << time << endl;
		cout << "How many guest: " << guest << endl;
		cout << "Type of food: " << food_type << endl;
	
	return 1;
}
void Dining::display_priority()//helper display priority functions
{
	if(priority_level==1)
	{
		cout << "Destination: " << destination << endl;
		cout << "Priority level: " << priority_level << endl;
		cout << "How long you plan to do this activity: " << length << endl;		
		cout << "Time and date to start this activity: " << time << endl;
		cout << "How many guest: " << guest << endl;
		cout << "Type of food: " << food_type << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Zoo::Zoo() : ticket_price(0)//initialization list
{}
Zoo::~Zoo()//destructor
{
	delete [] ticket_price;
}
Zoo::Zoo(const Zoo & source) :ABC(source)//copy constructor
{

	if(source.ticket_price)
	{
		this->ticket_price = new char[strlen(source.ticket_price) + 1];
		strcpy(this->ticket_price, source.ticket_price);
	}
	else
		ticket_price = NULL;

}
Zoo::Zoo(char * destination_source, char * length_source, char * time_source, char * guest_source,int priority_level_source, char * ticket_price_source): ABC(destination_source, length_source, time_source, guest_source,priority_level_source)//constructor with arguments
{
		this->ticket_price = new char[strlen(ticket_price_source) + 1];
		strcpy(this->ticket_price, ticket_price_source);
		
}
int Zoo::display(char * key)//pure virtual helper display function 
{
	if(strcmp(key, destination) ==0)
	{
		cout << "Destination: " << destination << endl;
		cout << "Priority level: " << priority_level << endl;
		cout << "How long you plan to do this activity: " << length << endl;		
		cout << "Time to start this activity: " << time << endl;
		cout << "How many guest: " << guest << endl;
		cout << "Ticket Price: " << ticket_price << endl;
	}
	return 1;
}
void Zoo::display_priority()//pure virtual display priority function
{
	if(priority_level ==1)
	{
		cout << "Destination: " << destination << endl;
		cout << "Priority level: " << priority_level << endl;
		cout << "How long you plan to do this activity: " << length << endl;		
		cout << "Time to start this activity: " << time << endl;
		cout << "How many guest: " << guest << endl;
		cout << "Ticket Price: " << ticket_price << endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Hiking::Hiking(): items_to_bring(0), weather(0) //initialization list
{}
Hiking::~Hiking()//destructor
{
	delete [] items_to_bring;
	delete [] weather;

}
Hiking::Hiking(const Hiking & source) : ABC(source)//copy constructor
{

	if(source.items_to_bring)
	{
		this->items_to_bring = new char[strlen(source.items_to_bring) + 1];
		strcpy(this->items_to_bring, source.items_to_bring);
	}
	else
		items_to_bring = NULL;
	if(source.weather)
	{
		this->weather = new char[strlen(source.weather) + 1];
		strcpy(this->weather, source.weather);
	}
	else
		weather = NULL;

}
Hiking::Hiking(char * destination_source, char * length_source, char * time_source, char * guest_source,int priority_level_source, char * items_to_bring_source, char * weather_source): ABC(destination_source, length_source, time_source, guest_source,priority_level_source)//constructor with arguments to kickstart base class constructor
 
{
		this->items_to_bring = new char[strlen(items_to_bring_source) + 1];
		strcpy(this->items_to_bring, items_to_bring_source);
		
		this->weather = new char[strlen(weather_source) + 1];
		strcpy(this->weather, weather_source);

}
int Hiking::display(char * key)//virutal dispaly function
{
	if(strcmp(key, destination) ==0)
	{
		cout << "Destination: " << destination << endl;
		cout << "Priority level: " << priority_level << endl;
		cout << "How long you plan to do this activity: " << length << endl;		
		cout << "Time to start this activity: " << time << endl;
		cout << "Supplies to bring: " << items_to_bring<< endl;
		cout << "Today's weather: " << weather << "°F" << endl;
	}
	return 1;
}
void Hiking::display_priority()//virutal hlper display priority function
{
	if(priority_level ==1)
	{
		cout << "Destination: " << destination << endl;
		cout << "Priority level: " << priority_level << endl;
		cout << "How long you plan to do this activity: " << length << endl;		
		cout << "Time to start this activity: " << time << endl;
		cout << "Supplies to bring: " << items_to_bring<< endl;
		cout << "Today's weather: " << weather << "°F" << endl;
	}
}
