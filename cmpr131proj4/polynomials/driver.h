#pragma once
#include "polynomials.h"
#include<vector>
#include<iostream>
#include "../input.h"

using namespace std;

void PolynomialsTest()
{
	std::vector<double> coef1 = { 1, 2, 3 };
	std::vector<double> coef2 = { 4, 5, 6 };
	auto poly1 = Polynomials(std::move(coef1));
	auto poly2 = Polynomials(std::move(coef2));
	std::cout << poly1 << std::endl;
	std::cout << poly2 << std::endl;
	std::cout << poly1 + poly2 << std::endl;
	std::cout << poly1 - poly2 << std::endl;
	std::cout << poly1 * 0 << std::endl;
	std::cout << poly1 * 3 << std::endl;
	std::cout << poly1 * poly2 << std::endl;

	{
		std::vector<double> coef1 = { 1, 2, 3 };
		std::vector<double> coef2 = { 4, 0, 6 };
		auto poly1 = Polynomials(std::move(coef1));
		auto poly2 = Polynomials(std::move(coef2));
		std::cout << poly1 << std::endl;
		std::cout << poly2 << std::endl;
		std::cout << poly1 + poly2 << std::endl;
		std::cout << poly1 - poly2 << std::endl;
		std::cout << poly1 * 0 << std::endl;
		std::cout << poly1 * 3 << std::endl;
		std::cout << poly1 * poly2 << std::endl;
		std::cout << poly1.getDerivative() << std::endl;
		std::cout << poly1.getIntergral() << std::endl;
	}

}

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
void polyMany() {}

// main menu with 2 choices a and B
void polyMain();

//Precondition: N/A
//Postcondition: Prints menu of polynomials to choose A polynomial or Multiple polynomials
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

//Precondition: N/A
//Postcondition: print put the menu choice on a polynomial.
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
		Polynomials object;

		switch (option)
		{
		case 1: object.getHigestDegree();  break;
		case 2:   break;
		case 3: object.substituteXEqual();  break;
		case 4: object.getDerivative(); break;
		case 5: object.getIntergral();  break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (option == '0')
			break;
		cout << endl << endl;
		system("pause");
	}
}

