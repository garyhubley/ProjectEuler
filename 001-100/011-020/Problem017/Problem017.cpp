/*
* File: Problem017.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem017 from projecteuler.com
*
*
*/

#include "EulerLib.h"
#include <iostream>
#include <numeric>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

int main()
{
	uint64_t size = 20;

	auto start = Clock::now();
	std::vector<uint8_t> digits = { 2 };

	
	auto end = Clock::now();
	std::cout << "Answer: " << std::endl;


	std::cout << "Time: " << ToSeconds(end - start).count() << " seconds" << std::endl;
	std::cin.get();
	return 0;
}