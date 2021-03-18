#pragma once

#include <iostream>
#include <vector>
#include <ranges>

class Polynomials
{
public:
	Polynomials() = default;
	// init class with cofficeints. stored in order of increasing exponent. for ex: first element has exponent 0, 2nd element is coeff for exponennt 1
	Polynomials(std::vector<double>&& coefficients);

	friend Polynomials operator+(const Polynomials& lhs, const Polynomials& rhs);
	friend Polynomials operator-(const Polynomials& lhs, const Polynomials& rhs);

	friend Polynomials operator*(const Polynomials& lhs, const Polynomials& rhs);

	friend Polynomials operator*(const Polynomials& lhs, double constant);
	friend Polynomials operator*(double constant, const Polynomials& rhs);

	Polynomials getDerivative();
	Polynomials getIntergral();
	
	// calculate value of poly when x = value
	void substituteXEqual();

	friend std::ostream& operator<<(std::ostream& os, const Polynomials& poly);

	// get highest degree of polynomials
	int getHigestDegree() const;

private:
	// example. polynomial 13x^2 + 2 is represented by this vector [2, 0, 13]. 
	std::vector<double> coefficients;

	// I think it should have a variable degree as private., could be. i would think it would just be size of coefficients - 1
	int degree = coefficients.size() - 1;
};
