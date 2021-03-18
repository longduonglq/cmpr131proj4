//Names: Long Duong, Duyen Tran, Lincoln 
//Date: 3/17/2021
//Description: header file for the polynomials class
#pragma once

#include <iostream>
#include <vector>
#include <ranges>

class Polynomials
{
public:
	//preconditions:N/a
	//postconditions:Creates a default ploynomials object
	Polynomials() = default;
	//preconditions: A vector of doubles
	//postconditions: Creates a polynomials object out of the vector
	Polynomials(std::vector<double>&& coefficients);
	//preconditions: Two polynomials objects
	//postconditions: returns the sum of the two objects
	friend Polynomials operator+(const Polynomials& lhs, const Polynomials& rhs);
	//preconditions: two polynomials objects
	//postconditions: returns the difference of the two objects
	friend Polynomials operator-(const Polynomials& lhs, const Polynomials& rhs);
	//preconditions: two polynomials objects
	//postconditions: returns the product of the two objects
	friend Polynomials operator*(const Polynomials& lhs, const Polynomials& rhs);
	//preconditions: A polynomials object and a number
	//postconditions: returns the product of the polynomial * the number
	friend Polynomials operator*(const Polynomials& lhs, double constant);
	//preconditions: A number and a polynomials object
	//postconditions: returns the product of the number * the polynomial
	friend Polynomials operator*(double constant, const Polynomials& rhs);
	//preconditions: Two polynomial objects, or a polynomial object and a function which returns a polynomial object
	//postconditions: sets the left hand objects contents equal to that of the right hand object
	Polynomials operator= (const Polynomials& rhs);
	//preconditions: Any polynomials object
	//postconditions: returns the derivative of the polynomial
	Polynomials getDerivative();
	//preconditions: any polynomials object
	//postconditions: returns the intergral of the polynomial
	Polynomials getIntergral();
	//preconditions: a polynomials object
	//postconditions: returns the result of evaluating the polynomial as if every x was the called number
	double substituteXEqual(double x);
	//preconditions:a polynomial object
	//postconditions: properly displays the polynomial
	friend std::ostream& operator<<(std::ostream& os, const Polynomials& poly);
	//preconditions: a polynomial object
	//postconditions: returns the largest degree contained in the object
	int getHigestDegree() const;

private:
	// example. polynomial 13x^2 + 2 is represented by this vector [2, 0, 13]. 
	std::vector<double> coefficients;

	// I think it should have a variable degree as private., could be. i would think it would just be size of coefficients - 1
	int degree = coefficients.size() - 1;
};
