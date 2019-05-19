#ifndef LAB3_LIST
#define LAB3_LIST
#include <string>


template <class T>
class Node
{
public:
	T  item;
	Node *prev;
	Node *next;
	Node *head;
	Node *tail;
};

int itemCountList = 0;

template <class T> class ListInterface : public Node<T>
{
public:

	virtual bool isEmpty() { return true; }
	virtual bool add(T newEntry) { return true; }
	virtual bool remove(T anEntry) { return true; }
	virtual void clear() { cout << "Error in ListInterface Class"; }
	virtual bool search(T anEntry) { return true; }
	virtual bool displayList() { return true; }
	virtual void sortingList() {}
};



template <class T> class List : public ListInterface<T>
{
private:
	using Node<T>::head;
	using Node<T>::tail;


public:
	List() { head = nullptr; tail = nullptr; }

//--New functions (Lab 3) ------------------

	// Using structure of old display function
	int sizeOfList();


//--Old functions (Lab 2) ------------------
	void sortingListNum();
	void sortingListString();
	bool binarySearch(T value);
//--Older functions (Lab 1) ------------------	
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else { return false; }
	}


	bool add(T newEntry) {
		Node<T> *newNode = new Node<T>;
		newNode->item = newEntry;
		newNode->head = NULL;
		newNode->tail = NULL;

		if (isEmpty() == true) {
			head = newNode;
			tail = newNode;
			itemCountList++;
		}
		else {
			newNode->next = tail;
			tail->prev = newNode;
			tail = newNode;
			tail->prev = NULL;
			itemCountList++;
		}

		return true;
	}

	bool remove(T anEntry) {
		if (isEmpty() == true) {
			cout << "The list is empty!" << endl;
			return false;
		}
		else {
			if (isEmpty() == false) {
				Node<T> *rover = head;
				Node<T> *nodePtr = rover->prev;
				while (nodePtr != tail) { // Rover goes until it hits the end of the list
					if (nodePtr->item == anEntry) {
						rover->prev = nodePtr->prev;
						delete nodePtr;
						itemCountList--;
						return true;
					}
					else nodePtr = nodePtr->prev; // Setting rover to the previous
				}
				return false;
			}
		}
		cout << "Error #1 has Occured: Remove function" << endl;
		return false;
	}

	void clear() {
		Node<T> *nodePtr = head;
		Node<T> *n;
		while (nodePtr != tail) {
			n = nodePtr->prev;
			delete nodePtr; // delete Dynamic memory
			nodePtr = n;
			itemCountList--;
		}
		head = nullptr; // point head to null 
		cout << "List has been cleared!" << endl;
	}



	bool search(T anEntry) {
		// Rover will go through the list one by one
		Node<T> *rover = head;
		while (rover != tail) { // Rover goes until it hits the end of the list
			if (rover->item == anEntry)
				return true;
			// Setting rover to the previous
			else rover = rover->prev;
		}

		return false;
	}


	bool displayList()
	{
		//// Rover will go through the list one by one
		Node<T> *rover = head;
		if (isEmpty() == true) {
			return false;
		}
		else {
			while (rover != NULL) // Rover goes until it hits the end of the list
			{
				cout << rover->item;
				cout << endl;
				// Setting rover to the previous
				rover = rover->prev;
			}
			// cout << tail->item;
			return true;
		}
	}


	
};


template<class T>
int List<T>:: sizeOfList() {
	int counter = 0;
	// Rover will go through the list one by one
	Node<T> *rover = head;
	if (isEmpty() == true) {
		return 0;
	}
	else {
		while (rover != NULL) // Rover goes until it hits the end of the list
		{
			cout << rover->item;
			cout << endl;
			// Setting rover to the previous
			rover = rover->prev;
			counter++;
		}

		return counter;
	}
}


#endif