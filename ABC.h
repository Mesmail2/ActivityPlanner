/*This is my ABC.h file where I am defining the prototypes that need to be implmeneted in the .cpp file. Below are the abstract base class, and derived classes like hiking, zoo, and dinging. All classes have thie constructors, destructors, and proper data members and functions to help manage their respective data.
*/
#include <iostream>
#include <cctype>
#include <cstring>
#ifndef ABC_H
#define ABC_H
using namespace std;

class ABC//Abstract Base class for the events derived classes that contain the common data elements
{
	public: //public functions
		ABC();//constructor
		virtual	~ABC();//destructor
		ABC(const ABC & source);//copy constructor since we have 
		ABC(char * destination_source, char * length_source, char * time_source, char * guest_source, int priority_level_source);
		virtual int display(char * key) =0;
		virtual void display_priority()=0;
		int compare_info(char * key);

	protected:	//protected data memebers, these are the common data members all of the derived classes have
		char * destination;//destination of hiking, dinner, or zoo name
		char * length;//the amount of time the user will spend there
		char * time;	
		int priority_level;//the priority level
		char * guest;

};

class Dining: public ABC//dinner class
{
	public: //public member functions
		Dining();//constructor
		~Dining();//destructor
		Dining(const Dining & source);//copy constructor for the dynamic memory
		Dining(char * destination_source, char * length_source, char * time_source, char * guest_source,int priority_level_source, char * food_type_source);
		int display(char * key);//pure virtual display function
		void display_priority();//pure virutal dipslay function
	private:
		char * food_type;
};

class Zoo: public ABC//zoo class
{
	public://public member functions

		Zoo();//constructor
		~Zoo();//destructor
		Zoo(const Zoo & source);
		Zoo(char * destination_source, char * length_source, char * time_source, char * guest_source,int priority_level_source, char * ticket_price_source); 
		int display(char * key);
		void display_priority();
	private:
		char * ticket_price;		
		
};

class Hiking: public ABC//Hiking class
{
	public:
		Hiking();//constrcutor
		~Hiking();//destructor
		Hiking(const Hiking & source);//copy constructor
		Hiking(char * destination_source, char * length_source, char * time_source, char * guest_source,int priority_level_source, char * items_to_bring_source, char * weather_source);//constructor with arguments
		int display(char * key);//pure virutal display function
		void display_priority();//pure virutal display priority function
	private:
		char * items_to_bring; //data memebers, supplies to bring and the weather for that day
		char * weather;
};
#endif
