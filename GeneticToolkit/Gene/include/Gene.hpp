#ifndef __GENES_HPP__
#define __GENES_HPP__

#include <vector>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

#define AUTORESERVESIZE 1024

class Gene{
	private:
		std::vector<double> Values;
		int NumVars;
	public:
		Gene();
		Gene(const int&);

		double operator[](int) const;
		double& operator[](int);

		void PushBack(const double&);
		void EmplaceBack(const double&);
		int Size() const;
		void Print() const;
		double Average() const;
		double StdDev() const;

		std::pair<double,int> FindMax() const;
		double FindMaxValue() const;
		int FindMaxValueIndex() const;

		std::pair<double,int> FindMin() const;
		double FindMinValue() const;
		int FindMinValueIndex() const;

		friend std::ostream& operator << (std::ostream&,const Gene&);
};

#endif
