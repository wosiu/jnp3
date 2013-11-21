/**
  * JNP, zadanie 3
  * Rafał Soszyński i Michał Woś
  * rs335786 + mw336071
  *
  * CCFLAGS -std=c++11
  */

#ifndef SEJF_H
#define SEJF_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "kontroler.h"

const static unsigned long long LIMIT_DOSTEPOW = 1000000ULL;
const static unsigned long long ILOSC_DOMYSLNA_DOSTEPOW = 42ULL;

class Kontroler;

class Sejf
{

friend class Kontroler;

public:
	// W przypadku próby tworzenia niepoprawnego sejfu (o ujemnej liczbie
	// dostepow) zostaje rzucony wyjatek.
	Sejf( const std::string & napis, int liczba = ILOSC_DOMYSLNA_DOSTEPOW );
	Sejf( std::string && napis, int liczba = ILOSC_DOMYSLNA_DOSTEPOW );
	Sejf( Sejf && rhs );
	void operator=( Sejf && rhs );
	friend std::ostream & operator<<( std::ostream & wyjscie,
									const Kontroler & k );
	void operator+=( int x );
	void operator-=( int x );
	void operator*=( int x );
	int16_t operator[]( size_t x );
	const Kontroler kontroler() const;

private:
	// napis jest jedynym zamiennym elementem sejfu - jego zawartoscia operacje
	// swap uznajemy jako operacje zmiany zawartosci dwoch sejfow czyli
	// kontrolel (liczba dostepow, manipulacje, wlamanie) pozostaje wraz
	// z sejfem
	std::string napis;
	unsigned long long liczba;
    bool wlamanie, manipulacja;
    void setLiczba( int x );
    void init( int liczba );

};

#endif
