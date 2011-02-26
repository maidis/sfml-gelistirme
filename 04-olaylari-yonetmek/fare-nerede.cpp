#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    // Ana pencereyi oluştur
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Söyle Bana Fare Nerde");

    // Girdi yöneticisine oluşturduğumuz pencereyle ilişkilendirilmiş bir referans al
    // ve sonraki kullanımlar için sakla
    const sf::Input& Input = App.GetInput();

    App.SetFramerateLimit(60);

    int i;

    // Ana döngüye başla
    while (App.IsOpened())
    {
        // Olayları işle
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Pencereyi kapat: çıkış
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // ESC tuşu: çıkış
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();

            // Fare hareketleri: yakın takip
            if (Event.Type == sf::Event::MouseMoved)
            {
                i++;
                if (i==30)
                {
                    i=0;
                    std::cout << "X: " << Input.GetMouseX() << " Y: " << Input.GetMouseY() << std::endl;
                }
            }
        }

        // Pencereyi ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
