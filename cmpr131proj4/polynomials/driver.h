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
		cout << "\t\tA>  A Polynomial "; << endl;
		cout << "\t\tB> Multiple Rational Numbers" << endl;
		cout << "\t" << string(40, char(196)) << endl;
		cout << "\t\t0. return" << endl;
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

