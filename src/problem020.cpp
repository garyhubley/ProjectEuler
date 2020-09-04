/*
* File: Problem020.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem020 from projecteuler.net
*
* n! means n × (n − 1) × ... × 3 × 2 × 1
* 
* For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
* and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
* 
* Find the sum of the digits in the number 100!
* 
*/

#include <iostream>
#include <chrono>
#include <vector>
#include "EulerLib.h"
#include <numeric>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

void problem020()
{
	auto start = Clock::now();
	std::vector<uint8_t> factorial = LargeFactorial( 100 );
	uint32_t sum = std::accumulate( factorial.begin(), factorial.end(), 0, std::plus<uint32_t>() );
	auto end = Clock::now();

	std::cout << "Answer: " << sum << std::endl;
	std::cout << 
        "Time: " << 
        ToSeconds( end - start ).count() << 
        " seconds" << 
        std::endl;
}


