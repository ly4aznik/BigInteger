#include <iostream>
#include "BigInteger.h"
#include <cassert>
using namespace std;
/*
    ���������� ��������� �� cl.exe, g++ � clang++.
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "����..." << endl;
    cout << "�������� �������������: " << endl;
    BigInteger int0, int12(12), int123("-123");
    cout << "��-���������: " << int0 << endl
        << "�� ������ �����: " << int12 << endl
        << "�� ������: " << int123 << endl
        << "�������� ���������� ���������: " << endl;
    assert(int0 >= int123);
    cout << "�������� >= �������� � ���� �������� >, <, ==, != (��. ����������)." << endl
        << "0 >= -123 ? : " << boolalpha << (int0 >= int123) << endl
        << "�������� �������������� ��������: " << endl;
    assert((int12 + int123) == BigInteger(-111));
    assert((int12 - int123) == BigInteger(135));
    assert((int123 * int12) == BigInteger(-1476));
    assert((BigInteger(3) % BigInteger(2)) == BigInteger(1));
    assert((BigInteger(24) / int12) == BigInteger(2));
    assert(++BigInteger(11) == int12);
    assert(--BigInteger(13) == int12);
    assert(BigInteger(11)++ != int12);
    assert(BigInteger(13)-- != int12);
    cout << "12 + (-123) = " << (int12 + int123) << endl
        << "12 - (-123) = " << (int12 - int123) << endl
        << "-123 * 12 = " << (int123 * int12) << endl
        << "3 % 2 = " << (BigInteger(3) % BigInteger(2)) << endl
        << "24 / 12 = " << (BigInteger(24) / int12) << endl
        << "++11 = " << ++BigInteger(11) << endl
        << "--13 = " << --BigInteger(13) << endl
        << "11++ = " << BigInteger(11)++ << endl
        << "13-- = " << BigInteger(13)-- << endl;
    int12 *= BigInteger(13);
    assert(int12 == BigInteger(156));
    cout << "12 *= 13 -> " << int12 << endl;
    int12 /= BigInteger(12);
    assert(int12 == BigInteger(13));
    cout << "156 /= 12 -> " << int12 << endl;
    int12 = BigInteger(12);
    assert(-int12 == BigInteger(-12));
    cout << "-(12) = " << -int12 << endl
        << "�������� ���������� �������: " << endl;
    int12 = BigInteger(-13);
    cout << "�������� ������� 'abs_bi':" << endl;
    assert(int12.abs_bi() == BigInteger(13));
    cout << "|-13| = 13 ? :" << (int12 == BigInteger(-13)) << endl;
    cout << "�������� ��������� ������������: " << endl;
    int12 = int0;
    assert(int12 == int0);
    cout << "12 := 0 -> " << int12 << endl
        << "������������� �������� �� �������� ������������ � �� ����������� ������� ������� �����: " << endl
        << "100! = ";
    BigInteger res(1);
    for (auto i = 1; i <= 100; ++i)
        res *= i;
    assert(res.getNumber() == "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
    cout << res;

    system("pause");
}