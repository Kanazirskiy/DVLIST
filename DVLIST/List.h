#pragma once

#include <iostream>

class List
{
private:
	class Node
	{
	public:
		Node* next;
		Node* prev;
		int value;
		Node();
		Node(int valuex, Node* nextx = nullptr, Node* prevx = nullptr);
	};

	Node* head;
	Node* tail;
	size_t sizep;
public:
	class Iterator;
	class reverse_Iterator;
	List();
	~List();
	List(const List& other);

	int& operator[] (size_t n);


	void push_back(int element);
	void push_front(int element);
	void pop_front();
	void pop_back();
	void erase(size_t i);
	void insert(size_t i, int element);
	void assign(List& other);
	void resize(size_t n,int x=0);
	void clear();
	void swap(List& other);
	void reverse();
	bool empty();
	List& operator=(const List& other);
	int& front();
	int& back();
	size_t size();

	Iterator begin() {return Iterator(head);}
	Iterator end() { return Iterator(tail->next); }
	reverse_Iterator rbegin() { return reverse_Iterator(tail); }
	reverse_Iterator rend() { return reverse_Iterator(head->prev); }

	class Iterator
	{
		Node* cur;
	public:
		Iterator(Node* first): cur(first){}
		Iterator& operator+ (int n) 
		{ 
			for (int i = 0; i < n; ++i) 
				cur = cur->next; 
			return *this; 
		}
		Iterator& operator- (int n) 
		{
			for (int i = 0; i < n; ++i)
				cur = cur->prev;
			return *this;
		}
		Iterator& operator++ (int n)
		{
			cur = cur->next;
			return *this;
		}
		Iterator& operator-- (int n)
		{
			cur = cur->prev;
			return *this;
		}
		Iterator& operator++ ()
		{
			cur = cur->next;
			return *this;
		}
		Iterator& operator-- ()
		{
			cur = cur->prev;
			return *this;
		}

		bool operator!= (const Iterator& it) { return cur != it.cur; }
		bool operator== (const Iterator& it) { return cur == it.cur; }
		int& operator* () { return cur->value; }
	};

	class reverse_Iterator
	{
		Node* cur;
	public:
		reverse_Iterator(Node* first) : cur(first) {}
		reverse_Iterator& operator+ (int n)
		{
			for (int i = 0; i < n; ++i)
				cur = cur->prev;
			return *this;
		}
		reverse_Iterator& operator- (int n)
		{
			for (int i = 0; i < n; ++i)
				cur = cur->next;
			return *this;
		}
		reverse_Iterator& operator++ (int n)
		{
			cur = cur->prev;
			return *this;
		}
		reverse_Iterator& operator-- (int n)
		{
			cur = cur->next;
			return *this;
		}
		reverse_Iterator& operator++ ()
		{
			cur = cur->prev;
			return *this;
		}
		reverse_Iterator& operator-- ()
		{
			cur = cur->next;
			return *this;
		}

		bool operator!= (const reverse_Iterator& it) { return cur != it.cur; }
		bool operator== (const reverse_Iterator& it) { return cur == it.cur; }
		int& operator* () { return cur->value; }
	};
};
