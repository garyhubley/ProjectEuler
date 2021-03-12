/*
 * File: Problem032.cpp
 * Author: Gary Hubley
 * Company: Self
 * Description:
 *   We shall say that an n-digit number is pandigital if it makes use of all
 *   the digits 1 to n exactly once; for example, the 5-digit number, 15234, is
 *   1 through 5 pandigital. 
 *  
 *   The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
 *   multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 *   Find the sum of all products whose multiplicand/multiplier/product
 *   identity can be written as a 1 through 9 pandigital.
 *
 *   HINT: Some products can be obtained in more than one way so be sure to
 *   only include it once in your sum.
 */

#include "EulerLib.h"

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds(x) (std::chrono::duration_cast<std::chrono::seconds>(x))
#define ToMilliSeconds(x) (std::chrono::duration_cast<std::chrono::milliseconds>(x))
#define ToMicroSeconds(x) (std::chrono::duration_cast<std::chrono::microseconds>(x))

void problem032() {
    
    auto start = Clock::now();

    auto end = Clock::now();

    std::cout << "Answer: " << std::endl;
	std::cout << "Time: " << std::endl;
    std::cout << "  Seconds" << ToSeconds(end - start).count() << std::endl;
    std::cout << "  Milliseconds" << ToMilliSeconds(end - start).count() << std::endl;
    std::cout << "  Microseconds" << ToMicroSeconds(end - start).count() << std::endl;
}
