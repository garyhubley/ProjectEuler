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

// Uses the sieve of Eratosthenes to generate a vector of prime numbers LESS THAN n
std::vector< int > primeEratosthenes( unsigned long n );

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