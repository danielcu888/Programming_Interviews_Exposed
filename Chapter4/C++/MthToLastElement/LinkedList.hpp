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

	bool mthToLastElement(ListElement *head, std::size_t m, ListElement *elem);

} // ! namespace linkedlist


#endif /* LINKEDLIST_HPP_ */
