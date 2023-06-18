#include <iostream>
#include <vector>
#include "klient.h"
#include "zamowienie.h"
using namespace std;

int main()
{
    vector<Produkt> produkty;
    vector<Klient> klienci;
    //wczytanie produktow z pliku tekstowego i pushback na vector

    //wyswietlenie wektora produktow
    //for(unsigned long i=0;i<produkty.size();i++)
       // cout << produkty[i] << endl;
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
        case 2:
            cout << "jakiego klienta chcialbys edytowac: ";

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

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
