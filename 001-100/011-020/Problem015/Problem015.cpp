/*
* File: Problem015.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem015 from projecteuler.com
*
* Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 
* 6 routes to the bottom right corner.
* 
* R,R,D,D/R,D,R,D/R,D,D,R/
* D,R,R,D/D,R,D,R/D,D,R,R/
* 
* How many such routes are there through a 20×20 grid ?
*
*/

#include <iostream>
#include <chrono>
#include "EulerLib.h"

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

int main()
{

	auto start = Clock::now();


	auto end = Clock::now();
	std::cout << "Answer: " << std::endl;


	std::cout << "Time: " << ToSeconds(end - start).count() << " seconds" << std::endl;
	std::cin.get();
	return 0;
}
