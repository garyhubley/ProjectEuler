/*
* File: Problem025.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem025 from projecteuler.net
*
* The Fibonacci sequence is defined by the recurrence relation:
*
*		Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
*
* Hence the first 12 terms will be:
*
*		F1 = 1
*		F2 = 1
* 		F3 = 2
* 		F4 = 3
* 		F5 = 5
* 		F6 = 8
* 		F7 = 13
* 		F8 = 21
* 		F9 = 34
* 		F10 = 55
* 		F11 = 89
* 		F12 = 144
*
* The 12th term, F12, is the first term to contain three digits.
*
* What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>
#include <chrono>
#include <algorithm>

#include "EulerLib.h"

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )
#define ToMilliSeconds( x ) ( std::chrono::duration_cast<std::chrono::milliseconds>( x ) )

LargeNumber operator+( const LargeNumber& lhs, const LargeNumber& rhs )
{
	LargeNumber res( std::max( lhs.size(), rhs.size() ) );

	auto pred = [&res]( const LargeNumber& small, const LargeNumber& large )
	{
		auto sm_sz = small.size();
		auto lg_sz = large.size();
		uint8_t tmp = 0;
		for ( unsigned i = 0; i < sm_sz; i++ )
		{
			tmp = large[i] + small[i] + tmp;
			res[i] = tmp % 10;
			tmp /= 10;
		}
		for ( unsigned i = sm_sz; i < lg_sz; i++ )
		{
			tmp = large[i] + tmp;
			res[i] = tmp % 10;
			tmp /= 10;
		}
		while ( tmp != 0 )
		{
			res.push_back( tmp % 10 );
			tmp /= 10;
		}
	};

	auto lhs_sz = lhs.size();
	auto rhs_sz = rhs.size();
	if ( lhs_sz > rhs_sz )
	{
		// lhs is larger
		pred( rhs, lhs );
	}
	else
	{
		// rhs is larger
		pred( lhs, rhs );
	}

	
	return std::move( res );
}

int main()
{
	LargeNumber firstPrevious( 1, 1 ), secondPrevious( 1, 1 ), current;
	uint32_t count = 2;

	auto start = Clock::now();

	while ( current.size() < 1000 )
	{
		count++;

		current = firstPrevious + secondPrevious;
		secondPrevious = firstPrevious;
		firstPrevious = current;
	}

	auto end = Clock::now();

	std::cout << "Answer: " << count << std::endl;
	std::cout << "Time: " << ToMilliSeconds( end - start ).count() << " milliseconds" << std::endl;
	std::cin.get();
	return 0;
}

