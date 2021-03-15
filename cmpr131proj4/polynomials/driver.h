#pragma once
#include "polynomials.h"
#include<vector>
#include<iostream>
#include "../input.h"

using namespace std;

// get polynomials. first ask for degree then ask user to input each coefficients
Polynomials getPolynomials()
{
	std::vector<double> coefficients;
	int degree; 
	cout << "Enter the number of terms(1..100) for the polynomial: ";
	cin >> degree;

	for (int i = 0; i <= degree; i++)
	{
		cout << "Enter the coefficient for term #" << i << ": ";
		coefficients.push_back(i);
	}

	return Polynomials(std::move(coefficients));
}

// option "single poly"
void polySingular();

// option "multiple poly"
void polyMany();

// main menu with 2 choices a and B
void polyMain();

//Duyen TRan
void polyMain()
{
	string input = "0ab";
	char option;
	while (true)
	{
		system("cls");
		cout << "\n3> Polynomials: " << endl;
		cout << string(40, char(205)) << endl;
		cout << "\t\tA>  A Polynomial " << endl;
		cout << "\t\tB>  Multiple Polynomials " << endl;
		cout << "\t" << string(40, char(196)) << endl;
		cout << "\t\t0> return" << endl;
		cout << "\t" << string(40, char(205)) << endl;
		cout << "\t\tOption: ";


		option = inputChar("", input);

		switch (toupper(option))
		{
		case 'A': polySingular(); break;
		case 'B': polyMany(); break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (option == '0')
			break;
		cout << endl << endl;
		system("pause");
	}
}

//Duyen TRan
void polySingular()
{
	char option;
	while (true)
	{
		system("cls");
		cout << "A> A Polynomial:  " << endl;
		cout << string(40, char(205)) << endl;
		cout << "\t\t1>  Enter the number of terms  " << endl;
		cout << "\t\t2>  Specify the coefficients " << endl;
		cout << "\t\t3>  Evaluate epxression " << endl;
		cout << "\t\t4>  Solve for the derivative " << endl;
		cout << "\t\t5>  Solve for the integral " << endl;
		cout << string(40, char(196)) << endl;
		cout << "\t\t0> return" << endl;
		cout << "\t" << string(40, char(205)) << endl;
		cout << "\t\tOption: ";


		option = inputInteger("", 0, 5);

		switch (option)
		{
		case 1: getHigestDegree();  break;
		case 2: Polynomials(vector<double> && coefficients);  break;
		case 3: substituteXEqual(double x);  break;
		case 4: getDerivative(); break;
		case 5: getIntergral();  break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (option == '0')
			break;
		cout << endl << endl;
		system("pause");
	}
}

