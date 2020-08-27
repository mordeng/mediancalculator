#include "Mediancalculator.hpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>    // std::sort
using namespace rapidjson;
using namespace std;
Mediancalculator::Mediancalculator() {


}


//sourcce: http://www.cplusplus.com/forum/general/198284/
// Function for calculating median 
double Mediancalculator::findMedian(double a[], unsigned int n)
{ 
    // First we sort the array 
    sort(a, a+n); 
  
    // check for even case 
    if (n % 2 != 0) 
       return (double)a[n/2]; 
      
    return (double)(a[(n-1)/2] + a[n/2])/2.0; 
} 
  


void Mediancalculator::ParseNumerArrayJson(const char * path){

 string line;



	printf("this is my path %s\n", path );

  ifstream myfile (path);
  // if (myfile.is_open())
  // {
  //   while ( getline (myfile,line) )
  //   {
  //     cout << line << '\n';
  //   }
  //   myfile.close();
  // }

  // else cout << "Unable to open file"; 



std::string NumbersJson;

myfile.seekg(0, std::ios::end);   
NumbersJson.reserve(myfile.tellg());
myfile.seekg(0, std::ios::beg);

NumbersJson.assign((std::istreambuf_iterator<char>(myfile)),
std::istreambuf_iterator<char>());


printf("get char array %s\n",NumbersJson.c_str() );

    Document parser;
   parser.Parse(NumbersJson.c_str(), NumbersJson.length());

	assert(parser.IsObject());
   assert(parser.HasMember("numbers"));

   const Value& numberarray = parser["numbers"];
	assert(numberarray.IsArray());
	unsigned int arraySize=numberarray.Size();

	double* lliNumberArray = NULL;   // Pointer to int, initialize to nothing.

	lliNumberArray = new double[arraySize];  // Allocate n ints and save ptr in a.


	for (unsigned int i = 0; i < arraySize; i++) {// Uses SizeType instead of size_t
			   lliNumberArray[i]=numberarray[i].GetInt();

	        // printf("a[%d] = %d\n", i, lliNumberArray[i]);



	}

		int quantityOfNum{0};



    cout << "Median = " << findMedian(lliNumberArray, arraySize) << arraySize << endl;  


delete [] lliNumberArray;  // When done, free memory pointed to by a.
}

Mediancalculator::~Mediancalculator() {}