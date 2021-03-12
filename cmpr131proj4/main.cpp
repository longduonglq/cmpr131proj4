// Name: 
// Date: 
// Description: 

#include <iostream>
#include "rationals/rational.h"

//test
int main() {
	using namespace rat;
	Rational R1;
	Rational R2(4, 5);
	Rational R3(13);

	cin >> R1;
	cin >> R2;

	cout << "\nR1 = " << R1 << "\n";
	cout << "R2 = " << R2 << "\n";
	cout << "R3 = " << R3 << "\n";

	cout << "R1 == R2 -> " << (R1 == R2) << "\n";
	cout << "R1 > R2 -> " << (R1 > R2) << "\n";
	cout << "R1 >= R2 -> " << (R1 >= R2) << "\n";
	cout << "R1 < R2 -> " << (R1 < R2) << "\n";
	cout << "R1 <= R2 -> " << (R1 <= R2) << "\n";

	cout << "R1 + R2 = " << (R1 + R2) << "\n";
	cout << "R1 - R2 = " << (R1 - R2) << "\n";
	cout << "R1 * R2 = " << (R1 * R2) << "\n";
	cout << "R1 / R2 = " << (R1 / R2) << "\n";
}