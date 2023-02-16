#pragma once
#include<iostream>
namespace Lp700
{
	template<class T>
	class vector
	{
		typedef T* iterator;
	public:
		//�޲������캯��
		vector()
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{}
		//�в����Ĺ��캯��
		vector(int n,const T& value=T())
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			reserve(n);
			while (n)
			{
				push_back(value);
				n--;
			}
		}
		//��������
		vector(const vector<T>& v)
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			reserve(v.end_of_storage);
		}
		//������������С
		int size()
		{
			return finish - start;
		}
		//�����Ŀռ��С
		int capacity()
		{
			return end_of_storage - start;
		}
		//���������ռ��С
		void reserve(int n)
		{
			if (n > capacity())
			{
				int _size = size();

				//_capacity == 0 ? 1 : n;
				//�����ǵ���0,�������������Ҳ��û�������,�˴�ֻ�������ݵĿռ�

				T* _start = new T[n];
				for (int i = 0; i < _size ; i++)
				{
					_start[i] = start[i];
				}
				start = _start;
				finish = start + _size;
				end_of_storage = start + n;
			}
		}
		//β������
		void push_back(const T& value)
		{
			//�ռ䲻������
			if (finish == end_of_storage)
			{
				//��Ҫ����������
				int _capacity = capacity();
				_capacity == 0 ? 1 : 2 * _capacity;
				//����
				reserve(_capacity);
			}
			//��β���������
			int _size = size();
			start[_size] = value;
			//start[size()] = value;
			++finish;
			//start[size()] = '\0';
			//start[_size] = '\0';
		}
		//��ӡ����ĳ�Ա
		void print()
		{
			int n = size();
			for (int i = 0; i < n; i++)
			{
				std::cout << start[i] << " ";
			}
			printf("\n");
		}
		//��������
		~vector()
		{
			delete[] start;
			start = finish = end_of_storage = nullptr;
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}
