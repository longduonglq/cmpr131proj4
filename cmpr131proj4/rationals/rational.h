#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace rational {
	class Rational {
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

namespace rational {
	Rational::Rational() : numer(0), denom(1) {}
	Rational::Rational(int newNumer, int newDenom) : numer(newNumer), denom(newDenom) {}
	Rational::Rational(int newNumer) : numer(newNumer), denom(1) {}

	int GreatestCommondenom(int num1, int num2) {
		if (num1 == 0 || num2 == 0)
			return 1;
		if (num1 < 0)
			num1 = -1 * num1;
		if (num2 < 0)
			num2 = -1 * num2;
		while (num2 != 0) {
			int temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}
		return num1;
	}
	void Rational::setNum(int num)
	{
		num = inputInteger("\n\tEnter an integer for the numer:");
		numer = num;
	}
	void Rational::setDenom(int den)
	{
		while (true)
		{
			den = inputInteger("\n\tEnter an integer for the denom:");

			if (den == 0)
				cout << "\n\tdenom cannot be zero please try again.\n";
			else
				break;
		}
		denom = den;
	}

	int Rational::getNum()
	{
		return numer;
	}

	int Rational::getDenom()
	{
		return denom;
	}

	void Rational::normalize() {
		if (numer == 0) {
			denom = 1;
		}
		else if (denom < 0) {
			numer = -1 * numer;
			denom = -1 * denom;
		}
		int div = GreatestCommondenom(numer, denom);
		numer = numer / div;
		denom = denom / div;
	}


	bool operator == (const Rational obj1, const Rational obj2)
	{
		return (obj1.numer * obj2.denom == obj2.numer * obj1.denom);
	}
	bool operator != (const Rational obj1, const Rational obj2)
	{
		return (obj1.numer * obj2.denom != obj2.numer * obj1.denom);
	}
	bool operator >= (const Rational obj1, const Rational obj2)
	{
		return (obj1.numer * obj2.denom >= obj2.numer * obj1.denom);
	}
	bool operator <= (const Rational obj1, const Rational obj2)
	{
		return (obj1.numer * obj2.denom <= obj2.numer * obj1.denom);
	}
	bool operator > (const Rational obj1, const Rational obj2)
	{
		return (obj1.numer * obj2.denom > obj2.numer * obj1.denom);
	}
	bool operator < (const Rational obj1, const Rational obj2)
	{
		return (obj1.numer * obj2.denom < obj2.numer* obj1.denom);
	}

	// ++++++++++++
	Rational operator + (const Rational& obj1, const Rational& obj2)
	{
		Rational temp;
		temp.numer = obj1.numer * obj2.denom + obj2.numer * obj1.denom;
		temp.denom = obj1.denom * obj2.denom;
		return temp;
	}
	Rational operator + (const Rational& obj1, const int& obj2)
	{
		Rational temp;
		temp.numer = ((obj1.numer * 1) + (obj2 * obj1.denom));
		temp.denom = obj1.denom;
		return temp;
	}
	Rational operator + (const int& obj1, const Rational& obj2)
	{
		Rational temp;
		temp.numer = ((obj2.numer * 1) + (obj1 * obj2.denom));
		temp.denom = obj2.denom;
		return temp;
	}

	// ------------
	Rational operator - (const Rational& obj1, const Rational& obj2)
	{
		Rational temp;
		temp.numer = obj1.numer * obj2.denom - obj2.numer * obj1.denom;
		temp.denom = obj1.denom * obj2.denom;
		return temp;
	}
	Rational operator - (const Rational& obj1, const int& obj2)
	{
		// 2/4 + 2 = 2*1 + 4* -2
		Rational temp;
		temp.numer = ((obj1.numer * 1) + ((obj2 * -1) * obj1.denom));
		temp.denom = obj1.denom;
		return temp;
	}
	Rational operator - (const int& obj1, const Rational& obj2)
	{
		Rational temp;
		// 2 - 2/4 = 2 * 4 + -2*1
		temp.numer = ((obj1 * obj2.denom) + (-obj2.numer * 1));
		temp.denom = obj2.denom;
		return temp;
	}

	// ***********
	Rational operator * (const Rational& obj1, const Rational& obj2)
	{
		Rational temp;
		temp.numer = obj1.numer * obj2.numer;
		temp.denom = obj1.denom * obj2.denom;
		return temp;
	}
	Rational operator * (const Rational& obj1, const int& obj2)
	{
		Rational temp;
		temp.numer = obj1.numer * obj2;
		temp.denom = obj1.denom;
		return temp;
	}
	Rational operator * (const int& obj1, const Rational& obj2)
	{
		Rational temp;
		temp.numer = obj1 * obj2.numer;
		temp.denom = obj2.denom;
		return temp;
	}

	// //////////////
	Rational operator / (const Rational& obj1, const Rational& obj2)
	{
		Rational temp;
		temp.numer = obj1.numer * obj2.denom;
		temp.denom = obj2.numer * obj1.denom;
		return temp;
	}
	Rational operator / (const Rational& obj1, const int& obj2)
	{
		Rational temp;
		// 2/4 /2 = 2*1
		temp.numer = obj1.numer * 1;
		temp.denom = obj1.denom * obj2;
		return temp;
	}
	Rational operator / (const int& obj1, const Rational& obj2)
	{
		Rational temp;
		// 2/1 / 2/4 = 2*4 /2*1
		temp.numer = obj1 * obj2.denom;
		temp.denom = obj2.numer * 1;
		return temp;
	}

	// cout
	ostream& operator << (ostream& outs, const Rational& obj) {
		outs << obj.numer << "/" << obj.denom;
		return outs;
	}
	istream& operator >> (istream& ins, Rational& obj) {
		cout << "numer: ";
		ins >> obj.numer;

		cout << "denom: ";
		ins >> obj.denom;
		return ins;
	}
}