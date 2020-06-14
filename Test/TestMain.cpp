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
	std::cout << "Usage: " << programname << " -n [numvar] -p [popsize] -m [mutrate] -g [gens] -t [tol] for the num of val to generate" << std::endl;
}


int main( int argc, char* argv[]){
	int opt;
	int vals = 0;
	int pop = 0;
	double mut = 0.3;
	int gen = 0;
	double tol = 1.0e-3;

	while( (opt = getopt(argc,argv,":n:p:g:m:t:")) != -1 ){
		switch( opt ){
			case 'n':
				vals = std::atoi(optarg);
				break;
			case 'p':
				pop = std::atoi(optarg);
				break;
			case 'g':
				gen = std::atoi(optarg);
				break;
			case 'm':
				mut = std::atof(optarg);
				break;
			case 't':
				tol = std::atof(optarg);
				break;
			default:
				std::cout << "Unknown option. See usage" << std::endl;
				ShowUsage(argv[0]);
				break;
		}
	}

	if( vals <= 0 or pop <= 0 or mut <= 0.0 or tol <= 0 or gen <= 0 ){
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
	GASolver solver(vals,pop,bounds,mut,gen,tol); 
	solver.Print();

	exit(EXIT_SUCCESS);
}
