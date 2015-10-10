#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
using namespace std;


template <class T>
class LinkedList
{

	template <class T>
	class Node
	{
	public:
		T data;
		Node<T> *next;

		Node(const T& data) : data(data), next(NULL) {}

	};


public:
	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();
	LinkedList& operator=(const LinkedList& other);

	void add(const T& data);
	void remove(const T& data);

	int getSize() const;

	void deleteList();
	
	template <class T>
	friend ostream& operator<<(ostream& os, const LinkedList<T>& list)
	{
		Node<T> *iter = list.head;
		while (iter != NULL)
		{
			os << iter->data << endl;
			iter = iter->next;
		}
		return os;
	}

private:
	Node<T> *head;
	Node<T> *tail;
	int size;

};

#endif // LINKED_LIST_H


template<class T>
LinkedList<T>::LinkedList() : head(NULL), tail(NULL)
{
	this->size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(NULL), tail(NULL)
{
	*this = other;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	deleteList();
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
	if (this != &other)
	{ 
		deleteList();

		if (other.head != NULL && other.size > 0)
		{
			head = new Node<T>(other.head->data);
			tail = head;
			Node<T> *iter = other.head->next;

			while (iter != NULL)
			{
				Node<T> *node = new Node<T>(iter->data);
				tail->next = node;
				tail = node;
				iter = iter->next;
			}
			size = other.size;
		}
	}
	return *this;
}

template<class T>
void LinkedList<T>::add(const T& data)
{
	if (tail != NULL)
	{
		tail->next = new Node<T>(data);
		tail = tail->next;
	}
	else
	{
		head = new Node<T>(data);
		tail = head;
	}
	++size;
}

template<class T>
void LinkedList<T>::remove(const T& data)
{
	Node<T> *found = head;
	Node<T> *prev = NULL;
	while (found != NULL && !(found->data == data))
	{
		prev = found;
		found = found->next;
	}
	if (found != NULL)
	{
		if (found == head)
		{
			if (head == tail)	// one element
			{
				tail = NULL;
			}
			head = head->next;
		}
		else if (found == tail)
		{
			prev->next = NULL;
		}
		else
		{
			prev->next = found->next;
		}
		delete found;
		--size;
	}
}

template<class T>
int LinkedList<T>::getSize() const
{
	return size;
}

template<class T>
void LinkedList<T>::deleteList()
{
	Node<T> *iter = head;
	while (iter != NULL)
	{
		Node<T> *next = iter->next;
		delete iter;
		iter = next;
	}
	size = 0;
	head = NULL;
	tail = NULL;
}