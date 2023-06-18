#include "zamowienie.h"

Zamowienie::Zamowienie(Produkt produkt, unsigned int ilosc,
                       string data, string sposob_platnosci) :
                       produkt(produkt), ilosc(ilosc), data(data),
                       sposob_platnosci(sposob_platnosci)
{ }

void wyswietl_zamowienie(){
    cout << "Produkt: " << produkt.get_nazwa()
         << ", Ilosc: " << ilosc
         << ", Stawka VAT: " << stawka
         << ", Wartosc: " << wartosc
         << ", Data: " << data
         << "Metoda platnosci: " << metoda_platnosci << endl;
}
