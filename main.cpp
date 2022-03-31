#include "node.h"
#include "ABC.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
/*My name is Mohamed Esmail and In this main.cpp file is where I test the implementation of the functions I have created in the .h and.cpp files. Below is a menu user interface to help the user decide what they want to do and plan their future activites after the Stay home mandate has been lifted. */

int main()
{
	int SIZE = 100;
	bool running = true;
	DLL my_list;
	while(running)
	{
		int main_choice;
		
		cout << "Welcome to the event planner where we are planning the activities to do after quarentine is over. \n Enter 1 for Dining activities \n Enter 2 for Hiking activities \n Enter 3 for Zoo activities" << endl;
		cin>>main_choice;
		cin.ignore(100, '\n');

		if(main_choice ==0)
			running = false;
		else if(main_choice == 1) //prompt the user for the Dining activities		
		{
			//defining the proper variables to take in the input from the user
			int dining_choice = 0;
			char destination_source[SIZE];//creating variable for restaurant name
			char length_source[SIZE];//variable for the amount of time this activity will take
			char time_source[SIZE];//date and time variable
			int priority_level_source;//pirioty level
			char guest_source[SIZE];//number of guests
			char food_type_source[SIZE];//type of food at this restaurant
			
			//prompting the user for options to add, remove, display, or retrieve
			cout << "\n Enter 1 to add a new Dining activity\n Enter 2 to remove an existing activity by restaurant name \n Enter 3 to display a specific restaurant by name \n Enter 4 to display all high priority level activities \n Enter 5 to remove all activities \n Enter 6 to retrieve by restaurant name" << endl;
			cin>>dining_choice;
			cin.ignore(100, '\n');

			if(dining_choice == 1)
			{
				cout << "Please enter the name of the restaurant\n" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "How long will this dinner take? Enter the amount of time\n" << endl; 
				cin.get(length_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "Please enter the date and time this will take place" << endl;
				cin.get(time_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "What is the priority level of this activity? Between 1 and 5. 1 being highest priority, 5 being lowest." << endl;
				cin >> priority_level_source;
				cin.ignore(SIZE, '\n');

				cout << "How many guests will be with you?" << endl;
				cin.get(guest_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
		
				cout << "What kind of food does this restaurant serve" << endl;
				cin.get(food_type_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				ABC * temp = new Dining(destination_source, length_source, time_source, guest_source, priority_level_source, food_type_source); 
				my_list.create_event(temp);
			}
			else if(dining_choice ==2)
			{
				cout << "Please enter the name of the restaurant you want to remove \n" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				my_list.remove_event(destination_source);
			}
			else if(dining_choice==3)
			{
				cout << "\nPlease enter the name of the restaurant you'd like to display \n" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				my_list.display_specific(destination_source);
			}
			else if(dining_choice==4)
			{
				cout << "\nWe are now displaying all highest priority dining activities" << endl;
				
				my_list.search_priority();


			}
			else if(dining_choice==5)
			{
				cout << "\nWe will now remove all dining activities" << endl;

				my_list.remove_all();

			}
			else if(dining_choice==6)
			{
				cout << "\nPlease enter the name of the restuarant you'd like to retrieve" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				ABC * copy_to;
				if(my_list.retrieve(destination_source, copy_to) ==1)
					cout << "\nWe've successfuly retrieved this activity" << endl;
	
				else
					cout << "\nThis restaurant does not exist in your list" << endl;
			}
		}
		else if(main_choice==2)//hiking choice
		{
			
			int hiking_choice = 0;
			char destination_source[SIZE];
			char length_source[SIZE];
			char time_source[SIZE];
			int priority_level_source;
			char guest_source[SIZE];
			char items_to_bring_source[SIZE];
			char weather_source[SIZE];
			//prompting for add,remove,display, retrieve options
			cout << "\nPlease enter 1 to add a new Hiking activity \n Enter 2 to remove a specific Hiking activity by destination \n Enter 3 to remove all Hiking activites \n Enter 4 to display a specific Hiking activity \n Enter 5 to display highest priority activites \n Enter 6 to retrieve an activity by hiking destination " << endl;

			cin >> hiking_choice; 
			cin.ignore(100, '\n');

			if(hiking_choice ==1)
			{

				cout << "\nPlease enter the name of the hiking destination\n" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "\nHow long will this hike take? Enter the amount of time\n" << endl; 
				cin.get(length_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "\nPlease enter the date and time this will take place" << endl;
				cin.get(time_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "\nWhat is the priority level of this activity? Between 1 and 5. 1 being highest priority, 5 being lowest." << endl;
				cin >> priority_level_source;
				cin.ignore(SIZE, '\n');

				cout << "\nHow many guests will be with you?" << endl;
				cin.get(guest_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
		
				cout << "\nEnter the supplies you will need for this hike" << endl;
				cin.get(items_to_bring_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "\nEnter the weather for this day" << endl;
				cin.get(weather_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				ABC * temp = new Hiking(destination_source, length_source, time_source, guest_source, priority_level_source, items_to_bring_source, weather_source); 

				my_list.create_event(temp);

			}
			else if(hiking_choice ==2)
			{
				cout << "\nPlease enter the name of the destination you'd like to search for and remove" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				my_list.remove_event(destination_source);

			}
			else if(hiking_choice ==3)
			{
				cout << "\nWe will now remove all hiking activites" << endl;
				
				my_list.remove_all();
			}
			else if(hiking_choice ==4)
			{
				cout << "\nEnter the name of the hiking destination you'd like to display" << endl;

				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				my_list.display_specific(destination_source);
			}
			else if(hiking_choice ==5)
			{
				cout << "\nWe are now displaying all highest priority hiking events" << endl;
				my_list.search_priority();
			}
			else if(hiking_choice ==6)
			{
				
				cout << "\nPlease enter the name of the destination you'd like to retrieve" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				ABC * copy_to;
				if(my_list.retrieve(destination_source, copy_to) ==1)
					cout << "\nWe've successfuly retrieved this activity" << endl;
	
				else
					cout << "\nThis hiking destination does not exist in your list" << endl;
			}
		}
		else if(main_choice ==3)
		{
			//zoo option
			int zoo_choice = 0;
			char destination_source[SIZE];
			char length_source[SIZE];
			char time_source[SIZE];
			int priority_level_source;
			char guest_source[SIZE];
			char ticket_price_source[SIZE];
			//prompting the user for their options
			cout << "\nPlease enter 1 to add a new Zoo activity \n Enter 2 to remove a specific Zoo activity by destination \n Enter 3 to remove all Zoo activites \n Enter 4 to display a specific Zoo activity \n Enter 5 to display highest priority activites \n Enter 6 to retrieve an activity by zoo destination " << endl;
			cin>>zoo_choice;

			if(zoo_choice ==1)
			{

				cout << "\nPlease enter the name of the Zoo\n" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "\nHow long will you be at the zoo\n" << endl; 
				cin.get(length_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "\nPlease enter the date and time this will take place" << endl;
				cin.get(time_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "\nWhat is the priority level of this activity? Between 1 and 5. 1 being highest priority, 5 being lowest." << endl;
				cin >> priority_level_source;
				cin.ignore(SIZE, '\n');

				cout << "\nHow many guests will be with you?" << endl;
				cin.get(guest_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
		
				cout << "\nEnter the ticket price " << endl;
				cin.get(ticket_price_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				ABC * temp = new Zoo(destination_source, length_source, time_source, guest_source, priority_level_source, ticket_price_source); 

				my_list.create_event(temp);

			}
			else if(zoo_choice ==2)
			{
				cout << "\nPlease enter the name of the Zoo you'd like to search for and remove" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				my_list.remove_event(destination_source);

			}
			else if(zoo_choice ==3)
			{
				cout << "\nWe will now remove all Zoo activites" << endl;
				
				my_list.remove_all();
			}
			else if(zoo_choice ==4)
			{
				cout << "\nEnter the name of the Zoo destination you'd like to display" << endl;

				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				my_list.display_specific(destination_source);
			}
			else if(zoo_choice ==5)
			{
				cout << "\nWe are now displaying all highest priority hiking events" << endl;
				my_list.search_priority();
			}
			else if(zoo_choice ==6)
			{
				
				cout << "\nPlease enter the name of the destination you'd like to retrieve" << endl;
				cin.get(destination_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				ABC * copy_to;
				if(my_list.retrieve(destination_source, copy_to) ==1)
					cout << "\nWe've successfuly retrieved this activity" << endl;
	
				else
					cout << "\nThis hiking destination does not exist in your list" << endl;
			}
		}

	}
	
}	
