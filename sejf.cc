#include "sejf.h"

using namespace std;

Sejf::Sejf( const std::string & napis, int liczba )
{
	this->napis = napis;
	this->liczba = liczba;
	this->kontroler_instancja = new Kontroler();
}

Sejf::~Sejf()
{
	delete kontroler_instancja;
}

void Sejf::setLiczba(int x)
{
	kontroler_instancja->manipulacja = true;
	liczba = x;
}

int16_t Sejf::operator[]( unsigned int x )
{
	if ( x < 0 || x >= napis.size() )
		return -1;

	if ( liczba <= 0 ){
		kontroler_instancja->wlamanie = true;
		return -1;
	}

	--liczba;
	return napis[x];

}

void Sejf::operator+=( int x )
{
	if (x < 0) return;

	setLiczba( liczba + x );
	return;
}

void Sejf::operator-=( int x )
{
	if ( x < 0 || x > liczba ) return;

	setLiczba(liczba - x);
	return;
}

void Sejf::operator*=( int x )
{
	if ( x <= 0 ) return;

	setLiczba( liczba * x );
	return;
}

const Kontroler* Sejf::kontroler()
{
	return kontroler_instancja;
}
