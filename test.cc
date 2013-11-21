#include <iostream>
#include <assert.h>
#include <sstream>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <stdexcept>
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
	/* case 1 */
	Sejf s1( "aaa", 1 ), s2( "bbb", 0 );
	auto k1 = s1.kontroler();
	swap( s1, s2 );
	if ( k1 ) assert( false );

	/* case 2 */

	Sejf s3("aaa");
	Sejf s4("bbb", 0);

	swap( s3, s4 );

	assert( s3[1] == -1 );
	assert( s4[1] == (int)'a' );
	assert( !s3.kontroler() );
	assert( s4.kontroler() );

	/* case 3 */
	Sejf a("A", 1), b("B", 1);
	b += 1;
	auto k = b.kontroler();
	a[0]; a[0];
	swap(a, b);
	string res,res2;
	stringstream ss;
	ss << k;
	ss >> res;
	ss >> res2;
	assert ( res2.compare( "WLAMANIE" ) == 0 );

	//to powinno dawac blad kompilacji (odkomnetowac i sprawdzic!):
	//Sejf s3( s2 );
	//ale to juz nie, bo taki konstruktor zrobilismy, zeby dzialal swap:
	//Sejf s3( move(s2) );
}

void exception_test(){

    try{
        Sejf s_ujemny("kartofel", -1);
    }
    catch (const range_error & oor) {
        cerr << "Zlapano sejf ujemny.    \tERROR: " << oor.what();
    }

    try{
        Sejf s_za_duzy("kanapka", 1000001LL);
    }
    catch (const range_error & oor) {
        cerr << "Zlapano sejf za_duzy.   \tERROR: " << oor.what();
    }

    try{
        Sejf s_ujemny_duzy("indyk", -999999999LL);
    }
    catch (const range_error & oor) {
        cerr << "Zlapano sejf ujemny_duzy. \tERROR: " << oor.what();
    }

    try{
        Sejf s_ujemny_duzy("orteoblasty", 999999999LL);
    }
    catch (const range_error & oor) {
        cerr << "Zlapano sejf duzy_duzy. \tERROR: " << oor.what();
    }
    cerr <<endl;
}

int main(){

	kontroler_test();
	bool_test();
	swap_test();
	exception_test();

    cout << "OK :)" << endl;
	return 0;
}
