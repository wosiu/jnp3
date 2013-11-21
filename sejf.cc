#include "sejf.h"

using namespace std;


Sejf::Sejf( const std::string & napis, int liczba ) : napis( napis ) ,
										wlamanie( false ), manipulacja( false )
{
	init( liczba );
}

Sejf::Sejf( std::string && napis, int liczba ) : napis( move( napis ) ),
										wlamanie( false ), manipulacja( false )
{
	init( liczba );
}

void Sejf::init( int liczba )
{
	if ( liczba < 0 || (unsigned long long)liczba > LIMIT_DOSTEPOW ){
		throw range_error ("Niepoprawna liczba dostepow\n");
	}
	this->liczba = liczba;
}

Sejf::Sejf( Sejf && rhs ) : napis ( move( rhs.napis ) ), liczba( rhs.liczba ),
					wlamanie( rhs.wlamanie ), manipulacja( rhs.manipulacja )
{
}

void Sejf::operator=( Sejf && rhs )
{
	this->napis = move( rhs.napis );
	this->liczba = rhs.liczba;
    this->wlamanie = rhs.wlamanie;
    this->manipulacja = rhs.manipulacja;
}

void Sejf::setLiczba( int x )
{
	manipulacja = true;
	liczba = x;
}

int16_t Sejf::operator[]( int x )
{
	if ( x < 0 || (unsigned int)x >= napis.size() )
		return -1;

	if ( liczba == 0 ){
		wlamanie = true;
		return -1;
	}

	--liczba;
	return napis[x];
}

/*
 * W przypadku próby zmiany liczby pozostałej liczby dostępu ponad limit
 * (+=, *=), nie podejmowane są żadne działania, w szczególności,
 * nie zostaje to uznane za próbę manipulacji.
 */
void Sejf::operator+=( int x )
{
	if ( x < 0 || liczba + x > LIMIT_DOSTEPOW ) return;

	setLiczba( liczba + x );
}

void Sejf::operator*=( int x )
{
	if ( x <= 0 && liczba > 0 ) return;
	if ( liczba * x > LIMIT_DOSTEPOW ) return;

	setLiczba( liczba * x );
}

void Sejf::operator-=( int x )
{
	if ( x < 0 || (unsigned long long)x > liczba ) return;

	setLiczba( liczba - x );
}

const Kontroler Sejf::kontroler() const
{
	return Kontroler( this );
}
