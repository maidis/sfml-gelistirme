#include <SFML/System.hpp>
#include <iostream>

int main()
{
    int sayi, kac = 0;
    sf::Clock Saat;
    while (Saat.GetElapsedTime() < 10.f)
    {
        std::cout << "10 saniye içinde kaç sayı girebilirsiniz: ";
        std::cin >> sayi;
        kac++;
    }
    std::cout << "O degil de: " << kac << std::endl;

    return 0;
}
