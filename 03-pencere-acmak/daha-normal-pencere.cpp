#include <SFML/Window.hpp>

int main()
{
    // Ana pencereyi oluştur
    sf::Window App(sf::VideoMode::GetDesktopMode(), "SFML Penceresi", sf::Style::Fullscreen);

    // Ana döngüye başla
    bool Running = true;
    while (Running)
    {
        App.Display();

        sf::Event Event;
        while (App.GetEvent(Event))
        {
        // Pencere kapandı
        if (Event.Type == sf::Event::Closed)
            App.Close();

        // ESC'ye basıldı
        if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
            App.Close();
        }

    }

    return EXIT_SUCCESS;
}
