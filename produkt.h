#ifndef PRODUKT_H
#define PRODUKT_H
#include <string>
#include <iostream>
using namespace std;

class Produkt
{
private:
    string nazwa;
    int stawka;
    int cenaNetto;
    int cenaBrutto;

public:
    Produkt(string nazwa, int stawka,
            int cenaNetto);
    int get_cenaBrutto();
    void wyswietl_produkt();
    const string get_nazwa() const;
    int get_stawka() const;
};

#endif // PRODUKT_H
