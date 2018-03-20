/*
* File: Problem04.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem04 from projecteuler.com
*
* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers
* is 9009 = 91 × 99.
*
* Find the largest palindrome made from the product of two 3-digit numbers.
*
*/

#include "EulerLib.h"
#include <iostream>

int main()
{
	int max_palindrome = 0;
	for( int i = 100; i < 1000; i++ )
	{
		for( int j = 100; j < 1000; j++ )
		{
			int current = i * j;
			if( current > max_palindrome && isPalindrome( current ) )
			{
				max_palindrome = current;
			}
		}
	}
	std::cout << "Answer: " << max_palindrome << std::endl;
	
	std::cin.get();
	return 0;
}
