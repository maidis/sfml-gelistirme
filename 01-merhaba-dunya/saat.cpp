#include <SFML/System.hpp>
#include <iostream>

int main()
{
    sf::Clock Saat;
    while (Saat.GetElapsedTime() < 5.f)
    {
        std::cout << Saat.GetElapsedTime() << std::endl;
        sf::Sleep(0.5f);
    }

    return 0;
}
