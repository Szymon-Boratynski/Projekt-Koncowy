#ifndef PRODUKT_H
#define PRODUKT_H
#include <string>
#include <iostream>
using namespace std;

class Produkt
{
private:
    string nazwa;
    unsigned int stawka;
    unsigned int cenaNetto;
    unsigned int cenaBrutto;

public:
    Produkt(string nazwa, unsigned int stawka,
            unsigned int cenaNetto);
    unsigned int get_cenaBrutto();
    void wyswietl_produkt();
    const string get_nazwa() const;
    unsigned int get_stawka() const;
};

#endif // PRODUKT_H
