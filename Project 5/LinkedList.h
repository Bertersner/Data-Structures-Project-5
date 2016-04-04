
// Byron Burdette
// COP2535.0M1



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
												CLASS SPECIFICATION FILE FOR THE CLASS LinkedList
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/





/**********************************************					 PREPROCESSOR DIRECTIVES				**************************************************/
#pragma once															//	include guard ensures this file is included, but only once

#include<iostream>														//	includes the library for standard I/O stream objects
#include<string>														//	includes the library for string types
#include<iomanip>
/**********************************************************************************************************************************************************/


using namespace std;													//	lifts all entities in the standard namespace into the current global namespace



template <class T>														//	template prefex marks the beginning of the template
class LinkedList														//	begins the class declaration
{
protected:
	struct ListNode														//	begins structure ListNode declaration
	{
		T value;														//	holds the data portion of the node
		ListNode* next;													//	holds the address of the next node in the list
		ListNode(T value1, ListNode* next1 = NULL)						//	constructor for initializing a new node in the list.
		{
			value = value1;												//	sets the value of the node
			next = next1;												//	sets the address of the next node in the list. Automatically set to NULL if no address is provided, indicating this node is the last node in the list
		}
	};
	ListNode* head;														//	create a pointer "head" to the first ListNode in the list

public:
	LinkedList() { head = NULL; }										//	constructor sets the pointer "head" to NULL
	void mainMenu();													//	prototype for function which displays the main menu
	char validate(T);													//	prototype for function that validates user input
	void addBeg(T);														//	prototype for function that adds a new ListNode to the beginning of the list
	void addEnd(T);														//	prototype for function that adds a new ListNode to the end of the list
	void removeBeg();													//	prototype for function that removes the first ListNode in the list
	void removeEnd();													//	prototype for function that removes the last ListNode in the list
	void remove(T);														//	prototype for function that removes a specified ListNode from the list
	void displayList() const;											//	prototype for function that displays the values stored in each ListNode
	~LinkedList();														//	desctructor frees up memory allocated during execution
};

/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
											THIS MARKS THE END OF THE CLASS SPECIFICATION FILE
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/

