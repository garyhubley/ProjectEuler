/*
 * File: Problem026.cpp
 * Author: Gary Hubley
 * Company: Self
 * Description:
 *		This is my attempt at problem026 from projecteuler.net
 *
 * A unit fraction contains 1 in the numerator. The decimal representation of
 * the unit fractions with denominators 2 to 10 are given:
 *
 *        1/2 = 0.5
 *        1/3 = 0.(3)
 *        1/4 = 0.25
 *        1/5 = 0.2
 *        1/6 = 0.1(6)
 *        1/7 = 0.(142857)
 *        1/8 = 0.125
 *        1/9 = 0.(1)
 *        1/10 = 0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
 * seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring
 * cycle in its decimal fraction part.
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <string>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds(x) (std::chrono::duration_cast<std::chrono::seconds>(x))
#define ToMilliSeconds(x) (std::chrono::duration_cast<std::chrono::milliseconds>(x))

int lengthRecurringCycle(int numerator, int denominator) {
    int rem = numerator % denominator;
    std::vector<int> prev_rems(denominator, 0);

    prev_rems[numerator / denominator] = -1;

    rem = rem % denominator;
    int i;
    for (i = 1; i <= denominator && prev_rems[rem] == 0; ++i) {
        prev_rems[rem] = i;

        while ((rem *= 10) < denominator) {
            i++;
        }

        rem = rem % denominator;
    }
    return rem == 0 ? 0 : i - prev_rems[rem];
}

void problem026() {
    int longest_cycle = 6;  // from the above list
    int longest_d     = 0;
    auto start        = Clock::now();

    for (int d = 2; d < 1000; ++d) {
        int length = lengthRecurringCycle(1, d);
        if (length > longest_cycle) {
            longest_cycle = length;
            longest_d     = d;
        }
    }

    auto end = Clock::now();

    std::cout << "Answer: " << longest_d << ", " << longest_cycle << std::endl;
    std::cout << "Time: " << ToMilliSeconds(end - start).count() << " milliseconds" << std::endl;
}

