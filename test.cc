#include <iostream>
#include <assert.h>
#include <sstream>
#include <string>
#include "sejf.h"

using namespace std;

void kontroler_test()
{
	Sejf s1( "abcd", 1 );
	auto k1 = s1.kontroler();

	stringstream ss;
	string res,res2;

	ss << k1;
	ss >> res;
	assert ( res.compare("OK") == 0 );
	assert( s1[1] == (int)'b' );
	ss << k1;
	ss >> res;
	assert ( res.compare("OK") == 0 );

	s1 += 2;
	assert( s1[2] == (int)'c' );
	assert( s1[4] == -1 );
	assert( s1[3] == (int)'d' );
	ss << k1;
	ss >> res;
	ss >> res2;
	assert ( res2.compare("ZMANIPULOWANY") == 0 );

	assert( s1[1] == -1 );
	ss << k1;
	ss >> res;
	ss >> res2;
	assert ( res2.compare("WLAMANIE") == 0 );
}


int main(){

	kontroler_test();
	return 0;
}
