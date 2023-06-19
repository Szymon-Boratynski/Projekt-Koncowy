#include "klient.h"

Klient::Klient(string imie, string nazwisko,
               string adres, Plec plec, unsigned int id) :
               imie(imie), nazwisko(nazwisko), adres(adres),
               plec(plec), id(id)
{ }

void Klient::dodaj_zamowienie(Zamowienie zamowienie){
    zamowienia.push_back(zamowienie);
}

void Klient::edytuj_zamowienie(int i,Zamowienie zamowienie){
    if(i>=0 && i<zamowienia.size())
        zamowienia[i] = zamowienie;
}

void Klient::wyswietl_zamowienia(){
    for(int i=0;i<zamowienia.size();i++)
        zamowienia[i].wyswietl_zamowienie();
}

void Klient::wyswietl_klienta()
{
    cout << "Imie: " << imie
         << ", Nazwisko: " << nazwisko
         << ", Adres: " << adres
         << ", Plec: " << plec
         << ", ID: " << id << endl;
}

const string Klient::get_imie() const{
    return imie;
}

void Klient::set_imie(string noweImie)
{
    imie = noweImie;
}

void Klient::set_nazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Klient::set_adres(string nowyAdres)
{
    adres = nowyAdres;
}

void Klient::set_plec(Plec nowaPlec)
{
    plec = nowaPlec;
}
