#include "aplikacja.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void Aplikacja::zapiszKlientowdDoTekstu(string nazwaPliku) const
{
    ofstream plik(nazwaPliku);
    if(plik.is_open()){
        for(int i=0;i<klienci.size();i++){
            plik << klienci[i].get_imie() << ","
                 << klienci[i].get_nazwisko() << ","
                 << klienci[i].get_adres() << ","
                 << klienci[i].get_plec() << endl;
        }
        plik.close();
        cout << "Klient zapisany do: " << nazwaPliku << endl;
    }
    else
        cout << "cos nie tak z plikiem" << endl;
}

void Aplikacja::zapiszKlientowDoBinarnego(string nazwaPliku) const
{
    ofstream plik(nazwaPliku, ios_base::out|ios_base::binary);
    if(plik.is_open()){
        for(int i=0;i<klienci.size();i++){
            int imieDlugosc = klienci[i].get_imie().length();
            int nazwiskoDlugosc = klienci[i].get_nazwisko().length();
            int adresDlugosc = klienci[i].get_adres().length();
            string p = klienci[i].get_plec();
            size_t plecDlugosc = strlen(klienci[i].get_plec());

            plik.write(reinterpret_cast<const char*>(&imieDlugosc), sizeof(int));
            plik.write(klienci[i].get_imie().c_str(), imieDlugosc);

            plik.write(reinterpret_cast<const char*>(&nazwiskoDlugosc), sizeof(int));
            plik.write(klienci[i].get_nazwisko().c_str(), nazwiskoDlugosc);

            plik.write(reinterpret_cast<const char*>(&adresDlugosc), sizeof(int));
            plik.write(klienci[i].get_adres().c_str(), adresDlugosc);

            plik.write((char*)&plecDlugosc, sizeof(plecDlugosc));
            plik.write(klienci[i].get_plec(), plecDlugosc);
        }
        plik.close();
        cout << "Klient zapisany do: " << nazwaPliku << endl;
    }
    else
        cout << "cos nie tak z plikiem" << endl;
}

void Aplikacja::zapiszZamowieniaDoTekstu(string nazwaPliku) const
{
    ofstream plik(nazwaPliku);
    int ilosc_zamowien = 0;
    if(plik.is_open()){
        for(int i=0;i<klienci.size();i++){
            for(int j=0;j<klienci[i].get_ilosc_zamowien();i++)
                plik << klienci[i].get_imie() << ","
                     << klienci[i].get_produkt_nazwa(j) << ","
                     << klienci[i].get_ilosc(j) << ","
                     << klienci[i].get_wartosc(j) << ","
                     << klienci[i].get_data(j) << ","
                     << klienci[i].get_sposob(j) << endl;
        }
        plik.close();
        cout << "Zamownienia zapisane do: " << nazwaPliku << endl;
    }
    else
        cout << "cos nie tak z plikiem" << endl;
}

void Aplikacja::zapiszZamowieniaDoBinarnego(string nazwaPliku) const
{
    ofstream plik(nazwaPliku);
    if(plik.is_open()){
        for(int i=0;i<klienci.size();i++){
            for(int j=0;j<klienci[i].get_ilosc_zamowien();i++){
                int imieDlugosc = klienci[i].get_imie().length();
                int nazwaDlugosc = klienci[i].get_produkt_nazwa(j).length();
                int dataDlugosc = klienci[i].get_data(j).length();
                int sposobDlugosc = klienci[i].get_sposob(j).length();

                plik.write(reinterpret_cast<const char*>(&imieDlugosc),sizeof(int));
                plik.write(klienci[i].get_imie().c_str(), imieDlugosc);

                plik.write(reinterpret_cast<const char*>(&nazwaDlugosc),sizeof(int));
                plik.write(klienci[i].get_produkt_nazwa(j).c_str(), nazwaDlugosc);

                plik.write(reinterpret_cast<const char*>(&dataDlugosc),sizeof(int));
                plik.write(klienci[i].get_data(j).c_str(), dataDlugosc);

                plik.write(reinterpret_cast<const char*>(&sposobDlugosc),sizeof(int));
                plik.write(klienci[i].get_sposob(j).c_str(), sposobDlugosc);

                plik.write(reinterpret_cast<const char*>(&klienci[i].get_ilosc(j)),sizeof(int));
                plik.write(reinterpret_cast<const char*>(&klienci[i].get_wartosc(j)),sizeof(int));
            }
            plik.close();
            cout << "Plik zapisany do: " << nazwaPliku << endl;
        }
        else
            cout << "cos nie tak z plikiem" << endl;
    }
}

void Aplikacja::wczytajProdukty(string nazwaPliku) const
{
    ifstream plik(nazwaPliku);
    if(plik.is_open()){
        string linia;
        while(getline(plik,linia)){
            istringstream iss(linia);
            string nazwa;
            int cenaNetto, stawka;
            if(iss >> nazwa >> cenaNetto >> stawka){
                Produkt prod(nazwa,stawka,cenaNetto);
                produkty.push_back(prod);
            }
        }
        plik.close();
        cout << "Produkty wczytane z: " << nazwaPliku << endl;
    }
    else
        cout << "cos nie tak z plikiem" << endl;
}

void Aplikacja::sklep()
{
    wczytajProdukty("produkty.txt");

    vector<Produkt> produkty;
    vector<Klient> klienci;

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
            int w;
            cout << "tekst(1) czy plik(0): ";
            cin >> w;
            if(w == 1)
                zapiszKlientowdDoTekstu("klienci.txt");
            else
                zapiszKlientowDoBinarnego("klienci.bin");
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
            int ilosc;
            int wybor, ktoreZam;
            cout << "Podaj imie klienta: ";
            cin >> klientImie;
            auto k = find_if(klienci.begin(),klienci.end(),[&klientImie](const Klient& klient){
                    return klient.get_imie() == klientImie;
            });
            if(k != klienci.end()){
                cout << "ktore zamowienie: ";
                cin >> ktoreZam;
                cout << "Podaj nazwe produktu: ";
                cin >> produktNazwa;
                cout << "Podaj date: ";
                cin >> data;
                cout << "Podaj ilosc: ";
                cin >> ilosc;
                cout << "Podaj sposob platnosci: ";
                cin >> sposob;
                auto prod = find_if(produkty.begin(),produkty.end(),[&produktNazwa](const Produkt& produkt){
                    return produkty.get_nazwa(); == produktNazwa;
                });
                Zamowienie zam(prod,ilosc,data,sposob);
                k->edytuj_zamowienie(ktoreZam,zam);
                }
            else
                cout << "Nie znaleziono klienta" << endl;
        }
            break;
        case 7:
            for(int i=0;i<klienci.size();i++){
                klienci[i].wyswietl_zamowienia();
            }
            break;
        case 8:
            int wy;
            cout << "tekst(1) czy plik(0): ";
            cin >> wy;
            if(wy == 1)
                zapiszZamowieniaDoTekstu("zamowienia.txt");
            else
                zapiszZamowieniaDoBinarnego("zamowienia.bin");
            break;
        case 9:
            for(int i=0;i<produkty.size();i++){
                produkty[i].wyswietl_produkt();
            }
            break;
        case 10:
            break;
        default:
            cout << "zly wybor" << endl;
        }
    }
}
