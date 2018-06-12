/*
* File: Problem006.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem006 from projecteuler.com
*
* The sum of the squares of the first ten natural numbers is,
*			1^2 + 2^2 + ... + 10^2 = 385
* 
* The square of the sum of the first ten natural numbers is,
*			(1 + 2 + ... + 10)^2 = 55^2 = 3025
* 
* Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 
* 3025 − 385 = 2640.
* 
* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the 
* sum.
*
*/

#include "EulerLib.h"
#include <iostream>

int main()
{
	// slow way
	std::cout << "Answer: " << squareOfSum_slow( 1, 100 ) - sumOfSquares_slow( 1, 100 ) << std::endl;

	// fast way
	std::cout << "Answer: " << squareOfSum( 100 ) - sumOfSquares( 100 ) << std::endl;

	std::cin.get();
	return 0;
}
