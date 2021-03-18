// Participants: Andrew Thompson and Gabriela Lopez
// Date: 03-11-21
// Description: Complex numbers implementation

#include "complex.h"
#include "input.h"

Complex::Complex() : real(0.0), imag(0.0)
{}

Complex::Complex(Complex& object)
{
	real = object.real;
	imag = object.imag;
}

Complex::Complex(double realPart, double imagPart)
{
	real = realPart;
	imag = imagPart;
}

Complex::Complex(double realPart) : imag(0.0)
{
	real = realPart;
}

void Complex::setRealPart(double value)
{
	real = value;
}

void Complex::setImaginaryPart(double value)
{
	imag = value;
}

double Complex::getRealPart()
{
	return real;
}

double Complex::getImaginaryPart()
{
	return imag;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// MENUS AND HEADER ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Complex::complexHeader()
{
	cout << '\t' << char(201) << string(65, char(205)) << char(187) << '\n';
	cout << '\t' << char(186) << "     \t\t     CMPR131: Complex Numbers                     " << char(186) << '\n';
	cout << '\t' << char(186) << " Made by:                                                        " << char(186) << '\n';
	cout << '\t' << char(186) << " - Gabriela Lopez\t- Andrew Thompson\t- Lincoln Nguyen  " << char(186) << '\n';
	cout << '\t' << char(186) << " - Long Duong\t\t- Christopher Gomez\t- Gia Minh Hoang  " << char(186) << '\n';
	cout << '\t' << char(186) << " - Duyen Tran                                                    " << char(186) << '\n';
	cout << "\t" << char(200) << string(65, char(205)) << char(188) << "\n";
}

int Complex::complexMainMenu() 
{
	int opt;
	cout << "\n\t 1- A complex number.\n";
	cout << "\n\t 2- Multiple complex numbers.\n";
	cout << "\n\t 0- Quit.\n\n";
	cout << '\t' << string(40, char(205)) << '\n';
	opt = inputInteger("\n\t Option: ", 0, 2);
	return opt;
}

int Complex::aComplexMenu()
{
	int opt;
	cout << "\n\t 1- Enter the real number\n";
	cout << "\t 2- Enter the imag number\n";
	cout << "\t 3- Display the complex number\n";
	cout << "\t 4- Negate the complex number\n";
	cout << "\t 5- Add (+) the complex number with a constant\n";
	cout << "\t 6- Subtract (-) the complex number with a constant\n";
	cout << "\t 7- Multiply (*) the complex number with a constant\n";
	cout << "\t 8- Divide (/) the complex number with a constant\n";
	cout << "\t 0- Quit.\n\n";
	cout << '\t' << string(67, char(205)) << '\n';
	opt = inputInteger("\n\t Option: ", 0, 8);
	return opt;
}

int Complex::twoComplexMenu()
{
	int opt;
	cout << "\n\t 1- Enter complex number C1.\n";
	cout << "\t 2- Enter complex number C2.\n";
	cout << "\t 3- Verify condition operators (== and !=) of C1 and C2.\n";
	cout << "\t 4- Evaluate arithmatic operators (+, - , * and /) of C1 and C2.\n";
	cout << "\t 5- Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?\n";
	cout << "\t 0- Quit.\n\n";
	cout << '\t' << string(67, char(205)) << '\n';
	opt = inputInteger("\n\t Option: ", 0, 5);
	return opt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////// OVERLOADED FUNCTIONS FOR A COMPLEX NUMBER AND A CONSTANT ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Complex operator + (const Complex& obj1, double value)
{
	Complex temp;
	temp.real = obj1.real + value;
	temp.imag = obj1.imag;
	return temp;
}

Complex operator -(const Complex& obj1, double value)
{
	Complex temp;
	temp.real = obj1.real - value;
	temp.imag = obj1.imag;
	return temp;
}

Complex operator *(const Complex& obj1, double value)
{
	Complex temp;
	temp.real = (obj1.real * value);
	temp.imag = (obj1.real * value);
	return temp;
}

Complex operator /(const Complex& obj1, double value)
{
	Complex temp;
	temp.real = (obj1.real / value);
	temp.imag = (obj1.imag / value);
	return temp;
}

Complex operator + (double value, const Complex& obj1)
{
	Complex temp;
	temp.real = value + obj1.real;
	temp.imag = obj1.imag;
	return temp;
}

Complex operator -(double value, const Complex& obj1)
{
	Complex temp;
	temp.real = value - obj1.real;
	temp.imag = obj1.imag;
	return temp;
}

Complex operator *(double value, const Complex& obj1)
{
	Complex temp;
	temp.real = (value * obj1.real);
	temp.imag = (value * obj1.imag);
	return temp;
}

Complex operator /(double value, const Complex& obj1)
{
	Complex temp;
	temp.real = (obj1.real / value);
	temp.imag = (obj1.imag / value);
	return temp;
}

Complex operator -(const Complex& obj1)
{
	Complex temp;
	if (obj1.real == 0 && obj1.imag == 0)
	{
		temp.real = obj1.real;
		temp.imag = obj1.imag;
		return temp;
	}

	if (obj1.real == 0 || obj1.imag == 0)
	{
		if (obj1.real == 0)
		{
			temp.real = obj1.real;
			temp.imag = -obj1.imag;
			return temp;
		}
		else
		{
			temp.real = -obj1.real;
			temp.imag = obj1.imag;
			return temp;
		}
	}

	temp.real = -obj1.real;
	temp.imag = -obj1.imag;
	return temp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// OVERLOADED FUNCTIONS FOR TWO COMPLEX NUMBERS ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Complex operator +(const Complex& obj1, const Complex& obj2)
{
	Complex result;
	result.real = obj1.real + obj2.real;
	result.imag = obj1.imag + obj2.imag;
	return result;
}

Complex operator -(const Complex& obj1, const Complex& obj2)
{
	Complex result;
	result.real = obj1.real - obj2.real;
	result.imag = obj1.imag - obj2.imag;
	return result;
}

istream& operator >>(istream& ins, Complex& theObject)
{
	theObject.real = inputDouble("\n\tEnter a number (double value) for the real part of the number: ");
	theObject.imag = inputDouble("\tEnter a number (double value) for the imag part of the number: ");
	return ins;
}

ostream& operator << (ostream& outs, const Complex& object) {

	if (object.imag * -1 > 0)
	{
		outs << object.real << " - " << object.imag * -1 << "i";
		return outs;
	}
	else if (object.imag != 0) {
		outs << object.real << " + " << object.imag << "i";
		return outs;
	}
	else
	{
		outs << object.real;
		return outs;
	}
}

bool operator ==(const Complex& complex1, const Complex& complex2)
{
	if (complex1.real == complex2.real && complex1.imag == complex2.imag)
		return true;
	else
		return false;
}


bool operator !=(const Complex& complex1, const Complex& complex2)
{
	if (complex1.real != complex2.real && complex1.imag != complex2.imag)
		return true;
	else
		return false;
}

Complex operator *(const Complex& obj1, const Complex& obj2)
{
	Complex result;
	result.real = (obj1.real * obj2.real)-(obj1.imag*obj2.imag);
	result.imag = (obj1.real * obj2.imag) + (obj2.real * obj1.imag);
	return result;
}

Complex operator /(const Complex& obj1, const Complex& obj2)
{
	Complex result;
	result.real = ((obj1.real * obj2.real) + (obj1.imag * obj2.imag)) / ((pow(obj2.real, 2) + pow(obj2.imag, 2)));
	result.imag = ((obj2.real * obj1.imag) - (obj1.real * obj2.imag)) / ((pow(obj2.real, 2) + pow(obj2.imag, 2)));
	return result;
}

void evaluate(const Complex& C1, const Complex& C2)
{
	Complex temp;
	Complex C3(1.07109, 0.120832);
	cout << "\tC1 = " << C1 << '\n';
	cout << "\tC2 = " << C2 << '\n';
	cout << "\tC3 = " << C3 << "\n\n";
	cout << "\tEvaluating expression...\n";
	cout << "\t (3 *(C1 + C2) /7) / (C2 - C1 / 9) != (" << C3 << ") ?";
	cout << "\n\tStep #1: (3 *(C1 + C2) /7) /" << "(C2 - " << C1 / 9 << ") = (" << C3 << ")";
	cout << "\n\tStep #2: ((" << 3 * (C1 + C2) << ") / 7) /" << C2 - (C1 / 9) << ") != (" << C3 << ")";
	cout << "\n\tStep #3: (" << (3 * (C1 + C2)) / 7 << ") /( " << C2 - (C1 / 9) << ") != (" << C3 << ")";
	cout << "\n\tStep #4: (" << ((3 * (C1 + C2)) / 7) / (C2 - (C1 / 9)) << ") != (" << C3 << ") ?";
	cout << "\n\tStep #5: ";
	if (((3 * (C1 + C2)) / 7) / (C2 - (C1 / 9)) != C3)
	{
		cout << "\ttrue";
	}
	else if (((3 * (C1 + C2)) / 7) / (C2 - (C1 / 9)) == C3)
	{
		cout << "\tfalse";
	}
	cout << '\n';
}