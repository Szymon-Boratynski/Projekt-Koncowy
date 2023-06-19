#include "klient.h"

Klient::Klient(string imie, string nazwisko,
               string adres, Plec plec, int id) :
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

string Klient::get_imie() const{
    return imie;
}

string Klient::get_nazwisko() const{
    return nazwisko;
}

string Klient::get_adres() const{
    return adres;
}

char Klient::get_plec() const{
    char p = static_cast<char>(plec);
    return p;
}

int Klient::get_ilosc_zamowien() const
{
    return zamowienia.size();
}

string Klient::get_produkt_nazwa(int i) const
{
    return zamowienia[i].get_produktNazwa();
}

int Klient::get_ilosc(int i) const
{
    return zamowienia[i].get_ilosc();
}

string Klient::get_data(int i) const
{
    return zamowienia[i].get_data();
}

int Klient::get_wartosc(int i) const
{
    return zamowienia[i].get_wartosc();
}

string Klient::get_sposob(int i) const
{
    return zamowienia[i].get_sposob();
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
