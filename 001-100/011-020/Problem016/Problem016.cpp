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

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

int main()
{
	uint64_t size = 20;

	auto start = Clock::now();



	auto end = Clock::now();
	std::cout << "Answer: " << std::endl;


	std::cout << "Time: " << ToSeconds(end - start).count() << " seconds" << std::endl;
	std::cin.get();
	return 0;
}
