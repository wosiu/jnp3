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
	friend std::ostream & operator<< ( std::ostream &wyjscie, const Kontroler* k );

private:
	Kontroler();
	bool wlamanie, manipulacja;
};

#endif
