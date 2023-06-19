#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "klient.h"
#include "zamowienie.h"
using namespace std;

int main()
{
    vector<Produkt> produkty;
    vector<Klient> klienci;
    //wczytanie produktow z pliku tekstowego i pushback na vector

    int wybor = 0;
    while(wybor!=10){
        cout << "1) dodaj klienta" << endl
             << "2) edytuj klienta" << endl
             << "3) zapisz klientow" << endl
             << "4) wyswietl liste klientow" << endl
             << "5) dodaj zamowienie do klienta" << endl
             << "6) edytuj zamowienie" << endl
             << "7) wyswietl liste zamowien" << endl
             << "8) zapisz liste zamowien" << endl
             << "9) wyswietl produkty" << endl
             << "10) wyjscie z programu" << endl << endl;
        cout << "wybor: ";
        cin >> wybor;
        switch(wybor){
        case 1:{
            string imie;
            string nazwisko;
            string adres;
            char plec;
            int id;
            cout << "Imie: ";
            cin >> imie;
            cout << "Nazwisko: ";
            cin >> nazwisko;
            cout << "Adres: ";
            cin >> adres;
            cout << "Plec: ";
            cin >> plec;
            while(plec != 'M' && plec != 'K'){
                if(plec != 'M' && plec != 'K')
                    cout << "zla plec" << endl;
                cout << "Plec: ";
                cin >> plec;
            }
            Plec p = static_cast<Plec>(plec);
            cout << "Numer ID: ";
            cin >> id;
            Klient klient(imie,nazwisko,adres,p,id);
            klienci.push_back(klient);
            break;}
        case 2:{
            cout << "jakiego klienta chcialbys edytowac: ";
            string imie;
            cin >> imie;
            auto k = find_if(klienci.begin(),klienci.end(),[imie](Klient klient){
                    return klient.get_imie() == imie;
            });
            if(k != klienci.end()){
                string noweImie, noweNazwisko, nowyAdres;
                char nowaPlec;
                cout << "Podaj nowe imie: ";
                cin >> noweImie;
                cout << "Podaj nowe nazwisko: ";
                cin >> noweNazwisko;
                cout << "Podaj nowy adres: ";
                cin >> nowyAdres;
                cout << "Podaj nowa plec: ";
                cin >> nowaPlec;
                k->set_imie(noweImie);
                k->set_nazwisko(noweNazwisko);
                k->set_adres(nowyAdres);
                while(nowaPlec != 'M' && nowaPlec != 'K'){
                    if(nowaPlec != 'M' && nowaPlec != 'K')
                        cout << "zla plec" << endl;
                    cout << "Plec: ";
                    cin >> nowaPlec;
                }
                Plec p = static_cast<Plec>(nowaPlec);
                k->set_plec(p);
            }
            else
                cout << "Nie znaleziono klienta" << endl;
        }
            break;
        case 3:
            //zapis klientow
            break;
        case 4:
            for(int i=0;i<klienci.size();i++)
                klienci[i].wyswietl_klienta();
            break;
        case 5:{
            string klientImie, produktNazwa, data, sposob;
            unsigned int ilosc;
            cout << "Podaj imie klienta: ";
            cin >> klientImie;
            cout << "Podaj nazwe produktu: ";
            cin >> produktNazwa;
            cout << "Podaj ilosc: ";
            cin >> ilosc;
            cout << "Podaj date: ";
            cin >> data;
            cout << "Podaj sposob zaplaty";
            cin >> sposob;
            auto prod = find_if(produkty.begin(),produkty.end(),[&produktNazwa](const Produkt& produkt){
                    return produkt.get_nazwa() == produktNazwa;
            });
            auto k = find_if(klienci.begin(),klienci.end(),[&klientImie](const Klient& klient){
                    return klient.get_imie() == klientImie;
            }); 
            if(prod != produkty.end()){
                if(k != klienci.end()){
                    Zamowienie zam(prod,ilosc,data,sposob);
                    k->dodaj_zamowienie(zam);
                }
                else
                    cout << "Nie znaleziono klienta" << endl;
            }
            else
                cout << "Nie znaleziono produktu" << endl;
        }
            break;
        case 6:{
            string klientImie, produktNazwa, data, sposob;
            unsigned int ilosc;
            unsigned short int wybor, ktoreZam;
            cout << "Podaj imie klienta: ";
            cin >> klientImie;
            auto k = find_if(klienci.begin(),klienci.end(),[&klientImie](const Klient& klient){
                    return klient.get_imie() == klientImie;
            });
            if(k != klienci.end()){
                cout << "" ;
                }
            else
                cout << "Nie znaleziono klienta" << endl;
        }
            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:
            break;
        default:
            cout << "zly wybor" << endl;
        }
    }
    return 0;
}
