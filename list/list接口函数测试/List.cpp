#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
void test1()
{
	//List�Ĺ���
	std::list<int> L1;
	std::list<int>L2(5, 10);
	std::list<int>L3(L2);
	std::list<int>L4(L2.begin(), L2.end());
}
void test2()
{
	//erase������ʧЧ
	int arry[] = { 1,2,3,4,5,6,7,8,9 };
	std::list<int> L1(arry, arry + sizeof(arry) / sizeof(arry[0]));
	auto it = L1.begin();
	while (it != L1.end())
	{
		//������ʧЧ
		L1.erase(it);
		it++;
		//erase֮��ýڵ�ĵ�����ʧЧ�������ܹ�����ʹ��
		
		//������
		L1.erase(it++);
	}
}
int main()
{
	//test1();
	test2();
	return 0;
}