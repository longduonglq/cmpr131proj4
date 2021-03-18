#include "polynomials.h"
#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

//Precondition: 2 polynomials
//Postcondition: the sum results of those polynomials.
Polynomials operator+(const Polynomials& lhs, const Polynomials& rhs)
{
	std::vector<double> coeffs;
	for (int i = 0; i < std::max(lhs.coefficients.size(), rhs.coefficients.size()); i++)
	{
		double lhsCoef = i < lhs.coefficients.size() ? lhs.coefficients[i] : 0.0;
		double rhsCoef = i < rhs.coefficients.size() ? rhs.coefficients[i] : 0.0;
		coeffs.push_back(lhsCoef + rhsCoef);
	}
	return Polynomials(std::move(coeffs));
}

//Precondition: 2 polynomials
//Postcondition: the subtraction results of those polynomials.
Polynomials operator-(const Polynomials& lhs, const Polynomials& rhs)
{
	std::vector<double> coeffs;
	for (int i = 0; i < std::max(lhs.coefficients.size(), rhs.coefficients.size()); i++)
	{
		double lhsCoef = i < lhs.coefficients.size() ? lhs.coefficients[i] : 0.0;
		double rhsCoef = i < rhs.coefficients.size() ? rhs.coefficients[i] : 0.0;
		coeffs.push_back(lhsCoef - rhsCoef);
	}
	return Polynomials(std::move(coeffs));
}


std::ostream& operator<<(std::ostream& os, const Polynomials& poly)
{
	for (int i = poly.coefficients.size() - 1; i >= 0; i--)
	{
		if (poly.coefficients[i] == 0) continue;
		else if (poly.coefficients[i] < 0)
			os << std::abs(poly.coefficients[i]) << (i == 0 ? "" : ("x^" + std::to_string(i))) << (i == 0 ? "" : " - ");
		else if (poly.coefficients[i] > 0)
			os << poly.coefficients[i] << (i == 0 ? "" : ("x^" + std::to_string(i))) << (i == 0 ? "" : " + ");
	}
	if (std::all_of(poly.coefficients.begin(), poly.coefficients.end(), [](auto c) { return c == 0;}))
		os << "0";
	return os;
}

//Precondition: A polynomial
//Postcondition: the derivative of that polynomial
Polynomials Polynomials::getDerivative()
{
	std::vector<double> newCoeffs(coefficients);
	for (int i = 0; i < newCoeffs.size() - 1; i++)
	{
		newCoeffs[i] = static_cast<double>(i + 1) * newCoeffs[i + 1];
	}
	newCoeffs.pop_back();
	return Polynomials(std::move(newCoeffs));
}

//Precondition: A polynomial
//Postcondition: the integral of that polynomial
Polynomials Polynomials::getIntergral()
{
	std::vector<double> newCoeffs(coefficients);
	newCoeffs.push_back(0);
	for (int i = newCoeffs.size() - 1; i > 0; i--)
	{
		newCoeffs[i] = newCoeffs[i - 1] * (1 / static_cast<double>(i));
	}
	newCoeffs.at(0) = 0;
	return Polynomials(std::move(newCoeffs));
}

//Precondition: N/A
//Postcondition: return the highest degree of the polynomial
int Polynomials::getHigestDegree() const 
{
	return static_cast<int>(coefficients.size()) - 1;
}

//Precondition: x valueable
//Postcondition:show the result of the polynomial at the x value.
void Polynomials::substituteXEqual()
{
	double substitule = 0;
	double x;

	cout << "X = ";
	cin >> x;

	for (int index = 0; index <= degree; index++)
	{
		substitule += coefficients.at(index) * pow(x, degree - index);
	}
	
	cout << "Substitute of the polynomial at x = " << x << " is: " << substitule << endl;

}

//Precondition: N/A
//Postcondition: constructor
Polynomials::Polynomials(std::vector<double>&& _coefficients)
	: coefficients {std::move(_coefficients)}
{
}

//Precondition: 2 polynomials
//Postcondition: the multiplication results of those 2 polynomials
Polynomials operator *(const Polynomials& lhs, const Polynomials& rhs)
{
	std::vector<double> coeffs(lhs.getHigestDegree() + rhs.getHigestDegree() + 1, 0);
	for (int lhsCoeffIndex = 0; lhsCoeffIndex < lhs.coefficients.size(); lhsCoeffIndex++)
	{
		for (int rhsCoeffIndex = 0; rhsCoeffIndex < rhs.coefficients.size(); rhsCoeffIndex++)
		{
			coeffs[lhsCoeffIndex + rhsCoeffIndex] += lhs.coefficients[lhsCoeffIndex] * rhs.coefficients[rhsCoeffIndex];
		}
	}
	return Polynomials(std::move(coeffs));
}

//Precondition:  a polynomial and a number
//Postcondition: the multiplication results of a polynomial and a number.
Polynomials operator*(const Polynomials& lhs, double constant)
{
	std::vector<double> coeffs(lhs.coefficients);
	for (auto& coeff : coeffs) coeff *= constant;
	return Polynomials(std::move(coeffs));
}
Polynomials operator*(double constant, const Polynomials& rhs)
{
	return rhs * constant;
}
