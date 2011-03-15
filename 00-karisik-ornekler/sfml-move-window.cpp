#include <SFML/Graphics.hpp>

int main()
{
    // Ana tarama penceremiz, kıymetlimis
    sf::RenderWindow App(sf::VideoMode(640, 480, 32), "SFML Window Move");

    int xxx, yyy = 0;
    App.SetPosition(xxx,yyy);

    while (App.IsOpened())
    {
        // Olayları işle
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Pencereyi kapat: çıkış
            if (Event.Type == sf::Event::Closed)
                App.Close();
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Left))
            {
                xxx--;
                App.SetPosition(xxx,yyy);
            }
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right))
            {
                xxx++;
                App.SetPosition(xxx,yyy);
            }
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Up))
            {
                yyy--;
                App.SetPosition(xxx,yyy);
            }
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Down))
            {
                yyy++;
                App.SetPosition(xxx,yyy);
            }
            //if (event.Type == sf::Event::Moved)
            //    xxx = App.GetPosition().x;
            //    yyy = App.GetPosition().y;
            //}
        }

        // Ekranı temizle
        App.Clear();

        // Pencere içeriğini ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
