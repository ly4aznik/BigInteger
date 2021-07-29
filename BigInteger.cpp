#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "BigInteger.h"

BigInteger::BigInteger()
{
	number = "0";
	sign = false;
}

BigInteger::BigInteger(string s)
{
	setNumber(s);
}

BigInteger::BigInteger(string s, bool sign) : BigInteger(s)
{
	setSign(sign);
}

BigInteger::BigInteger(long long int n) : BigInteger(to_string(n)) {}

void BigInteger::setNumber(string s)
{
	if (!isnumber(s))
		throw invalid_argument("Incorrect number");
	if (isdigit(s[0]))
	{
		number = s;
		sign = false;
	}
	else
	{
		setNumber(s.substr(1));
		sign = (s[0] == '-');
	}
	clearZeroes();
}

const string& BigInteger::getNumber()
{
	return number;
}

void BigInteger::setSign(bool sign)
{
	if (number == "0")
		this->sign = false;
	else
		this->sign = sign;
}

const bool& BigInteger::getSign()
{
	return sign;
}

BigInteger BigInteger::abs_bi()
{
	return BigInteger(getNumber());
}

void BigInteger::operator=(BigInteger b)
{
	setNumber(b.getNumber());
	setSign(b.getSign());
}

bool BigInteger::operator==(BigInteger b)
{
	return getNumber() == b.getNumber() && getSign() == b.getSign();
}

bool BigInteger::operator!=(BigInteger b)
{
	return !(*this == b);
}

bool BigInteger::operator<(BigInteger b)
{
	bool sign1 = getSign();
	bool sign2 = b.getSign();

	if (sign1 && !sign2)
		return true;
	else if (!sign1 && sign2)
		return false;
	else if (!sign1)
	{
		if (getNumber().length() < b.getNumber().length())
			return true;
		if (getNumber().length() > b.getNumber().length())
			return false;
		return getNumber() < b.getNumber();
	}
	return b.abs_bi() < abs_bi();
}

bool BigInteger::operator>(BigInteger b)
{
	return (*this != b) && !(*this < b);
}

bool BigInteger::operator>=(BigInteger b)
{
	return (*this == b) || (*this > b);
}

bool BigInteger::operator<=(BigInteger b)
{
	return (*this == b) || (*this < b);
}

BigInteger BigInteger::operator+(BigInteger b)
{
	int sum_sign = 1;
	bool res_sign = false;
	string first;
	string second;
	int final_n;
	if (getSign() == b.getSign())
	{
		if (abs_bi() > b.abs_bi())
		{
			first = getNumber();
			second = b.getNumber();
		}
		else
		{
			first = b.getNumber();
			second = getNumber();
		}
		res_sign = getSign();
	}
	else
	{
		sum_sign = -1;
		if (abs_bi() > b.abs_bi())
		{
			first = getNumber();
			second = b.getNumber();
			res_sign = getSign();
		}
		else
		{
			first = b.getNumber();
			second = getNumber();
			res_sign = b.getSign();
		}
	}
	final_n = first.size() - second.size();
	int temp = 0;
	for (auto i = first.size() - 1; i >= final_n && i != string::npos; --i)
	{
		first[i] += sum_sign * temp + sum_sign * (second[i - final_n] - '0');
		if ((first[i] - '0') > 9 || (first[i] - '0') < 0)
		{
			temp = 1;
			first[i] -= sum_sign * 10;
		}
		else
			temp = 0;
	}
	int n = 1;
	while (temp)
	{
		if ((final_n - n) >= 0)
		{
			first[final_n - n] += sum_sign * temp;
			if ((first[final_n - n] - '0') > 9 || (first[final_n - n] - '0') < 0)
			{
				temp = 1;
				first[final_n - n] -= sum_sign * 10;
			}
			else
			{
				temp = 0;
			}
			n++;
		}
		else
		{
			first.insert(0, 1, '1');
			temp = 0;
		}
	}
	BigInteger result(first, res_sign);
	return result;
}

BigInteger BigInteger::operator-(BigInteger b)
{
	return *this + BigInteger(b.getNumber(), !b.getSign());
}

BigInteger& BigInteger::operator+=(BigInteger b)
{
	*this = *this + b;
	return *this;
}

BigInteger& BigInteger::operator-=(BigInteger b)
{
	*this = *this - b;
	return *this;
}

BigInteger& BigInteger::operator++()
{
	*this += 1;
	return *this;
}

BigInteger BigInteger::operator++(int)
{
	BigInteger origin = *this;
	*this += 1;
	return origin;
}

BigInteger& BigInteger::operator--()
{
	*this -= 1;
	return *this;
}

BigInteger BigInteger::operator--(int)
{
	BigInteger origin = *this;
	*this -= 1;
	return origin;
}

BigInteger BigInteger::operator*(BigInteger b)
{
	string num1 = getNumber();
	string num2 = b.getNumber();
	if ((num1 == "0") || (num2 == "0"))
		return BigInteger();
	bool resSign = !(getSign() == b.getSign());
	if (num1.size() == 1 && num2.size() == 1)
	{
		auto n1 = num1[0] - '0';
		auto n2 = num2[0] - '0';
		auto nn = n1 * n2;
		return BigInteger(to_string(nn));
	}
	if (num1 == "1")
		return BigInteger(num2, resSign);
	if (num2 == "1")
		return BigInteger(num1, resSign);
	size_t alignPos = max(num1.size(), num2.size());
	if (alignPos % 2)
		alignPos++;
	BigInteger N(num1);
	N.align(alignPos);
	BigInteger M(num2);
	M.align(alignPos);
	BigInteger A(N.getNumber().substr(0, alignPos / 2));
	BigInteger B(N.getNumber().substr(alignPos / 2));
	BigInteger C(M.getNumber().substr(0, alignPos / 2));
	BigInteger D(M.getNumber().substr(alignPos / 2));
	auto first = (A * C).prodByTen(alignPos);
	auto second = ((A * D) + (B * C)).prodByTen(alignPos / 2);
	auto third = B * D;
	BigInteger res = first + second + third;
	res.setSign(resSign);
	return res;
}

BigInteger BigInteger::operator/(BigInteger b)
{
	if (b.number == "0")
		throw invalid_argument("division by zero");
	if (number == "0")
		return BigInteger();
	if (b.number == "1")
		return *this;
	BigInteger div;
	BigInteger tmp(this->getNumber());
	while (tmp >= b.abs_bi())
	{
		div++;
		tmp -= b;
	}
	div.setSign(!(getSign() == b.getSign()));
	return div;
}

BigInteger BigInteger::operator%(BigInteger b)
{
	if (b.number == "0")
		throw invalid_argument("division by zero");
	if (number == "0" || b.number == "1")
		return BigInteger();
	BigInteger tmp(this->getNumber());
	while (tmp > b.abs_bi())
	{
		tmp -= b;
	}
	tmp.setSign(!(getSign() == b.getSign()));
	return tmp;
}

BigInteger& BigInteger::operator*=(BigInteger b)
{
	*this = *this * b;
	return *this;
}

BigInteger& BigInteger::operator/=(BigInteger b)
{
	*this = *this / b;
	return *this;
}

BigInteger& BigInteger::operator%=(BigInteger b)
{
	*this = *this % b;
	return *this;
}

BigInteger BigInteger::operator-()
{
	return *this * -1;
}

bool BigInteger::isnumber(const string& number)
{
	if (number == "" || (number[0] != '-' && !isdigit(number[0])))
		return false;
	for (auto it = number.begin() + 1; it != number.end(); ++it)
	{
		if (!isdigit(*it))
			return false;
	}
	return true;
}

bool BigInteger::isZero(const string& number)
{
	for (auto digit : number)
	{
		if ((digit - '0') != 0)
			return false;
	}
	return true;
}

void BigInteger::align(size_t n)
{
	if (number.size() < n)
		number.insert(0, n - number.size(), '0');
}

BigInteger BigInteger::prodByTen(size_t n)
{
	if (number == "0")
		return *this;
	number.insert(number.size(), n, '0');
	return *this;
}

void BigInteger::clearZeroes()
{
	if (number != "0")
	{
		if (isZero(number))
			setNumber("0");
		else
		{
			while (number.front() == '0')
				number.erase(0, 1);
		}
	}
}

#endif