#include "kontroler.h"

std::ostream & operator<<( std::ostream &wyjscie, const Kontroler& k )
{
	if ( k.sejf->wlamanie ) {
		wyjscie << "ALARM: WLAMANIE\n";
	} else if ( k.sejf->manipulacja ) {
		wyjscie << "ALARM: ZMANIPULOWANY\n";
	} else {
		wyjscie << "OK\n";
	}

	return wyjscie;
}

Kontroler::Kontroler( Sejf *sejf )
{
	this->sejf = sejf;
}

Kontroler::operator bool() const
{
	return ( sejf->liczba > 0 );
}
