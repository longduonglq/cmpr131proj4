// Name: 
// Date: 
// Description: 

#include <iostream>
#include "rationals/rational.h"
#include "polynomials/driver.h"

using namespace std;

void RationalNumber();
void calculateRation();
int DriverMenuA();
int DriverMenuB();
void mainDriver();

int main()
{
	PolynomialsTest();
	// mainDriver();
	return 0;
}

void mainDriver()
{
	string input = "0ab";
	char option;
	while (true)
	{
		system("cls");
		cout << "\n\t2> Rational Numbers";
		cout << "\n\t" << string(40, char(205));
		cout << "\n\t\tA> A Rational Number";
		cout << "\n\t\tB> Multiple Rational Numbers";
		cout << "\n\t" << string(40, char(205));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(40, char(205));
		cout << "\n\t\tOption: ";


		option = inputChar("", input);

		switch (toupper(option))
		{
		case 'A':RationalNumber(); break;
		case 'B': calculateRation(); break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (option == '0')
			break;
		cout << "\n\n";
		system("pause");
	}

}
int DriverMenuA()
{
	system("cls");
	cout << "\n\t1. Enter the numerator\n";
	cout << "\t2. Enter the deminator\n";
	cout << "\t3. Display the rational number\n";
	cout << "\t4. Normalize the rational number\n";
	cout << "\t5. Negate the rational number\n";
	cout << "\t6. Add (+) the rational number with a constant\n";
	cout << "\t7. Subtract (-) the rational number with a constant\n";
	cout << "\t8. Multiply (*) the rational number with a constant\n";
	cout << "\t9. Divide (/) the rational number with a constant\n";
	cout << "\t0. return\n";
	cout << "\tOption: ";

	char option = inputInteger("", 0, 9);

	return option;
}

int DriverMenuB()
{
	system("cls");
	cout << "\n\t1. Enter rational number R1\n";
	cout << "\t2. Enter rational number R2\n";
	cout << "\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2\n";
	cout << "\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2\n";
	cout << "\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889\n";
	cout << "\t0. return\n";
	cout << "\tOption: ";

	char option = inputInteger("", 0, 5);
	return option;
}

void calculateRation()
{
	using namespace rational;
	int option = 0; // = DriverMenuB();
	Rational test, test2, normalize;
	int num = 0, den = 0;

	while (true)
	{
		option = DriverMenuB();
		switch (option)
		{
		case 0: break;
		case 1:
			test.setNum(num); test.setDenom(den);
			test.normalize();
			cout << "\n\tR1 = " << test; break;
		case 2:
			test2.setNum(num); test2.setDenom(den);
			test2.normalize();
			cout << "\n\tR2 = " << test2; break;
		case 3:
			cout << "\n\tR1 < R2 " << " -> " << test << " < " << test2 << " ? " << (test < test2 ? "true" : "false") << "\n";
			cout << "\tR1 <= R2 " << " -> " << test << " <= " << test2 << " ? " << (test <= test2 ? "true" : "false") << "\n";
			cout << "\tR1 > R2 " << " -> " << test << " > " << test2 << " ? " << (test > test2 ? "true" : "false") << "\n";
			cout << "\tR1 >= R2 " << " -> " << test << " >= " << test2 << " ? " << (test >= test2 ? "true" : "false") << "\n";
			cout << "\tR1 == R2 " << " -> " << test << " == " << test2 << " ? " << (test == test2 ? "true" : "false") << "\n";
			cout << "\tR1 != R2 " << " -> " << test << " != " << test2 << " ? " << (test != test2 ? "true" : "false") << "\n"; break;
		case 4:
			cout << "\n\tAddiction:\t R1 + R2 --> " << test << " + " << test2 << " = " << test + test2;
			cout << "\n\tSubtraction:\t R2 - R1 --> " << test << " - " << test2 << " = " << test2 - test;
			cout << "\n\tMultiplication:\t R1 * R2 --> " << test << " * " << test2 << " = " << test * test2;
			cout << "\n\tDivision:\t R2 / R1 --> " << test << " / " << test2 << " = " << test2 / test;
			break;
		case 5:
			//missing


		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (option == 0)
			break;
		cout << "\n\n";
		system("pause");
	}
}

void RationalNumber()
{
	using namespace rational;
	int option; // = DriverMenu();
	Rational test, test2, normalize;
	int num = 0, den = 0;
	int i = 0;

	while (true)
	{
		option = DriverMenuA();
		switch (option)
		{
		case 0: break;
		case 1: test.setNum(num); break;
		case 2: test.setDenom(den); break;
		case 3: cout << "\n\tRational number R1 = " << test; break;
		case 4:
			test2 = test;
			test2.normalize();
			cout << "\n\tNormalized rational number R2 (a copy of R1)\n\t";
			cout << test2; break;
		case 5:
			test2 = test * (-1);
			cout << "\n\tNegated rational number R2 (a copy of R1)\n\t";
			cout << test2; break;
		case 6: //+
			i = inputInteger("\t Enter an integer value:");
			test2 = test + i;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tR2 + value\n\t" << test << " + " << i << " = " << test2 << " = " << normalize;
			test2 = i + test;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tvalue + R2 \n\t" << i << " + " << test << " = " << test2 << " = " << normalize; break;
		case 7: // - 
			i = inputInteger("\t Enter an integer value:");
			test2 = test - i;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tR2 - value\n\t" << test << " - " << i << " = " << test2 << " = " << normalize;
			test2 = i - test;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tvalue - R2 \n\t" << i << " - " << test << " = " << test2 << " = " << normalize; break;
		case 8:
			i = inputInteger("\t Enter an integer value:");
			test2 = test * i;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tR2 * value\n\t" << test << " * " << i << " = " << test2 << " = " << normalize;
			test2 = i * test;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tvalue * R2 \n\t" << i << " * " << test << " = " << test2 << " = " << normalize; break;
		case 9:
			i = inputInteger("\t Enter an integer value:");
			test2 = test / i;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tR2 / value\n\t" << test << " / " << i << " = " << test2 << " = " << normalize;
			test2 = i / test;
			normalize = test2;
			normalize.normalize();
			cout << "\n\tvalue / R2 \n\t" << i << " / " << test << " = " << test2 << " = " << normalize; break;

		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}

		if (option == 0)
			break;
		cout << "\n\n";
		system("pause");
	}
}