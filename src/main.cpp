
#include "problems.h"

#include <iostream>

int main() {

	unsigned int problemNum;
    auto numProblems = problems.size();

	std::cout << numProblems << " problems have been complete." << std::endl;
	std::cout << "What problem would you like to see?" << std::endl;
	std::cin >> problemNum;
	 
	if( problemNum > problems.size() ) {
		std::cout << "This problem hasn't been completed yet" << std::endl;
		exit(1);
	}

	problemNum--; //account for 0 indexing

	problems[problemNum]();

	return 0;
}
