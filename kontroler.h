#ifndef KONTROLER_H
#define KONTROLER_H

#include <iostream>
#include <string>
#include "sejf.h"

class Sejf;

class Kontroler
{
	friend Sejf;
	public:
		//std::string operator<<();
		//operator porównywania z boolem? żeby możliwe było zastosowanie go w "ifie"11
		//friend std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler &k );

	private:
		Kontroler();
		bool wlamanie, manipulacja;
};

/*std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler &k )
{
	if ( k.wlamanie ) {
		wyjscie << "ALARM: WLAMANIE\n";
	} else if ( k.manipulacja ) {
		wyjscie << "ALARM: ZMANIPULOWANY\n";
	}

	return  wyjscie;
}*/

#endif
