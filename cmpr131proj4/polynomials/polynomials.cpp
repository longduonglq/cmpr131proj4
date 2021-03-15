#include "polynomials.h"
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

Polynomials operator+(const Polynomials& lhs, const Polynomials& rhs)
{
	// std::vector<double> coeff(std::max(lhs.getHigestDegree(), rhs.getHigestDegree()) + 1, 0);
	auto coeffs = Polynomials::applyElementWise(std::plus<>(), lhs.coefficients, rhs.coefficients);
	return Polynomials(std::move(coeffs));
}

Polynomials operator-(const Polynomials& lhs, const Polynomials& rhs)
{
	auto coeffs = Polynomials::applyElementWise(std::minus<>(), lhs.coefficients, rhs.coefficients);
	return Polynomials(std::move(coeffs));
}

std::ostream& operator<<(std::ostream& os, const Polynomials& poly)
{
	for (int i = poly.getHigestDegree(); i >= 0; i++)
	{
		os << poly.coefficients[i] << (i != 0 ? "+ x^" + i : "+ ");
	}
	return os;
}

template <typename Iterable, typename BinOp>
Iterable Polynomials::applyElementWise(BinOp&& op, const Iterable& vec1, const Iterable& vec2)
{
	Iterable res;
	for (auto [it1, it2] = std::tie(vec1.begin(), vec2.begin());
		it1 != vec1.end() && it2 != vec2.end();
		it1++, it2++)
	{
		res.push_back(BinOp(*it1, *it2));
	}
	return res;
}

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
Polynomials Polynomials::getIntergral()
{
	std::vector<double> newCoeffs(coefficients);
	newCoeffs.push_back(0);
	for (int i = newCoeffs.size() - 1; i > 0; i--)
	{
		newCoeffs[i] = newCoeffs[i - 1] * (1 / static_cast<double>(i));
	}
	return Polynomials(std::move(newCoeffs));
}

//Duyen TRan
int Polynomials::getHigestDegree() const 
{
	return static_cast<int>(coefficients.size()) - 1;
}
//Duyen TRan
double Polynomials::substituteXEqual(double x)
{
	double substitule = 0;

	for (int index = 0; index <= degree; index++)
	{
		substitule += coefficients.at(index) * pow(x, degree - index);
	}
	
	cout << "subtutute of the polynomial at x=" << x << " is: " << substitule << endl;

	return substitule;
}


Polynomials::Polynomials(std::vector<double>&& _coefficients)
	: coefficients {std::move(_coefficients)}
{
}


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
