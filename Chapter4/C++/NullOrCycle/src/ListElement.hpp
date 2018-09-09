/*
 * ListElement.hpp
 *
 *  Created on: 30 Aug 2018
 *      Author: danielcumberbatch
 */

#ifndef LISTELEMENT_HPP_
#define LISTELEMENT_HPP_

namespace linkedlist
{
	struct ListElement
	{
		void *data;
		ListElement *next;
	};

	bool isCyclic(ListElement *head);

} // ! namespace linkedlist

#endif /* LISTELEMENT_HPP_ */
