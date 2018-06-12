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

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )
#define ToMilliSeconds( x ) ( std::chrono::duration_cast<std::chrono::milliseconds>( x ) )

int main()
{
	uint64_t nameScores = 0;

	auto start = Clock::now();

	auto end = Clock::now();

	std::cout << "Answer: " << std::endl;
	std::cout << "Time: " << ToMilliSeconds( end - start ).count() << " milliseconds" << std::endl;
	std::cin.get();
	return 0;
}

