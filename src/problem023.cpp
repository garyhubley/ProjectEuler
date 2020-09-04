/*
* File: Problem023.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem023 from projecteuler.net
*
* A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example,
* the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
*
* A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this
* sum exceeds n.
*
* As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of
* two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be
* written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even
* though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than
* this limit.
*
* Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <chrono>
#include <set> 

#include "EulerLib.h"

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )
#define ToMilliSeconds( x ) ( std::chrono::duration_cast<std::chrono::milliseconds>( x ) )

void problem023()
{
	std::vector< uint32_t > abundants;
	std::vector < bool > flags( 28123 + 1, false );
	uint64_t sum = 0;
	std::set<uint32_t> summable;

	auto start = Clock::now();

	abundants = GenerateAbundants( 28123 );
	
	for ( const auto& ab1 : abundants )
	{
		for ( const auto& ab2 : abundants )
		{
			uint32_t tmp;
			if ( ab1 <= ab2 && (tmp = ab1 + ab2) < 28123 )
			{
				summable.insert( tmp );
			}
		}
	}

	uint32_t idx = 1;
	for ( const auto& element : summable )
	{
		while ( idx < element )
		{
			sum += idx;
			idx++;
		}
		idx++;
	}

	auto end = Clock::now();

	std::cout << "Answer: " << sum << std::endl;
	std::cout << "Time: " << ToMilliSeconds( end - start ).count() << " milliseconds" << std::endl;
}

