#include <iostream>
#include "testfile.hpp"

using namespace std;



int main(){


	printf("%s\n","this is my text a new one and another" );
	testfile t;

	t.test(1);
	t.~testfile();


	return 0;
}