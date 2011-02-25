#include <SFML/Window.hpp>

int main()
{
    // Ana pencereyi oluştur
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Penceresi");

    // Ana döngüye başla
    bool Running = true;
    while (Running)
    {
        App.Display();
    }

    return EXIT_SUCCESS;
}
