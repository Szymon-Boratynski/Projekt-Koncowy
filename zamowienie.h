#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H
#include <string>
#include <iostream>
#include "produkt.h"
using namespace std;

class Zamowienie
{
private:
    Produkt produkt;
    int ilosc;
    string data;
    int wartosc;
    string sposob_platnosci;

public:
    Zamowienie(Produkt produkt, int ilosc,
               string data, string sposob_platnosci);
    void wyswietl_zamowienie() const;
    string get_produktNazwa() const;
    int get_ilosc() const;
    string get_data() const;
    int get_wartosc() const;
    string get_sposob() const;
};

#endif // ZAMOWIENIE_H
