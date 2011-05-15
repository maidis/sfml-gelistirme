// başlıklar
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow App(sf::VideoMode(1280, 800), "SFML Shapes", sf::Style::Fullscreen);

    // Bir ara işimize yarayacak bir değişken tanımlayalım
    int xxx = 0;
    int yyy = 0;

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
        if (App.GetInput().IsKeyDown(sf::Key::Left))  Triangle.SetPointPosition(0, Triangle.GetPointPosition(0).x + 1, Triangle.GetPointPosition(0).y +1);
        if (App.GetInput().IsKeyDown(sf::Key::Right)) Triangle.SetPointPosition(1, Triangle.GetPointPosition(1).x + 1, Triangle.GetPointPosition(1).y + 1);
        if (App.GetInput().IsKeyDown(sf::Key::Up))    Triangle.SetPointPosition(2, Triangle.GetPointPosition(2).x + 1, Triangle.GetPointPosition(2).y + 1);
        if (App.GetInput().IsKeyDown(sf::Key::W))  Triangle.SetPointPosition(0, Triangle.GetPointPosition(0).x - 1, Triangle.GetPointPosition(0).y -1);
        if (App.GetInput().IsKeyDown(sf::Key::A)) Triangle.SetPointPosition(1, Triangle.GetPointPosition(1).x - 1, Triangle.GetPointPosition(1).y - 1);
        if (App.GetInput().IsKeyDown(sf::Key::S))    Triangle.SetPointPosition(2, Triangle.GetPointPosition(2).x - 1, Triangle.GetPointPosition(2).y - 1);
        if (App.GetInput().IsKeyDown(sf::Key::K)) Triangle.AddPoint(100, 150,  sf::Color(255, 170, 170), sf::Color(0, 128, 128));

        App.Clear();
        App.Draw(Triangle);
        App.Display();
    }

    return EXIT_SUCCESS;
}
