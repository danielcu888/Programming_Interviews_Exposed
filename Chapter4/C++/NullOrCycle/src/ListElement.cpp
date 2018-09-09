/*
 * ListElement.cpp
 *
 *  Created on: 30 Aug 2018
 *      Author: danielcumberbatch
 */

#include "ListElement.hpp"
#include <stdexcept>

namespace linkedlist
{

	bool isCyclic(ListElement *head)
	{
		if (!head)
		{
			throw std::logic_error("Empty list.");
		}

		ListElement *fast_head = head;

		if (fast_head->next)
		{
			fast_head = fast_head->next->next;
		}
		else
		{
			return false;
		}

		while (fast_head && head != fast_head)
		{
			head = head->next;

			if (head == fast_head)
			{
				break;
			}

			fast_head = fast_head->next;

			if (fast_head->next)
			{
				fast_head = fast_head->next;
			}
		}

		return fast_head;
	}

} // ! namespace linkedlist


