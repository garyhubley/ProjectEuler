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


