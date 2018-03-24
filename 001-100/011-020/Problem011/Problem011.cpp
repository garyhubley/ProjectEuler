/*
* File: Problem011.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem011 from projecteuler.com
*
* 
*/

//#include "EulerLib.h"
#include <iostream>
#include <string>
#include <numeric>

int main()
{
	//std::vector<unsigned> primes = primeEratosthenes( 2000000 );

	std::cout << "Answer: " << std::accumulate( primes.begin(), primes.end(), uint64_t( 0 ), []( uint64_t a, uint64_t b ) -> uint64_t { return a + b; } ) << std::endl;
	std::cin.get();
	return 0;
}

