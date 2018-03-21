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
#include <iostream>

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

// Uses the sieve of Eratosthenes to find the nth prime number
unsigned long long nthPrimeEratosthenes( unsigned long n )
{
	const int composite = 1;
	unsigned max = static_cast<unsigned> (2 * n * log( n ));
	std::vector< int > markers( max + 1 ); // used to mark composite numbers
	std::vector< unsigned long long > primes;
	primes.reserve( n + 1 );

	markers[0] = composite;
	markers[1] = composite;
	unsigned i = 2;

	while ( primes.size() < n )
	{
		if ( !markers[i] )
		{
			// i is a prime number
			primes.push_back( i );

			int multiplier = 2;
			for ( unsigned j = i * multiplier; j < max; multiplier++, j = i * multiplier )
			{
				// mark all multiples of j as composite numbers.
				markers[j] = composite;
			}
		}
		i++;
	}

	return primes.at( n - 1 );
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

unsigned long long maxProduct( unsigned span, const std::string &str )
{
	unsigned long long max = 1;
	unsigned long long current = max;
	unsigned start = 0;

	for ( unsigned i = 0; i < str.size() - 1; i++ )
	{
		while ( str.at( i ) == '0' )
		{
			// Found a zero
			i++;
			start = i;
			current = 1;
		}

		current *= str.at( i ) - '0';
		if ( i - start == span )
		{
			current /= str.at( start ) - '0';
			start++;
		}

		if ( current > max )
		{
			max = current;
		}
	}
	return max;
}