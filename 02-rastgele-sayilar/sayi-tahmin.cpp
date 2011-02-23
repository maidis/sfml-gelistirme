#include <SFML/System.hpp>
#include <iomanip>
#include <iostream>

int main()
{
    unsigned int sayi = sf::Randomizer::Random(0, 100);
    unsigned int tahmin;

    for (int i = 0; i < 7; ++i)
        {
        std::cout << "tahmininiz: ";
        std::cin >> tahmin;

        if (tahmin==sayi)
            {
            std::cout << "Bildiniz!\n";
            i=7;
            }
        if (tahmin<sayi)
            std::cout << "Daha büyük!\n";
        if (tahmin>sayi)
            std::cout << "Daha küçük!\n";
        }

    if (tahmin!=sayi)
        std::cout << "O değil de, sayı: " << sayi << "\n";

    return EXIT_SUCCESS;
}
 
