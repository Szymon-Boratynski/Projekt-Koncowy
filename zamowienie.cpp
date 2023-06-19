#include "zamowienie.h"

Zamowienie::Zamowienie(Produkt produkt, int ilosc,
                       string data, string sposob_platnosci) :
                       produkt(produkt), ilosc(ilosc), data(data),
                       sposob_platnosci(sposob_platnosci)
{ wartosc = ilosc * produkt.get_cenaBrutto() * produkt.get_stawka(); }

void Zamowienie::wyswietl_zamowienie() const{
    cout << "Produkt: " << produkt.get_nazwa()
         << ", Ilosc: " << ilosc
         << ", Stawka VAT: " << produkt.get_stawka()
         << ", Wartosc: " << wartosc
         << ", Data: " << data
         << ", Metoda platnosci: " << sposob_platnosci << endl;
}

string Zamowienie::get_produktNazwa() const
{
    return produkt.get_nazwa();
}

int Zamowienie::get_ilosc() const
{
    return ilosc;
}

string Zamowienie::get_data() const
{
    return data;
}

int Zamowienie::get_wartosc() const
{
    return wartosc;
}

string Zamowienie::get_sposob() const{
    return sposob_platnosci;
}
