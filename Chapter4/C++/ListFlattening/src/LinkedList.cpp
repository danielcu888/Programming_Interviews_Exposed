/*
 * LinkedList.cpp
 *
 *  Created on: 29 Aug 2018
 *      Author: danielcumberbatch
 */

#include "LinkedList.hpp"
#include <iostream>
#include <deque>

namespace linkedlist
{

	bool flatten(ListElement *head, ListElement **tail)
	{
		if (!head || !tail || !*tail)
		{
			return false;
		}

		while (head)
		{
			if (head->child)
			{
				(*tail)->next = head->child;
				(*tail)->next->prev = *tail;
				while ((*tail)->next)
				{
					*tail = (*tail)->next;
				}
			}

			head = head->next;
		}

		return true;
	}

	void print(ListElement *head, bool printChildren)
	{
		if (head)
		{
			std::cout << head->data << " ";
			if (printChildren)
			{
				print(head->child, printChildren);
			}
			print(head->next, printChildren);
		}
	}

	bool unflatten(ListElement *head, ListElement **tail)
	{
		if (!head || !tail || !*tail)
		{
			return false;
		}

		while (head)
		{
			if (head->child)
			{
				if (head->child->prev)
				{
					head->child->prev->next = nullptr;
					head->child->prev = nullptr;
				}

				if (!unflatten(head->child, tail))
				{
					return false;
				}
			}

			if (!head->next)
			{
				*tail = head;
			}

			head = head->next;
		}

		return true;
	}

} // ! namespace linkedlist


