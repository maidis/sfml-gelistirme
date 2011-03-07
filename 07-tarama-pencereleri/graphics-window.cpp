// Başlıklar
#include <SFML/Graphics.hpp>

int main()
{
    // Tarama penceremizi oluşturalım
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Grafik");

    // birkaç değişken ekleyelim
    int xxx, yyy, zzz = 0;

    // Oyun döngüsü başlangıcı
    while (App.IsOpened())
    {
        // Olayları işle
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Pencereyi kapat: çıkış
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // Bir tuşa basıldı
            if (Event.Type == sf::Event::KeyPressed)
            {
                // Escape tuşu: çıkış
                if (Event.Key.Code == sf::Key::Escape)
                    App.Close();

                // F1, F2 ve F3 tuşu: xxx, yyy ve zzz artır
                if (Event.Key.Code == sf::Key::F1)
                    xxx = xxx + 5;

                if (Event.Key.Code == sf::Key::F2)
                    yyy = yyy + 5;

                if (Event.Key.Code == sf::Key::F3)
                    zzz = zzz + 5;
            }
        }

        // Ekranı xxx, yyy, zzz ile boya
        App.Clear(sf::Color(xxx, yyy, zzz));

        // Pencere içeriğini ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
