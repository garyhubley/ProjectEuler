/*
* File: Problem022.cpp
* Author: Gary Hubley
* Company: Self
* Description:
*		This is my attempt at problem022 from projecteuler.net
*
* Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first
* names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply
* this value by its alphabetical position in the list to obtain a name score.
*
* For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is
* the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
*
* What is the total of all the name scores in the file?
*/

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::chrono::high_resolution_clock Clock;
#define ToSeconds( x ) ( std::chrono::duration_cast<std::chrono::seconds>( x ) )
#define ToMilliSeconds( x ) ( std::chrono::duration_cast<std::chrono::milliseconds>( x ) )

std::vector<std::string> GetNames( const std::string &filename )
{
	std::ifstream name_file;
	std::vector< std::string > names( 5163 );
	std::string name;
	uint32_t ref = 0, count = 0;
	
	name_file.open( filename );
	
	if ( !name_file.is_open() )
		throw std::exception( "Unable to open file" );
	
	while ( std::getline( name_file, name, '"' ) )
	{
		if ( ref == 1 )
		{
			names[count] = name;
			count++;
		}
		ref = (ref + 1) % 2;
	}

	// should use move semantics. 
	return names;
}

int main()
{
	std::ifstream name_file;
	std::vector< std::string > names( 5163 );
			
	auto start = Clock::now();
	
	names = GetNames( "C:\\Projects\\ProjectEuler\\001-100\\021-030\\Problem022\\p022_names.txt" );

	std::sort( names.begin(), names.end() );
	
	auto end = Clock::now();

	std::cout << "Answer: " << std::endl;
	std::cout << "Time: " << ToMilliSeconds( end - start ).count() << " milliseconds" << std::endl;
	std::cin.get();
	return 0;
}


