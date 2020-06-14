#include "GASolver.hpp"

GASolver::GASolver(const int& numvars,const int& popsize,const std::vector<std::pair<double,double>>& bounds,const double& mutate,const int& numgens,const double& tol){
	if( numvars <= 0 )
		throw "GASolver needs more than one variable to minimize";

	this->Population = std::vector<Gene>(popsize,Gene(numvars));
	this->FitVals = std::vector<double>(popsize,0.0);
	this->MutateRate = mutate;
	this->Bounds = bounds;
	this->PopSize = popsize;
	this->Generations = numgens;
	this->Tolerance = tol;

	this->RandomGenerator = new MersenneTwister();
	this->RandomGenerator->init_genrand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());

	double upper = 0.0;
	double lower = 0.0;	
	
	for( unsigned int jj = 0; jj < numvars; ++jj ){
		upper = bounds.at(jj).second;
		lower = bounds.at(jj).first;
		for( unsigned int ii = 0; ii < popsize; ++ii )
			this->Population.at(ii).EmplaceBack((upper - lower)*this->RandomGenerator->random() + lower);	
	}
}

GASolver::~GASolver(){
	delete this->RandomGenerator;
	this->RandomGenerator = nullptr;
}

void GASolver::Print(std::string opt){
	if( opt != "" )
		this->RandomGenerator->print();

	for( unsigned int ii = 0; ii < this->PopSize; ++ii )
		std::cout << this->Population.at(ii) << '\n';
}

void GASolver::LoadOneDimData(const std::vector<double>& x,const std::vector<double>& y){
	if( x.size() != y.size() )
		throw "size of x not equal to size of y";
	
	this->OneDimData.reserve(x.size());
	for( unsigned int ii = 0; ii < x.size(); ++ii )
		OneDimData.emplace_back(std::make_pair(x.at(ii),y.at(ii)));
}

void GASolver::LoadTwoDimData(const std::vector<double>& x,const std::vector<double>& y,const std::vector<double>& z){
	if( x.size() != y.size() )
		throw "size of x not equal to size of y";
	if( x.size() != z.size() )
		throw "size of x not equal to size of z";

	this->TwoDimData.reserve(x.size());
	for( unsigned int ii = 0; ii < x.size(); ++ii )
		TwoDimData.emplace_back(std::make_tuple(x.at(ii),y.at(ii),z.at(ii)));
}
		
double GASolver::Chi2(const std::vector<double>& measured,const std::vector<double>& model){
	//write chi2 calculation
}

void GASolver::Rank(){
	//write quicksort for ranking the genes base on FitVals
	this->QuickSortRec(this->Population,this->FitVals,0,this->PopSize);
}

void GASolver::Mutate(){
}
		
void GASolver::EvaluateGeneration(){
}

void GASolver::Function(){
}
		
int GASolver::Partition(std::vector<Gene>& population,std::vector<double>& fitness,const int& first,const int& last){
	int ii = first;
	int jj = last + 1;
	while( ii <= jj ){
		do ++ii;
		while( fitness[ii] < fitness[first] );
		do --jj;
		while( fitness[first] < fitness[jj] );
		if( ii < jj ){
			std::swap(fitness[ii],fitness[jj]);
			std::swap(population[ii],population[jj]);
		}
	}
	std::swap(fitness[ii],fitness[jj]);
	std::swap(population[ii],population[jj]);
	return jj;
}

void GASolver::QuickSortRec(std::vector<Gene>& population,std::vector<double>& fitness,const int& first,const int& last){
	if( first < last ){
		int pivot = this->Partition(population,fitness,first,last);
		this->QuickSortRec(population,fitness,first,pivot - 1);
		this->QuickSortRec(population,fitness,pivot,last);
	}
}

std::tuple<Gene,double,int> GASolver::Solve(){
	int currgen = 0;
	
	do{
		EvaluateGeneration();
		++currgen;
	}while( currgen <= this->Generations and FitVals.at(0) >= this->Tolerance );
	
	return std::make_tuple(this->Population.at(0),this->FitVals.at(0),currgen);
}
