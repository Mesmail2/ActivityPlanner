/*This node.cpp is where the implementation of the functions defined in the node.h file are. Below is the implementation of all the member functions in the node.h file respectively, a description of the functions are commented next to them below.*/
#include "node.h"
#include "ABC.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

node::node()//constructor for my node class initializing the data
{
	size = 5;
	previous = NULL;
	next = NULL;
	events_array = new ABC * [size];	
	for(int i=0; i < size; ++i)
		events_array[i] = NULL;	

}
node::~node()//deconstructor for node class to deallocate memory
{
	if(!events_array) return;

	previous = NULL;
	next = NULL;
	for(int i=0; i < size; i++)
		delete events_array[i];
	if(events_array) delete [] events_array;
	events_array = NULL;
}
node *& node::get_next()//function to get the next node
{
	return next;
}
node *& node::get_previous()//function to get the previous node
{
	return previous;

}
void node::set_next(node * new_item)//function to help set the next node
{
	next = new_item;

}
void node::set_previous(node * new_item)//function to help set the previous node
{
	previous = new_item;

}
int node::add_item(ABC *&copy_from, int index)//RTTI to add a new element in our array of base class pointers
{
	ABC * temp = copy_from;

	Hiking * ptr = dynamic_cast<Hiking*>(copy_from);//checking if it's a Hiking element
	if(ptr)
	{
		events_array[index] = new Hiking(*ptr); //if it is add the proper data type and increment the index
		return 1;
	}
	else
	{
		Dining * ptr = dynamic_cast<Dining*>(copy_from);//checking if it's of type Dining 
		if(ptr)
		{
			events_array[index] = new Dining(*ptr);
			return 1;
		}
		else
		{
			Zoo * ptr = dynamic_cast<Zoo*>(copy_from);//checking if it's of type Zoo 
			if(ptr)
			{
				events_array[index] = new Zoo(*ptr);
				return 1;
			}
			
		}
	return 0;
	}
}
int node::display_array()//helper function to display element of the array
{
	if(!events_array) return 0;
	for( int i =0; i < size; i++)
	{
		events_array[i]->display_priority();

	}
	return 1;
}
int node::remove_array(char * key)
{
	if(!events_array) return 0;
	for( int i =0; i < size; i++) //loop through the array in the node
	{
		if(events_array[i]->compare_info(key)==0)//if there's a match, delete the array and the node
		{
			delete events_array[i];
			events_array[i]= NULL;
			return 1;
		}
	}
	return 0;
}
int node::search_array(char * key)//helper function to search through the array
{
	if(!events_array) return 0;
	for( int i =0; i < size; i++) //loop through the array in the node
	{
		if(events_array[i]->compare_info(key)==0)//if there's a match, delete the array and the node
		{
			events_array[i]->display(key);	
			return 1;
		}
	}
	return 1;

}
int node::retrieve_array(char * key, ABC * copy_to)//helper function to retrieve an element in the array
{
	if(!events_array) return 0;
	for( int i =0; i < size; i++)
	{
		if(events_array[i]->compare_info(key)==0)
		{
			Hiking * ptr = dynamic_cast<Hiking*>(events_array[i]);//checking if it's a Hiking element
			if(ptr)
			{
				copy_to = new Hiking(*ptr); //if it is add the proper data type and increment the index
				return 1;
			}
			else
			{
				Dining * ptr = dynamic_cast<Dining*>(events_array[i]);//checking if it's of type Dining 
				if(ptr)
				{
					copy_to = new Dining(*ptr);
					return 1;
				}
				else
				{
					Zoo * ptr = dynamic_cast<Zoo*>(events_array[i]);//checking if it's of type Zoo 
					if(ptr)
					{
						copy_to = new Zoo(*ptr);
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
DLL::DLL()// constructor for Doubly Linked List
{	
	head = NULL;
	top_index =0;
}
DLL::~DLL()//destructor for DLL
{
	delete head;
	head = NULL;
}
int DLL::create_event(ABC *&copy_from)//function to create an event 
{
	return create_event(copy_from, head);//calling recursive function

}
int DLL::create_event(ABC *&copy_from,node *&head)//recurisve function to add an event 
{
	if(!head)//if the list is empty create a new node and allocate memory for the array 
	{
		head = new node;
		head->add_item(copy_from, top_index); //calling function to save the data
		top_index = 1;
		return 1;
	}
	else if(top_index == MAX)
	{
		node * temp = new node;
		temp->get_next() = head;
		head = temp;
		head->add_item(copy_from, top_index); //some function call
		top_index ++;
		return 1;
	}
	else
	{
		head->add_item(copy_from, top_index); //some function call;
		top_index++;
		return 1;
	}
	return create_event(copy_from, head->get_next());
}
int DLL::search_priority()//wrapper function to display the elements that have the highest priority
{
	if(!head) return 0;
	return search_priority(head);
}
int DLL::search_priority(node * head)//recurisve function to display the elements that have the highest priority
{
	if(!head) return 0;

	head->display_array();

	return search_priority(head->get_next());
}
int DLL::display_specific(char * key)//wrapper function to display a specific event
{
	if(!head) return 0;
	return display_specific(key, head);
}
int DLL::display_specific(char * key, node *head)//wrapper function to display a specific event
{
	if(!head) return 0;
	head->search_array(key);
	
	return display_specific(key, head->get_next());
}
int DLL::remove_event(char * key)//wrapper function to remove a specific event
{
	if(!head) return 0;
	return remove_event(key, head);
}
int DLL::remove_event(char * key, node *&head)//recursive function to remove a specific event
{
	if(!head)return 0;
	if(head->remove_array(key)==1)//if successful, decrement top index
		--top_index;
	return remove_event(key, head->get_next());

}
int DLL::remove_all()//wrapper remove all function
{
	if(!head) return 0;
	return remove_all(head);

}
int DLL::remove_all(node *&head)//recursive remove all function
{
	if(!head) return 0;
	remove_all(head->get_next());
	delete head;
	head = NULL;
	return 1; 
}
int DLL::retrieve(char * key, ABC * copy_to)//wrapper retriever function
{
	if(!head) return 0;
	return retrieve(key, copy_to, head);
}
int DLL::retrieve(char * key, ABC * copy_to, node *&head)//recurisve retreive function
{
	if(!head) return 0;
	head->retrieve_array(key, copy_to);
	return retrieve(key,copy_to,head->get_next());
}
