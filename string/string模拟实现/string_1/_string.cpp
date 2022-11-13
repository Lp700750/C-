#define _CRT_SECURE_NO_WARNINGS 1
#include"_string.h"
Lp700::_string::_string(const char* str)
{
	assert(nullptr != str);
	_str = new char[strlen(str) + 1];
	strcpy(_str, str);
}
//�ɰ汾�Ŀ�������
Lp700::_string::_string(const _string& s)
	:_str(new char[strlen(s._str)+1])
{
	strcpy(_str, s._str);
}
//�°汾�Ŀ�������
Lp700::_string::_string(const _string& s)
	:_str(nullptr)
{
	_string tmpStr(s._str);
	//tmpStr��Ϊһ���м���󣬳���������ͻ��������������������ռ�
	strcpy(_str, tmpStr._str);
}
//�ɰ汾�ĸ�ֵ����
Lp700::_string& Lp700::_string::operator=(const Lp700::_string& s)
{
	if (this != &s)
	{
		char* ptr = new char[strlen(s._str) + 1];
		strcpy(ptr, s._str);
		delete[] _str;
		_str = ptr;
	}
	return *this;
}
//�°汾�ĸ�������
Lp700::_string& Lp700::_string::operator=(const Lp700::_string& s)
{
	if (this != &s)
	{
		_string tmpStr(s);
		std::swap(_str, tmpStr._str);
	}
	return *this;
}
Lp700::_string::~_string()
{
	if (_str)
	{
		delete _str;
		_str = nullptr;
	}
}