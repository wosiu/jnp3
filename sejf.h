#ifndef SEJF_H
#define SEJF_H

class Sejf
{
public:
	Sejf(const string & napis, int liczba = 42);
	Sejf(string && napis, int liczba = 42);

	void operator+=(int x);
	void operator-=(int x);
	void operator*=(int x);
	int operator[](int x); //czy nie powinien być unsigned?

	Kontroler kontroler();

private:
	string _napis;
	int _liczba;

	class Kontroler
	{
	public:
		string operator<<();


	};

};

#endif
