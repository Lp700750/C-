#pragma once
#include<iostream>
namespace Lp700
{
	//1.�����ڵ�
	template <class T>
	struct ListNode
	{
		//���캯��(��֤ÿһ���ڵ㶼�Ǿ�����ʼ����  ListNode<T> ln())
		ListNode(const T& _data = T())
			:prev(nullptr),
			next(nullptr),
			data(_data)
		{}

		ListNode<T>* prev;
		ListNode<T>* next;
		T data;
	};
	//2.����������
	//3.����List��
}