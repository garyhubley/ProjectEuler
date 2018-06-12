/*
* File: Problem021.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem021 from projecteuler.net
*
* Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
* If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable 
* numbers.
* 
* For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The 
* proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
* 
* Evaluate the sum of all the amicable numbers under 10000.
*
*/

#include <iostream>
#include <chrono>
#include <vector>
#include "EulerLib.h"
#include <numeric>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )
#define ToMilliSeconds( x ) ( std::chrono::duration_cast<std::chrono::milliseconds>( x ) )

int main()
{
	uint32_t sum_i, sum_d;
	std::vector< uint32_t > amicables;
	uint32_t idx = 0;

	auto start = Clock::now();

	for ( uint32_t i = 2; i < 10000; i++ )
	{
		if( std::find( amicables.begin(), amicables.end(), i ) != amicables.end() )
		{
			continue;
		}

		std::vector< uint32_t > divisors = ProperDivisors( i );
		sum_i = std::accumulate( divisors.begin(), divisors.end(), 0, std::plus<uint32_t>() );
		if ( sum_i > i )
		{
			std::vector< uint32_t > div_pair = ProperDivisors( sum_i );
			sum_d = std::accumulate( div_pair.begin(), div_pair.end(), 0, std::plus<uint32_t>() );

			if ( i == sum_d )
			{
				amicables.push_back( i );
				amicables.push_back( sum_i );
			}
		}

	}
	sum_i = std::accumulate( amicables.begin(), amicables.end(), 0, std::plus<uint32_t>() );
	//FwdPrintVector( amicables );
	auto end = Clock::now();

	std::cout << "Answer: " << sum_i << std::endl;
	std::cout << "Time: " << ToMilliSeconds( end - start ).count() << " milliseconds" << std::endl;
	std::cin.get();
	return 0;
}


