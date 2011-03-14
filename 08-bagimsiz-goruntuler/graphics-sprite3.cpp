#include <SFML/Graphics.hpp>

int main()
{
    // Ana tarama penceremiz
    sf::RenderWindow App(sf::VideoMode(1024, 768, 32), "SFML Grafik III");

    // Bir dosyadan bağımsız görüntü için kullanacağımız görüntüyü almayalım, kendimiz yapalım
    sf::Image Image;
    Image.Create(400, 300, sf::Color(255,0,0));

    // Bağımsız görüntüyü oluşturalım
    sf::Sprite Sprite1(Image);

    // Bağımsız görüntünün merkezini tam ortası yapalım
    Sprite1.SetOrigin(Sprite1.GetSize() * 0.5f);

    // Bağımsız görüntüyü ekranın ortasına yerleştirelim
    Sprite1.SetPosition(App.GetView().GetSize() * 0.5f);

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


        // Ekranı temizle
        App.Clear();

        // Sadece Sleep ve SetPixel'i göstermek için
        for (int x=0; x<=400; x++)
            for (int y=0; y<=300; y++)
            {
                Image.SetPixel(x, y, sf::Color(0, 255, 0));
                sf::Sleep(0.0000009f);
                App.Draw(Sprite1);
                App.Display();
                App.Clear();
            }

        // Pencere içeriğini ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
