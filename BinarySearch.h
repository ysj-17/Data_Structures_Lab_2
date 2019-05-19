#ifndef LAB2_LIST_SEARCH
#define LAB2_LIST_SEARCH
#include "List.h"


template<class T>
bool List<T>::binarySearch(T value) {

	Node<T> *start = head;
	Node<T> *last = NULL;

	do
	{
		// Find middle
		if (head == NULL)
			return NULL;

		Node<T> *firstContainer = start;
		Node<T> *secondContainer = start->prev;

		while (secondContainer != last)
		{
			secondContainer = secondContainer->prev;
			if (secondContainer != last)
			{
				firstContainer = firstContainer->prev;
				secondContainer = secondContainer->prev;
			}
		}

		Node<T> *middle = firstContainer;

		// If middle is empty
		if (middle == NULL)
			return false;

		// If value is present at middle
		if (middle->item == value)
			return true;

		// If value is more than mid
		else if (middle->item < value)
			start = middle->prev;

		// If value is less than mid.
		else
			last = middle;

	} while (last == NULL ||
		last->prev != start);

	// value not present
	return false;
}


#endif