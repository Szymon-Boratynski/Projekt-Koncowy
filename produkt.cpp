#include "produkt.h"

Produkt::Produkt(string nazwa, unsigned int stawka,
                 unsigned int cenaNetto) :
                nazwa(nazwa), stawka(stawka),
                cenaNetto(cenaNetto), cenaBrutto(cenaNetto*stawka)

{ }

unsigned int Produkt::get_cenaBrutto()
{
    return cenaBrutto;
}

void Produkt::wyswietl_produkt(){
    cout << "Nazwa: " << nazwa
         << ", Cena netto: " << cenaNetto
         << ", Cena brutto: " << cenaBrutto
         << ", Stawka: " << stawka << endl;
}

const string Produkt::get_nazwa() const{
    return nazwa;
}

unsigned int Produkt::get_stawka() const{
    return stawka;
}
