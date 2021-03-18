

#pragma once
#include <iostream>
#include "../input.h"
#include <string>	

using namespace std;

namespace rational 
{
	class Rational 
	{
	private:
		int numer;
		int denom;
	public:

		void normalize();

		Rational();
		Rational(int numer, int denom);
		Rational(int numer);

		void setNum(int num);
		void setDenom(int num);
		int getNum();
		int getDenom();

		friend istream& operator >> (istream& ins, Rational& object);
		friend ostream& operator << (ostream& outs, const Rational& object);

		friend bool operator == (const Rational obj1, const Rational obj2);
		friend bool operator != (const Rational obj1, const Rational obj2);
		friend bool operator < (const Rational obj1, const Rational obj2);
		friend bool operator <= (const Rational obj1, const Rational obj2);
		friend bool operator > (const Rational obj1, const Rational obj2);
		friend bool operator >= (const Rational obj1, const Rational obj2);

		friend Rational operator + (const Rational& obj1, const Rational& obj2);
		friend Rational operator - (const Rational& obj1, const Rational& obj2);
		friend Rational operator * (const Rational& obj1, const Rational& obj2);
		friend Rational operator / (const Rational& obj1, const Rational& obj2);

		friend Rational operator + (const Rational& obj1, const int& obj2);
		friend Rational operator + (const int& obj1, const Rational& obj2);
		friend Rational operator - (const Rational& obj1, const int& obj2);
		friend Rational operator - (const int& obj1, const Rational& obj2);
		friend Rational operator * (const Rational& obj1, const int& obj2);
		friend Rational operator * (const int& obj1, const Rational& obj2);
		friend Rational operator / (const Rational& obj1, const int& obj2);
		friend Rational operator / (const int& obj1, const Rational& obj2);
	};
}