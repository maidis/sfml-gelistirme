// kırmızı başlıklı kızlar
#include <SFML/Graphics.hpp>

int main()
{
    // Tarama penceresi
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Grafik II");

    // Dosyadan bağımsız görüntü görselini hüplet
    sf::Image Image;
    if (!Image.LoadFromFile("resimler/sfml-logo.tga"))
        return EXIT_FAILURE;

    // Bağımsız görüntüyü oluştur
    sf::Sprite Sprite(Image);

    int red, green, blue, alpha = 128;
    bool terslen = 0;

    Sprite.SetOrigin(Sprite.GetSize() * 0.5f);
    Sprite.SetPosition(App.GetView().GetSize() * 0.5f);

    // Oyun döngüsünü başlat
    while (App.IsOpened())
    {
        // Olayları işle
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Pencereyi kapat: çıkış, çık dışarı
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }

        // Geçen süreyi al
        float ElapsedTime = App.GetFrameTime();

        // Bağımsız görüntüyü hareket ettir
        if (App.GetInput().IsKeyDown(sf::Key::Left))  Sprite.Move(-100 * ElapsedTime, 0);
        if (App.GetInput().IsKeyDown(sf::Key::Right)) Sprite.Move( 100 * ElapsedTime, 0);
        if (App.GetInput().IsKeyDown(sf::Key::Up))    Sprite.Move(0, -100 * ElapsedTime);
        if (App.GetInput().IsKeyDown(sf::Key::Down))  Sprite.Move(0,  100 * ElapsedTime);

        // Bağımsız görüntüyü döndür
        if (App.GetInput().IsKeyDown(sf::Key::W)) Sprite.Rotate(- 100 * ElapsedTime);
        if (App.GetInput().IsKeyDown(sf::Key::S)) Sprite.Rotate(+ 100 * ElapsedTime);


        if (App.GetInput().IsKeyDown(sf::Key::R))  red++;
        if (App.GetInput().IsKeyDown(sf::Key::T))  green++;
        if (App.GetInput().IsKeyDown(sf::Key::Y))  blue++;
        if (App.GetInput().IsKeyDown(sf::Key::U))  alpha++;

        // Bağımsız görüntünün özelliklerini değiştir
        Sprite.SetColor(sf::Color(red, green, blue, alpha));

        if (App.GetInput().IsKeyDown(sf::Key::G))  {Sprite.FlipX(terslen); terslen = !terslen;}
        if (App.GetInput().IsKeyDown(sf::Key::H))  {Sprite.FlipY(terslen); terslen = !terslen;}

        App.Clear();

        App.Draw(Sprite);

        App.Display();
    }

    return EXIT_SUCCESS;
}
