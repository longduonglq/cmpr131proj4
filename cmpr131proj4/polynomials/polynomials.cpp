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
	cout << "Enter the number of terms(1..100) for the polynomial: ";
	cin >> degree;

	return degree;
}

Polynomials::Polynomials(std::vector<double>&& coefficients)
{
	for (int i = 0; i <= degree; i++)
	{
		cout << "Enter the coefficient for term #" << i << ": ";
		coefficients.push_back(i);
	}
}

