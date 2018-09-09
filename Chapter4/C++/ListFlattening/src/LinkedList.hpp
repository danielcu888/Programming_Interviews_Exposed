/*
 * LinkedList.hpp
 *
 *  Created on: 29 Aug 2018
 *      Author: danielcumberbatch
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <memory>

namespace linkedlist
{
	struct ListElement
	{
		ListElement( int data
				   , ListElement *prev = nullptr
				   , ListElement *next = nullptr
				   , ListElement *child = nullptr
				   )
			: data(data)
			, prev(prev)
			, next(next)
			, child(child)
		{}

		int data;
		ListElement *prev;
		ListElement *next;
		ListElement *child;

	}; // ! struct ListElement

	bool flatten(ListElement *head, ListElement **tail);
	bool unflatten(ListElement *head, ListElement **tail);

	void print(ListElement *head, bool printChildren);

} // ! namespace linkedlist



#endif /* LINKEDLIST_HPP_ */
