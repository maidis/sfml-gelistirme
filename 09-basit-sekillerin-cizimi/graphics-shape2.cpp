// başlıklar
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow App(sf::VideoMode(1280, 800), "SFML Shapes", sf::Style::Fullscreen);

    // Bir ara işimize yarayacak bir değişken tanımlayalım
    int xxx, yyy = 0;
    int red, green, blue = 128;

    // Öntanımlı bir şekil çiz
    sf::Shape Rect = sf::Shape::Rectangle(0, 0, 200, 100, sf::Color::Yellow);
    Rect.Move(640, 400);
    Rect.SetOrigin(100, 50);

    // Özel bir çokgen oluştur
    sf::Shape Triangle;
    Triangle.AddPoint(0, 0,  sf::Color(255, 0, 0),     sf::Color(0, 128, 128));
    Triangle.AddPoint(200, 0,   sf::Color(255, 85, 85),   sf::Color(0, 128, 128));
    Triangle.AddPoint(100, 150,  sf::Color(255, 170, 170), sf::Color(0, 128, 128));
    Triangle.Move(240, 400);
    Triangle.SetOrigin(100, 75);

    while (App.IsOpened())
    {
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                App.Close();

            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();
        }
        // Geçen süreyi al
        float ElapsedTime = App.GetFrameTime();

        // Bağımsız görüntüyü hareket ettir
        if (App.GetInput().IsKeyDown(sf::Key::Left))  Rect.Move(-100 * ElapsedTime, 0);
        if (App.GetInput().IsKeyDown(sf::Key::Right)) Rect.Move( 100 * ElapsedTime, 0);
        if (App.GetInput().IsKeyDown(sf::Key::Up))    Rect.Move(0, -100 * ElapsedTime);
        if (App.GetInput().IsKeyDown(sf::Key::Down))  Rect.Move(0,  100 * ElapsedTime);

        // Bağımsız görüntüyü döndür
        if (App.GetInput().IsMouseButtonDown(sf::Mouse::Left)) xxx++;

        if (xxx % 3 == 0) { Rect.Rotate(- 50 * ElapsedTime); Triangle.Rotate(- 50 * ElapsedTime); }
        if (xxx % 3 == 1) { Rect.Rotate(0); Triangle.Rotate(0); }
        if (xxx % 3 == 2) { Rect.Rotate(+ 50 * ElapsedTime); Triangle.Rotate(+ 50 * ElapsedTime); }
        
        yyy++;
        if (yyy == 1000)
        {
            red = sf::Randomizer::Random(0, 255);
            green = sf::Randomizer::Random(0, 255);
            blue = sf::Randomizer::Random(0, 255);
            Rect.SetColor(sf::Color(red, green, blue, 255));
            yyy=0;
        }
        
        App.Clear();
        App.Draw(Rect);
        App.Draw(Triangle);
        App.Display();
    }

    return EXIT_SUCCESS;
}
