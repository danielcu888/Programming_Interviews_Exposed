/*
 * ListElement.hpp
 *
 *  Created on: 27 Aug 2018
 *      Author: danielcumberbatch
 */

#ifndef LISTELEMENT_HPP_
#define LISTELEMENT_HPP_

struct ListElement
{
	ListElement *next;
	int data;
};

// interface function declarations

void deleteList(ListElement **head);
bool deleteElement(ListElement **head, int data);
bool deleteElement(ListElement **head, ListElement *n);
bool insertInFront(ListElement **head, int data);
ListElement *find(ListElement *head, int data);
bool removeHead(ListElement **head);
bool append(ListElement **head, int data);
bool insertAfter(ListElement **head, ListElement* n, int data);
bool insertBefore(ListElement **head, ListElement* n, int data);

// interface function definitions

void deleteList(ListElement **head)
{
	if (!head)
	{
		return;
	}

	while (*head)
	{
		ListElement *tmp = *head;
		*head = (*head)->next;
		delete tmp;
	}
}

bool deleteElement(ListElement **head, int data)
{
	bool ret = true;

	if (!head || !*head)
	{
		ret = false;
	}
	else if ((*head)->data == data)
	{
		ListElement *tmp = *head;
		*head = (*head)->next;
		delete tmp;
	}
	else
	{
		ListElement *tmp = *head;
		while (tmp)
		{
			if (tmp->next && tmp->next->data == data)
			{
				ListElement *tmp2 = tmp->next;
				tmp->next = tmp2->next;
				delete tmp2;
				break;
			}

			tmp = tmp->next;
		}

		if (!tmp)
		{
			ret = false;
		}
	}

	return ret;
}

bool deleteElement(ListElement **head, ListElement *n)
{
	bool ret = true;
	if (!head || !n)
	{
		ret = false;
	}

	if (n == *head)
	{
		*head = (*head)->next;
		delete n;
	}
	else
	{
		ListElement *tmp = *head;
		while (tmp)
		{
			if (tmp->next == n)
			{
				tmp->next = tmp->next->next;
				delete n;
				break;
			}

			tmp = tmp->next;
		}

		if (!tmp)
		{
			ret = false;
		}
	}

	return ret;
}

bool insertInFront(ListElement **head, int data)
{
	bool ret = true;
	if (!head)
	{
		ret = false;
	}
	else
	{
		ListElement *tmp = new ListElement();
		tmp->data = data;
		tmp->next = *head;
		*head = tmp;
	}

	return ret;
}

ListElement *find(ListElement *head, int data)
{
	while (head)
	{
		if (head->data == data)
		{
			break;
		}

		head = head->next;
	}

	return head;
}

bool removeHead(ListElement **head)
{
	bool ret = true;
	if (!head)
	{
		ret = false;
	}
	else
	{
		ListElement *tmp = *head;
		*head = (*head)->next;
		delete tmp;
	}

	return ret;
}

bool append(ListElement **head, int data)
{
	bool ret = true;
	if (!head)
	{
		ret = false;
	}

	if (!*head)
	{
		*head = new ListElement();
		(*head)->data = data;
	}
	else
	{
		ListElement *tmp = *head;
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = new ListElement();
				tmp->next->data = data;
			}

			tmp = tmp->next;
		}
	}

	return ret;
}

bool insertAfter(ListElement **head, ListElement *n, int data)
{
	bool ret = true;
	if (!head || !n || !*head)
	{
		ret = false;
	}
	else
	{
		ListElement *tmp = n->next;
		n->next = new ListElement();
		n->next->data = data;
		n->next->next = tmp;
	}

	return ret;
}

bool insertBefore(ListElement **head, ListElement *n, int data)
{
	bool ret = true;
	if (!head || !n || !*head)
	{
		ret = false;
	}
	else
	{
		ListElement *tmp = *head;
		while (tmp)
		{
			if (tmp->next == n)
			{
				ListElement *tmp2 = tmp->next;
				tmp->next = new ListElement();
				tmp->next->data = data;
				tmp->next->next = tmp2;
				break;
			}
		}

		if (!tmp)
		{
			ret = false;
		}
	}

	return ret;
}

#endif /* LISTELEMENT_HPP_ */
