#include "produkt.h"

Produkt::Produkt(string nazwa, int stawka,
                 int cenaNetto) :
                nazwa(nazwa), stawka(stawka),
                cenaNetto(cenaNetto), cenaBrutto(cenaNetto*stawka)

{ }

int Produkt::get_cenaBrutto()
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

int Produkt::get_stawka() const{
    return stawka;
}
