#include <iostream>

using namespace std;

class Point
{
public:
    int a;
    int b;

    Point (int a_, int b_)
    {
        a = a_;
        b = b_;

        cout << "Jestem w konstruktorze z parametrami " << endl;
    }

    Point () //konstruktor domyslny. wywola sie zawsze kiedt wywolamy cos bez parametrow. Musi byc zawsze pusty. mozna zapisac = default
    {
    a = 0;
    b = 0;
    cout << "Jestem w konstruktorze bez parametrow." << endl;
    }

    // konstruktor kopiujacy. przyjmuje jako parametr referencje const na ten sam typ. przyjmuje jeden parametr
    // chce dostac inny punkt. chcemy do pkt A skopiowac pkt B

    Point (const Point & P1)
           {
            a = P1.a;
            b = P1.b;
            cout << "Jestem w konstruktorze kopiujacym. " << endl;
           }
    // operator przypisania =. bedziemy go nadpisywac. Sa zastrzezone operatory.
    // instrukcja, ze bedziemy nadpisywac. tj, jak normalna f(x). opertor musi zwracac. ppowinien zwracac ref. na dany typ.
    // this - tj. wskaznik na samego siebie.


    Point & operator=(const Point & P2) // to, co jest zwracane tj. ta lewa strona.
    {
        if (&P2 != this)
        {
            a = P2.a;
            b = P2.b;
        }

        // zabezp przed przypisywaniem samego siebie

        cout << "Jestem w operatorze przypisania. " << endl;
        return *this; // musimy wysluskac wartosc . this tj. caly wskaznik
    }

    ~Point ()
    {
       cout << " Jestem w destruktorze" << endl;
    }

};

int main()
{
    {
        Point D = Point(10, 10); // jest to optymalzowane. robiona jest tymczasowa kopia. jest wywolywany tylko operator z parametrami, nie operator przypisania
    } // zakres zycia zmiennej - destruktor wywola sie wewnatrz tych nawiasow

    Point PunktA(8, 9); // wywolanie listy inicjalizacyjnej. tez jest w konstruktorze
    Point PunktB = PunktA; // wywolanie konstruktora kopiujacego

    cout << PunktB.a << " , " << PunktB.b << endl;

    Point PunktC(1, 1);

    PunktA = PunktC;

    //cout << D.a << " , " << D.b << endl;


    return 0;
}
