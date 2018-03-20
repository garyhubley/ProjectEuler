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

	for ( unsigned i = 2; i < n; i++ )
	{
		if ( !markers[i] )
		{
			// i is a prime number
			primes.push_back( i );

			int multiplier = 2;
			for ( unsigned j = i * multiplier; j < n; multiplier++, j = i * multiplier )
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
	while ( low <= high )
	{
		if ( str.at( low ) != str.at( high ) )
		{
			return false;
		}
		low++;
		high--;
	}
	return true;
}

unsigned long long sumOfSquares_slow( int start, int end )
{
	unsigned long long sum = 0;
	for ( int i = start; i <= end; i++ )
	{
		sum += i * i;
	}
	return sum;
}

unsigned long long sumOfSquares( int end )
{
	return (2 * end + 1)*(end + 1)*end / 6;	
}

unsigned long long squareOfSum_slow( int start, int end )
{
	unsigned long long sum = 0;
	for ( int i = 1; i <= end; i++ )
	{
		sum += i;
	}
	return sum * sum;
}

unsigned long long squareOfSum( int end )
{
	unsigned long long sum = (end * (end + 1) / 2);
	return sum * sum;
}