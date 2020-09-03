/*
* File: Problem005.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem005 from projecteuler.com
*
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
*
* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?.
*
*/

#include "EulerLib.h"
#include <iostream>
#include <numeric>

void problem005()
{
	int max = 20;
	// get initialize vector to 2 and 3. (the first two prime numbers) 
	std::vector< uint64_t > factors = primeEratosthenes( 4 );

	// 4 is the first non prime number
	for (uint64_t i = 4; i <= 20; i++ )
	{
		uint64_t test = i;
		for ( uint64_t factor : factors )
		{
			if( test % factor == 0 )
			{
				test /= factor;
			}
		}

		if( test != 1 )
		{
			factors.push_back( test );
		}
	}

	std::cout << "Answer: " << std::accumulate( factors.begin(), factors.end(), 1, []( int a, int b ) { return a * b; } ) << std::endl;

	std::cin.get();
}
