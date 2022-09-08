#pragma once
#include<iostream>
using namespace std;
class GetDate
{
public:
	//���캯��
	GetDate(int year, int month, int day);
	
	//��ӡ
	void print();

	//��ȡһ�����м���
	int GetMonthDay(int year, int month);

	//����������
	bool operator>(const GetDate& d);
	bool operator<(const GetDate& d);
	bool operator>=(const GetDate& d);
	bool operator<=(const GetDate& d);
	bool operator==(const GetDate& d);
	bool operator!=(const GetDate& d);

	GetDate& operator+=(int day);
	GetDate operator+(int day);
	GetDate& operator-=(int day);
	GetDate operator-(int day);
	GetDate& operator++();
	GetDate& operator++(int);


private:
	int _year;
	int _month;
	int _day;
};