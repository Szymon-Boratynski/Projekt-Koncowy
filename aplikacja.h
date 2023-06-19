#ifndef APLIKACJA_H
#define APLIKACJA_H
#include <vector>
#include "klient.h"
#include "produkt.h"

class Aplikacja
{
private:
    vector<Klient> klienci;
    vector<Produkt> produkty;

    void zapiszKlientowdDoTekstu(string nazwaPliku) const;
    void zapiszKlientowDoBinarnego(string nazwaPliku) const;
    void zapiszZamowieniaDoTekstu(string nazwaPliku) const;
    void zapiszZamowieniaDoBinarnego(string nazwaPliku) const;
    void wczytajProdukty(string nazwaPliku) const;

public:
    void sklep();
};

#endif // APLIKACJA_H
