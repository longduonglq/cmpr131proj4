//Names: Christopher Gomez, Gia Minh Hoang
//Date: 3/17/2021
//Description: Implementation file for the polynomials class
#pragma once
#include <iostream>
#include "../input.h"
#include <string>	

using namespace std;

namespace rational {
	class Rational {
	private:
		int numer;
		int denom;
	public:
		//preconditions: A rational object
		//postconditions: normalizes the contained fraction 
		void normalize();
		//preconditions:  N/A
		//postconditions: creates a default rational object
		Rational();
		//preconditions: A numerator and a denominator
		//postconditions: creates a rational object with numerator/denominator
		Rational(int numer, int denom);
		//preconditions: A numerator
		//postconditions: creates a rational object that is Numerator/1
		Rational(int numer);
		//preconditions: a new numerator
		//postconditions: sets the contained numerator to the new numerator
		void setNum(int num);
		//preconditions: a new denominator
		//postconditions: sets the contained numerator to the new numerator
		void setDenom(int num);
		//preconditions: a rational object
		//postconditions: returns the contained numerator
		int getNum();
		//preconditions: a rational object
		//postconditions: returns the contained denominator
		int getDenom();
		//preconditions: a Rational object
		//postconditions: allows the user to directly change the contained fraction. Existing contents will be lost
		friend istream& operator >> (istream& ins, Rational& object);
		//preconditions: A rational object
		//postconditions: displays the rational object as a fraction
		friend ostream& operator << (ostream& outs, const Rational& object);
		//preconditions: two rational objects
		//postconditions: returns true if the contents of the objects are equal, false if not
		friend bool operator == (const Rational obj1, const Rational obj2);
		//preconditions: two rational objects
		//postconditions: returns true if the contents are not equal, false if they are
		friend bool operator != (const Rational obj1, const Rational obj2);
		//preconditions: two rational objects
		//postconditions: returns true if the contained fraction of object one is less than that of object 2, false if not
		friend bool operator < (const Rational obj1, const Rational obj2);
		//preconditions: two rational objects
		//postconditions: returns true if the contained fraction of object one is less than or equal to object 2, false if not
		friend bool operator <= (const Rational obj1, const Rational obj2);
		//preconditions: two rational objects
		//postconditions: returns true if the contained fraction of object one is greater than that of object 2, false if not
		friend bool operator > (const Rational obj1, const Rational obj2);
		//preconditions: two rational objects
		//postconditions: returns true if the contained fraction of object one is greater than or equal to that of object 2, false if not
		friend bool operator >= (const Rational obj1, const Rational obj2);
		//preconditions: two rational objects
		//postconditions: returns the sum of the two objects
		friend Rational operator + (const Rational& obj1, const Rational& obj2);
		//preconditions: two rational objects
		//postconditions: returns the difference of the two rational objects
		friend Rational operator - (const Rational& obj1, const Rational& obj2);
		//preconditions: two rational objects
		//postconditions: returns the product of the two rational objects
		friend Rational operator * (const Rational& obj1, const Rational& obj2);
		//preconditions: two rational objects
		//postconditions:returns the dividend of the two rational objects
		friend Rational operator / (const Rational& obj1, const Rational& obj2);
		//preconditions: a rational object and a integer
		//postconditions:returns the sum of the rational number and the integer
		friend Rational operator + (const Rational& obj1, const int& obj2);
		//preconditions: a integer and a rational object
		//postconditions: returns the sum of the integer and the rational object
		friend Rational operator + (const int& obj1, const Rational& obj2);
		//preconditions: a rational object and a integer
		//postconditions: returns the difference of the rational object and the integer
		friend Rational operator - (const Rational& obj1, const int& obj2);
		//preconditions: a integer and a rational object
		//postconditions:returns the difference the integer and the rational object 
		friend Rational operator - (const int& obj1, const Rational& obj2);
		//preconditions: a rational object and an integer
		//postconditions: returns the product of the object times the integer
		friend Rational operator * (const Rational& obj1, const int& obj2);
		//preconditions: a integer and a rational object
		//postconditions: returns the product of the integer times the object
		friend Rational operator * (const int& obj1, const Rational& obj2);
		//preconditions: a rational object and an integer
		//postconditions: returns the dividend of the rational object divided by the integer
		friend Rational operator / (const Rational& obj1, const int& obj2);
		//preconditions: an integer and a rational object
		//postconditions: returns the dividend of the integer divided by the rational object
		friend Rational operator / (const int& obj1, const Rational& obj2);
	};
}
