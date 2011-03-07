// Başlıklar
#include <SFML/Graphics.hpp>

int main()
{
    // Tarama penceremizi oluşturalım
    // Pencere başlığında UTF-8
    // http://www.sfml-dev.org/forum/viewtopic.php?p=27101&sid=de3224ac4da564d665b51f3086d65e7c
    sf::String Baslik("SFML Pencere Görüntüsü Alma");
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), Baslik);

    // birkaç değişken ekleyelim
    int xxx, yyy, zzz = 0;

    // resim için
    sf::Image Image1;

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

                // F1 tuşu: ekran görüntüsü al
                if (Event.Key.Code == sf::Key::F1)
                {
                    Image1.CopyScreen(App);
                    Image1.SaveToFile("ekrangoruntusu.jpg");
                }
            }
        }

        // xxx, yyy ve zzz değerlerini rastgele artır
        int Random = sf::Randomizer::Random(0, 2);
        if (Random == 0) xxx++;
        if (Random == 1) yyy++;
        if (Random == 2) zzz++;

        // Ekranı xxx, yyy, zzz ile boya
        App.Clear(sf::Color(xxx, yyy, zzz));

        // Pencere içeriğini ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
