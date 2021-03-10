/*
 * File: Problem031.cpp
 * Author: Gary Hubley
 * Company: Self
 * Description:
 *   In the United Kingdom the currency is made up of pound (£) and pence (p).
 *   There are eight coins in general circulation:
 *
 *     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 *     It is possible to make £2 in the following way:
 *
 *     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 *
 *   How many different ways can £2 be made using any number of coins?
 */

#include "EulerLib.h"

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds(x) (std::chrono::duration_cast<std::chrono::seconds>(x))
#define ToMilliSeconds(x) (std::chrono::duration_cast<std::chrono::milliseconds>(x))

typedef std::vector<std::tuple<uint64_t, uint64_t>> PrimeFactor;

void problem031() {
    
    std::vector< uint32_t > coinValues{ 1, 2, 5, 10, 20, 50, 100, 200 };

    auto start = Clock::now();

    auto end = Clock::now();

    std::cout << "Answer: " << std::endl;
    std::cout << "Time: " << ToMilliSeconds(end - start).count() << " milliseconds" << std::endl;
}
