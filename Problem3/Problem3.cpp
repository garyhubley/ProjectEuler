/*
* File: Problem3.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem3 from projecteuler.com
*
* The prime factors of 13195 are 5, 7, 13 and 29.
*
* What is the largest prime factor of the number 600851475143 ?
*
*/

#include "EulerLib.h"
#include <iostream>

int main()
{
	// get list of all prime numbers that COULD be a factor of 600851475143
	std::vector<int> primes{ primeEratosthenes( static_cast< unsigned long >( sqrt( 600851475143 ) ) ) };

	// Loop from the end of the list of prime numbers. 
	for ( int idx = primes.size() - 1; idx != 0; --idx )
	{
		if ( isMultiple( 600851475143, primes[idx] ) )
		{
			// prime number is a factor of big number. complete
			std::cout << "Largest Prime Factor: " << primes[idx] << std::endl;
			break;
		}
	}


	std::cin.get();
}
