#include <iostream>
#include <map>
#include <string>
int main()
{
    // Map of string & int i.e. words as key & there
    // occurrence count as values

    std::map<std::string, int> wordMap = {
                        { "is", 6 },
                        { "the", 5 },
                        { "hat", 9 },
                        { "at", 6 }
                    };
    // Check if key 'hat' exists in the map
    if (wordMap.count("hat") > 0)
    {
        std::cout << "'hat' Found" << std::endl;
    }
    else
    {
        std::cout << "'hat' Not Found" << std::endl;
    }
    // Check if key 'hello' exists in the map
    if (wordMap.count("hello") > 0)
    {
        std::cout << "'hello' Found" << std::endl;
    }
    else
    {
        std::cout << "'hello' Not Found" << std::endl;
    }


    return 0;

    /*
    Sprawdzanie, czy dany klucz istnieje
Za pomoc¹ metody find mo¿na sprawdziæ, czy dany klucz istnieje. Metoda ta znajduje dany klucz i zwraca do niego wskaŸnik lub zwraca wskaŸnik na koniec listy. Oto przyk³ad:

Listing
std::map<std::string, int> mapExample;

mapExample["key 1"] = 1;
mapExample["key 2"] = 2;

if(mapExample.find("key 1") == mapExample.end()){
    std::cout << "Key not exist!" << std::endl;
}
    */

}
