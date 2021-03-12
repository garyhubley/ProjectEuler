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
#include <numeric>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds(x) (std::chrono::duration_cast<std::chrono::seconds>(x))
#define ToMilliSeconds(x) (std::chrono::duration_cast<std::chrono::milliseconds>(x))
#define ToMicroSeconds(x) (std::chrono::duration_cast<std::chrono::microseconds>(x))

void problem031() {
    
	const uint32_t MAX_TARGET = 200;

	std::vector< uint32_t > coinValues{ 1, 2, 5, 10, 20, 50, 100, 200 };
	std::vector< uint32_t > combinations(201, 0);
	combinations[0] = 1;

    auto start = Clock::now();

	for( auto &coin : coinValues ) {
		for( uint32_t target = coin; target <= MAX_TARGET; target++ ) {
			combinations[target] += combinations[target-coin];
		}

	}

    auto end = Clock::now();

    std::cout << "Answer: " << combinations.back() << std::endl;
	std::cout << "Time: " << std::endl;
    std::cout << "  Seconds: " << ToSeconds(end - start).count() << std::endl;
    std::cout << "  Milliseconds: " << ToMilliSeconds(end - start).count() << std::endl;
    std::cout << "  Microseconds: " << ToMicroSeconds(end - start).count() << std::endl;
}
