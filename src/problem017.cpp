/*
* File: Problem017.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem017 from projecteuler.com
*
* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19
* letters used in total.
*
* If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
*
*
* NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (
* one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with
* British usage.
*/

#include "EulerLib.h"
#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

int main()
{
	uint32_t sum = 0;
	auto start = Clock::now();

	for (uint32_t i = 1; i < 1001; i++) {
		sum += CountLettersInNumberVernacular(i);
	}

	auto end = Clock::now();
	std::cout << "Answer: " << sum << std::endl;


	std::cout << "Time: " << ToSeconds(end - start).count() << " seconds" << std::endl;
	std::cin.get();
	return 0;
}
