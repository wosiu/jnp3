#ifndef SEJF_H
#define SEJF_H

#include <string>
#include "kontroler.h"

class Kontroler;

class Sejf
{
	public:
		Sejf(const std::string & napis, int liczba = 42);
		//Sejf(std::string && napis, int liczba = 42);
		~Sejf();

		void operator+=(int x);
		void operator-=(int x);
		void operator*=(int x);
		int16_t operator[](unsigned int x); //czy nie powinien być unsigned?
		Kontroler& kontroler();

	private:
		std::string napis;
		int liczba;
		Kontroler* kontroler_instancja;
		void setLiczba(int x);
};

#endif
