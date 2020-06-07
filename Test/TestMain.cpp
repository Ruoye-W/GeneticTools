/*
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>

#include "Gene.hpp"
#include "MersenneTwister.hpp"
#include "GASolver.hpp"

void ShowUsage(char* );
void ShowUsage(char* programname){
	std::cout << "Usage: " << programname << " -n [num] for the num of val to generate" << std::endl;
}


int main( int argc, char* argv[]){
	int opt;
	int vals = 0;

	while( (opt = getopt(argc,argv,":n:")) != -1 ){
		switch( opt ){
			case 'n':
				vals = std::atoi(optarg);
				break;
			default:
				std::cout << "Unknown option. See usage" << std::endl;
				ShowUsage(argv[0]);
				break;
		}
	}

	if( vals <= 0 ){
		std::cout << "Need Argument for either inputfile or outputfile or xmlfile. See usage" << std::endl;
		ShowUsage(argv[0]);
		exit(EXIT_FAILURE);
	}

	if( optind > argc ){
		std::cout << "Need Argument(s). See usage" << std::endl;
		ShowUsage(argv[0]);
		exit(EXIT_FAILURE);
	}

	Gene test(vals);
	MersenneTwister rand;
	GASolver solver(1,vals,0.7); 

	for( auto ii = 0; ii < vals; ++ii )
		test.PushBack(rand.random());

	std::cout << "Average:  " << test.Average() << "\n";
	std::cout << "StdDev:   " << test.StdDev() << "\n";
	std::cout << "MaxValue: " << test.FindMaxValue() << "\n";
	std::cout << "MinValue: " << test.FindMinValue() << "\n";

	exit(EXIT_SUCCESS);
}
