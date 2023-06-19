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
    int id;
    std::vector<Zamowienie> zamowienia;

public:

    Klient(string imie, string nazwisko, string adres, Plec plec, int id);
    void dodaj_zamowienie(Zamowienie zamowienie);
    void edytuj_zamowienie(int i,Zamowienie zamowienie);
    void wyswietl_zamowienia();
    void wyswietl_klienta();
    string get_imie() const;
    string get_nazwisko() const;
    string get_adres() const;
    char get_plec() const;
    int get_ilosc_zamowien() const;
    string get_produkt_nazwa(int i) const;
    int get_ilosc(int i) const;
    string get_data(int i) const;
    int get_wartosc(int i) const;
    string get_sposob(int i) const;
    void set_imie(string noweImie);
    void set_nazwisko(string noweNazwisko);
    void set_adres(string nowyAdres);
    void set_plec(Plec nowaPlec);
};

#endif // KLIENT_H
