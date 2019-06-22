#include <iostream>
#include "IntList.h"
using namespace std;


IntList::IntList(){									//: Initializes an empty list with dummy head and dummy tail.
	dummyHead = NULL;
	dummyTail = NULL;
}


IntList::~IntList(){ 								//: Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
	delete dummyHead;
	delete dummyTail;
}


void IntList::push_front(int value){ 				//: Inserts a data value (within a new node) at the front end of the list. This must be an O(1) operation.
	IntNode* newNode = new IntNode(value);

	if (dummyHead==NULL){							// if the list is empty
		dummyHead = new IntNode(0);					// creates a node for dummyHead (prevent segmentation error)
		dummyHead->next = newNode;
		dummyHead->prev = newNode;
	 	dummyTail = new IntNode(0);					// creates a node for dummyTail (no segmentation error)
		dummyTail->next = newNode;
		dummyTail->prev = newNode;
	}
	else {											// if list != empty
		newNode->next = dummyHead->next;			// connect new nodes next to head
		newNode->prev = dummyTail->next;			// connect new node's back to tail
		dummyHead->next->prev = newNode;			// set head to point backwards to newnode
		dummyTail->next->next = newNode;			// set tail to point forward to new node
		dummyHead->next = newNode;					// set the new node as head
	}
	return;
}


void IntList::push_back(int value){					//: Inserts a data value (within a new node) at the back end of the list. This must be an O(1) operation.
	IntNode* newNode = new IntNode(value);
	
	if (dummyHead == NULL){							// if the list is empty
		dummyHead = new IntNode(0);					// creates a node for dummyHead (prevent segmentation error)
		dummyHead->next = newNode;
		dummyHead->prev = newNode;
	 	dummyTail = new IntNode(0);					// creates a node for dummyTail (no segmentation error)
		dummyTail->next = newNode;
		dummyTail->prev = newNode;
	} 
	else { 
		newNode->next = dummyHead->next;			// set newnode->next to	head (connect new node to head)
		newNode->prev = dummyTail->next;			// set newnode->prev to tail  (connect new node to tail)
		dummyHead->next->prev = newNode;			// set head->prev to new node (connect back of head to new node)
		dummyTail->next->next = newNode;			// set tail to point forward to new node
		dummyTail->next = newNode;					// make the new node the tail
	}
	return; 
}


void IntList::pop_front(){ 									//: Removes the node at the front end of the list (the node after the dummy head). Does nothing if the list is already empty. This must be an O(1) operation.
	if (dummyHead!=NULL){
		IntNode* afterHead = dummyHead->next->next;			// temporarily let afterHead be the node after the head node
		dummyTail->next->next = afterHead;					// Sets the tail to point to the node after the head
		afterHead->prev = dummyTail->next;					// Sets the node after head to point backwards to tail
		dummyHead->next = afterHead;						// Sets head to node after head
	}
	return;
}


void IntList::pop_back(){									//: Removes the node at the back end of the list (the node before the dummy tail). Does nothing if the list is already empty. This must be an O(1) operation.
	if (dummyHead!=NULL){
		IntNode* beforeTail = dummyTail->next->prev;		// Temporarily let beforeTail be the node before the tail
		beforeTail->next = dummyHead->next;					// Disconnects the tail from the back 
		dummyHead->next->prev = beforeTail;					// Disconnects the tail from the head
		dummyTail->next = beforeTail;						// Sets tail to node before old tail
	}
	return;
}


void IntList::deleteChosen(){									//: Removes the node at the back end of the list (the node before the dummy tail). Does nothing if the list is already empty. This must be an O(1) operation.
		beforeChosen->next = afterChosen;					// Disconnects the tail from the back 
		afterChosen->prev = beforeChosen;					// Disconnects the tail from the head
		chosenOne = afterChosen;
		afterChosen = chosenOne->next;
	return;
}

bool IntList::empty() const { 								//: Returns true if the list does not store any data values (it only has dummy head and dummy tail), otherwise returns false.
	if (dummyHead==NULL)
		return true;
	return false;
}


ostream & operator<<(ostream &out, const IntList &rhs){ 	//: A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. This function does NOT send to the stream a newline or space at the end.
	if (rhs.dummyHead!=NULL){								// If the list is not empty
		IntNode* curr = rhs.dummyHead->next;				// Node used to traverse the list
		while (curr->next!=rhs.dummyHead->next){			// while the traversing node is not the last item on the list
			out << curr->data << " ";
			curr = curr->next;
		}
		out << curr->data;									// If the traversing node is the last item on the list don't send a space to the output buffer
	}
	return out;
}


void IntList::printReverse() const{							//: prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space. This function does NOT output a newline or space at the end.
	if (dummyTail->next!=NULL){								// If the lsit is not empty
		IntNode* curr = dummyTail->next;					// Node set to tail to traverse the list backwards
		while (curr->prev!=dummyTail->next){				// While the node is not the head (first item o the list ot last when traversing backwards)
			cout << curr->data << " ";
			curr = curr->prev;
		}
		cout << curr->data;									// If the traversing node is the last item on the list, cout without a ending whitspace 
	}
	return;
}