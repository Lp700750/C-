#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class Day
{
	/*
	1.��̬��Ա��������������������������������У�������ĳһ���������˽��
	2.��̬��Ա�����ͳ�Ա�������Է��ʾ�̬��Ա�����ͳ�Ա���������ǲ��ܷ��ʷǾ�̬��Ա�����ͳ�Ա����
	3.�Ǿ�̬��Ա�����ͳ�Ա�������Է��ʾ�̬���߷Ǿ�̬��Ա�����;�̬����
	*/
public:
	Day(int hour=10)
		:_hour(hour)
	{}
	void print()
	{
		std::cout << _hour <<"-"<<_minute<< std::endl;
		_print();
	}
	static void _print()
	{
		//Day::print();
		std::cout << _minute << std::endl;
		//std::cout << Day::_hour << std::endl;
	}

private:
	int _hour;
	static int _minute;
};
int Day::_minute = 20;
int main()
{
	//int Day::_minute = 10;
	Day d;
	d.print();
	d._print();

	return 0;
}