/*
 * File: Problem1.cpp
 * Author: Gary Hubley
 * Company: Self
 * Description:
 *		This is my attempt at problem1 from projecteuler.com
 *		
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
 * The sum of these multiples is 23.
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>
#include "EulerLib.h"

using namespace std;

int main()
{
	int sum = 0;
	for( int i = 0; i < 1000; i++ )
	{
		if ( isMultiple( i, 3 ) || isMultiple( i, 5 ) )
			sum += i;
	}
	cout << "Sum: " << sum << std::endl;
	cin.get();
}
