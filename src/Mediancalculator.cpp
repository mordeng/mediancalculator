#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>    // std::sort
#include <vector>

#include "Mediancalculator.hpp"
using namespace rapidjson;
using namespace std;


Mediancalculator::Mediancalculator() {


}

// Function for calculating median 
double Mediancalculator::findMedian(vector<double> NumberVector)
{ 
    // First we sort the array 


	unsigned int begin=0;
	unsigned int end= NumberVector.size();

	unsigned int vsize=end;


	sort(NumberVector.begin(), NumberVector.end()); 

	//find start-position of values we want to calculate the median with
	while(begin<end && NumberVector[begin]<= (-70)){

		begin++;

	}

	//find end-position of values we want to calculate the median with
	while(end>begin && (NumberVector[end-1] > 2279999999)){
		end--;

	}


	//print number array with markings
	for (unsigned int i = 0; i < vsize; ++i)
	{

		if(i>=begin && i<end){
			printf("\033[0;32m%.2f, ",NumberVector[i] );  	
		}else{
			printf("\033[1;31m%.2f, ",NumberVector[i] );  	
		}
	}
	printf("\033[0;0m\n" );  	



	//create subset of numbers to calculate median
	vector<double> realNumberVector(&NumberVector[begin], &NumberVector[end]); 

	vsize=realNumberVector.size();

	if (vsize % 2 != 0) 
		return (double)realNumberVector[vsize/2]; 

	return (double)(realNumberVector[(vsize-1)/2] + realNumberVector[vsize/2])/2.0; 
} 



double Mediancalculator::ParesNumbersandGetMedian(const char * path){

	string line;

	printf("this is the path I got %s\n", path );

	ifstream myfile (path);

	if (myfile.is_open())
	{

		std::string NumbersJson;

		myfile.seekg(0, std::ios::end);   
		NumbersJson.reserve(myfile.tellg());
		myfile.seekg(0, std::ios::beg);

		NumbersJson.assign((std::istreambuf_iterator<char>(myfile)),
			std::istreambuf_iterator<char>());


		Document parser;
		parser.Parse(NumbersJson.c_str(), NumbersJson.length());


		if(parser.IsObject()==0 || parser.HasMember("numbers")==0){

			return -72;
		}
		
		const Value& numberarray = parser["numbers"];

		if(numberarray.IsArray()==0){

			return -72;
		}
		unsigned int arraySize=numberarray.Size();


		vector<double> lliNumberVector; 


	for (unsigned int i = 0; i < arraySize; i++) {// Uses SizeType instead of size_t

		
		if(numberarray[i].IsInt64()==0){

			printf("Invalid sign found in input array\n");

			return -72;
		}
		lliNumberVector.push_back(numberarray[i].GetInt64());


	}

	double median= findMedian(lliNumberVector);

	printf("Median = %.2f\n\n\n", median);

	myfile.close();

	return median;

}else{

	printf("unable to open file %s\n", path );
	return -71;

}
}

Mediancalculator::~Mediancalculator() {}