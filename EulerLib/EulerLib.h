/*
* File: EulerLib.h
* Author: Gary Hubley
* Company: Self
* Description:
*		Declaration of functions used in Project Euler problems. Contains inline functions as well
*
*/
#pragma once
#include <vector>

// Checks if num is multiple of mul
inline bool isMultiple( long long num, long long mul )
{
	return num % mul == 0;
}

// check if a given number is even. 
inline bool isEven( int num )
{
	return isMultiple( num, 2 );
}

inline uint64_t min(uint64_t i, uint64_t j)
{
	return (i < j) ? i : j;
}

// Uses the sieve of Eratosthenes to generate a vector of prime numbers LESS THAN n
std::vector< uint64_t > primeEratosthenes( const uint32_t n );

// Uses the sieve of Eratosthenes to find the nth prime number
unsigned long long nthPrimeEratosthenes( unsigned long n );

// checks if an integer number is a palindrome
bool isPalindrome( int num );

// checks if a string is a palindrome
bool isPalindrome( const std::string &num );

// Calculate the sum of squares in range [start, end]
unsigned long long sumOfSquares_slow( int start, int end );

// calculate the sum of squares for the first n natural numbers
unsigned long long sumOfSquares( int n );

// Calculate the square of the sum for range [start, end]
unsigned long long squareOfSum_slow( int start, int end );

// calculate the square of the sum for the first n natural numbers
unsigned long long squareOfSum( int end );

// Find the max product of 'span' digits in a string of numbers
unsigned long long maxProduct( unsigned span, const std::string &str );

// Get the prime factorization of n as a vector of tuples
std::vector< std::tuple<uint64_t, uint64_t>> PrimeFactorization(uint64_t n, const std::vector<uint64_t> &primes);

// Computes the number of divisors for a given number n
uint32_t NumberOfDivisors(uint64_t n, const std::vector<uint64_t> &primes);

// Given a Collatz sequence number, this function returns the next number in the sequence.
uint64_t GetNextCollatzTerm( uint64_t n );

// multiply a large number by a scalar. 
std::vector<uint8_t> LargeMultiply(uint64_t x, std::vector<uint8_t> &ret);

// Get the binomial coefficient of n choose k. (Combinations)
uint64_t BinomialCoefficient(uint64_t n, uint64_t k);

// ex: "one" -> 3. "five" -> 4. Only works for numbers less than 20 thousand.
uint32_t CountLettersInNumberVernacular(uint32_t n);