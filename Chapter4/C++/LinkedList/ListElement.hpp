#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_

#include <stdexcept>

template<typename T>
class ListElement
{
 public:
	ListElement(const T& val, ListElement *next = nullptr);
	~ListElement() = default;

	T val;
	ListElement *next;
};

template<typename T>
ListElement<T>::ListElement(const T& val, ListElement *next)
 : val(val)
 , next(next)
{}

template<typename T>
void deleteList(ListElement<T> **head)
{
	if (!head)
	{
		throw std::logic_error("Attempt to delete empty list.");
	}

	while (*head)
	{
		ListElement<T> *tmp = *head;
		*head = (*head)->next();
		delete tmp;
	}
}

template<typename T>
void deleteElement(ListElement<T> **head, int data)
{
	if (!head || !*head)
	{
		throw std::logic_error("Attempt to delete element from empty list.");
	}

	ListElement<T> *tmp = *head;
	while (tmp)
	{
		if (tmp->next() && tmp->next->val == data)
		{
			ListElement<T> *tmp2 = tmp->next;
			tmp->next = tmp2->next;
			delete tmp2;
			break;
		}

		tmp = tmp->next;
	}

	if (!tmp)
	{
		throw std::logic_error("Attempt to delete non-existent element from list.");
	}
}

template<typename T>
void deleteElement(ListElement<T> **head, ListElement<T> *n)
{
	if (!n)
	{
		throw std::logic_error("Attempt to delete null element.");
	}

	if (!head || !*head)
	{
		throw std::logic_error("Attempt to delete element from empty list.");
	}

	ListElement<T> *tmp = *head;
	while (tmp)
	{
		if (tmp->next && tmp->next == n)
		{
			tmp->next = tmp->next->next;
			delete n;
			break;
		}

		tmp = tmp->next;
	}

	if (!tmp)
	{
		throw std::logic_error("Attempt to delete non-existent element.");
	}
}

template<typename T>
void insertInFront(ListElement<T> **head, int data)
{
	if (!head)
	{
		throw std::logic_error("Attempt to insert element into non-existent list.");
	}

	if (!*head)
	{
		*head = new ListElement<T>(data);
	}
	else
	{
		ListElement<T> *tmp = *head;
		*head = new ListElement<T>(data, tmp);
	}
}

template<typename T>
ListElement<T> *find(ListElement<T> *head, int data)
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

template<typename T>
void removeHead(ListElement<T> **head)
{
	bool ret = true;
	if (!head || !*head)
	{
		throw std::logic_error("Attempt to delete head from empty list.");
	}
	else
	{
		ListElement<T> *tmp = (*head)->next;
		delete *head;
		*head = tmp;
	}
}

template<typename T>
void append(ListElement<T> **head, int data)
{
	if (!head)
	{
		throw std::logic_error("Attempt to append element to non-existent list.");
	}
	else if (!*head)
	{
		*head = new ListElement<T>(data);
	}
	else
	{
		ListElement<T> *tmp = *head;
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = new ListElement<T>(data);
				break;
			}

			tmp = tmp->next;
		}
	}
}

template<typename T>
void insertAfter(ListElement<T> **head, ListElement<T>* n, int data)
{
		bool ret = true;
	if (!head || !*head || !n)
	{
		ret = false;
	}
	else
	{
		ListElement<T> *tmp = n->next;
		n->next = new ListElement<T>(data, tmp);
	}

	return ret;
}

template<typename T>
bool insertBefore(ListElement<T> **head, ListElement<T>* n, int data)
{
	bool ret = true;
	if (!head || !*head || !n)
	{
		ret = false;
	}
	else if (*head == n)
	{
		*head = new ListElement<T>(data, *head);
	}
	else
	{
		ListElement<T> *tmp = *head;
		while (tmp)
		{
			if (tmp->next == n)
			{
				ListElement<T> tmp2 = tmp->next;
				tmp->next = new ListElement<T>(data, tmp2);
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

#endif // ! LISTELEMENT_H_
