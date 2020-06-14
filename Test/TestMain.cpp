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
	std::cout << "Usage: " << programname << " -n [numvar] -p [popsize] for the num of val to generate" << std::endl;
}


int main( int argc, char* argv[]){
	int opt;
	int vals = 0;
	int pop = 0;
	double mut = 0.3;

	while( (opt = getopt(argc,argv,":n:p:")) != -1 ){
		switch( opt ){
			case 'n':
				vals = std::atoi(optarg);
				break;
			case 'p':
				pop = std::atoi(optarg);
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

	std::vector<std::pair<double,double>> bounds(vals,std::pair<double,double>(-1.0,1.0));
	Gene test(pop);
	MersenneTwister rand;
	GASolver solver(vals,pop,bounds,mut); 

	for( auto ii = 0; ii < pop; ++ii )
		test.EmplaceBack(rand.random());

	std::cout << "Average:  " << test.Average() << "\n";
	std::cout << "StdDev:   " << test.StdDev() << "\n";
	std::cout << "MaxValue: " << test.FindMaxValue() << "\n";
	std::cout << "MinValue: " << test.FindMinValue() << "\n";

	exit(EXIT_SUCCESS);
}
