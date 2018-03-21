/*
* File: Problem007.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem007 from projecteuler.com
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
* 
* What is the 10 001st prime number?
*/

#include "EulerLib.h"
#include <iostream>

int main()
{
	std::cout << "Answer: " << nthPrimeEratosthenes( 100001 ) << std::endl;

	std::cin.get();
	return 0;
}
