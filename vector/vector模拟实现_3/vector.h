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
		vector(int n, const T& value = T())
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
			reserve(v.capacity());
			for (int i = 0; i < v.size(); i++)
			{
				start[i] = v.start[i];
			}
			finish = start + v.size();
		}
		//��ֵ����
		vector<T>& operator=(vector<T>& v)
		{
			swap(v);
			return *this;
		}
		//��������
		void swap(vector<T>& v)
		{
			std::swap(start,v.start);
			std::swap(finish,v.finish);
			std::swap(end_of_storage,v.end_of_storage);
		}
		//������������С
		int size()const
		{
			return finish - start;
		}
		//�����Ŀռ��С
		int capacity()const
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
				for (int i = 0; i < _size; i++)
				{
					_start[i] = start[i];
				}
				start = _start;
				finish = start + _size;
				end_of_storage = start + n;
			}
		}
		//����������������С
		void resize(int n, T value = T())
		{
			//��С����
			if (n < size())
			{
				finish -= 2;
			}
			//��������
			else
			{
				//��Ҫ�ж����е������Ƿ���Ҫ����
				if (n > capacity())
				{
					reserve(n);
				}
				//������������
				for (int i = size(); i < n; i++)
				{
					start[i] = value;
				}
				finish = start + n;
			}
		}
		//���λ�ý��в���
		iterator insert(iterator pos, const T& value)
		{
			//�������λ�õ����ľ��룬��ֹ���������ʧЧ��
			int oldSize_iterator = pos - start;

			//�ж��Ƿ���Ҫ����
			if (finish == end_of_storage)
			{
				int _num = (capacity() == 0 ? 1 : 2 * capacity());
				reserve(_num);
				pos = start + oldSize_iterator;
			}
			
			//��ʼ��ֵ������
			iterator end = finish - 1;
			while (pos != end)
			{
				*(end + 1) = *end;
				--end;
			}
			//��ʼ�����滻ֵ
			*pos = value;
			++finish;
			return pos;
		}
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
		//β������
		void push_back(const T& value)
		{
			//�ռ䲻������
			if (finish == end_of_storage)
			{
				//��Ҫ����������
				int _capacity = (capacity() == 0 ? 1 : 2 * capacity());
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
		//β��ɾ��
		void pop_back()
		{
			if (start != finish)
			{
				--finish;
			}
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

