#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
//���캯��
Lp700::string::string(const char* pStr)
{
	_size = strlen(pStr);
	_capacity = _size;
	_pStr = new char[_capacity + 1];
	strcpy(_pStr, pStr);
}
//��������
Lp700::string::~string()
{
	//ֻ�����Ƿǿ�ָ��������������������
	if (this != nullptr)
	{
		delete[] _pStr;
		_pStr = nullptr;
	}
}
//��������
Lp700::string::string(const string& s)
	:_pStr(nullptr),
	_size(0),
	_capacity(0)
{
	string tmpStr(s._pStr);
	swap(tmpStr);
}
//��������
void Lp700::string::swap(string& s)
{
	std::swap(_pStr,s._pStr);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}
//��ֵ����
Lp700::string& Lp700::string::operator=(string& s)
{
	if (this != &s)
	{
		swap(s);
	}
	return *this;
}
//��Ԫ��ָ��
Lp700::string::iterator Lp700::string::begin()
{
	return _pStr;
}
//βԪ��ָ��
Lp700::string::iterator Lp700::string::end()
{
	return _pStr+_size;
}
//β�����һ���ַ�
void Lp700::string::push_back(char c)
{
	if (_size == _capacity)
	{
		//���ٵĿռ䲻������Ҫ����
		_capacity = 2 * _capacity;
		reserve(_capacity);
		_pStr[_size++] = c;
		_pStr[_size] = '\0';
	}
}
//���ٿռ�
void Lp700::string::reserve(int n)
{
	if (n > _capacity)
	{
		char* newStr = new char[n];
		strcpy(newStr, _pStr);
		delete[] _pStr;
		_pStr = newStr;
		_capacity = n;
	}
}
//�������
void Lp700::string::clear()
{
	_size = 0;
	_pStr[_size] = '\0';
}
//����c�ַ���
const Lp700::string::iterator Lp700::string::c_str()const
{
	return _pStr;
}
//�ַ����ĳ���
int Lp700::string::size()
{
	return _size;
}
//�ַ����ĳ���
int Lp700::string::length()
{
	return _size;
}
//���ٿռ�Ĵ�С
int Lp700::string::capacity()
{
	return _capacity;
}
//�����ַ����Ĵ�С
void Lp700::string::resize(int n, char c)
{
	if (n < _size)
	{
		_size = n;
		_pStr[_size] = '\0';
	}
	else
	{
		if(n>_capacity)
		{
			reserve(n);
		}
		memset(_pStr + _size, c, n - _size);
		_size = n;
		_pStr[_size] = '\0';
	}
}