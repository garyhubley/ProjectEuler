/*
* File: EulerLib.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		Definition of functions used in Project Euler problems.
*
*/

#include "stdafx.h"
#include <sstream>

// Uses the sieve of Eratosthenes to generate a vector of prime numbers LESS THAN n
std::vector< int > primeEratosthenes( unsigned long n )
{
	const int composite = 1;
	std::vector< int > markers( n ); // used to mark composite numbers
	std::vector< int > primes; 
	primes.reserve( n / 2 ); // guaranteed not to have more than half of all numbers as primes. Avoids reallocation later

	markers[0] = composite;
	markers[1] = composite;

	for ( int i = 2; i < n; i++ )
	{
		if ( !markers[i] )
		{
			// i is a prime number
			primes.push_back( i );

			int multiplier = 2;
			for ( int j = i * multiplier; j < n; multiplier++, j = i * multiplier )
			{
				// mark all multiples of j as composite numbers.
				markers[j] = composite;
			}
		}
	}

	return primes;
}

bool isPalindrome( int num )
{
	std::stringstream str;
	str << num;
	return isPalindrome( str.str() );
}

bool isPalindrome( const std::string &str )
{
	int low = 0;
	int high = str.length() - 1;
	while( low <= high)
	{
		if( str.at( low ) != str.at( high ) )
		{
			return false;
		}
		low++;
		high--;
	}
	return true;
}