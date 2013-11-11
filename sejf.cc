#include "sejf.h"

using namespace std;

Sejf::Sejf( const std::string & napis, int liczba )
{
	if ( liczba < 0 || liczba > LIMIT_DOSTEPOW ) liczba = ILOSC_DOMYSLNA_DOSTEPOW;

	this->napis = napis;
	this->liczba = liczba;
	this->kontroler_instancja = new Kontroler();
}

Sejf::Sejf( std::string&& napis, int liczba )
{
	if ( liczba < 0 || liczba > LIMIT_DOSTEPOW ) liczba = ILOSC_DOMYSLNA_DOSTEPOW;

///Trzeba sprawdzić, czy jest ok rvalue (pewnie nie)
	this->napis = napis;
	this->liczba = liczba;
	this->kontroler_instancja = new Kontroler();
}

Sejf::~Sejf()
{
	delete kontroler_instancja;
}

void Sejf::setLiczba( int x )
{
	kontroler_instancja->manipulacja = true;
	liczba = x;
}

int16_t Sejf::operator[]( unsigned int x )
{
	if ( x < 0 || x >= napis.size() )
		return -1;

	if ( liczba == 0 ){
		kontroler_instancja->wlamanie = true;
		return -1;
	}

	--liczba;
	return napis[x];
}

/*
 * W przypadku próby zmiany liczby pozostałej liczby dostępu ponad limit (+=, *=),
 * nie podejmowane są żadne działania,
 * w szczególności, nie zostaje to uznane za próbę manipulacji.
 */
void Sejf::operator+=( int x )
{
	if (x < 0 || liczba + x > LIMIT_DOSTEPOW) return;

	setLiczba( liczba + x );
}

void Sejf::operator*=( int x )
{
	if ( x <= 0 || liczba * x > LIMIT_DOSTEPOW) return;

	setLiczba( liczba * x );
}

void Sejf::operator-=( int x )
{
	if ( x < 0 || x > liczba ) return;

	setLiczba(liczba - x);
}

const Kontroler* Sejf::kontroler()
{
	return kontroler_instancja;
}
