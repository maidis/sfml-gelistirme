// http://www.sfml-dev.org/forum/viewtopic.php?t=507&sid=37fd3cb3f1762d629ce194a8498f75a4
#include <SFML/Window.hpp>

int main()
{
    // Tam ekran için küçük bir değişken
    bool fullscreen;

    // Ana pencereyi oluştur
    sf::Window App(sf::VideoMode(640, 480, 16), "SFML Penceresi");

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

            // Tam ekran normal pencere geçişi
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::F))
            {
                fullscreen = !fullscreen;
                App.Create(sf::VideoMode(640, 480, 16), "SFML Penceresi", (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize|sf::Style::Close)); 
            }
        }
    }

    return EXIT_SUCCESS;
}
