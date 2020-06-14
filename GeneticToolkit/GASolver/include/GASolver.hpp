#ifndef __GA_SOLVER_HPP__
#define __GA_SOLVER_HPP__

#include <vector>
#include <utility>
#include <chrono>
#include <iostream>
#include <string>
#include <tuple>

#include "Gene.hpp"
#include "MersenneTwister.hpp"

class GASolver{
	protected:
		MersenneTwister* RandomGenerator;
		std::vector<Gene> Population;
		std::vector<std::pair<double,double>> Bounds;
		std::vector<double> FitVals;

		std::vector<std::pair<double,double>> OneDimData;
		std::vector<std::tuple<double,double,double>> TwoDimData;
		
		int PopSize;		
		double MutateRate;
		double Tolerance;
		int Generations;

		double Chi2(const std::vector<double>&,const std::vector<double>&);
		virtual void Mutate();
		void Rank();
		int Partition(std::vector<Gene>&,std::vector<double>&,const int&,const int&);
		void QuickSortRec(std::vector<Gene>&,std::vector<double>&,const int&,const int&);
	public:
		GASolver(const int&,const int&,const std::vector<std::pair<double,double>>&,const double&,const int&,const double&);
		~GASolver();

		void LoadOneDimData(const std::vector<double>&,const std::vector<double>&);
		void LoadTwoDimData(const std::vector<double>&,const std::vector<double>&,const std::vector<double>&);
		void Print(std::string opt = "");

		virtual std::tuple<Gene,double,int> Solve();
		virtual void EvaluateGeneration();
		virtual void Function();
};

#endif
