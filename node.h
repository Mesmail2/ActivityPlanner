/*
this is my node.h file where I am defining the prototypes to be implemented in the .cpp file. Below are the node and DLL classes. The node class will manage the nodes in my Doubly Linked list, and the DLL class will manage the list of nodes. They both have their respective constructors and destructors. Along with the proper data members and functions to help them manage their data.

*/
#include <iostream>
#include <cctype>
#include <cstring>
#include "ABC.h"
#ifndef NODE_H
#define NODE_H
using namespace std;

class node //node class definition
{
	public:
		node();//constructor
		~node();//destructor
		node *& get_next();//function to get the next node
		node *& get_previous();//function to get the previous node
		void set_next(node * new_item);//function to set the next node
		void set_previous(node * new_item);//function to set the previous node
		int add_item(ABC *&copy_from, int index);//wrapper function for RTTI adding
		int search_array(char * key);
		int retrieve_array(char * key, ABC * copy_to);
		int display_array();
		int remove_array(char * key);
	private:
		node * next; //next pointer for our DLL
		node * previous;//previous pointer for our DLL
		ABC ** events_array;//each node will have an array of base class pointers
		int size;//size of the array	
		int items;//index for the array
};

class DLL
{
	public:
	
		DLL();//constructor for the DLL
		~DLL();//destructor for our DLL
		int create_event(ABC *&copy_from);//wrapper to create an event
		int remove_event(char *key);//wrapper to remove a specific event
		int search_priority();//wrapper to display priority
		int display_specific(char * key);//wrapper to display a specific element
		int remove_all();//wrapper to remove all nodes
	 	int retrieve(char * key, ABC * copy_to);	
	private:
		node * head;//head pointer for our DLL
		int top_index;//index
		int MAX;//maximum size for the array
		int create_event(ABC *&copy_from, node *&head);//recurisve create event function
		int remove_event(char * key, node *&head); //recursive remove function
		int display_specific(char * key, node *head);//recursive display specific function
		int search_priority(node *head);//recurisve display priority level function
		int remove_all(node *&head);//recursive remove all funciton
		int retrieve(char * key, ABC * copy_to, node *&head);	

};
#endif 
