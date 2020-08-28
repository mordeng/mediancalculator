#include <iostream>
#include "Mediancalculator.hpp"
#include <vector>
using namespace std;

typedef vector<string> CommandLineStringArgs;

int main(int argc, char *argv[]){
	
    CommandLineStringArgs cmdlineStringArgs(&argv[0], &argv[0 + argc]);
	Mediancalculator median;

     for (int i = 1; i < cmdlineStringArgs.size(); ++i)
    {
		median.ParesNumbersandGetMedian(cmdlineStringArgs[i].c_str());
    }


	return 0;
}