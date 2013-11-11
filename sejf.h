#ifndef SEJF_H
#define SEJF_H

#include <string>
#include "kontroler.h"

const static int LIMIT_DOSTEPOW = 1e6;
const static int ILOSC_DOMYSLNA_DOSTEPOW = 42;

class Kontroler;

class Sejf
{
public:
	//W przypadku próby tworzenia niepoprawnego sejfu zostaje stworzony sejf o domyślnej liczbe dostępów.
	Sejf( const std::string & napis, int liczba = ILOSC_DOMYSLNA_DOSTEPOW );
	Sejf( std::string && napis, int liczba = ILOSC_DOMYSLNA_DOSTEPOW );
	void operator=(Sejf && rhs);
	Sejf(Sejf && rhs);
	~Sejf();

	void operator+=( int x );
	void operator-=( int x );
	void operator*=( int x );
	int16_t operator[]( unsigned int x );
	const Kontroler & kontroler();

private:
	std::string napis;
	Kontroler* kontroler_instancja;
	void setLiczba( int x );
};

#endif
