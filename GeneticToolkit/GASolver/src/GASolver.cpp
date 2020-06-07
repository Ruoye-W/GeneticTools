#include "GASolver.hpp"

GASolver::GASolver(const int& numvars,const int& popsize,const double& mutate){
	if( numvars <= 0 )
		throw "GASolver needs more than one variable to minimize";

	this->Population = std::vector<Gene>(numvars,Gene(popsize));
	this->RandomDistribution = "normal";
	this->FitVals.reserve(popsize);
	this->MutateRate = mutate;
	
	for( int ii = 0; ii < numvars; ++ii ){
		for( int jj = 0; jj < popsize; ++jj )
			this->Population.at(ii).PushBack(this->RandomGenerator.random());
	}
}
