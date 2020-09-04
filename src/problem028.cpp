/*
 * File: Problem028.cpp
 * Author: Gary Hubley
 * Company: Self
 * Description:
 *		This is my attempt at problem028 from projecteuler.net
 *
 * Starting with the number 1 and moving to the right in a clockwise direction
 * a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way?
 */

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds(x) (std::chrono::duration_cast<std::chrono::seconds>(x))
#define ToMilliSeconds(x) (std::chrono::duration_cast<std::chrono::milliseconds>(x))

void problem028() {
    auto start = Clock::now();

    int spiralDimension = 1001;
    int sum = 0;
    int n = 1;
    for( int curDim = 1; curDim <= spiralDimension; curDim += 2 ) {
        int localMax = curDim * curDim;
        do {
            n += curDim - 1;
            sum += n;
        } while( n < localMax );
    }

    auto end = Clock::now();

    std::cout << "Answer: " << sum << std::endl;
    std::cout << "Time: " << ToMilliSeconds(end - start).count() << " milliseconds" << std::endl;
}

