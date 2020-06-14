#include "GASolver.hpp"

GASolver::GASolver(const int& numvars,const int& popsize,const std::vector<std::pair<double,double>>& bounds,const double& mutate){
	if( numvars <= 0 )
		throw "GASolver needs more than one variable to minimize";

	this->Population = std::vector<Gene>(numvars,Gene(popsize));
	this->FitVals.reserve(popsize);
	this->MutateRate = mutate;
	this->Bounds = bounds;

	double upper = 0.0;
	double lower = 0.0;	
	for( int ii = 0; ii < numvars; ++ii ){
		upper = bounds.at(ii).second;
		lower = bounds.at(ii).first;
		for( int jj = 0; jj < popsize; ++jj )
			this->Population.at(ii).PushBack((upper - lower)*this->RandomGenerator.random() + lower);
	}
}
