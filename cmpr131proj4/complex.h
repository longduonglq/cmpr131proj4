// Participants: Andrew Thompson and Gabriela Lopez
// Date: 03-11-21
// Description: Complex numbers header

#pragma once

#include <iostream>
using namespace std;

class Complex
{
public:
	//Precondition: declare a complex object
	//Postcondition: initializes all variables
	Complex();

	//Precondition: declare a copy of a complex object
	//Postcondition: initializes all variables copying the original object into a new one
	Complex(Complex& object);

	//Precondition: declare a complex object with two double data type numbers
	//Postcondition: initializes all variables with values given
	Complex(double realPart, double imagPart);

	//Precondition: declare a complex object with one double data type number
	//Postcondition: initializes the real part of the complex number with the value given
	Complex(double realPart);

	//Precondition: a double value for the real part of a complex number
	//Postcondition: sets a new value for the real part
	void setRealPart(double value);

	//Precondition: a double value for the imaginary part of a complex number
	//Postcondition: sets a new value for the imaginary part
	void setImaginaryPart(double value);

	//Precondition: N/A
	//Postcondition: returns the real part value of the complex number
	double getRealPart();

	//Precondition: N/A
	//Postcondition: returns the real part value of the complex number
	double getImaginaryPart();

	//Precondition: N/A
	//Postcondition: prints project title and collaborator names
	void complexHeader();

	//Precondition: N/A
	//Postcondition: prints principal menu and returns option selected
	int complexMainMenu();

	//Precondition: N/A
	//Postcondition: prints menu for operations with a complex number and a constant then returns the option selected
	int aComplexMenu();

	//Precondition: N/A
	//Postcondition: prints menu for operations with two complex numbers and return the option selected
	int twoComplexMenu();

	//Preconditions: A complex object and a value
	//Postconditions: returns the sum of the two in complex form
	friend Complex operator + (const Complex& obj1, double value);

	//Preconditions: A complex object and a value
	//Postconditions: returns the differece of the two in complex form
	friend Complex operator -(const Complex& obj1, double value);

	//Preconditions: A complex object and a value
	//Postconditions: returns the product of the two in complex form
	friend Complex operator *(const Complex& obj1, double value);

	//Preconditions: a complex object and a value 
	//Postconditions: returns the dividend of the two in complex form
	friend Complex operator /(const Complex& obj1, double value);

	//Preconditions: a complex object to negate
	//Postconditions: returns the complex number * -1 to change sign
	friend Complex operator -(const Complex& obj1);

	//Preconditions: A value and a complex object
	//Postconditions: returns the sum of the two in complex form
	friend Complex operator + (double value, const Complex& obj1);

	//Preconditions: A value and a complex object
	//Postconditions: returns the diffrence of the two in complex form
	friend Complex operator -(double value, const Complex& obj1);

	//Preconditions: A value and a complex object
	//Postconditions: returns the product of the two
	friend Complex operator *(double value, const Complex& obj1);

	//Preconditions: A value and a complex object
	//Postconditions: returns the dividend of the two in complex form 
	friend Complex operator /(double value, const Complex& obj1);

	//Precondition: overloading + operator for complex addition
	//Postcondition: returns the sum result of a complex object
	friend Complex operator +(const Complex& obj1, const Complex& obj2);

	//Precondition: overloading - operator for complex subtraction
	//Postcondition: returns the sub result of a complex object
	friend Complex operator -(const Complex& obj1, const Complex& obj2);

	//Precondition: overloading * operator for complex multiplication
	//Postcondition: returns the mul result of a complex object
	friend Complex operator *(const Complex& obj1, const Complex& obj2);

	//Precondition: overloading / operator for complex division
	//Postcondition: returns the div result of a complex object
	friend Complex operator /(const Complex& obj1, const Complex& obj2);

	//Precondition: a complex object to print
	//Postcondition: prints the complex number given
	friend ostream& operator <<(ostream& outs, const Complex& obj);

	//Precondition: a complex object
	//Postcondition: ask user for real and imaginary part for the new complex number
	friend istream& operator >>(istream& ins, Complex& theObject);

	//Precondition: two complex objects to compare
	//Postcondition: 
	friend bool operator ==(const Complex& complex1, const Complex& complex2);

	//Precondition:
	//Postcondition:
	friend bool operator !=(const Complex& complex1, const Complex& complex2);

	//preconditions: two complex obj
	//postconditions: Displays an evaluation on whether or not the expession contained is equal to the complex number 1.07109 + 0.120832i
	friend void evaluate(const Complex& C1, const Complex& C2);

private:
	double real;
	double imag;
};