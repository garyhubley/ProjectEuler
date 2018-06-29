/*
* File: Problem024.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem024 from projecteuler.net
*
* A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1,
* 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The
* lexicographic permutations of 0, 1 and 2 are:
*
*					012   021   102   120   201   210
*
* What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <iostream>
#include <chrono>
#include <algorithm>

#include "EulerLib.h"

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )
#define ToMilliSeconds( x ) ( std::chrono::duration_cast<std::chrono::milliseconds>( x ) )

int main()
{
	const uint32_t permutationNumber = 1000000;

	LargeNumber digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	LargeNumber res;

	uint64_t cnt = 0;
	auto sz = digits.size();
	auto start_sz = sz;

	auto start = Clock::now();

	while ( res.size() < start_sz )
	{
		for ( size_t idx = 0; idx < sz; idx++ )
		{
			auto tmp = cnt + LargeNumToLongLong( LargeFactorial( sz - 1 ) );
			if ( tmp < permutationNumber )
			{
				cnt = tmp;
			}
			else
			{
				res.push_back( digits[idx] );
				digits.erase( digits.begin() + idx );
				idx = -1;
				sz = digits.size();
			}
		}
	}
	std::reverse( res.begin(), res.end() );
	auto end = Clock::now();

	std::cout << "Answer: " << LargeNumToLongLong( res ) << std::endl;
	std::cout << "Time: " << ToMilliSeconds( end - start ).count() << " milliseconds" << std::endl;
	std::cin.get();
	return 0;
}

