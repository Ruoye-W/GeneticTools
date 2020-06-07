#ifndef __GENES_HPP__
#define __GENES_HPP__

#include <vector>
#include <iostream>
#include <utility>
#include <cmath>

#define AUTORESERVESIZE 1024

class Gene{
	private:
		std::vector<double> values;
	public:
		Gene();
		Gene(const int&);
		Gene(const double&,const int&);

		double operator[](int) const;
		double& operator[](int);

		void PushBack(const double&);
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
