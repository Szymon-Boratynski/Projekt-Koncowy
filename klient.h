#ifndef KLIENT_H
#define KLIENT_H
#include <string>
#include <vector>
#include "zamowienie.h"

using namespace std;

enum Plec {M,K};

class Klient
{
private:
    string imie;
    string nazwisko;
    string adres;
    Plec plec;
    unsigned int id;
    std::vector<Zamowienie> zamowienia;

public:

    Klient(string imie, string nazwisko, string adres, Plec plec, unsigned int id);
    void dodaj_zamowienie(Zamowienie zamowienie);
    void edytuj_zamowienie(int i,Zamowienie zamowienie);
    void wyswietl_zamowienia();
    void wyswietl_klienta();
    const string get_imie() const;
    void set_imie(string noweImie);
    void set_nazwisko(string noweNazwisko);
    void set_adres(string nowyAdres);
    void set_plec(Plec nowaPlec);
};

#endif // KLIENT_H
