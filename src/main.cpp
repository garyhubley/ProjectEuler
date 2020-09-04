
#include "problems.h"

#include <iostream>

int main( int argc, char **argv ) {

	unsigned int problemNum;
    auto numProblems = problems.size();

    switch( argc ) {
        case 1:
            std::cout << numProblems << " problems have been complete." << std::endl;
            std::cout << "What problem would you like to see?" << std::endl;
            std::cin >> problemNum;
            break;
        case 2:
            problemNum = std::stoi( argv[1] );
            break;
        default:
            std::cout << "incorrect number of args" << std::endl;
            exit(1);
    }

	if( problemNum > problems.size() ) {
		std::cout << "This problem hasn't been completed yet" << std::endl;
		exit(1);
	}

	problemNum--; //account for 0 indexing

	problems[problemNum]();

	return 0;
}
