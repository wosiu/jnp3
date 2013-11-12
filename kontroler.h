#ifndef KONTROLER_H
#define KONTROLER_H

#include <iostream>
#include <string>
#include "sejf.h"

class Sejf;

class Kontroler
{
friend class Sejf;

public:
	friend std::ostream & operator<<( std::ostream &wyjscie,
									const Kontroler& k );
	// explicit jest po to, zeby nie mozna bylo przypisywac do boola => porownywac z innym boolem
	explicit operator bool() const;

private:
    Sejf* sejf;
	Kontroler( Sejf* sejf );
};

#endif
