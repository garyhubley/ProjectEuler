/*
 * File: Problem027.cpp
 * Author: Gary Hubley
 * Company: Self
 * Description:
 *		This is my attempt at problem027 from projecteuler.net
 *
 * Euler discovered the remarkable quadratic formula:
 *
 *      n2+n+41
 *
 * It turns out that the formula will produce 40 primes for the consecutive
 * integer values 0≤n≤39. However, when n=40,402+40+41=40(40+1)+41 is divisible
 * by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.
 *
 * The incredible formula n2−79n+1601 was discovered, which produces 80 primes
 * for the consecutive values 0≤n≤79. The product of the coefficients, −79 and
 * 1601, is −126479.
 *
 * Considering quadratics of the form:
 *
 *      n2+an+b, where |a|<1000 and |b|≤1000
 *
 *      where |n| is the modulus/absolute value of n
 *      e.g. |11|=11 and |−4|=4
 *
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes for consecutive values of n,
 * starting with n=0.
 */

#include "EulerLib.h"

#include <iostream>
#include <chrono>
#include <algorithm>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds(x) (std::chrono::duration_cast<std::chrono::seconds>(x))
#define ToMilliSeconds(x) (std::chrono::duration_cast<std::chrono::milliseconds>(x))

// binary search to find if a number is prime
bool isPrime( const std::vector<uint64_t> &primes, int val) {
    auto high = primes.size() - 1;
    auto middle = high / 2;
    auto low = 0;

    if( val <= 1 ) {
        return false;
    }

    while( low <= high ) {
        if( primes[middle] == val ) {
            return true;
        } else if ( val < primes[middle] ) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }

        middle = ( high + low ) / 2;
    }

    return false;
}

void problem027() {
    int max = 0;
    int valA = -2000, valB = -2000; // These are invalid values. Indicating 
                                    // error if they show up in the answer. 
    auto start = Clock::now();

    std::vector<uint64_t> primes = primeEratosthenes( 1000 * 1000 );

    for( int a = -999; a < 1000; a++ ) {
        for( int b = -1000; b <= 1000; b++ ) {
            int n = 0;
            while( isPrime( primes, n*n + a*n + b ) ) {
                n++;
                if( n > max ) {
                    max = n;
                    valA = a;
                    valB = b;
                }
            }
        }
    }
    
    auto product = valA * valB;

    auto end = Clock::now();

    std::cout << "Answer: " << product << std::endl;
    std::cout << "Is the product of " << valA << "and " << valB << std::endl;
    std::cout << "With " << max << " consecutive primes." << std::endl;

    std::cout << "Time: " << ToMilliSeconds(end - start).count() << " milliseconds" << std::endl;
}

