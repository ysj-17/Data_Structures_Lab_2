// Program Name: Lab2
//
// Description:  
//  Using double linked list operations
//  Insertion sort (switching pointers of list instead of values)
//  And using Binary Search
//
// Author: Jason Yoon
//
// Date: 7/15/2018
//
// IDE Used: Visual Microsoft
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "List.h"
#include "SortingList.h"
#include "BinarySearch.h"


using namespace std;



int main() {


	List<int> objectInt;
	int intInput;
	string FILE_NAME = "Numbers.txt";
	fstream streamInt(FILE_NAME, ios::in);
	
	if (!streamInt) {
		cout << "Error #2: Error opening file. Program aborting." << endl;
		return 0; // Exits main if read wrong
	}

	// Reading the NUBMERS txt file
	string container;
	while (getline(streamInt, container)) { 
		stringstream(container) >> intInput;
		if (objectInt.add(intInput) == false) {
			cout << "Error #3: Error occured in reading the file." << endl;
			break;
		}
	}

	cout << "Number of nodes: " << itemCountList << endl;
	cout << "Double linked list will not be sorted with inseration sort!" << endl;
	objectInt.sortingListNum();
	objectInt.displayList();
	cout << endl << "Sorted listed has been displayed" << endl;

	streamInt.close();
	

	int value = 12;
	if (objectInt.binarySearch(value) == false)
		cout << "Value not present" << endl;
	else
		cout << "The chosen value of \"" << value << "\" is present." << endl;

	objectInt.clear();

	cin.ignore();
	cin.get();

	return 0;
}