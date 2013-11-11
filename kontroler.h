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
	Kontroler( const Kontroler& rhs );
	//operator porównywania z boolem? żeby możliwe było zastosowanie go w "ifie"11
	friend std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler& k );
	friend std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler* k );
	//void operator=(const Kontroler &b);
	// explicit jest po to, zeby nie mozna bylo przypisywac do boola => porownywac z innym boolem
	explicit operator bool() const;

private:
	Kontroler( int liczba );
	// ilosc dostepow, ktore pozostaly
	int liczba;
	bool wlamanie, manipulacja;
	unsigned long long chuj[1000];
};

#endif
