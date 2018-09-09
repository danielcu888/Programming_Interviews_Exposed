/*
 * LinkedList.cpp
 *
 *  Created on: 29 Aug 2018
 *      Author: danielcumberbatch
 */

#include "LinkedList.hpp"

namespace linkedlist
{
	// interface function definitions
	bool deleteElement(ListElement *elem)
	{
		if (!head || !elem)
		{
			return false;
		}

		if (head == elem)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			ListElement *tmp = head;
			while (tmp)
			{
				if (tmp->next == elem)
				{
					tmp->next = tmp->next->next;
					if (tail == elem)
					{
						tail = tmp->next;
					}
					delete elem;
					break;
				}

				tmp = tmp->next;
			}

			if (!tmp)
			{
				return false;
			}
		}

		return true;
	}

	bool insertAfter(ListElement *elem, int data)
	{
		if (!elem)
		{
			if (!head)
			{
				head = tail = new ListElement();
				if (!head)
				{
					return false;
				}

				head->data = (void *)new int(data);
				if (!head->data)
				{
					return false;
				}

				return true;
			}
			else
			{
				ListElement *tmp = new ListElement();
				if (!tmp)
				{
					return false;
				}

				tmp->data = (void *)new int(data);
				if (!tmp->data)
				{
					return false;
				}
				head->next = tmp;

				if (tail == head)
				{
					tail = tmp;
				}

				return true;
			}
		}
		else if (!head)
		{
			return false;
		}
		else
		{
			ListElement *tmp = head;
			while (tmp)
			{
				if (tmp == elem)
				{
					ListElement *tmp2 = new ListElement();
					if (!tmp2)
					{
						return false;
					}

					tmp2->data = (void *)new int(data);
					if (!tmp2->data)
					{
						return false;
					}

					tmp2->next = tmp->next;
					if (tail == tmp->next)
					{
						tail = tail->next;
					}
				}

				tmp = tmp->next;
			}

			if (!tmp)
			{
				return false;
			}
		}

		return true;
	}

} // ! namespace linkedlist



