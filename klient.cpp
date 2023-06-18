#include "klient.h"

Klient::Klient(string Imie, string Nazwisko, string Adres, Plec Plec, int ID)
{
    imie = Imie;
    nazwisko = Nazwisko;
    adres = Adres;
    plec = Plec;
    id = ID;
}

void dodaj_klienta(Zamowienie zamowienie){
    orders.push_back(zamowienie);
}

void edytuj_zamowienie(int i,Zamowienie zamowienie){
    if(i>=0 && i<zamowienia.size())
        zamowienia[i] = zamowienia;
}

string wyswietl_zamowienia(){
    for(Zamowienie zamowienie : zamowienia)
        zamowienia.display();
}
