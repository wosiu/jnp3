#include "kontroler.h"

std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler* k )
{
	if ( k->wlamanie ) {
		wyjscie << "ALARM: WLAMANIE\n";
	} else if ( k->manipulacja ) {
		wyjscie << "ALARM: ZMANIPULOWANY\n";
	} else {
		wyjscie << "OK\n";
	}

	return wyjscie;
}

std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler& k )
{
	if ( k.wlamanie ) {
		wyjscie << "ALARM: WLAMANIE\n";
	} else if ( k.manipulacja ) {
		wyjscie << "ALARM: ZMANIPULOWANY\n";
	} else {
		wyjscie << "OK\n";
	}

	return wyjscie;
}

/*void Kontroler::operator=( const Kontroler & b ) {
	std::cout << "wszedl" << std::endl;
}*/

Kontroler::Kontroler( int liczba )
{
	this->liczba = liczba;
	wlamanie = false;
	manipulacja = false;
}

Kontroler::Kontroler( const Kontroler& rhs )
{
	//std::cout << "const Kontroler& rhs" << std::endl;
	//this = rhs;
	//ACEK: jak to zrobic, zeby dzialalo auto tak jak chcemy
	//czy moze przepisac wskaźniki z pól z rhs na pola z obecnego (this)
}

Kontroler::operator bool() const
{
	return ( liczba > 0 );
}
