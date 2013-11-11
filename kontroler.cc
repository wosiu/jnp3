#include "kontroler.h"

std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler &k )
{
	if ( k.wlamanie ) {
		wyjscie << "ALARM: WLAMANIE\n";
	} else if ( k.manipulacja ) {
		wyjscie << "ALARM: ZMANIPULOWANY\n";
	} else {
		wyjscie << "OK\n";
	}

	return  wyjscie;
}

Kontroler::Kontroler()
{
	wlamanie = false;
	manipulacja = false;
}

