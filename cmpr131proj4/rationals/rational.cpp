// Name: 
// Date: 
// Description: 

#include <iostream>
#include <string>
#include "Rational.h"

namespace rat {
	Rational::Rational() : numer(0), denom(0) {}
	Rational::Rational(int newNumer, int newDenom) : numer(newNumer), denom(newDenom) {}
	Rational::Rational(int newNumer) : numer(newNumer), denom(1) {}
	int gcd(int num1, int num2) {
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
	void Rational::normalize() {
		if (numer == 0) {
			denom = 1;
		}
		else if (denom < 0) {
			numer = -1 * numer;
			denom = -1 * denom;
		}
		int div = gcd(numer, denom);
		numer = numer / div;
		denom = denom / div;
	}
	bool operator == (const Rational& obj1, const Rational& obj2) {
		return (obj1.numer * obj2.denom == obj2.numer * obj1.denom);
	}
	bool operator >= (const Rational& obj1, const Rational& obj2) {
		return (obj1.numer * obj2.denom >= obj2.numer * obj1.denom);
	}
	bool operator <= (const Rational& obj1, const Rational& obj2) {
		return (obj1.numer * obj2.denom <= obj2.numer * obj1.denom);
	}
	bool operator > (const Rational& obj1, const Rational& obj2) {
		return (obj1.numer * obj2.denom > obj2.numer * obj1.denom);
	}
	bool operator < (const Rational& obj1, const Rational& obj2) {
		return (obj1.numer * obj2.denom < obj2.numer* obj1.denom);
	}
	Rational operator + (const Rational& obj1, const Rational& obj2) {
		Rational temp;
		temp.numer = obj1.numer + obj2.numer;
		return temp;
	}
	Rational operator - (const Rational& obj1, const Rational& obj2) {
		Rational temp;
		temp.numer = obj1.numer - obj2.numer;
		return temp;
	}
	Rational operator * (const Rational& obj1, const Rational& obj2) {
		Rational temp;
		temp.numer = obj1.numer * obj2.numer;
		return temp;
	}
	Rational operator / (const Rational& obj1, const Rational& obj2) {
		Rational temp;
		temp.numer = obj1.numer / obj2.numer;
		return temp;
	}
	ostream& operator << (ostream& outs, const Rational& obj) {
		outs << obj.numer << "/" << obj.denom;
		return outs;
	}
	istream& operator >> (istream& ins, Rational& obj) {
		cout << "Numerator: ";
		ins >> obj.numer;

		cout << "Denominator: ";
		ins >> obj.denom;
		return ins;
	}
}