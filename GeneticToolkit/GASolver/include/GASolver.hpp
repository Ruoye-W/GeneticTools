#ifndef __GA_SOLVER_HPP__
#define __GA_SOLVER_HPP__

#include <vector>
#include <utility>

#include "Gene.hpp"
#include "MersenneTwister.hpp"

class GASolver{
	private:
		MersenneTwister RandomGenerator;
		std::vector<Gene> Population;
		std::vector<std::pair<double,double>> Bounds;
		std::vector<double> FitVals;
		
		int NumVars;
		int PopSize;		
		double MutateRate;
	public:
		GASolver(const int&,const int&,const std::vector<std::pair<double,double>>&,const double&);
};

#endif
