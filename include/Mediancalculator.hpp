#pragma once
#include <vector>
class Mediancalculator {
public:

	Mediancalculator();
	~Mediancalculator();
	double ParesNumbersandGetMedian(const char * path);

	double findMedian(std::vector<double> NumberVector);



};