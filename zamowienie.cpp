#include "zamowienie.h"

Zamowienie::Zamowienie(Produkt produkt, unsigned int ilosc,
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
