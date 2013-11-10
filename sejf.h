#ifndef SEJF_H
#define SEJF_H

#include<string>

class Kontroler;

class Sejf
{
public:
	class Kontroler
	{
	public:
		//std::string operator<<();
		//operator porównywania z boolem? żeby możliwe było zastosowanie go w "ifie"
	private:
		Kontroler();
	};

	Sejf(const std::string & napis, int liczba = 42);
	//Sejf(std::string && napis, int liczba = 42);

	void operator+=(int x);
	void operator-=(int x);
	void operator*=(int x);
	int16_t operator[](unsigned int x); //czy nie powinien być unsigned?

	Kontroler kontroler(){ return instancja;}

private:
	std::string napis;
	int liczba;
	bool manipulacja = false;
	bool wlamanie = false;

	void setLiczba(int x);

	Kontroler instancja;
};

#endif
