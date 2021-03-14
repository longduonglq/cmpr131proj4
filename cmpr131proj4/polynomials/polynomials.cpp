#include "polynomials.h"
#include<iostream>
#include<vector>

using namespace std;

Polynomials operator+(const Polynomials& lhs, const Polynomials& rhs)
{
    return Polynomials();
}



//Duyen TRan
int Polynomials::getHigestDegree()
{
    return degree;
}

Polynomials::Polynomials(std::vector<double>&& coefficients)
{
	cout << "Enter the degree of the polynomial: ";
	cin >> degree;

	for (int i = 0, i <= degree; i++)
	{
		cout << "Enter the coefficient for term #" << i << ": ";
		coefficients.push_back();
	}
}

