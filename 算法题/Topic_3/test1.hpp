//����һ���ַ��� s ��һ������ k�����ַ�����ͷ����
//ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ�
//Jolly.Roger

#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution
{
public:
	string reverseStr(string s, int k)
	{
		int i = s.size() / (2 * k);
		int j = s.size() % (2 * k);
		string::iterator ptr1 = s.begin();
		//���ֻ��һ���ַ�����ʱ��
		if (1 == s.size())
		{
			return s;
		}
		//����������2k���ַ���
		while (i)
		{
			int cnt = 2 * k;
			reverse(ptr1, ptr1 + k);
			while (cnt)
			{
				ptr1++;
				cnt--;
			}
			i--;
		}
		//��������0-2k���ַ�
		if (j > 0 && j < k)
		{
			reverse(ptr1, ptr1 + j);
		}
		else if (j >= k)
		{
			reverse(ptr1, ptr1 + k);
		}
		return s;
	}
};

