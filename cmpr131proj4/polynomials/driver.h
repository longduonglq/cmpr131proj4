#pragma once
#include "polynomials.h"
#include<vector>
#include<iostream>
#include "../input.h"

using namespace std;

//void PolynomialsTest()
//{
//	std::vector<double> coef1 = { 1, 2, 3 };
//	std::vector<double> coef2 = { 4, 5, 6 };
//	auto poly1 = Polynomials(std::move(coef1));
//	auto poly2 = Polynomials(std::move(coef2));
//	std::cout << poly1 << std::endl;
//	std::cout << poly2 << std::endl;
//	std::cout << poly1 + poly2 << std::endl;
//	std::cout << poly1 - poly2 << std::endl;
//	std::cout << poly1 * 0 << std::endl;
//	std::cout << poly1 * 3 << std::endl;
//	std::cout << poly1 * poly2 << std::endl;
//
//	{
//		std::vector<double> coef1 = { 1, 2, 3 };
//		std::vector<double> coef2 = { 4, 0, 6 };
//		auto poly1 = Polynomials(std::move(coef1));
//		auto poly2 = Polynomials(std::move(coef2));
//		std::cout << poly1 << std::endl;
//		std::cout << poly2 << std::endl;
//		std::cout << poly1 + poly2 << std::endl;
//		std::cout << poly1 - poly2 << std::endl;
//		std::cout << poly1 * 0 << std::endl;
//		std::cout << poly1 * 3 << std::endl;
//		std::cout << poly1 * poly2 << std::endl;
//		std::cout << poly1.getDerivative() << std::endl;
//		std::cout << poly1.getIntergral() << std::endl;
//	}

//}

// for the single version
Polynomials getPolynomials(int degree)
{
	std::vector<double> coefficients;
	double temp;
	for (int i = 0; i < degree; i++)
	{
		cout << "Enter the coefficient for term #" << i+1 << ": ";
		cin >> temp;
		coefficients.push_back(temp);
	}
	reverse(coefficients.begin(), coefficients.end());
	return Polynomials(std::move(coefficients));
}
//for the version with two polynomials
Polynomials getPolynomials()
{
	std::vector<double> coefficients;
	int degree;
	degree = inputInteger("\tEnter the number of terms(1..100) for the polynomial: ", 1, 100);
	double term;

	for (int i = 0; i < degree; i++)
	{
		cout << "\tEnter the coefficient for term #" << i + 1;
		term = inputDouble(": ");
		coefficients.push_back(term);
	}
	reverse(coefficients.begin(), coefficients.end());
	return Polynomials(std::move(coefficients));
}
// option "single poly"
void polySingular();

// option "multiple poly"
void polyMany()
{
	Polynomials poly1, poly2;
	double constant;

	cout << "B> Two Polynomials\n";
	poly1 = getPolynomials();
	cout << "\nThe first polynomial (P1) is entered: " << poly1 << '\n';
	poly2 = getPolynomials();
	cout << "\nThe second polynomial (P2) is entered: " << poly2 << '\n';
	cout << "\tAddition of polynomials          -> P1 + P2 = " << poly1 + poly2 << '\n';
	cout << "\tSubtraction of polynomials       -> P1 - P2 = " << poly1 - poly2 << '\n';
	cout << "\tMultiplication of polynomials    -> P1 * P2 = " << poly1 * poly2 << '\n';
	constant = inputDouble("\n\tEnter a constant value: ");
	cout << constant << " * Polynomial(P1) = " << constant * poly1 << '\n';
	cout << '\n' << "Polynomial(P2) = " << poly2 * constant << '\n';

}

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
		cout << '\t' << string(40, char(205)) << endl;
		cout << "\t\tA>  A Polynomial " << endl;
		cout << "\t\tB>  Multiple Polynomials " << endl;
		cout << "\t" << string(40, char(196)) << endl;
		cout << "\t\t0> return" << endl;
		cout << "\t" << string(40, char(205)) << endl;
		cout << "\t\tOption: ";


		option = inputChar("", input);
		if (option == '0')
			break;
		switch (toupper(option))
		{
		case 'A': polySingular(); break;
		case 'B': polyMany(); break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		
		cout << endl << endl;
		system("pause");
	}
}

//Precondition: N/A
//Postcondition: print put the menu choice on a polynomial.
void polySingular()
{
	Polynomials object;
	int degree = 0;
	double constant;
	bool inputCheck = false;
	char option;
	while (true)
	{
		system("cls");
		cout << "A> A Polynomial:  " << endl;
		cout << '\t'<< string(40, char(205)) << endl;
		cout << "\t\t1>  Enter the number of terms  " << endl;
		cout << "\t\t2>  Specify the coefficients " << endl;
		cout << "\t\t3>  Evaluate expression " << endl;
		cout << "\t\t4>  Solve for the derivative " << endl;
		cout << "\t\t5>  Solve for the integral " << endl;
		cout << '\t' << string(40, char(196)) << endl;
		cout <<'\t'<< '\t' << "\t\t0> return" << endl;
		cout << '\t' << string(40, char(205)) << endl;
		cout << "\t\tOption: ";


		option = inputInteger("", 0, 5);
		
		if (option == 0)
			break;
		switch (option)
		{
	
		case 1:degree = inputInteger("Enter the number of coeffcients (1-100): ", 1, 100); break;
		case 2:
		{
			if (degree == 0)
			{
				cout << "Error: 0 terms! please enter the number of terms";
				break;
			}
			else
			{
				object = getPolynomials(degree);
				inputCheck = true;
				break;
			}
		}
		case 3:
		{

			if (inputCheck) 
			{
				cout << "P1(x) = " << object << '\n';
				constant = inputDouble("\nEnter the value of x to evaluate the polynomial");
				object.substituteXEqual(constant);
				break;
			}
			else
			{ 
				cout << "Error: 0 terms! Please enter the terms and try again.";
				break;
			}
		}
		case 4: 
		{ 
			if (inputCheck)
			{
				cout << "\tPolynomial(x) = " << object << '\n';
				cout << "\n\tDerivative" << object.getDerivative();
				break;
			}
			else
			{
				cout << "Error: 0 terms! Please enter the terms and try again.";
				break;
			}
		}
		case 5: 
		{	
			if (inputCheck)
			{
				cout << "\tPolynomial(x) = " << object << '\n';
				cout << "\n\tIntegeral" << object.getIntergral();
				break;
			}
			else
			{
				cout << "Error: 0 terms! Please enter the terms and try again.";
				break;
			}
		}
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		
		cout << endl << endl;
		system("pause");
	}
}

