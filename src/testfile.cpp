#include "testfile.hpp"
#include <iostream>


testfile::testfile() {


	printf("created testfile\n");
}

testfile::~testfile() {


printf("destroyed testfile\n");


}


int testfile::test(int i){

i=i+2;
printf("running test %d \n", i);

	return i;

}