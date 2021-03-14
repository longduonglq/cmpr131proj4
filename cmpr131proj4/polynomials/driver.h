#pragma once
#include "polynomials.h"
#include<vector>
#include<iostream>

using namespace std;

// get polynomials. first ask for degree then ask user to input each coefficients
Polynomials getPolynomials();

// option "single poly"
void polySingular();

// option "multiple poly"
void polyMany();

// main menu with 2 choices a and B
void polyMain();

//DuyenTran
Polynomials getPolynomials()
{
	int degree;
	cout << "Enter the degree of the polynomial: ";
	cin >> degree;

	for (int i = 0, i <= degree; i++)
	{
		cout << "Enter the coefficient for term #" << i << ": ";
		coefficients.push_back();
	}

}