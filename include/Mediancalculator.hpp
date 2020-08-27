#pragma once

class Mediancalculator {
public:

	Mediancalculator();
	~Mediancalculator();
	void ParseNumerArrayJson(const char * path);

	// https://www.geeksforgeeks.org/program-for-mean-and-median-of-an-unsorted-array/
	double findMedian(double a[], unsigned int n);



};