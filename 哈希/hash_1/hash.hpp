//Author:Jolly.Roger
//Time:2022.12.13

#pragma once
#include<iostream>
#include<vector>
#include<map>
namespace Lp700
{
	enum state
	{
		EMPTY,
		EXIST,
		DELETE
	};
	template<class T1,class T2>
	class hash
	{
	private:
		//��ϣ�������ÿһ��Ԫ�����
		struct HashData
		{
			std::pair<T1, T2> _p;
			state _state;
		};
		
		//��ϣ����
		size_t HashFunc(const T1& value)
		{
			return value % _hata.size();
		}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     )
	public:
		hash(int capacity = 10)
			:_hata(capacity)
			, _size(0)
		{
			for (int i = 0; i < capacity; i++)
			{
				_hata[i]._state = EMPTY;
			}
		}
		//����
		void insert(std::const pair<T1,T2>& p)
		{
			size_t HashAddr = HashFunc(p.first);
			while (_hata[HashAddr]._state != EMPTY)
			{

			}
		}
		//����
		//ɾ��
		//����
		//�Ƿ�Ϊ��
		//����
	private:
		std::vector<HashData> _hata;
		size_t _size;
	};
}
