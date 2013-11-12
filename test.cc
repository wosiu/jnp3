#include <iostream>
#include <assert.h>
#include <sstream>
#include <string>
#include <typeinfo>
#include <algorithm>
#include "sejf.h"
#include "kontroler.h"

using namespace std;

void kontroler_test()
{
/*

	Sejf s1("abcd",2);
	//const Kontroler* k1 = &( s1.kontroler() );
	//const Kontroler & k1 = s1.kontroler(); //chcemy zeby auto dzialalo tak
	//Kontrel k1 = s1.kontroler();
	auto k1 = s1.kontroler();
	//cout << sizeof( k1 ) << endl;
	//cout << typeid(k1).name() << endl;
	cout << (s1.kontroler());
	cout << (k1);
	s1 += 1;
	cout << (k1);
*/

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

	// to musi dawac blad kompilacji (odkomnetowac i sprawdzic!):
	/*
	Sejf s2( "abcd", 0 );
	Sejf s3( "abcd", 0 );

	if ( s2.kontroler() < s3.kontroler() )
		cout << "HMM" << endl;
    */
}

void swap_test()
{
	Sejf s1("aaa");
	Sejf s2("bbb",0);

	swap( s1, s2 );

	assert( s1[1] == (int)'b' );
	assert( s1.kontroler() );
	assert( ! s2.kontroler() );

	//to powinno dawac blad kompilacji (odkomnetowac i sprawdzic!):
	//Sejf s3( s2 );
	//ale to juz nie, bo taki konstruktor zrobilismy, zeby dzialal swap:
	//Sejf s3( move(s2) );
}


int main(){

	kontroler_test();
	bool_test();
	swap_test();

    cout << "OK :)" << endl;
	return 0;
}
