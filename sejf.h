#ifndef SEJF_H
#define SEJF_H

#include<string>

class Sejf
{
public:
	Sejf(const std::string & napis, int liczba = 42);
	//Sejf(std::string && napis, int liczba = 42);

	void operator+=(int x);
	void operator-=(int x);
	void operator*=(int x);
	int16_t operator[](unsigned int x); //czy nie powinien być unsigned?

private:
	std::string napis;
	int liczba;
	bool manipulacja = false;
	bool wlamanie = false;

	void setLiczba(int x);
};

#endif
