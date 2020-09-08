/*
Napisz program, który pobierze od uzytkownika imie pracownika i pokój do którego chce sie udac i zwrotnie,
na podstawie kodu pracownika, przydzieli mu dostep do danego pomieszczenia, badz mu tego dostepu odmowi.
*/

#include <utility>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool szukajZnaku(int kod, int szukana_cyfra)
{
     vector < int > tab;

    do
    {
        int cyfra = kod % 10; // W przypadku dowolnej liczby, reszta z dzielenia przez 10 to jest ostatnia cyfra.
        tab.push_back( cyfra );
        kod = kod / 10;
    } while (kod > 0);


   vector<int>::iterator it;
   for( it=tab.begin(); it!=tab.end(); ++it )
   {
      if (*it == 9 || *it == szukana_cyfra)
        return true;
   }

   return false;

}

bool pokoj_ciszy(int & zajety)
{
    if (zajety == 0)
    {
        zajety = 1;
        return false;
    }

    if (zajety == 1)
    {
        zajety = 0;
        return true;
    }
}

int pokoj_zajety = 0;

int main()
{
 map <string, int> mymap;

    mymap["Sabrina"] = 9999;
    mymap["Bonifacy"] = 6400;
    mymap["Armenia"] = 7430;
    mymap["Suszek"] = 3000;
    mymap["Wawrzyniec"] = 8764;

string imie = "Aleks";

cout << "Podaj swoje imie:";
cin >> imie;

int dostep = 0;

// znajdz mi imie. mapa szuka imienia przez iterator. kiedy go znajdzie zwraca ten wskaznik na konkretny element, ktory znalazl
// poniewaz mamy wskaznik na element, ktory zostal znaleziony mozemu go usunac, wyswietlic, wziac wartosc.

auto temp = mymap.find(imie); // zwraca iterator . jesli znajdzie da nam iterator, jesli nie, da nam mymap.end

if (temp != mymap.end())
    dostep = (*temp).second;

// dostep = mymap.at(imie); // imie jest stringiem, jesli nie znajdzie - dopisze

int pokoj = 0;

cout << " Lista pokoi: "<< endl;
cout << "8 - Biuro Glowne " << endl;
cout << "7 - Magazyn" << endl;
cout << "6 - Sterownia" << endl;
cout << "5 - Spizarnia" << endl;
cout << "4 - Pokoj Ciszy (dostepny pod warunkiem, ze jest pusty)" << endl;
cout << "3 - Ksiegowosc" << endl;
cout << "2 - Kantyna (pokoj ogolnodopstepny - wejscie nie wymaga kodu dostepu) " << endl;

cout << "Wybierz z listy i wprowadz kod pokoju, do ktorego chcesz sie udac: ";
cin >> pokoj;

if (pokoj == 4 && szukajZnaku(dostep, pokoj)== true && pokoj_ciszy(pokoj_zajety) == false)
    {
        cout << "Masz dostep do wybranego pokoju" << endl;
    }

else if (pokoj != 4 && szukajZnaku(dostep, pokoj)== true)
    {
        cout << "Masz dostep do wybranego pokoju" << endl;
    }

else
        cout << "Nie masz dostepu do wybranego pokoju. " << endl;

cout << "Baza Danych. Wcisnij odpowiedni klawisz: \n1.-Dodawanie pracownika do listy\n2.-Usuwanie danych pracownika z listy\n3.-Modyfikacja kodu dostepu\n4.-Wyjscie" << endl;

    int odp = 0;

    do
    {
        cin >> odp;

        switch( odp )
        {
        case 1:


            {
            string nazwisko_pracownika2 = "Daniel";
            int kod_dostepu;
            cout << "Wpisz nazwisko pracownika, ktorego dane nalezy dodac do listy: ";
            cin >> nazwisko_pracownika2;
            cout << "Wpisz kod dostepu pracownika " << nazwisko_pracownika2 << " : ";
            cin >> kod_dostepu;
            mymap.insert ( pair<string,int>(nazwisko_pracownika2, kod_dostepu) );

            break;

            }


        case 2:

            {
            string nazwisko_pracownika = "Damian";
            cout << "Wpisz nazwisko pracownika, ktorego dane nalezy usunac z listy: ";
            cin >> nazwisko_pracownika;
            mymap.erase(nazwisko_pracownika);

            break;
            }

        case 3:

            {
            string nazwisko = "Wozniak";
            cout << "Wskaz nazwisko pracownika, ktorego kod zamierzasz zmodyfikowac";
            cin >> nazwisko;

            int zmieniony_kod = 0;
            cout << "Wprowadz nowy kod pracownika " << nazwisko << " : ";
            cin >> zmieniony_kod;

            mymap[nazwisko] = zmieniony_kod;
            cout << " po zmianie: " << mymap["Sabrina"] << endl;

            }

        }

    cout << "Wcisnij odpowiedni klawisz: \n1.-Dodawanie pracownika do listy\n2.-Usuwanie danych pracownika z listy\n3.-Modyfikacja kodu dostepu\n4.-Wyjscie" << endl;

    } while( odp != 4 );

/*
auto wynik = mymap.find("Sabat");

    if (wynik == mymap.end())
    {
        cout << "Nie znaleziono produktu. " << endl;
    }

    else

    {
        cout << "Produkt " << (*wynik).first << " zostal znaleziony. " << endl;
    }

*/

    return 0;
}
