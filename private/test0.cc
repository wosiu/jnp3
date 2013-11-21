/* Test 0 */
/* Linie oznaczone przez FIXME po odkomentowaniu powinny dawach (chyba) bledy kompilacji */
#include "../sejf.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

void pobierz(Sejf &se, const string &s, bool uda_sie = true) {
    size_t sz = s.length();
    size_t pos = rand() % sz;
    int16_t ch = se[pos];
//    cout << pos << " " << sz << " " << (int)s[pos] <<  " " << (int)ch << endl;
    if(uda_sie) {
        assert((char)ch == s[pos]);
    } else {
        assert(ch == -1);
    }
}

void testuj(Sejf &se, unsigned int ile, const string &s) {
    for(unsigned int i = 0; i < ile; i++) {
        assert(se.kontroler());
        pobierz(se, s);
    }
    assert(!se.kontroler());
    int16_t ch = se[rand() % s.length()];
    assert(ch == -1);
}


void testuj_liczbe(unsigned int ile, const string &s = "rybakot") {
    cout << "Testuje liczbe " << ile << endl;
    Sejf se(s, ile);
    testuj(se, ile, s);
}

void testy_liczb() {
    cout << "Testy liczb" << endl;
    testuj_liczbe(0);
    testuj_liczbe(1);
    testuj_liczbe(2);
    testuj_liczbe(3);
    testuj_liczbe(10);
    testuj_liczbe(100);
    testuj_liczbe(10000);
    testuj_liczbe(1000000);

//    testuj_liczbe(-1); // Ciekawe, co tutaj siÄ dzieje?
//    testuj_liczbe(-2000000022); // A tutaj?
}

void testuj_42(const string &s = "kotopies") {
    cout << "Testuje domyslne 42" << endl;
    Sejf se(s);
    testuj(se, 42, s);
}

void testuj_pusty() {
    cout << "Test pustego napisu" << endl;
    Sejf se("", 1);
    assert(se.kontroler());
    int16_t ch = se[0];
    assert(se.kontroler());
    assert(ch == -1);
    ch = se[0];
    assert(ch == -1);
    assert(se.kontroler());
    se -= 1;
    assert(!se.kontroler());
}

void testuj_operatory(const string &s = "piesokotokot") {
    cout << "Testy operatorow" << endl;
    Sejf se(s, 10); // 10
    pobierz(se, s); // 9
    se *= 3; // 27
    for(int i = 0; i < 26; i++) pobierz(se, s); // 1
    assert(se.kontroler());
    se += 6; // 7
    se -= 6; // 1
    pobierz(se, s);
    assert(!se.kontroler());
    int16_t ch = se[0];
    assert(!se.kontroler());
    assert(ch == -1);
}

void testuj_operatory_zdradliwe(const string &s = "ryboplazokon") {
    cout << "Testy \"ZDRADA\"" << endl;
    Sejf se(s, 10); // 10
    se *= -1;
    assert(se.kontroler());

    // ZakĹadam, Ĺźe wtedy nic siÄ nie dzieje (bo byĹby overflow)
    // Ale chyba to nie jest jedyne sensowne zaĹoĹźenie
    // W kaĹźdym razie jest przynajmniej jasnoĹÄ co do zmniejszania o zbyt duĹźo
    //
    /* Czy po wykonaniu operacji -= mamy zmniejszyÄ iloĹÄ dostÄpĂłw o tyle o
     * ile jest moĹźliwe pĂłki nie dojdziemy do 0 czy jeĹli dostajemy rozkaz
     * zmniejszenia o wiÄcej niĹź moĹźemy to nic nie robimy?

    PrzejdĹş do wiadomoĹci wyĹźej (âparentâ) | Odpowiedz
    Obraz Maciej Zielenkiewicz
    Odp: Zadanie 3
    Maciej Zielenkiewicz w dniu Thursday, 7 November 2013, 15:32 napisaĹ(a)


    JeĹźeli nie jest moĹźliwe zmniejszenie liczby dostÄpĂłw o ĹźÄdanÄ wartoĹÄ to nic nie robimy.
*/
    for(int i = 0; i < 10; i++) pobierz(se, s);
    assert(!se.kontroler());

    Sejf se2(s, 999);
    se2 += -1;
    for(int i = 0; i < 999; i++) pobierz(se2, s);
    assert(!se2.kontroler());

    Sejf se3(s, 11);
    se3 -= -1;
    for(int i = 0; i < 11; i++) pobierz(se3, s);
    assert(!se3.kontroler());
}

void testuj_kontroler() {
    cout << "Testy kontrolera" << endl;
    string s = "potworpieskomysz";
    Sejf se(s, 15);
    auto k = se.kontroler();
    stringstream ss;
    ss << k;
    assert(ss.str() == "OK\n");
    for(int i = 0; i < 15; i++) {
        pobierz(se, s);
        ss.str("");
        ss << k;
        assert(ss.str() == "OK\n");
    }
    se += 10;
    ss.str("");
    ss << k;
    assert(ss.str() == "ALARM: ZMANIPULOWANY\n");
    for(int i = 0; i < 10; i++) {
        pobierz(se, s);
        ss.str("");
        ss << k;
        assert(ss.str() == "ALARM: ZMANIPULOWANY\n");
    }
    pobierz(se, s, false);
    ss.str("");
    ss << k;
    se += 10;
    assert(ss.str() == "ALARM: WLAMANIE\n");
    for(int i = 0; i < 10; i++) {
        pobierz(se, s);
        ss.str("");
        ss << k;
        assert(ss.str() == "ALARM: WLAMANIE\n");
    }
    pobierz(se, s, false);
}

void testy_dzikie_z_palca() {
    cout << "Testy \"Dzikosc serca\"" << endl;
    Sejf s1("BezdroznyWedroiecDzisTuNiePrzyjdzie", 199);
    for(int i = 0; i < 1000; i++) {
        s1 -= 10;
        assert(s1.kontroler());
    }
    stringstream ss;
    ss << s1.kontroler();
    assert(ss.str() == "ALARM: ZMANIPULOWANY\n");
    Sejf s2("WodaNieUroda");
//    s1 = s2; // BLAD KOMPILACJI FIXME
    swap(s2, s1);
    assert(s1.kontroler());
    auto k1 = s1.kontroler();
    auto k2 = k1; // A tutaj co??? Chyba OK
 //   __typeof(k2) k3(s1); // Ale tu ma sie wywalic. FIXME
    s1 += 1; //43
    s1 *= 2; //86
    s1 += -86; // 86
    s1 -= 85;
    assert(s1.kontroler());
    int16_t x = s1[0];
    assert((char)x == 'W');
    x = s1[0];
    assert(x == -1);
    assert(!k2);
    s1 += 10;
    s1 *= 0;
    assert(k2);
    ss.str("");
    ss << k2;
    assert(ss.str() == "ALARM: WLAMANIE\n");
}

void testy_z_tresci() {
    cout << "Testy z tresci" << endl;
    Sejf s1("aaa", 2);
    auto k1 = s1.kontroler();
	s1[0];
	s1 *=3;
    assert(k1);
    for(int i = 0; i < 3; i++) {
        pobierz(s1, "aaa");
    }
    assert(!k1);
    pobierz(s1, "aaa", false);
    Sejf s2("bbb", 3);
    swap(s1, s2);
    assert(k1);
    for(int i = 0; i < 3; i++) {
        pobierz(s1, "bbb");
    }
    assert(!k1);
    pobierz(s1, "bbb", false);

//	Sejf s4 = s1; // BLAD KOMPILACJI FIXME
//	Sejf s5(s1); // BLAD KOMPILACJI FIXME
    {
        stringstream ss;
        Sejf s1("aaa", 2);
        s1[2];
        auto k1 = s1.kontroler();
        ss << k1 << "test\n";
        s1[2];
        s1[3];
        s1[4];
        ss << k1;
        s1[3];
        ss << k1;
        s1[2];
        ss << k1;
        assert(ss.str() ==
            "OK\ntest\nOK\nOK\nALARM: WLAMANIE\n");

    }
    {
        Sejf s1("aaa", 2);
        Sejf s2("aaa", 2);
        if (s1.kontroler()) {
            assert(true);
        }
/*        if(s1.kontroler() < s2.kontroler()) {
            assert(false); // tu ma byc blad kompilacji // FIXME
        }
        */
    }
}

void testy_z_forum() {
    cout << "Testy z forum" << endl;
    stringstream ss1, ss2;
    Sejf s1("pon");
    Sejf s2("wto");
    Sejf s3("sro");
    Sejf s4("pia");
    string okejka="OK\n", manipul="ALARM: ZMANIPULOWANY\n";
    ss1 << okejka << okejka << okejka;
    auto k1 = s1.kontroler(), k2(s2.kontroler()),  // To jest Ok
         k3 = s3.kontroler(), k4 = s4.kontroler();
    ss2 << k1 << k2 << k3;
    assert(ss1.str() == ss2.str());
    ss1.str(""), ss2.str("");
//  PrzemysĹaw Gumienny w dniu Tuesday, 5 November 2013, 20:48 napisaĹ(a)
    s1 += 0;
    s2 -= 0;
    s3 *= 1;
    s4 *= 0; // Mnozenie przez 0 nie skonczy sie sukcesem, wiec nie bedzie manipulacja

    ss1 << manipul << manipul << manipul << okejka;
    ss2 << k1 << k2 << k3 << k4;

    assert(ss1.str() == ss2.str());

// Tomasz StÄczniewski w dniu Wednesday, 6 November 2013, 15:26 napisaĹ(a)
    {
    Sejf s1("aaa", 1), s2("bbb", 0);

    auto k1 = s1.kontroler();

    swap(s1, s2);
    assert(!k1);
    }
    /*
On 2013-11-10 00:31, Maciej Szeszko wrote:
> Zamieszczam przykĹad. ProszÄ o wskazanie prawdiĹowego out'a
>*/

    {
 Sejf s1 ("aaa", 0);
 s1 += 0;
 s1[2];
 s1 += 2;
 s1[1];
 s1[3];
 stringstream ss;
 auto k1 = s1.kontroler();
 ss.str("");
 ss << k1;
    assert(ss.str() == "ALARM: WLAMANIE\n");

 ss.str("");
 ss << k1;
 assert(ss.str() == "ALARM: WLAMANIE\n");


 s1[0];
 s1 += 3;
 s1[2];
 ss.str("");
 ss << s1.kontroler();
 assert(ss.str() == "ALARM: WLAMANIE\n");

 ss.str("");
 ss << s1.kontroler();
 assert(ss.str() == "ALARM: WLAMANIE\n");
    }

        // Dawid Ĺazarczyk w dniu Sunday, 10 November 2013, 10:57 napisaĹ(a)
    {
    stringstream ss;
    Sejf a("A", 1), b("B", 1);
    b += 1;
    auto k = b.kontroler();
    a[0]; a[0];
    std::swap(a, b);
    ss << k;
    assert(ss.str() == "ALARM: WLAMANIE\n");

	int niezlapano = 1;
	try{
	    Sejf c("A", -3); // Nie powinno sie dac skonstruowac
		assert(c.kontroler());
    }
    catch (const range_error & oor) {
        niezlapano = 0;
	}
	if ( niezlapano ) {
		assert ( false );
	}

    // sejfu o ujemnej maksymalnej liczbie dostepow
    // Ponoc mozna to rozwiazywac na rozne sposoby
    // np. rzucac wyjatek. Ale jesli konstruktor przyjmuje
    // unsigned, to takie sejf zdaje sie moze sie stworzyc

    }

// Hubert Tarasiuk w dniu Saturday, 16 November 2013, 21:43 napisaĹ(a)
  {
    string str = "superokonioszcurowydra";
    Sejf s1(str, 41);
    s1 = move(s1);
    for(int i = 0; i < 10; i++)
        assert((char)s1[i] == str[i]);
  }

  {
      // Jacek KoziĹski w dniu Sunday, 17 November 2013, 00:16 napisaĹ(a)
     string s = "kot";
     Sejf s1("pies"), s2(s);
     Sejf s3 = std::move(s1);
     s1 = std::move(s2);
     for(int i = 0; i < 3; i++)
         assert(s1[i] == s[i]);

  }

// Hubert Tarasiuk w dniu Monday, 18 November 2013, 19:19 napisaĹ(a)
    {
        string str = "gadal_dziad_do_obrazu";
        Sejf s1(str, 5);
        auto k1 = s1.kontroler(); // to bylo na forum

        s1 = Sejf(move(s1));
        assert(k1);
        for(int i = 0; i < 5; i++) pobierz(s1, str);
        assert(!k1);
        pobierz(s1, str, false);

        s1 += 5;
        s1 = move(s1); // to tez mi sie kompiluje, chyba OK?
        assert(k1);
        for(int i = 0; i < 5; i++) pobierz(s1, str);
        assert(!k1);
        pobierz(s1, str, false);

    }

}

const long long ILE = 1000000LL; // Zmien na tyle, ile maksymalnie odczytow dopuszczasz

void testy_kontrowersyjne() {
  cout << "Testy kontrowersyjne" << endl;
  // Kontrowersyjne dlatego, ze zaleza od implemenatacji
  string str = "puchacz_przez_ch";

  Sejf s(str, 1);
  s *= ILE;
  s -= ILE;
  s += ILE - 1;
  s *= ILE; // To nie powinno sie udac :P
  s *= 2; // To tez nie :P
  s += 1;
  s -= ILE - 1;
  s -= ILE; // To rozwniez
  assert(s.kontroler());
  pobierz(s, str);
  assert(!s.kontroler());
  pobierz(s, str, false);


 Sejf s2(str, 10);
 s2 *= ILE;
 s2 *= -1;
 s2 += -1;
 s2 -= -1;
 s2 -= ILE;
 s2 *= 0;
 stringstream ss;
 ss << s2.kontroler();
 assert(ss.str() == "OK\n"); // Zadna z manipulacji nie zakonczyla sie "sukcesem"

 cout << "( Teraz bedzie kontrowersja, jakich malo: 0 x 0 )" << endl;
 Sejf s3(str, 0);
 s3 *= 0;
 ss.str("");
 ss << s3.kontroler();
 assert(ss.str() == "ALARM: ZMANIPULOWANY\n"); // KONTROWERSJAAAAA
}

void testy_konstruktorow() {
  cout << "Testy konstruktorow" << endl;
  Sejf s1("ein_Wurst");
  const Sejf s2("kein_Wurst");
//  s1 = s2; // FIXME Blad kompilacji
//  auto xx = s1.stan; // FIXME Blad kompilacji
//  auto s3(s2); // FIXME Blad kompilacji
//  s2 += 5; // FIXME Blad kompilacji
  auto k1 = s1.kontroler();
  auto k2(s1.kontroler());
//  if(k1 < k2) { // FIXME Blad kompilacji
//    assert(false);
//  }
//  swap(k1, k2); // FIXME Tu moze byc blad, ale nie musi
  // zalezy od tego, czy uzywamy wskaznikow, czy referencji
  auto k3 = k2;
  stringstream ss;
  ss << k3 << k1;
//  __typeof(k3) k4; // FIXME Blad kompilacji
//  __typeof(k3) k4(s1); // FIXME Blad kompilacji
}

const Sejf daj_const_sejfa() {
    Sejf s("a");
    return s;
}

Sejf daj_sejfa() {
    Sejf s("b");
    return s;
}

string daj_const_stringa() {
    string str("abc");
    return str;
}

string daj_stringa() {
    string str("abc");
    return str;
}

void testy_constow() {
    const Sejf s1("aa", 1);
//    Sejf s2 = daj_const_sejfa(); //FIXME
//    (to dziala, jesli ma sie konstruktor przenoszacy Sejf(const && Sejf)
//    ale z dyskusji na FB bylo wiecej glosow, zeby tak nie robic */
//    const Sejf s3 = daj_const_sejfa(); //FIXME
    Sejf s4 = daj_sejfa();
    const Sejf s5 = daj_sejfa();
//    Sejf s6 = s1; // FIXME
//    const Sejf s7 = s1; // FIXME
//    Sejf s8 = s2; // FIXME
//    const Sejf s9 = s2; // FIXME
    Sejf x1(daj_stringa(), 1);
    Sejf x2(daj_const_stringa(), 1);

    const Sejf y1("y1", 1);
    const Sejf y2("y2", 2);
//    swap(y1, y2);  // FIXME
    auto k1 = y1.kontroler();
    stringstream ss;
    ss << k1;
}

int main() {
    srand(1233321);
    testy_liczb();
    testuj_42();
    testuj_pusty();
    testuj_operatory();
    testuj_operatory_zdradliwe();

    testuj_kontroler();
    testy_z_tresci();
    testy_konstruktorow();

    testy_dzikie_z_palca();
    testy_z_forum();
    testy_constow();
	testy_kontrowersyjne();

    cout << "Twoj program dziala tak samo jak moj :P" << endl;
    cout << "Ciekawe, czy cos z tego wynika" << endl;
}
