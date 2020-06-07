#ifndef __GA_SOLVER_HPP__
#define __GA_SOLVER_HPP__

#include <vector>
#include <string>

#include "Gene.hpp"
#include "MersenneTwister.hpp"

class GASolver{
	private:
		MersenneTwister RandomGenerator;
		std::vector<Gene> Population;
		std::string RandomDistribution;
		
		double MutateRate;
		std::vector<double> FitVals;
	public:
		GASolver(const int&,const int&,const double&);
};

#endif
