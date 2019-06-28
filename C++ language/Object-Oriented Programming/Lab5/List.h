#pragma once

#include <iostream>
#include <fstream>
#include "Iterator.h"

 template <class T>
class List{
	
	struct ListNode{
		T data;
		ListNode * next;
		ListNode(){
			next = NULL;
		}
		ListNode( T dat ){
			data = dat;
		}
		void Print(){
			std::cout << data;
		}
	};
	
public:
	typedef ListNode node_type;
	typedef _iterator<node_type> iterator;
	//constructors / destructors
	List() {
		head = nullptr;
		first = new iterator(nullptr);
		last = new iterator(nullptr);
	}
	~List() { clear(); }

iterator begin();//Returns an iterator addressing the first element		
iterator end();//Returns an iterator that addresses the location		
   //succeeding the last element

bool load(const char *filename);
void clear();//Erases all the elements of a list.						
bool empty();//Tests if a list is empty.								

	iterator find(const node_type & val);//Returns an iterator to the   
// first element in a list that match a specified value.

void pop_front();//Deletes the element at the beginning of a list.		

void push_front( const node_type val);//Adds an element to the //beginning of a list.	
iterator remove(node_type val);//Erases first element in a list that //match a specified value and returns iterator to position next to removed //element.	
iterator remove(iterator _where);//	Erases element from specified position and returns iterator to position next to removed element.


	int size();//Returns the number of elements in a list.

	void splice(iterator _Where, List<T>& _Right);//Removes element from //the target list and inserts it in first
// position of the argument list.
	void	Print();//Dumps list into the screen
private:
	node_type *head;
	iterator *first, *last;
};

template <class T>
bool List<T>::load(const char* filename) {
	if (filename == NULL)
		return false;
	std::ifstream str;
	str.open(filename);
	if (str.is_open() == false)
		exit(20);
	node_type *t;
	while (str.eof() != true) {
		t = new node_type();
		str >> t->data;
		push_front(*t);
		delete t;
	}
	pop_front();
	str.close();
	return true;
}

template <class T>
typename List<T>::iterator List<T>::begin() {
	return *first;
}

template <class T>
typename List<T>::iterator List<T>::end() {
	iterator it = (*last);
	it++;
	return it;
}

template<class T>
void List<T>::clear() {
	for (iterator it = begin(); it != end(); it++)
		pop_front();
	delete last;
	last = new iterator(nullptr);
}

template <class T>
bool List<T>::empty() {
	return (head == nullptr);
}

template <class T>
typename List<T>::iterator List<T>::find(const node_type& val) {
	for (iterator it = begin(); it != end(); it++) {
		if ((*it).data == val.data)
			return it;
	}
}

template <class T>
void List<T>::pop_front() {
	if (empty() == false) {
		head = head->next;
		delete first;
		first = new iterator(head);
	}
}

template <class T>
typename List<T>::iterator List<T>::remove(node_type val) {
	iterator iter(nullptr);
	if (head == nullptr)
		return iter;
	iterator it = begin();
	while (it != end()) {
		if ((*it).data == val.data) {
			if (it == begin()) {
				pop_front();
				return it;
			}
			else {
				iterator *tmp = new iterator(it);
				iterator c1 = begin();
				while ((*((*c1).next)).data != (*it).data)
					c1++;
				if (it == *last) {
					delete last;
					last = new iterator(c1);
				}
				else 
					(*c1).next = (*it).next;
				it++;
				delete tmp;
				c1++;
				return c1;
			}
		}
		else
			it++;
	}
	return iter;
}

template <class T>
typename List<T>::iterator List<T>::remove(iterator _where) {
	if (&(*_where) == nullptr)
		return nullptr;
	else
		return remove(*_where);
}

template <class T>
void List<T>::push_front(const node_type val) {
	node_type *tmp = new node_type(val.data);
	tmp->next = head;
	bool flag = false;
	if (head == nullptr)
		flag = true;
	head = tmp;
	delete first;
	first = new iterator(head);
	if (flag == true) {
		flag = false;
		delete last;
		last = new iterator(head);
	}
	tmp = nullptr;
}

template <class T>
int List<T>::size() {
	int counter = 0;
	for (iterator it = begin(); it != end(); it++)
		counter++;
	return counter;
}

template <class T>
void List<T>::Print() {
	for (iterator it = begin(); it != end(); it++) {
		(*it).Print();
	}
}

template <class T>
void List<T>::splice(iterator _Where, List<T>& _Right) {
	remove(_Where);
	_Right.push_front(*_Where);
}