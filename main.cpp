#include <iostream>
#include <iomanip>
#include "IntList.h"
using namespace std;

//Credits to Assigment 2 IntList class upgraded and reused

int main()
{
	double numPeople, startPt, numSkip;
	char direction;
	int survivor = -1;
	IntList IslandSurvivors;
	

	cout << "How many people are on the island?" << endl;													// Ask for the number of people on the island
	cin >> numPeople;
	while (numPeople<1){																					
		cout << "The island cannot be uninhabited, Please enter a valid number." << endl;
		cin >> numPeople;
	}

	for (int i = 1; i <= numPeople; i++){																	// Create the list of people
		IslandSurvivors.push_back(i);	
	}
	IslandSurvivors.chosenOne = IslandSurvivors.dummyHead->next;

	cout << "What is the starting position?" << endl;														// Ask for starting postion of the countdown
	cin >> startPt;
	
	while (!(startPt > 0 && startPt <= numPeople)){
		cout << "Please enter a valid starting position (Between 1 and " << numPeople << ".)" << endl;
		cin >> startPt;
	}

	double counter = startPt;
	counter--;

	while (counter>0){																						// Set current position to user indicated starting postition
		IslandSurvivors.chosenOne = IslandSurvivors.chosenOne->next;
		counter--;
	}

	cout << "Enter the number of people to be skipped as we go around. (2 means every 2nd person is voted off the island)" << endl;		// Ask for # of people to be skipped
	cin >> numSkip;
	while (numSkip<2){
		cout << "Please enter a number greater than 1" << endl;
		cin >> numSkip;
	}

	cout << "Enter the direction we will go in. (Enter '+' to go right or '-' to go left.)" << endl;	 	// Ask for direction of countdown
	cin >> direction;
	while (direction!='+' && direction!='-'){
		cout << "Please enter a valid direction. Enter '+' to go right or '-' to go left." << endl;
		cin >> direction;
	}

	double numLeft = numPeople;																				// Set counter to check when there is only one person left on the island
	double skipCounter = numSkip - 1;																		// Set skipcounter to user entered number - 1 b/c if user entered 2, it means you have to traverse once to get to the node(person) you want to delete.
    while (numLeft > 1){																					// While loop to check for wne there is only one person left on the island
    	if (direction=='+'){																				// If we are counting up/ going in the positive right direction
    		while (skipCounter > 0){																		// Checks when we are done traversinf the lsit to the node/person we want to send away
				IslandSurvivors.beforeChosen = IslandSurvivors.chosenOne;									// keeps track of the node before the node we want to delete (makes it easier to delete the node later)
				IslandSurvivors.chosenOne = IslandSurvivors.chosenOne->next;								// main traversing node
				IslandSurvivors.afterChosen = IslandSurvivors.chosenOne->next;								// keeps track of the node after the node we want to delete (makes it easier to delete the node later)
				skipCounter--;
    		}
    		cout << IslandSurvivors.chosenOne->data << " ";													// Shows who/what is being deleted after each loop iteration
    		IslandSurvivors.deleteChosen();																	// Function call to delete the node
    		numLeft--;																						// Number of people decrease after delete function is called
			skipCounter = numSkip - 1;																		// Resets counter
		}
		else {																						
			while (skipCounter > 0){																		// same as if statement above, but in the left direction.
				IslandSurvivors.afterChosen = IslandSurvivors.chosenOne;
				IslandSurvivors.chosenOne = IslandSurvivors.chosenOne->prev;
				IslandSurvivors.beforeChosen = IslandSurvivors.chosenOne->prev;
				skipCounter--;
			}
	   		cout << IslandSurvivors.chosenOne->data << " ";
			IslandSurvivors.deleteChosen();
			IslandSurvivors.chosenOne = IslandSurvivors.chosenOne->prev;
			IslandSurvivors.beforeChosen = IslandSurvivors.chosenOne->prev;
			numLeft--;
			skipCounter = numSkip - 1;
		}
	}



	string fullDir;
	if (direction=='+')
		fullDir = "Right";
	else 
		fullDir = "Left";
	
	survivor = IslandSurvivors.chosenOne->data;

	cout << endl;
	cout << left << setw(27) << "Number of people at start: " << numPeople  << endl;
	cout << left << setw(27) <<  "Starting postion: " << startPt << endl;
	cout << left << setw(27) << "Number of people skipped: " << numSkip << endl;
	cout << left << setw(27) << "Direction went: " << fullDir << endl;
	cout << left << setw(27) << "Survivor #: " << survivor << endl;

}



