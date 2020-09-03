/*
* File: Problem009.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem009 from projecteuler.com
*
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
*					a^2 + b^2 = c^2
*
* For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
*
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
*/

#include <iostream>
#include <string>

void problem009()
{
	int a = 0, b = 0, c = 0;
	for ( int m = 1; m < 1000; m++ )
	{
		int numerator = 1000 - 2 * m * m;
		int denominator = 2 * m;

		if ( numerator % denominator == 0 )
		{
			int n = numerator / denominator;
			// Euclids equations.
			if ( (a = m * m - n * n) < 0 )
			{
				continue;
			}
			if ( (b = denominator * n) < 0 )
			{
				continue;
			}

			if ( (c = m * m + n * n) < 0 )
			{
				continue;
			}

			if ( a*a + b * b == c * c )
			{
				// found pythagorean triple.
				break;
			}
		}

	}
	std::cout << "a: " << a << std::endl << "b: " << b << std::endl << "c: " << c << std::endl;
	std::cout << "Answer: " << (a * b * c) << std::endl;
}

