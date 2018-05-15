/*
* File: Problem019.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem019 from projecteuler.net
*
* You are given the following information, but you may prefer to do some research for yourself.
* 
*    1 Jan 1900 was a Monday.
*    Thirty days has September,
*    April, June and November.
*    All the rest have thirty-one,
*    Saving February alone,
*    Which has twenty-eight, rain or shine.
*    And on leap years, twenty-nine.
*
* A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
* How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )

bool IsLeapYear( uint32_t year )
{
	//If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
	if ( year % 4 )
		//The year is not a leap year( it has 365 days ).
		return false;

	//If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
	//If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
	if ( !(year % 100) )
	{
		if ( !(year % 400) )
		{
			//The year is a leap year( it has 366 days ).
			return true;
		}
		
		return false;
		
	}
	return true;
	
}

uint32_t daysPerMonth[12] =
{
	31, // Jan
	28, // Feb
	31, // Mar
	30, // Apr
	31, // May
	30, // Jun
	31, // Jul
	31, // Aug
	30, // Sep
	31, // Oct
	30, // Nov
	31, // Dec
};

int main()
{
	uint32_t day = 1;
	uint32_t sundays = 0;

	auto start = Clock::now();

	for( uint32_t year = 1901; year < 2001; year++ )
	{
		for ( uint32_t mth = 0; mth < 12; mth++ )
		{
			day += daysPerMonth[mth];
			if( mth == 1 && IsLeapYear(year))
			{
				day++;
			}
			if( ( day % 7 ) == 6 )
			{
				sundays++;
			}
			
		}
		
	}

	auto end = Clock::now();
	
	std::cout << "Answer: " << sundays << std::endl;
	std::cout << "Time: " << ToSeconds( end - start ).count() << " seconds" << std::endl;
	std::cin.get();
	return 0;
}

