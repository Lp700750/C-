#pragma once
#include<iostream>
namespace Lp700
{
	//����ڵ�
	template<class T>
	struct pNode
	{
		pNode(const T& value=T())
			:LeftPtr(nullptr)
			,RightPtr(nullptr)
			,data(value)
		{}

		pNode<T>* LeftPtr;
		pNode<T>* RightPtr;
		T data;
	};
	//����������
	template<class T>
	class BSTree
	{
		typedef pNode<T> Node;
		typedef pNode<T>* iterator;
	public:
		BSTree()
			:pRoot(nullptr)
		{}
		//1.insert
		void insert(const T& value)
		{
			//1.����
			if (pRoot == nullptr)
			{
				pRoot = new Node(value);
				return;
			}
			//2.�ǿ����Ĳ���
			iterator CurPtr = pRoot;
			iterator parent = nullptr;
			while (CurPtr)
			{
				parent = CurPtr;
				if (CurPtr->data > value)
				{
					CurPtr = CurPtr->LeftPtr;
				}
				else if (CurPtr->data < value)
				{
					CurPtr = CurPtr->RightPtr;
				}
				//��ȵ�����²��벻��ȥ
				else
				{
					return;
				}
				CurPtr = new Node(value);
				if (parent->data > value)
				{
					parent->LeftPtr=CurPtr;
				}
				else
				{
					parent->RightPtr=CurPtr;
				}
			}
		}
		//2.find
		iterator find(const T& value)
		{
			iterator CurPtr = pRoot;
			while (CurPtr)
			{
				if (CurPtr->data > value)
				{
					CurPtr = CurPtr->LeftPtr;
				}
				else if (CurPtr->data < value)
				{
					CurPtr = CurPtr->RightPtr;
				}
				else
				{
					return CurPtr;
				}
			}
			return nullptr;
		}
		//3.erase
		void erase()
	private:
		iterator pRoot;
	};
}
