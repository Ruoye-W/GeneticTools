#include "Gene.hpp"

Gene::Gene(){
	this->Values.reserve(AUTORESERVESIZE);
}

Gene::Gene(const int& count){
	this->Values.reserve(count);
	this->NumVars = count;
}

void Gene::EmplaceBack(const double& val){
	this->Values.emplace_back(val);
}

void Gene::PushBack(const double& val){
	this->Values.push_back(val);
}

int Gene::Size() const{
	return this->Values.size();
}

void Gene::Print() const{
	int len = this->Values.size();
	for( int ii = 0; ii < len; ++ii )
		std::cout << this->Values.at(ii) << "\n";
}

double Gene::Average() const{
	double avg = std::accumulate(this->Values.begin(),this->Values.end(),0.0);
	return avg / static_cast<double>(this->NumVars);
}

double Gene::StdDev() const{
	double avg = this->Average();
	double sum = 0.0;
	for( int ii = 0; ii < this->NumVars; ++ii )
		sum += (this->Values.at(ii) - avg)*(this->Values.at(ii) - avg);
	sum /= static_cast<double>(this->NumVars);
	return std::sqrt(sum);
}

double Gene::operator[](int ii) const{
	return this->Values.at(ii);
}

double& Gene::operator[](int ii) {
	return this->Values.at(ii);
}
		
std::ostream& operator << (std::ostream& out,const Gene& gene){
	for( auto ii : gene.Values )
		out << ii << " ";
	return out;
};

double Gene::FindMaxValue() const{
	return this->FindMax().first;
}

int Gene::FindMaxValueIndex() const{
	return this->FindMax().second;
}

std::pair<double,int> Gene::FindMax() const{
	if( this->Values.size() == 0 ){
		throw "Trying to find max value on an empty gene";
	}else{
		double max = this->Values.at(0);
		int maxindex = 0;
		for( int ii = 0; ii < this->NumVars; ++ii ){
			if( this->Values.at(ii) > max ){
				max = this->Values.at(ii);
				maxindex = ii;
			}
		}
		return std::make_pair(max,maxindex);
	}
}

double Gene::FindMinValue() const{
	return this->FindMin().first;
}

int Gene::FindMinValueIndex() const{
	return this->FindMin().second;
}

std::pair<double,int> Gene::FindMin() const{
	if( this->Values.size() == 0 ){
		throw "Trying to find max value on an empty gene";
	}else{
		double min = this->Values.at(0);
		int minindex = 0;
		for( int ii = 0; ii < this->NumVars; ++ii ){
			if( this->Values.at(ii) < min ){
				min = this->Values.at(ii);
				minindex = ii;
			}
		}
		return std::make_pair(min,minindex);
	}

}
