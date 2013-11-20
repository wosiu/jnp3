#include "kontroler.h"

std::ostream & operator<<( std::ostream & wyjscie, const Kontroler & k )
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

Kontroler::Kontroler( const Sejf *sejf ) : sejf( sejf )
{
}

Kontroler::operator bool() const
{
	return ( sejf->liczba > 0 );
}
