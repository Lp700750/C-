#pragma once
#include<iostream>
namespace Lp700
{
	class person
	{
	public:
		virtual void print()
		{
			std::cout << "ȫ��" << std::endl;
		}
	};
	class student:public person
	{
	public:
		virtual void print()
		{
			std::cout << "���" << std::endl;
		}
	};
}
