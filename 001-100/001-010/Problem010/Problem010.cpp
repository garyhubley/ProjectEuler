/*
* File: Problem010.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem010 from projecteuler.com
*
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*
* Find the sum of all the primes below two million.
*/

#include "EulerLib.h"
#include <iostream>
#include <string>
#include <numeric>

int main()
{
	std::vector<uint64_t> primes = primeEratosthenes( 2000000 );

	std::cout << "Answer: " << std::accumulate( primes.begin(), primes.end(), uint64_t( 0 ), []( uint64_t a, uint64_t b ) -> uint64_t { return a + b; } ) << std::endl;
	std::cin.get();
	return 0;
}

