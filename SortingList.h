#ifndef LAB2_LIST_SORTING_LIST
#define LAB2_LIST_SORTING_LIST
#include "List.h"



template<class T>
void List<T>::sortingListNum() {
	int count = 0;
	Node<T> *startNode = head; // Only use for count
	Node<T> *currentNode = NULL;
	Node<T> *trailNode = NULL;
	Node<T> *tempNode = NULL;


	while (startNode != tail->prev) { // Gets count of list
		count++;
		startNode = startNode->prev;
	}


	for (int index = 0; index < count; ++index) { // Main loop for every element

		currentNode = trailNode = head; //set currentNode and trailNode at the start node

		while (currentNode->prev != NULL) { // 2nd loop for rest of elements
											//compare currentNode and currentNode->prev;
			if (currentNode->item > currentNode->prev->item) {
				// Swaps pointers if conditions met
				tempNode = currentNode->prev;
				currentNode->prev = currentNode->prev->prev;
				tempNode->prev = currentNode;

				// now we need to setup pointers for trailNode and possibly head
				// this is the case of the first element 
				// swapping to preserve the head pointer
				if (currentNode == head)
					head = trailNode = tempNode;
				else // Sets trailNode prev to point to temp
					trailNode->prev = tempNode; // Keep in mind tailNode = head
												// Need to update currentNode to be temp since the positions changed
				currentNode = tempNode;
			}
			// The trailNode always holds the "reference" pointer
			trailNode = currentNode;
			// Keep in mind currentNode->prev refers to the prior ->prev->prev
			currentNode = currentNode->prev;
		}
	}
}




// Added second function to compare string types of data
template<class T>
void List<T>::sortingListString() {
	int count = 0;
	Node<T> *startNode = head; // Only use for count
	Node<T> *currentNode = NULL;
	Node<T> *trailNode = NULL;
	Node<T> *tempNode = NULL;


	while (startNode != tail->prev) { // Gets count of list
		count++;
		startNode = startNode->prev;
	}


	for (int index = 0; index < count; ++index) { // Main loop for every element

		currentNode = trailNode = head; //set currentNode and trailNode at the start node

		while (currentNode->prev != NULL) { // 2nd loop for rest of elements
											//compare currentNode and currentNode->prev;

			// This is the special condition to alphabetize the list
			if (currentNode->item.compare(currentNode->prev->item) > 0) {
				// Swaps pointers if conditions met
				tempNode = currentNode->prev;
				currentNode->prev = currentNode->prev->prev;
				tempNode->prev = currentNode;

				// now we need to setup pointers for trailNode and possibly head
				// this is the case of the first element 
				// swapping to preserve the head pointer
				if (currentNode == head)
					head = trailNode = tempNode;
				else // Sets trailNode prev to point to temp
					trailNode->prev = tempNode; // Keep in mind tailNode = head
												// Need to update currentNode to be temp since the positions changed
				currentNode = tempNode;
			}
			// The trailNode always holds the "reference" pointer
			trailNode = currentNode;
			// Keep in mind currentNode->prev refers to the prior ->prev->prev
			currentNode = currentNode->prev;
		}
	}

	itemCountList = count;
}








#endif