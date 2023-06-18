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


public:
    std::vector<Zamowienie> orders;
    Klient(string Imie, string Nazwisko, string Adres, Plec Plec, int ID);
    void dodaj_zamowienie(Zamowienie zamowienie);
    void edytuj_zamowienie(int i,Zamowienie zamowienie);
    void wyswietl_zamowienia();
    string get_imie();
};

#endif // KLIENT_H
