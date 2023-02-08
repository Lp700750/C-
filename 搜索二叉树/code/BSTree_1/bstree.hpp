#pragma once
#include<iostream>
namespace Lp700
{
	template<class T>
	struct BSTNode
	{
		BSTNode(const T& value=T())
			:LeftPtr(nullptr)
			,RightPtr(nullptr)
			,data(value)
		{}

		BSTNode<T>* LeftPtr;
		BSTNode<T>* RightPtr;
		T data;
	};

	template<class T>
	class BSTree
	{
		typedef BSTNode<T> Node;
		typedef BSTNode<T>* iterator;
	public:
		BSTree()
			:pNode(nullptr)
		{}
		//1.insert
		void insert(const T& value)
		{
			//����ǿ��������
			if (pNode == nullptr)
			{
				pNode = new Node;
				pNode->data = value;
				pNode->RightPtr = nullptr;
				pNode->LeftPtr = nullptr;
				return;
			}
			//�ǿ����Ĳ���
			iterator parent = nullptr;
			iterator CurNode = pNode;
			
			//���ҿյ�λ�ò���
			while (CurNode)
			{
				//�����ҵ�����λ�õĸ��ڵ�
				parent = pNode;
				//��ڵ�
				if (CurNode->data > value)
				{
					CurNode = CurNode->LeftPtr;
				}
				//�ҽڵ�
				else if (CurNode->data < value)
				{
					CurNode = CurNode->RightPtr;
				}
				//��ȵ�ʱ��Ͳ��ò���
				else
				{
					return;
				}
			}

			CurNode = new Node(value);
			if (parent->data > value)
			{
				parent->LeftPtr= CurNode;
			}
			else
			{
				parent->RightPtr= CurNode;
			}
		}
		//2.erase
		//3.find
	private:
		iterator pNode;
	};
}