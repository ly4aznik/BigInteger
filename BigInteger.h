#pragma once
#include <string>

using namespace std;

class BigInteger
{
	string number;
	bool sign;

	/*
	number - ������
	�������� �������� �� ������ ������
	*/
	bool isnumber(const string& number);
	/*
	number - ������
	�������� �� 0
	*/
	bool isZero(const string& number);
	/*
	number - ������
	�������� �� ������������ ������� �����, � ������ �������������� ����������� ����
	*/
	void align(size_t n);
	/*
	n - ������� ����� 10
	��������� ����� BigInteger �� 10 � ������� n
	*/
	BigInteger prodByTen(size_t n = 1);
	/*
	�������� ����� ����� ������
	*/
	void clearZeroes();

public:
	/*
	������ ����������� ������� ����� �� ��������� �� ��������� 0
	*/
	BigInteger();
	/*
	s - ������
	����������� �� ������� ������� ����� ������ �������� ����� � ������ s
	*/
	BigInteger(string s);
	/*
	s - ������
	sign - ���������� ���������� ������������ ���� �����
	����������� �� ������� � ������ ������� ����� ������ �������� ����� � ������ s � �� ������ sign
	*/
	BigInteger(string s, bool sign);
	/*
	n - ����� �����
	����������� ������� ����� ������ n
	*/
	BigInteger(long long int n);
	/*
	s - ������, ���������� ������
	������������� �������� number ������ ����� ����������� � ������ s
	*/
	void setNumber(string s);
	/*
	���������� �������� number
	*/
	const string& getNumber();
	/*
	s - ������, ���������� ������
	������������� �������� sign
	*/
	void setSign(bool s);
	/*
	���������� �������� sign
	*/
	const bool& getSign();
	/*
	���������� ������ �����
	*/
	BigInteger abs_bi();
	// �������� ������������
	void operator=(BigInteger b);
	// �������� �� ���������
	bool operator==(BigInteger b);
	// �������� �� �����������
	bool operator!=(BigInteger b);
	// �������� �� ������� ����������� ������
	bool operator>(BigInteger b);
	// �������� �� ������� ����������� ������
	bool operator<(BigInteger b);
	// �������� �� ��������� ����������� ������
	bool operator>=(BigInteger b);
	// �������� �� ��������� ����������� ������
	bool operator<=(BigInteger b);
	// ���������� ���������
	BigInteger& operator++();
	// ����������� ���������
	BigInteger operator++(int);
	// ���������� ���������
	BigInteger& operator--();
	// ����������� ���������
	BigInteger operator--(int);
	// �������� ��������
	BigInteger operator+(BigInteger b);
	// �������� ���������
	BigInteger operator-(BigInteger b);
	// �������� ��������� ���������� ��������
	BigInteger operator*(BigInteger b);
	// �������� �������������� �������
	BigInteger operator/(BigInteger b);
	// �������� ��������� ������� �� �������������� �������
	BigInteger operator%(BigInteger b);
	// �������� ��������, ����������� � �������������
	BigInteger& operator+=(BigInteger b);
	// �������� ���������, ����������� � �������������
	BigInteger& operator-=(BigInteger b);
	// �������� ���������, ����������� � �������������
	BigInteger& operator*=(BigInteger b);
	// �������� �������, ����������� � �������������
	BigInteger& operator/=(BigInteger b);
	// �������� ��������� ������� �� �������������� �������, ����������� � �������������
	BigInteger& operator%=(BigInteger b);
	// ������� �����
	BigInteger operator-();
	// �������� ������ � �����
	friend ostream& operator<<(ostream& os, const BigInteger& b)
	{
		if (b.sign)
			os << "-";
		os << b.number;
		return os;
	}
};