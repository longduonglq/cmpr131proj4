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

