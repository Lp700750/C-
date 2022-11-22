#pragma once
#include<iostream>
namespace Lp700
{
	//1.�ڵ����͵Ĵ���
	template <class T>
	struct ListNode
	{
		ListNode(const T& _data=T())
			:prev(nullptr),
			next(nullptr),
			data(_data)
		{}

		ListNode<T>* prev;
		ListNode<T>* next;
		T data;
	};

	//2.list�������Ĵ���
	template<class T>
	class list_iterator
	{
		typedef list_iterator<T>* pNode;
		typedef list_iterator<T> self;
	public:
		list_iterator(pNode _pointer)
			:pointer(_pointer)
		{}
		list_iterator(const self& l)
			pointer(l.pointer)
		{}
		T& operator*()
		{
			return pointer->data;
		}
		T*operator->()
		{
			return &(pointer->data);
		}
		self& operator++()
		{
			pointer = pointer->next;
			return pointer;
		}
		self operator++(int)
		{
			self tmp(*this);
			pointer = pointer->next;
			return tmp;
		}
		self& operator--()
		{
			pointer = pointer->prev;
			return pointer;
		}
		self operator--(int)
		{
			self tmp(*this);
			pointer = pointer->prev;
			return tmp;
		}
		bool operator==(self& l)
		{
			return pointer == l.pointer;
		}
		bool operator!=(self& l)
		{
			return pointer == l.pointer;
		}
	private:
		pNode pointer;
	};
	//3.list����ʵ��
}

class Date
{
private:
	int year;
	int month;
	int day;
};
