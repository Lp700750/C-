#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdbool.h>
//int add(int a, int b)
//{
//	return a + b;
//}
//template<class T1,class T2>
//T1 add(T1 a, T2 b)
//{
//	return a + b;
//}
void test1()
{
	//����size()��capacity()
	std::string s1;
	std::string s2("hello Jolly.Roger");
	std::string s3(s2);
	int num_capacity = s2.capacity();
	int num_size = s2.size();//�ַ�����ʵ�ʴ�С��������\0
	std::cout << num_capacity << std::endl;
	std::cout << num_size << std::endl;
	std::cout << s2.empty() << std::endl;
}
void test2()
{
	//����clear()
	std::string s1;
	std::string s2("hello Jolly.Roger");
	std::string s3(s2);
	s2.clear();
	int num_capacity1 = s2.capacity();
	int num_size1 = s2.size();
	std::cout << num_capacity1 << std::endl;
	std::cout << num_size1 << std::endl;
}
void test3()
{
	//����resize��reserve
	std::string s2("hello Jolly.Roger");
	s2.resize(20,0);
	int num_capacity = s2.capacity();
	int num_size = s2.size();
	std::cout << num_capacity << std::endl;
	std::cout << num_size << std::endl;
	s2.reserve(15);
	//������С��ʱ��reserve�������仯
	//���������ʱ��reserve���ᰴ���Ƽ���nȻ����Ӧ�ı�������
	//���ڴ���size�Ĳ���ֻ��OSԤ���Ŀռ䣬���ǲ���ȥ���ʷ������Խ�����
	int num_capacity1 = s2.capacity();
	std::cout << num_capacity1 << std::endl;
}
void test4()
{
	//����push_back
	std::string s2("hello Jolly.Roger");
	std::string s1("handsome guys");
	//s2.push_back(s1.c_str);
	int num_size = s2.size();
	std::cout << num_size << std::endl;
	s2.push_back('!');
	int num_size1 = s2.size();
	std::cout << num_size1 << std::endl;

}
void test5()
{
	//����[]��begin() end() ��Χfor
	std::string s2("handsome guys!");
	std::cout << s2[4] << std::endl;
	std::cout << *(s2.begin()) << std::endl;
	std::cout << *(s2.end()-1) << std::endl;
	for (auto e : s2)
	{
		std::cout << e ;
	}
}
void test6()
{
	//����append() operator+= c_str() 
	std::string s2("handsome guys!");
	std::string s1("hello Jolly.Roger");
	std::cout << s2 << std::endl;
	std::cout << s2.c_str() << std::endl;
	s1.append(s2);
	s2 += s1;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();

	return 0;
}