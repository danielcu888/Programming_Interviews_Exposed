//============================================================================
// Name        : ListFlattening.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>
#include "LinkedList.hpp"

int main(int argc, char *argv[])
{
	linkedlist::ListElement *head = nullptr;
	linkedlist::ListElement *tail = nullptr;

	linkedlist::ListElement *el00 = new linkedlist::ListElement(5);
	linkedlist::ListElement *el01 = new linkedlist::ListElement(33);
	linkedlist::ListElement *el02 = new linkedlist::ListElement(17);
	linkedlist::ListElement *el03 = new linkedlist::ListElement(2);
	linkedlist::ListElement *el04 = new linkedlist::ListElement(1);

	el00->next = el01;
	el01->prev = el00;
	el01->next = el02;
	el02->prev = el01;
	el02->next = el03;
	el03->prev = el02;
	el03->next = el04;
	el04->prev = el03;
	head = el00;
	tail = el04;

	linkedlist::ListElement *el10 = new linkedlist::ListElement(6);
	linkedlist::ListElement *el11 = new linkedlist::ListElement(25);
	linkedlist::ListElement *el12 = new linkedlist::ListElement(6);
	linkedlist::ListElement *el13 = new linkedlist::ListElement(2);
	linkedlist::ListElement *el14 = new linkedlist::ListElement(7);

	el10->next = el11;
	el11->prev = el10;
	el11->next = el12;
	el12->prev = el11;
	el13->next = el14;
	el14->prev = el13;
	el00->child = el10;
	el03->child = el13;

	linkedlist::ListElement *el20 = new linkedlist::ListElement(8);
	linkedlist::ListElement *el21 = new linkedlist::ListElement(9);
	linkedlist::ListElement *el22 = new linkedlist::ListElement(12);
	linkedlist::ListElement *el23 = new linkedlist::ListElement(5);

	el11->child = el20;
	el12->child = el21;
	el13->child = el22;

	el22->next = el23;
	el23->prev = el22;

	linkedlist::ListElement *el30 = new linkedlist::ListElement(7);
	linkedlist::ListElement *el31 = new linkedlist::ListElement(21);
	linkedlist::ListElement *el32 = new linkedlist::ListElement(3);

	el21->child = el30;
	el22->child = el31;
	el31->next = el32;
	el32->prev = el31;

	std::cout << "Original List: " << std::endl;
	linkedlist::print(head, true);
	std::cout << std::endl;
	std::cout << "tail: ";
	linkedlist::print(tail, true);
	std::cout << std::endl;
	if (!linkedlist::flatten(head, &tail))
	{
		return EXIT_FAILURE;
	}
	std::cout << "Flattened List: " << std::endl;
	linkedlist::print(head, false);
	std::cout << std::endl;
	std::cout << "tail: ";
	linkedlist::print(tail, false);
	std::cout << std::endl;
	if (!linkedlist::unflatten(head, &tail))
	{
		return EXIT_FAILURE;
	}
	std::cout << "Unflattened List: " << std::endl;
	linkedlist::print(head, true);
	std::cout << std::endl;
	std::cout << "tail: ";
	linkedlist::print(tail, true);
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
