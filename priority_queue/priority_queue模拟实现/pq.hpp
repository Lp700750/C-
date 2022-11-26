#pragma once
#include<iostream>
#include<vector>
#include<functional>
namespace Lp700
{
	//1.�º���
	template<class T>
	struct less
	{
		bool operator()(const T& num1, const T& num2)
		{
			return num1 < num2;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& num1, const T& num2)
		{
			return num1 > num2;
		}
	};
	//2.priority_queueģ��
	template<class T,class Container=std::vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue()
			:container()//����������Ĭ�Ϲ��캯��
		{}
		template<class iterator>
		priority_queue(iterator first, iterator last)
			:container(first,last)
		{
			int heap_size = container.size();
			int last_parent = (heap_size - 2) / 2;
			//�����һ�����ڵ㿪ʼ���е���
			for (int i = last_parent; i > 0; i--)
			{
				adjustdown(i);
			}
		}
		//1.push
		void push(const T& value)
		{
			container.push_back(value);
			adjustup(container.size() - 1);
		}
		//2.pop
		void pop()
		{
			if (empty())
			{
				return;  
			}
			//��βԪ���໻��queue����β��ͷ��
			std::swap(container.front(), container.back());
			container.pop_back();
			adjustdown(0);
		}
		//3.top
		const T& top()const
		{
			return container.front();
		}
		//4.empty
		bool empty()const //���ص��ǳ�Ա�������ڲ�����
		{                 //Ϊ��ֹ���۸ļ���const����Ȩ��
			return container.empty();
		}
		//5.size
		int size()const
		{
			return container.size();
		}
	private:
		void adjustup(int child)
		{
			Compare compare;
			int parent = (child - 1) / 2;
			while (child)
			{
				if (compare(container[parent] , container[child]))
				{
					std::swap(container[parent], container[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void adjustdown(int parent)
		{
			//�����ĺ��ӽڵ㶼�����ӽڵ�
			size_t child = 2 * parent + 1;
			Compare compare;
			while (child < container.size())
			{
				//�ж��Һ����Ƿ������Һ��ӵ��������
				if ((child + 1) < container.size() && compare(container[child] , container[child + 1]))
				{
					//������ߵ��е��Һ��Ӹ�ֵ�����ӽڵ�
					child++;
				}
				//�жϸ��ڵ��Ƿ�Ⱥ��ӽڵ��
				if (compare(container[parent], container[child]))
				{
					std::swap(container[child], container[parent]);
					
					//�������½��е���Ϊ��
					parent = child;
					child = 2 * child + 1;
				}
				else
				{
					break;
				}
			}
		}
	private:
		Container container;
	};
}


