/*
* File: EulerLib.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		Definition of functions used in Project Euler problems.
*
*/

#include "stdafx.h"

// Uses the sieve of Eratosthenes to generate a vector of prime numbers LESS THAN n
std::vector< uint64_t > primeEratosthenes( const uint32_t n )
{
	const int composite = 1;
	std::vector< int > markers( n ); // used to mark composite numbers
	std::vector< uint64_t > primes;
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
	int high = static_cast<uint32_t>(str.length()) - 1;
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

std::vector< std::tuple<uint64_t, uint64_t>> PrimeFactorization( uint64_t n, const std::vector<uint64_t> &primes )
{
	uint64_t count = 0;
	std::vector< std::tuple<uint64_t, uint64_t>> ret;
	for ( uint32_t i = 0; i < primes.size() && n>1; i++ )
	{
		count = 0;
		while ( n%primes.at( i ) == 0 )
		{
			n /= primes[i];
			count++;
		}
		if ( count )
		{
			ret.push_back( std::tuple<uint64_t, uint64_t>( primes.at( i ), count ) );
		}
	}
	if ( n > 1 )
	{
		throw std::exception( "Insufficient quantity of prime numbers given" );
	}

	return ret;
}

uint64_t NumberOfDivisors( uint64_t n, const std::vector<uint64_t> &primes )
{
	uint64_t num_divisors = 1;
	std::vector<std::tuple<uint64_t, uint64_t>> prime_factors = PrimeFactorization( n, primes );

	for ( uint32_t i = 0; i < prime_factors.size(); i++ )
	{
		num_divisors *= std::get<1>( prime_factors.at( i ) ) + 1;
	}
	return num_divisors;
}

uint64_t GetNextCollatzTerm( uint64_t n )
{
	if ( n & 1 )
	{
		// n is odd
		return 3 * n + 1;
	}
	return n / 2;
}

std::vector<uint8_t> LargeMultiply( uint64_t x, std::vector<uint8_t> &ret, bool print )
{
	uint64_t carry = 0;

	for ( uint32_t i = 0; i < ret.size(); i++ )
	{
		uint64_t prod = ret[i] * x + carry;
		ret[i] = prod % 10;
		carry = prod / 10;
	}

	while ( carry )
	{
		ret.push_back( carry % 10 );
		carry /= 10;
	}
	if ( print )
	{
		auto f = ret.rbegin();
		while ( !(*f) )
			++f;

		while ( f != ret.rend() )
		{
			std::cout << static_cast<uint32_t>(*f);
			++f;
		}
		std::cout << std::endl;
	}
	return ret;
}

uint64_t BinomialCoefficient( uint32_t n, uint32_t k )
{
	std::vector<std::vector<uint64_t>> bc( n + 1, std::vector<uint64_t>( k + 1 ) );

	for ( uint32_t i = 0; i <= n; i++ )
	{
		for ( uint32_t j = 0; j <= min( i, k ); j++ )
		{
			if ( j == 0 || j == i )
			{
				bc[i][j] = 1;
			}
			else
			{
				bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
			}
		}
	}
	return bc[n][k];
}


uint32_t CountLettersInNumberVernacular( uint32_t n )
{
	static std::map<uint32_t, uint32_t> numbers(
		{ { 1, 3 },{ 2, 3 },{ 3, 5 },{ 4, 4 },{ 5, 4 },{ 6, 3 },{ 7, 5 },{ 8, 5 },{ 9, 4 },{ 10, 3 },{ 11, 6 },
		{ 12, 6 },{ 13, 8 },{ 14, 8 },{ 15, 7 },{ 16, 7 },{ 17, 9 },{ 18, 8 },{ 19, 8 },{ 20, 6 },{ 30, 6 },{ 40, 5 },
		{ 50, 5 },{ 60, 5 },{ 70, 7 },{ 80, 6 },{ 90, 6 },{ 100, 7 },{ 1000, 8 } }
	);
	uint32_t sum = 0;
	uint32_t thousands, hundreds, tens;

	if ( (thousands = n / 1000) )
	{
		sum += numbers[thousands] + numbers[1000];

		n = n % 1000;
	}

	if ( (hundreds = n / 100) )
	{
		sum += numbers[hundreds] + numbers[100];
		n = n % 100;
	}


	if ( n > 20 )
	{
		tens = n / 10 * 10;
		n = n % 10;
	}
	else
	{
		tens = 0;
	}

	sum += numbers[tens] + numbers[n];

	if ( (hundreds || thousands) && (tens || n) )
	{
		sum += 3; // length of 'and'
	}
	return sum;
}

std::vector< uint8_t > LargeFactorial( uint32_t num, bool print )
{
	std::vector<uint8_t> factorial( 1000 );
	factorial[0] = 1;
	for ( uint32_t x = num; x > 1; x-- )
	{
		factorial = LargeMultiply( x, factorial, print );
	}
	return factorial;
}

std::vector< uint32_t > ProperDivisors( uint32_t num, bool print )
{
	//***** This can be improved **** 
	std::vector< uint32_t > divisors; // all numbers are divisible by 1
	uint32_t max = num / 2 + 1;
	for( uint32_t d = 1; d < max; d++ )
	{
		if( isDivisible(num, d ) )
		{
			divisors.push_back( d );
		}
	}
	if ( print )
	{
		std::cout << num << ": ";
		FwdPrintVector( divisors );
	}
	return divisors;
}

template< typename tp >
void FwdPrintVector( std::vector< tp > &vec )
{
	for ( auto v : vec )
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

template< typename tp >
void RevPrintVector( std::vector< tp > &vec )
{
	auto f = vec.rbegin();
	while ( !(*f) )
		++f;

	while ( f != vec.rend() )
	{
		std::cout << static_cast<uint32_t>(*f);
		++f;
	}
	std::cout << std::endl;
}