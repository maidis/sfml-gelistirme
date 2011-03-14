// this is sparta dercesine, bunlar başlık
#include <SFML/Graphics.hpp>

int main()
{
    // Ana tarama penceremiz
    sf::RenderWindow App(sf::VideoMode(1024, 768, 32), "SFML Grafik I");

    // Bir dosyadan bağımsız görüntü için kullanacağımız görüntüyü alalım
    sf::Image Image;
    if (!Image.LoadFromFile("resimler/sfml-logo.tga"))
        return EXIT_FAILURE;

    // Bir ara işimize yarayacak bir değişken tanımlayalım
    int xxx = 0;

    // Bağımsız görüntüyü oluşturalım
    sf::Sprite Sprite(Image);

    // Bağımsız görüntünün merkezini tam ortası yapalım
    Sprite.SetOrigin(Sprite.GetSize() * 0.5f);

    // Bağımsız görüntüyü ekranın ortasına yerleştirelim
    // Sprite.SetPosition(App.GetView().GetSize().x * 0.5f, App.GetView().GetSize().y * 0.5f);
    Sprite.SetPosition(App.GetView().GetSize() * 0.5f);

    while (App.IsOpened())
    {
        // Olayları işle
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Pencereyi kapat: çıkış
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
        if (App.GetInput().IsMouseButtonDown(sf::Mouse::Left)) xxx++;

        if (xxx % 3 == 0) Sprite.Rotate(- 50 * ElapsedTime);
        if (xxx % 3 == 1) Sprite.Rotate(0);
        if (xxx % 3 == 2) Sprite.Rotate(+ 50 * ElapsedTime);

        // Ekranı temizle
        App.Clear();

        // Bağımsız görüntüyü pencerede göster
        App.Draw(Sprite);

        // Pencere içeriğini ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
