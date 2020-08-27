// #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "testfile.hpp"


using namespace std;


TEST_CASE( "Runnin class", "[init]" ) {

	testfile t;

    REQUIRE( t.test(1) == 3 );
   
}