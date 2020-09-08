#include<iostream>
#include<map> // for map operations
using namespace std;

int main()
{
    // declaring map
    // of char and int
    map< char, int > mp;

    // declaring iterator
    map<char, int>::iterator it ;

    // inserting values
     mp['a']=5;
     mp['b']=10;
     mp['c']=15;
     mp['d']=20;
     mp['e']=30;

    // printing initial map elements
    cout << "The initial map elements are : \n";
    for (it1 = mp.begin(); it1!=mp.end();  ++it1)
    cout << it1->first << "->" << it1->second << endl;

    // using clear() to erase all elements in map
    mp.clear();

    // printing map elements after deletion
    cout << "The map elements after clearing all elements are : \n";
    for (it1 = mp.begin(); it1!=mp.end();  ++it1)
    cout << it1->first << "->" << it1->second << endl;

}
