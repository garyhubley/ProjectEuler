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
    
    uint32_t firstTen[] = { 0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768,
                             59049 };
    uint32_t sum = 0;
    auto start = Clock::now();

    // 6*(9^5) = 354294, therefore any number above 354294 can't meet
    // conditions
    for( uint32_t num = 2; num < 354295; num++ ) {
        uint32_t fifthPwrSum = 0;
        uint32_t tmp = num;

        while( tmp > 0 ) {
            fifthPwrSum += firstTen[tmp % 10];
            tmp = tmp / 10;
        }

        if( fifthPwrSum == num ) {
            sum += num;
        }

    }

    auto end = Clock::now();

    std::cout << "Answer: " << sum << std::endl;
    std::cout << "Time: " << ToMilliSeconds(end - start).count() << " milliseconds" << std::endl;
}
