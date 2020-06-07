#include "Gene.hpp"

Gene::Gene(){
	this->values.reserve(AUTORESERVESIZE);
}

Gene::Gene(const int& count){
	this->values.reserve(count);
}

Gene::Gene(const double& init,const int& count){
	this->values = std::vector<double>(count,init);
}

void Gene::PushBack(const double& val){
	this->values.push_back(val);
}

int Gene::Size() const{
	return this->values.size();
}

void Gene::Print() const{
	int len = this->values.size();
	for( int ii = 0; ii < len; ++ii )
		std::cout << this->values.at(ii) << "\n";
}

double Gene::Average() const{
	double avg = 0.0;
	int len = this->values.size();
	for( int ii = 0; ii < len; ++ii )
		avg += this->values.at(ii);
	return avg / static_cast<double>(len);
}

double Gene::StdDev() const{
	double avg = this->Average();
	int len = this->values.size();
	double sum = 0.0;
	for( int ii = 0; ii < len; ++ii )
		sum += (this->values.at(ii) - avg)*(this->values.at(ii) - avg);
	sum /= static_cast<double>(len);
	return std::sqrt(sum);
}

double Gene::operator[](int ii) const{
	return this->values.at(ii);
}

double& Gene::operator[](int ii) {
	return this->values.at(ii);
}
		
std::ostream& operator << (std::ostream& out,const Gene& gene){
	for( auto ii : gene.values )
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
	if( this->values.size() == 0 ){
		throw "Trying to find max value on an empty gene";
	}else{
		double max = this->values.at(0);
		int len = this->values.size();
		int maxindex = 0;
		for( int ii = 0; ii < len; ++ii ){
			if( this->values.at(ii) > max ){
				max = this->values.at(ii);
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
	if( this->values.size() == 0 ){
		throw "Trying to find max value on an empty gene";
	}else{
		double min = this->values.at(0);
		int len = this->values.size();
		int minindex = 0;
		for( int ii = 0; ii < len; ++ii ){
			if( this->values.at(ii) < min ){
				min = this->values.at(ii);
				minindex = ii;
			}
		}
		return std::make_pair(min,minindex);
	}

}
