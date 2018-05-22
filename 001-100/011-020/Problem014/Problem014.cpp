/*
* File: Problem014.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem014 from projecteuler.com
*
* The following iterative sequence is defined for the set of positive integers:
*
* n = n/2 (n is even)
* n = 3n + 1 (n is odd)
*
* Using the rule above and starting with 13, we generate the following sequence:
*
*			13 ? 40 ? 20 ? 10 ? 5 ? 16 ? 8 ? 4 ? 2 ? 1
*
* It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been
* proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
*
* Which starting number, under one million, produces the longest chain?
*
* NOTE: Once the chain starts the terms are allowed to go above one million.
*
 */

#include <iostream>
#include <vector>
#include <stack>
#include "EulerLib.h"
#include <iomanip>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;


int main()
{
	uint64_t max = 1000000;
	uint32_t max_terms = max * 10;
	uint64_t max_start = 2;
	uint64_t max_count = 2;
	std::vector<int64_t> collatz_terms( max_terms, 0 );
	collatz_terms[1] = 1;
	collatz_terms[2] = 2;

	auto start = Clock::now();

	for ( uint32_t st = 3; st < max; st++ )
	{
		//if (!(start % 100000)) {
		//	std::cout << std::setw(7) << start << "|" << std::setw(7) << max_count << "|" << std::setw(7) << max_start << std::endl;
		//}
		uint32_t term = st;
		std::stack<uint64_t> terms;
		int64_t count;
		while ( true )
		{

			if ( term < max_terms && (count = collatz_terms[term]) > 0 )
			{
				// this term has been seen before
				break;
			}
			terms.push( term );
			term = static_cast<uint32_t>(GetNextCollatzTerm( term ));
		}

		while ( !terms.empty() )
		{
			count++;
			if ( uint32_t t = terms.top() < max_terms )
			{
				collatz_terms[t] = count;
			}
			terms.pop();
		}
		if ( count > max_count )
		{
			max_start = st;
			max_count = count;
		}
	}
	auto end = Clock::now();
	std::cout << "Answer: " << max_start << " with " << max_count << " terms" << std::endl;


	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
		<< " seconds" << std::endl;
	std::cin.get();
	return 0;
}
