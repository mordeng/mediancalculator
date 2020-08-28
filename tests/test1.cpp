// #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Mediancalculator.hpp"
#include <iostream>


using namespace std;


TEST_CASE( "Runnin Mediancalculator", "[small example with smaller and bigger numbers]" ) {


	Mediancalculator median;


	string pathtofile= "../ressources/numbers.json";


    REQUIRE( 	median.ParesNumbersandGetMedian(pathtofile.c_str())==32.00 );
   
}




TEST_CASE( "Runnin Mediancalculator 2", "[bigger example with smaller and bigger numbers]" ) {


	Mediancalculator median;


	string pathtofile= "../ressources/numbers2.json";


    REQUIRE( 	median.ParesNumbersandGetMedian(pathtofile.c_str())==10.00 );
   
}


TEST_CASE( "Runnin Mediancalculator with wrong path", "[wrong path]" ) {


	Mediancalculator median;


	string pathtofile= "../ressources/numbers-not there.json";


    REQUIRE( 	median.ParesNumbersandGetMedian(pathtofile.c_str())==-71 );
   
}


TEST_CASE( "Runnin Mediancalculator with invalid numbers or signs", "[wrong input]" ) {


	Mediancalculator median;


	string pathtofile= "../ressources/numbers-invalid.json";


    REQUIRE( 	median.ParesNumbersandGetMedian(pathtofile.c_str())==-72 );
   
}