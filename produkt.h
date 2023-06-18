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
    Produkt(string Nazwa, unsigned int Stawka,
            unsigned int CenaNetto);
    unsigned int get_cenaBrutto();
    void wyswietl_produkt();
    string get_nazwa();
};

#endif // PRODUKT_H
