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
#include "kontroler.h"

const static int LIMIT_DOSTEPOW = 1e6;
const static int ILOSC_DOMYSLNA_DOSTEPOW = 42;

class Kontroler;

class Sejf
{

friend class Kontroler;

public:
	// W przypadku próby tworzenia niepoprawnego sejfu (o ujemnej liczbie
	// dostepow) zostaje stworzony sejf o domyślnej liczbe dostępów.
	Sejf( const std::string & napis, int liczba = ILOSC_DOMYSLNA_DOSTEPOW );
	Sejf( std::string && napis, int liczba = ILOSC_DOMYSLNA_DOSTEPOW );
	void operator=( Sejf && rhs );
	friend std::ostream & operator<<( std::ostream & wyjscie,
									const Kontroler & k );
	Sejf(Sejf && rhs);

	void operator+=( int x );
	void operator-=( int x );
	void operator*=( int x );
	int16_t operator[]( int x );

	const Kontroler kontroler() const;

private:
	// napis jest jedynym zamiennym elementem sejfu - jego zawartoscia operacje
	// swap uznajemy jako operacje zmiany zawartosci dwoch sejfow czyli
	// kontrolel (liczba dostepow, manipulacje, wlamanie) pozostaje wraz
	// z sejfem
	std::string napis;
	void setLiczba( int x );
	int liczba;
    bool wlamanie, manipulacja;

};

#endif
