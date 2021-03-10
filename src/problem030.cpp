/*
 * File: Problem030.cpp
 * Author: Gary Hubley
 * Company: Self
 * Description:
 *   Surprisingly there are only three numbers that can be written as the sum
 *   of fourth powers of their digits:
 *
 *     1634 = 14 + 64 + 34 + 44
 *     8208 = 84 + 24 + 04 + 84
 *     9474 = 94 + 44 + 74 + 44
 *
 *   As 1 = 14 is not a sum it is not included.
 *
 *   The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 *   Find the sum of all the numbers that can be written as the sum of fifth
 *   powers of their digits.
 */

#include "EulerLib.h"

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds(x) (std::chrono::duration_cast<std::chrono::seconds>(x))
#define ToMilliSeconds(x) (std::chrono::duration_cast<std::chrono::milliseconds>(x))

typedef std::vector<std::tuple<uint64_t, uint64_t>> PrimeFactor;

void problem030() {

    auto start = Clock::now();


    auto end = Clock::now();

    std::cout << "Answer: " << std::endl;
    std::cout << "Time: " << ToMilliSeconds(end - start).count() << " milliseconds" << std::endl;
}
