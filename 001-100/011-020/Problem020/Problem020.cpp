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

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

int main()
{

	auto start = Clock::now();

	auto end = Clock::now();

	std::cout << "Answer: " << std::endl;
	std::cout << "Time: " << ToSeconds( end - start ).count() << " seconds" << std::endl;
	std::cin.get();
	return 0;
}

