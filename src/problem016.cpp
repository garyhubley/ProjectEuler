/*
* File: Problem016.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem016 from projecteuler.com
*
* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
* 
* What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <chrono>
#include "EulerLib.h"
#include <numeric>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

void problem016()
{
	uint64_t size = 20;

	auto start = Clock::now();
	std::vector<uint8_t> digits = { 2 };
	
	for( uint32_t i = 2; i < 1001; i++ ) {
		digits = LargeMultiply(2, digits);
		/*if (!(i % 100)) {
			std::cout << "2^" << i << " = ";
			for (auto d = digits.rbegin(); d != digits.rend(); ++d) {
				std::cout << static_cast<char>(*d + '0');
			}
			std::cout << std::endl; 
		}*/
	}

	uint64_t sum = accumulate(digits.begin(), digits.end(), 0, std::plus<uint64_t>());

	auto end = Clock::now();
	std::cout << "Answer: " << sum << std::endl;


	std::cout << "Time: " << ToSeconds(end - start).count() << " seconds" << std::endl;
}
