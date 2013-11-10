#include <iostream>
#include "sejf.h"


using namespace std;

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


int main(){
	//Sejf s1("asdf");
	//auto k1 = s1.kontroler();


	return 0;
}
