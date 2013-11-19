#include "sejf.h"

using namespace std;


Sejf::Sejf( const std::string & napis, int liczba ) : napis( napis ) ,
										wlamanie( false ), manipulacja( false )
{
	if ( liczba < 0 || liczba > LIMIT_DOSTEPOW ){
		liczba = ILOSC_DOMYSLNA_DOSTEPOW;
	}
	this->liczba = liczba;
}

Sejf::Sejf( std::string && napis, int liczba ) : napis( move( napis ) ),
										wlamanie( false ), manipulacja( false )
{
	if ( liczba < 0 || liczba > LIMIT_DOSTEPOW ){
		liczba = ILOSC_DOMYSLNA_DOSTEPOW;
	}
	this->liczba = liczba;
}

void Sejf::operator=( Sejf && rhs )
{
	this->napis = move( rhs.napis );
	this->liczba = rhs.liczba;
    this->wlamanie = rhs.wlamanie;
    this->manipulacja = rhs.manipulacja;
}

Sejf::Sejf( Sejf && rhs ) : napis ( move( rhs.napis ) ), liczba( rhs.liczba ),
					wlamanie( rhs.wlamanie ), manipulacja( rhs.manipulacja )
{
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
	if ( x <= 0 || liczba * x > LIMIT_DOSTEPOW ) return;

	setLiczba( liczba * x );
}

void Sejf::operator-=( int x )
{
	if ( x < 0 || x > liczba ) return;

	setLiczba( liczba - x );
}

Kontroler Sejf::kontroler()
{
	return Kontroler( this );
}
