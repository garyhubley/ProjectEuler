/*
* File: Problem026.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem026 from projecteuler.net
*
* A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 
* 10 are given:
* 
*        1/2 = 0.5
*        1/3 = 0.(3)
*        1/4 = 0.25
*        1/5 = 0.2
*        1/6 = 0.1(6)
*        1/7 = 0.(142857)
*        1/8 = 0.125
*        1/9 = 0.(1)
*        1/10 = 0.1
* 
* Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring 
* cycle.
* 
* Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )
#define ToMilliSeconds( x ) ( std::chrono::duration_cast<std::chrono::milliseconds>( x ) )

int main()
{
	auto start = Clock::now();

	auto end = Clock::now();

	std::cout << "Answer: " << std::endl;
	std::cout << "Time: " << ToMilliSeconds(end - start).count() << " milliseconds" << std::endl;
	std::cin.get();
	return 0;
}

