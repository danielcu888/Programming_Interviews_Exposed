/*
 * LinkedList.hpp
 *
 *  Created on: 29 Aug 2018
 *      Author: danielcumberbatch
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <cstddef>

namespace linkedlist
{
	struct ListElement
	{
		void *data;
		ListElement *next;
	}; // ! struct ListElement

	// Global pointers to terminal nodes that
	// are to be maintained.
	extern ListElement *head;
	extern ListElement *tail;

	// interface function declarations
	bool deleteElement(ListElement *elem);
	bool insertAfter(ListElement *elem, int data);

} // ! namespace linkedlist

#endif /* LINKEDLIST_HPP_ */
