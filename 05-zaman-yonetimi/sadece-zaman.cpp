#include <SFML/Window.hpp>

int main()
{
    // Ana penceremizi oluşturalım
    sf::Window App(sf::VideoMode(800, 600, 16), "SFML Zaman Zaman");

    // En yüksek kareoranını elde etmek için dikey eşzamanlamayı kapatalım
    App.EnableVerticalSync(false);

    // Zamanı ölçmek için bir saat oluşturalım
    sf::Clock Clock;

    // Yalandan bazı değişkenler oluşturalım, bir objeyi hareket ettiriyormuşçasına
    const float Speed = 50.f;
    float Left = 0.f;
    float Top  = 0.f;

    // Start main loop
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
        }

        // Son kareden bu zamana geçen süreyi bulalım (App.GetFrameTime() da kullanabilirdik)
        float ElapsedTime = Clock.GetElapsedTime();
        Clock.Reset();

        // Sanal objemizi hareket ettirelim
        if (App.GetInput().IsKeyDown(sf::Key::Left))  Left -= Speed * ElapsedTime;
        if (App.GetInput().IsKeyDown(sf::Key::Right)) Left += Speed * ElapsedTime;
        if (App.GetInput().IsKeyDown(sf::Key::Up))    Top  -= Speed * ElapsedTime;
        if (App.GetInput().IsKeyDown(sf::Key::Down))  Top  += Speed * ElapsedTime;

        // Pencereyi ekranda gösterelim
        App.Display();
    }

    return EXIT_SUCCESS;
}
