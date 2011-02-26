#include <SFML/Window.hpp>

int main()
{
    // Ana pencereyi oluştur
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Hareketi");

    // Girdi yöneticisine oluşturduğumuz pencereyle ilişkilendirilmiş bir referans al
    // ve sonraki kullanımlar için sakla
    const sf::Input& Input = App.GetInput();

    int x, y = 0;
    int h = App.GetHeight();
    int w = App.GetWidth();

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

            // Yukarı ok tuşu: pencere yukarı
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Up))
            {
                y--;
                App.SetPosition(x, y);
            }

            // Aşağı ok tuşu: pencere yukarı
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Down))
            {
                y++;
                App.SetPosition(x, y);
            }

            // Sol ok tuşu: pencere yukarı
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Left))
            {
                x--;
                App.SetPosition(x, y);
            }

            // Sağ ok tuşu: pencere yukarı
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right))
            {
                x++;
                App.SetPosition(x, y);
            }

            // W tuşu: pencere büyüt
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::W))
            {
                w++;
                h++;
                App.SetSize(w, h);
            }

            // S tuşu: pencere küçült
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::S))
            {
                w--;
                h--;
                App.SetSize(w, h);
            }

        }

        // Pencereyi ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
