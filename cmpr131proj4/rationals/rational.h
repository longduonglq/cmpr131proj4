// Name: 
// Date: 
// Description: 

#ifndef RATIONAL_H

#define RATIONAL_H
#include <iostream>
using namespace std;

namespace rat {
	class Rational {
	private:
		void normalize();
	public:
		int numer;
		int denom;
		Rational();
		Rational(int numer, int denom);
		Rational(int numer);

		friend istream& operator >> (istream& ins, Rational& object);
		friend ostream& operator << (ostream& outs, const Rational& object);

		friend bool operator == (const Rational obj1, const Rational& obj2);
		friend bool operator < (const Rational obj1, const Rational& obj2);
		friend bool operator <= (const Rational obj1, const Rational& obj2);
		friend bool operator > (const Rational obj1, const Rational& obj2);
		friend bool operator >= (const Rational obj1, const Rational& obj2);
		friend Rational operator + (const Rational obj1, const Rational& obj2);
		friend Rational operator - (const Rational obj1, const Rational& obj2);
		friend Rational operator * (const Rational obj1, const Rational& obj2);
		friend Rational operator / (const Rational obj1, const Rational& obj2);
	};
}
#endif