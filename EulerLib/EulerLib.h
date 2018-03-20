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

// checks if an integer number is a palindrome
bool isPalindrome( int num );

// checks if a string is a palindrome
bool isPalindrome( const std::string &num );