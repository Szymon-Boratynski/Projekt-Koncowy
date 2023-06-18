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
    unsigned int ilosc;
    string data;
    unsigned int wartosc;
    string sposob_platnosci;

public:
    Zamowienie(Produkt Produkt, unsigned int ilosc,
               string data, string sposob_platnosci);
};

#endif // ZAMOWIENIE_H
