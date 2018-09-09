/*
 * LinkedList.cpp
 *
 *  Created on: 29 Aug 2018
 *      Author: danielcumberbatch
 */

#include "LinkedList.hpp"

namespace linkedlist
{

	bool mthToLastElement(ListElement *head, std::size_t m, ListElement **elem)
	{
		if (!head || !elem)
		{
			return false;
		}

		*elem = nullptr;

		ListElement *tmp = head;
		for (int i = 0; tmp && i < m; ++i)
		{
			tmp = tmp->next;
		}

		if (!tmp)
		{
			return false;
		}

		while (tmp)
		{
			head = head->next;
			tmp = tmp->next;
		}

		*elem = tmp;

		return true;
	}

} // ! namespace linkedlist


