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
	//operator porównywania z boolem? żeby możliwe było zastosowanie go w "ifie"11
	friend std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler& k );
	friend std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler* k );
	explicit operator bool() const;

private:
	Kontroler( int liczba );
	int liczba;
	bool wlamanie, manipulacja;
};

#endif
