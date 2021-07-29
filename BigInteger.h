#pragma once
#include <string>

using namespace std;

class BigInteger
{
	string number;
	bool sign;

	/*
	number - строка
	проверка является ли строка числом
	*/
	bool isnumber(const string& number);
	/*
	number - строка
	проверка на 0
	*/
	bool isZero(const string& number);
	/*
	number - строка
	проверка на соответствие разряда числа, в случае несоответствия добавляются нули
	*/
	void align(size_t n);
	/*
	n - степень числа 10
	умножение числа BigInteger на 10 в степени n
	*/
	BigInteger prodByTen(size_t n = 1);
	/*
	удаление нулей перед числом
	*/
	void clearZeroes();

public:
	/*
	пустой конструктор создает число со значением по умолчанию 0
	*/
	BigInteger();
	/*
	s - строка
	конструктор со строкой создает число равное значению числа в строке s
	*/
	BigInteger(string s);
	/*
	s - строка
	sign - логическая переменная определяющая знак числа
	конструктор со строкой и знаком создает число равное значению числа в строке s и со знаком sign
	*/
	BigInteger(string s, bool sign);
	/*
	n - целое число
	конструктор создает число равное n
	*/
	BigInteger(long long int n);
	/*
	s - строка, являющаяся числом
	устанавливает значение number равным числу записанному в строке s
	*/
	void setNumber(string s);
	/*
	возвращает значение number
	*/
	const string& getNumber();
	/*
	s - строка, являющаяся числом
	устанавливает значение sign
	*/
	void setSign(bool s);
	/*
	возвращает значение sign
	*/
	const bool& getSign();
	/*
	возвращает модуль числа
	*/
	BigInteger abs_bi();
	// операция присваивания
	void operator=(BigInteger b);
	// проверка на равенство
	bool operator==(BigInteger b);
	// проверка на неравенство
	bool operator!=(BigInteger b);
	// проверка на строгое неравенство больше
	bool operator>(BigInteger b);
	// проверка на строгое неравенство меньше
	bool operator<(BigInteger b);
	// проверка на нестрогое неравенство больше
	bool operator>=(BigInteger b);
	// проверка на нестрогое неравенство меньше
	bool operator<=(BigInteger b);
	// префиксный инкремент
	BigInteger& operator++();
	// постфиксный инкремент
	BigInteger operator++(int);
	// префиксный декремент
	BigInteger& operator--();
	// постфиксный декремент
	BigInteger operator--(int);
	// операция сложения
	BigInteger operator+(BigInteger b);
	// операция вычитания
	BigInteger operator-(BigInteger b);
	// операция умножения алгоритмом Карацубы
	BigInteger operator*(BigInteger b);
	// операция целочисленного деления
	BigInteger operator/(BigInteger b);
	// операция получения остатка от целочисленного деления
	BigInteger operator%(BigInteger b);
	// операция сложения, совмещённая с присваиванием
	BigInteger& operator+=(BigInteger b);
	// операция вычитания, совмещённая с присваиванием
	BigInteger& operator-=(BigInteger b);
	// операция умножения, совмещённая с присваиванием
	BigInteger& operator*=(BigInteger b);
	// операция деления, совмещённая с присваиванием
	BigInteger& operator/=(BigInteger b);
	// операция получения остатка от целочисленного деления, совмещённая с присваиванием
	BigInteger& operator%=(BigInteger b);
	// унарный минус
	BigInteger operator-();
	// операция вывода в поток
	friend ostream& operator<<(ostream& os, const BigInteger& b)
	{
		if (b.sign)
			os << "-";
		os << b.number;
		return os;
	}
};