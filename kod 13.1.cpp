// pary owoce i ceny
#include <utility>
#include <iostream>
#include <string>
#include <map> // mapy

using namespace std;

int main()
{
    pair <string, double> owoc1 = {"pomidor", 3.45};
    pair <string, double> owoc2;
    pair <string, double> owoc3;

    // zoptymalizowany sposob:
    owoc2 = make_pair("cukinia", 6.99);

    owoc3.first = "ogorki";
    owoc3.second = 6.78;

    cout << "nazwa owocu: " << owoc1.first << ", cena owocu: " << owoc1.second << endl;

    // mozna zrobic wektor par
    // mapa jest kontenerem, ktory sklada sie z par. kazda para jest kluczem i wartoscia. pomidor - klucz,
    // po ktorym szukamy. cena - wartosc. klucze musza byc unikatowe. wartosci moga sie powtarzac
    // w nawiasie kwadratowym klucz
    // jesli kontener nie znajdzie klucza, kontener go utworzy

    map<string, double> warzywa_i_ceny;
    warzywa_i_ceny["sliwki"] = 4.56;

    // mapa tez ma iteratory

    cout << "Nazwa: sliwki , " << "cena: " << warzywa_i_ceny["sliwki"] << " rozmiar mapy: " << warzywa_i_ceny.size() << endl;

    cout << "Nazwa: sliwki , " << "cena: " << warzywa_i_ceny["banany"] << endl;
    cout << " rozmiar mapy: " << warzywa_i_ceny.size() << endl;

    // jak zapobiec dodawaniu? funkcja find w srodku mapy. finkcja find zwraca nam iterator. jesli nie istnieje dostaniemy map_end

    warzywa_i_ceny.insert(pair<string, float>("brzoskwinie", 20.5));

   // cout << warzywa_i_ceny["brzoskwinie"] << endl;

   warzywa_i_ceny.erase("banany");

   auto wynik = warzywa_i_ceny.find("banany");

    if (wynik == warzywa_i_ceny.end())
    {
        cout << "Nie znaleziono produktu. " << endl;
    }

    else

    {
        cout << "Produkt " << (*wynik).first << " zostal znaleziony. " << endl;
    }

    return 0;
}
