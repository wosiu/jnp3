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
	assert ( s1[1] == (int)'b' );
	ss << k1;
	ss >> res;
	assert ( res.compare("OK") == 0 );

	s1 += 2;
	assert ( s1[2] == (int)'c' );
	assert ( s1[4] == -1 );
	assert ( s1[3] == (int)'d' );
	ss << k1;
	ss >> res;
	ss >> res2;
	assert ( res2.compare( "ZMANIPULOWANY" ) == 0 );

	assert ( s1[1] == -1 );
	ss << k1;
	ss >> res;
	ss >> res2;
	assert ( res2.compare( "WLAMANIE" ) == 0 );
}

void bool_test()
{
	Sejf s0( "abcd", 0 );
    assert ( ! s0.kontroler() );

	Sejf s1( "abcd", 2 );
    assert ( s1.kontroler() );
	assert ( s1[0] == (int)'a' );
	assert ( s1.kontroler() );
	assert ( s1[4] == -1 );
	assert ( s1.kontroler() );
	assert ( s1[1] == (int)'b' );
	assert ( !s1.kontroler() );

	Sejf s2( "abcd", 0 );
	auto k2 = s2.kontroler();
    assert ( ! k2 );
}


int main(){
	kontroler_test();
	bool_test();


/*
	Sejf s2( "abcd", 0 );
	Sejf s3( "abcd", 0 );

	if ( s2.kontroler() < s3.kontroler() )
		cout << "HMM" << endl;
*/

	return 0;
}
