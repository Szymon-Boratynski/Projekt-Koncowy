#include "produkt.h"

Produkt::Produkt(string nazwa, unsigned int stawka,
                 unsigned int cenaNetto) :
                nazwa(nazwa),
                cenaNetto(cenaNetto), cenaBrutto(cenaNetto*stawka)

{ this->stawka = stawka; }

unsigned int Produkt::get_cenaBrutto()
{
    return cenaBrutto;
}

void wyswietl_produkt(){
    cout << "Nazwa: " << nazwa
         << ", Cena netto: " << cenaNetto
         << ", Cena brutto: " << cenaBrutto
         << ", Stawka: " << stawka << endl;
}

string get_nazwa(){
    return nazwa;
}

unsigned int get_stawka(){
    return stawka;
}
